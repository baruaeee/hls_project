# 2026-11-18T02:56:38.409561816
import vitis

client = vitis.create_client()
client.set_workspace(path="hdlsrc")

comp = client.create_hls_component(name = "hls_component",part = "xc7z010iclg225-1L",cfg_file = ["hls_config.cfg"],template = "empty_hls_component")

cfg = client.get_config_file(path="/home/exotic/HLS_Thesis/Data_Compression_Decompression/codegen/split_quotient_remainder/hdlsrc/hls_component/hls_config.cfg")

cfg.set_values(key="syn.file", values=["../ap_fixed_ostream.hpp", "../hlsutils.hpp", "../k_in.dat", "../q_out_expected.dat", "../r_out_expected.dat", "../rt_defines.h", "../rtwtypes.hpp", "../split_quotient_remainder_fixptClass.hpp", "../split_quotient_remainder_fixpt_main.cpp", "../split_quotient_remainder_fixpt_wrapper.cpp", "../u_in.dat"])

cfg.set_values(key="tb.file", values=["../split_quotient_remainder_fixptClass_tb.hpp"])

comp = client.get_component(name="hls_component")
comp.run(operation="C_SIMULATION")

cfg.set_value(section="hls", key="syn.top", value="split_quotient_remainder_fixpt_wrapper")

comp.run(operation="SYNTHESIS")

comp.run(operation="SYNTHESIS")

