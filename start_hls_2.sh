#!/bin/bash
# =============================================================================
# CADENCE STRATUS HIGH-LEVEL SYNTHESIS AUTOMATED CONTAINER LAUNCHER
# =============================================================================

# 1. Authorize local container connections to the host X11 display graphics server
echo "[+] Forwarding X11 display rendering graphics privileges..."
xhost +local: > /dev/null 2>&1

# 2. Extract active user authorization security tokens to pass down into the sandbox
# This completely prevents 'QXcbConnection: Could not connect to display' blocks
if command -v xauth &> /dev/null; then
    xauth nextract /tmp/host_xkey $DISPLAY > /dev/null 2>&1
fi

# 3. Bypass non-Linux drive label permission blocks (SELinux permissive mode)
if command -v setenforce &> /dev/null; then
    sudo setenforce 0 2>/dev/null || true
fi

# 4. Detect whether the current host operating system uses Docker (Ubuntu) or Podman (Rocky/RHEL)
if command -v podman &> /dev/null; then
#    CONTAINER_ENGINE="sudo podman"
    CONTAINER_ENGINE="podman"
elif command -v docker &> /dev/null; then
#    CONTAINER_ENGINE="sudo docker"
    CONTAINER_ENGINE="docker"
else
    echo "[-] ERROR: Neither Podman nor Docker was detected on this host machine."
    exit 1
fi

echo "[+] Booting portable Cadence HLS workspace container via ${CONTAINER_ENGINE}..."

# 5. Launch the immutable container layer with full shared volume access matrices
${CONTAINER_ENGINE} run -it --rm \
  --net=host \
  --dns=8.8.8.8 \
  --ipc=host \
  --privileged \
  -v /run/media:/run/media:rw \
  -v /mnt:/mnt:rw \
  -v /home:/home:rw \
  -v /tmp/.X11-unix:/tmp/.X11-unix:ro \
  -e DISPLAY=$DISPLAY \
  cadence_hls_complete:v1 bash -c "
    # Import the X11 authorization key cookie seamlessly inside root profile paths
    if [ -f /tmp/host_xkey ]; then
        xauth nmerge /tmp/host_xkey > /dev/null 2>&1
        rm -f /tmp/host_xkey
    fi
    
    # Map the host name layout dynamically to loopback to unblock Genus sockets
    echo '127.0.0.1 $(hostname)' >> /etc/hosts
    echo '127.0.0.1 exotic' >> /etc/hosts
    
    # Drop right into your thesis design workspace directory 
    cd /home/ipad/HLS_Thesis/Stratus_HLS/Simple_FIR/
    
    # Print welcome status banner
    echo '===================================================================='
    echo '  PORTABLE CADENCE STRATUS HLS WORKSPACE ENVIRONMENT IS READY       '
    echo '===================================================================='
    echo ' -> Run: source /run/media/exotic/Cadence/Installed/init_cadence.sh '
    echo ' -> Run: make hls_fir_filter_config_HLS                             '
    echo '===================================================================='
    exec bash
  "
