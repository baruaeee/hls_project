# 2026-11-17T13:50:13.431536368
import vitis

client = vitis.create_client()
client.set_workspace(path="hdlsrc")

comp = client.create_hls_component(name = "hls_component",part = "xc7z010iclg225-1L",cfg_file = ["hls_config.cfg"],template = "empty_hls_component")

cfg = client.get_config_file(path="/home/exotic/HLS_Thesis/Data_Compression_Decompression/codegen/neuron_predictor/hdlsrc/hls_component/hls_config.cfg")

cfg.set_values(key="syn.file", values=["../ap_fixed_ostream.hpp", "../hlsutils.hpp", "../neuron_predictor_fixptClass.hpp", "../neuron_predictor_fixpt_main.cpp", "../neuron_predictor_fixpt_wrapper.cpp", "../predicted_expected.dat", "../reset_rsvd.dat", "../residual_expected.dat", "../rt_defines.h", "../rtwtypes.hpp", "../x_in.dat"])

cfg.set_values(key="tb.file", values=["../neuron_predictor_fixptClass_tb.hpp"])

comp = client.get_component(name="hls_component")
comp.run(operation="C_SIMULATION")

cfg.set_value(section="hls", key="syn.top", value="neuron_predictor_fixpt_wrapper")

comp.run(operation="SYNTHESIS")

comp.run(operation="SYNTHESIS")

vitis.dispose()

