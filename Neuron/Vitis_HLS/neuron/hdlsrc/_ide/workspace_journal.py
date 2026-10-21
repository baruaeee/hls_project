# 2026-10-19T04:52:10.649761678
import vitis

client = vitis.create_client()
client.set_workspace(path="hdlsrc")

comp = client.create_hls_component(name = "neuron",part = "xc7z010iclg225-1L",cfg_file = ["hls_config.cfg"],template = "empty_hls_component")

cfg = client.get_config_file(path="/home/exotic/HLS_Thesis/Neuron/Vitis_HLS/neuron/hdlsrc/neuron/hls_config.cfg")

cfg.set_values(key="syn.file", values=["../ap_fixed_ostream.hpp", "../hlsutils.hpp", "../neuron_fixptClass.hpp", "../neuron_fixpt_main.cpp", "../neuron_fixpt_wrapper.cpp", "../rtwtypes.hpp"])

cfg.set_values(key="tb.file", values=["/home/exotic/HLS_Thesis/Neuron/ap_fixed_ostream.hpp"])

cfg.set_values(key="tb.file", values=["/home/exotic/HLS_Thesis/Neuron/ap_fixed_ostream.hpp", "../neuron_fixptClass_tb.hpp"])

cfg.set_values(key="tb.file", values=["../neuron_fixptClass_tb.hpp"])

comp = client.get_component(name="neuron")
comp.run(operation="C_SIMULATION")

comp.run(operation="SYNTHESIS")

cfg.set_value(section="hls", key="syn.top", value="neuron_fixpt_wrapper")

comp.run(operation="SYNTHESIS")

