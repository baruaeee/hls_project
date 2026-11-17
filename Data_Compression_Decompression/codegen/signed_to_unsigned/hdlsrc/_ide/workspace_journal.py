# 2026-11-17T15:27:48.043950308
import vitis

client = vitis.create_client()
client.set_workspace(path="hdlsrc")

comp = client.create_hls_component(name = "hls_component",part = "xc7z010iclg225-1L",cfg_file = ["hls_config.cfg"],template = "empty_hls_component")

cfg = client.get_config_file(path="/home/exotic/HLS_Thesis/Data_Compression_Decompression/codegen/signed_to_unsigned/hdlsrc/hls_component/hls_config.cfg")

cfg.set_values(key="syn.file", values=["../ap_fixed_ostream.hpp", "../e_in.dat", "../hlsutils.hpp", "../rt_defines.h", "../rtwtypes.hpp", "../signed_to_unsigned_fixptClass.hpp", "../signed_to_unsigned_fixpt_main.cpp", "../signed_to_unsigned_fixpt_wrapper.cpp", "../u_out_expected.dat"])

cfg.set_values(key="tb.file", values=["../signed_to_unsigned_fixptClass_tb.hpp"])

comp = client.get_component(name="hls_component")
comp.run(operation="C_SIMULATION")

cfg.set_value(section="hls", key="syn.top", value="signed_to_unsigned_fixpt_wrapper")

comp.run(operation="SYNTHESIS")

