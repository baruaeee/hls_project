# 2026-11-17T02:56:11.487240983
import vitis

client = vitis.create_client()
client.set_workspace(path="hdlsrc")

comp = client.create_hls_component(name = "hls_component",part = "xc7z010iclg225-1L",cfg_file = ["hls_config.cfg"],template = "empty_hls_component")

vitis.dispose()

