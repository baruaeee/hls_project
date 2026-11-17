# 2026-11-17T23:47:49.139015537
import vitis

client = vitis.create_client()
client.set_workspace(path="hdlsrc")

comp = client.create_hls_component(name = "hls_component",part = "xc7z010iclg225-1L",cfg_file = ["hls_config.cfg"],template = "empty_hls_component")

cfg = client.get_config_file(path="/home/exotic/HLS_Thesis/Data_Compression_Decompression/codegen/calc_rice_k/hdlsrc/hls_component/hls_config.cfg")

cfg.set_values(key="syn.file", values=["../ap_fixed_ostream.hpp", "../calc_rice_k_fixptClass.hpp", "../calc_rice_k_fixpt_main.cpp", "../calc_rice_k_fixpt_wrapper.cpp", "../hlsutils.hpp", "../k_out_expected.dat", "../reset_rsvd.dat", "../rt_defines.h", "../rtwtypes.hpp", "../u_in.dat"])

cfg.set_values(key="tb.file", values=["../calc_rice_k_fixptClass_tb.hpp"])

comp = client.get_component(name="hls_component")
comp.run(operation="C_SIMULATION")

cfg.set_value(section="hls", key="syn.top", value="calc_rice_k_fixpt_wrapper")

comp.run(operation="C_SIMULATION")

comp.run(operation="C_SIMULATION")

comp.run(operation="SYNTHESIS")

comp.run(operation="SYNTHESIS")

