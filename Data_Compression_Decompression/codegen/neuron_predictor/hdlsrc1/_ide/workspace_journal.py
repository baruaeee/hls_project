# 2026-11-17T01:41:19.875200574
import vitis

client = vitis.create_client()
client.set_workspace(path="hdlsrc")

comp = client.get_component(name="hls_component")
comp.run(operation="SYNTHESIS")

