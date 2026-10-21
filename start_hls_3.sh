#!/bin/bash
# =============================================================================
# CADENCE STRATUS HIGH-LEVEL SYNTHESIS AUTOMATED CONTAINER LAUNCHER
# =============================================================================

# 1. Authorize local container connections to the host X11 display graphics server
echo "[+] Forwarding X11 display rendering graphics privileges..."
xhost +local: > /dev/null 2>&1

# 2. Extract active user authorization security tokens to pass down into the sandbox
if command -v xauth &> /dev/null; then
    xauth nextract /tmp/host_xkey $DISPLAY > /dev/null 2>&1
fi

# 3. Bypass non-Linux drive label permission blocks (SELinux permissive mode)
if command -v setenforce &> /dev/null; then
    sudo setenforce 0 2>/dev/null || true
fi

# 4. Boot the container with on-the-fly user database injection to bypass stateless blocks
echo "[+] Booting portable Cadence HLS workspace container..."
sudo podman run -it --rm \
  --net=host \
  --dns=8.8.8.8 \
  --ipc=host \
  --privileged \
  --user 1000:1000 \
  --passwd-entry "exotic:x:1000:1000:exotic user:/home/exotic:/bin/bash" \
  -v /home/exotic:/home/exotic:rw \
  -v /run/media/exotic/Cadence/Installed:/run/media/exotic/Cadence/Installed:rw \
  -v /tmp/.X11-unix:/tmp/.X11-unix:ro \
  -e DISPLAY=$DISPLAY \
  localhost/rhel_eda:v2 bash -c "
    # Import the X11 authorization key cookie seamlessly inside user profile paths
    if [ -f /tmp/host_xkey ]; then
        xauth nmerge /tmp/host_xkey > /dev/null 2>&1
        rm -f /tmp/host_xkey
    fi

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
