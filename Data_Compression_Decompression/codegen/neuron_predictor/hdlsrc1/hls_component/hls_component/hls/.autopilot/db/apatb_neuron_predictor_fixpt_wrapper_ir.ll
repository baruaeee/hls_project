; ModuleID = '/home/exotic/HLS_Thesis/Data_Compression_Decompression/codegen/neuron_predictor/hdlsrc/hls_component/hls_component/hls/.autopilot/db/a.g.ld.5.gdce.bc'
source_filename = "llvm-link"
target datalayout = "e-m:e-i64:64-i128:128-i256:256-i512:512-i1024:1024-i2048:2048-i4096:4096-n8:16:32:64-S128-v16:16-v24:32-v32:32-v48:64-v96:128-v192:256-v256:256-v512:512-v1024:1024"
target triple = "fpga64-xilinx-none"

%"struct.ap_int<11>" = type { %"struct.ap_int_base<11, true>" }
%"struct.ap_int_base<11, true>" = type { %"struct.ssdm_int<11, true>" }
%"struct.ssdm_int<11, true>" = type { i11 }
%"struct.ap_ufixed<14, 1>" = type { %"struct.ap_fixed_base<14, 1, false>" }
%"struct.ap_fixed_base<14, 1, false>" = type { %"struct.ssdm_int<14, false>" }
%"struct.ssdm_int<14, false>" = type { i14 }

; Function Attrs: noinline willreturn
define void @apatb_neuron_predictor_fixpt_wrapper_ir(%"struct.ap_int<11>"* nocapture readonly %x_in, i1 zeroext %reset_rsvd, %"struct.ap_ufixed<14, 1>"* noalias nocapture nonnull align 2 dereferenceable(2) %residual, %"struct.ap_ufixed<14, 1>"* noalias nocapture nonnull align 2 dereferenceable(2) %predicted) local_unnamed_addr #0 {
entry:
  %residual_copy = alloca i14, align 512
  %predicted_copy = alloca i14, align 512
  call fastcc void @copy_in(%"struct.ap_ufixed<14, 1>"* nonnull %residual, i14* nonnull align 512 %residual_copy, %"struct.ap_ufixed<14, 1>"* nonnull %predicted, i14* nonnull align 512 %predicted_copy)
  call void @apatb_neuron_predictor_fixpt_wrapper_hw(%"struct.ap_int<11>"* %x_in, i1 %reset_rsvd, i14* %residual_copy, i14* %predicted_copy)
  call void @copy_back(%"struct.ap_ufixed<14, 1>"* %residual, i14* %residual_copy, %"struct.ap_ufixed<14, 1>"* %predicted, i14* %predicted_copy)
  ret void
}

; Function Attrs: argmemonly noinline norecurse willreturn
define internal fastcc void @copy_in(%"struct.ap_ufixed<14, 1>"* noalias readonly "unpacked"="0", i14* noalias nocapture align 512 "unpacked"="1.0", %"struct.ap_ufixed<14, 1>"* noalias readonly "unpacked"="2", i14* noalias nocapture align 512 "unpacked"="3.0") unnamed_addr #1 {
entry:
  call fastcc void @"onebyonecpy_hls.p0struct.ap_ufixed<14, 1>.40"(i14* align 512 %1, %"struct.ap_ufixed<14, 1>"* %0)
  call fastcc void @"onebyonecpy_hls.p0struct.ap_ufixed<14, 1>.40"(i14* align 512 %3, %"struct.ap_ufixed<14, 1>"* %2)
  ret void
}

; Function Attrs: argmemonly noinline norecurse willreturn
define internal fastcc void @copy_out(%"struct.ap_ufixed<14, 1>"* noalias "unpacked"="0", i14* noalias nocapture readonly align 512 "unpacked"="1.0", %"struct.ap_ufixed<14, 1>"* noalias "unpacked"="2", i14* noalias nocapture readonly align 512 "unpacked"="3.0") unnamed_addr #2 {
entry:
  call fastcc void @"onebyonecpy_hls.p0struct.ap_ufixed<14, 1>"(%"struct.ap_ufixed<14, 1>"* %0, i14* align 512 %1)
  call fastcc void @"onebyonecpy_hls.p0struct.ap_ufixed<14, 1>"(%"struct.ap_ufixed<14, 1>"* %2, i14* align 512 %3)
  ret void
}

; Function Attrs: argmemonly noinline norecurse willreturn
define internal fastcc void @"onebyonecpy_hls.p0struct.ap_ufixed<14, 1>"(%"struct.ap_ufixed<14, 1>"* noalias "unpacked"="0" %dst, i14* noalias nocapture readonly align 512 "unpacked"="1.0" %src) unnamed_addr #3 {
entry:
  %0 = icmp eq %"struct.ap_ufixed<14, 1>"* %dst, null
  br i1 %0, label %ret, label %copy

copy:                                             ; preds = %entry
  %dst.0.0.04 = getelementptr %"struct.ap_ufixed<14, 1>", %"struct.ap_ufixed<14, 1>"* %dst, i64 0, i32 0, i32 0, i32 0
  %1 = bitcast i14* %src to i16*
  %2 = load i16, i16* %1
  %3 = trunc i16 %2 to i14
  store i14 %3, i14* %dst.0.0.04, align 2
  br label %ret

ret:                                              ; preds = %copy, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse willreturn
define internal fastcc void @"onebyonecpy_hls.p0struct.ap_ufixed<14, 1>.40"(i14* noalias nocapture align 512 "unpacked"="0.0" %dst, %"struct.ap_ufixed<14, 1>"* noalias readonly "unpacked"="1" %src) unnamed_addr #3 {
entry:
  %0 = icmp eq %"struct.ap_ufixed<14, 1>"* %src, null
  br i1 %0, label %ret, label %copy

copy:                                             ; preds = %entry
  %src.0.0.03 = getelementptr %"struct.ap_ufixed<14, 1>", %"struct.ap_ufixed<14, 1>"* %src, i64 0, i32 0, i32 0, i32 0
  %1 = bitcast i14* %src.0.0.03 to i16*
  %2 = load i16, i16* %1
  %3 = trunc i16 %2 to i14
  store i14 %3, i14* %dst, align 512
  br label %ret

ret:                                              ; preds = %copy, %entry
  ret void
}

declare i8* @malloc(i64)

declare void @free(i8*)

declare void @apatb_neuron_predictor_fixpt_wrapper_hw(%"struct.ap_int<11>"* %x_in, i1 %reset_rsvd, i14* %residual, i14* %predicted)

; Function Attrs: argmemonly noinline norecurse willreturn
define internal fastcc void @copy_back(%"struct.ap_ufixed<14, 1>"* noalias "unpacked"="0", i14* noalias nocapture readonly align 512 "unpacked"="1.0", %"struct.ap_ufixed<14, 1>"* noalias "unpacked"="2", i14* noalias nocapture readonly align 512 "unpacked"="3.0") unnamed_addr #2 {
entry:
  call fastcc void @"onebyonecpy_hls.p0struct.ap_ufixed<14, 1>"(%"struct.ap_ufixed<14, 1>"* %0, i14* align 512 %1)
  call fastcc void @"onebyonecpy_hls.p0struct.ap_ufixed<14, 1>"(%"struct.ap_ufixed<14, 1>"* %2, i14* align 512 %3)
  ret void
}

declare void @neuron_predictor_fixpt_wrapper_hw_stub(%"struct.ap_int<11>"* nocapture readonly, i1 zeroext, %"struct.ap_ufixed<14, 1>"* noalias nocapture nonnull, %"struct.ap_ufixed<14, 1>"* noalias nocapture nonnull)

define void @neuron_predictor_fixpt_wrapper_hw_stub_wrapper(%"struct.ap_int<11>"* %x_in, i1 %reset_rsvd, i14* %residual, i14* %predicted) #4 {
entry:
  %0 = call i8* @malloc(i64 2)
  %1 = bitcast i8* %0 to %"struct.ap_ufixed<14, 1>"*
  %2 = call i8* @malloc(i64 2)
  %3 = bitcast i8* %2 to %"struct.ap_ufixed<14, 1>"*
  call void @copy_out(%"struct.ap_ufixed<14, 1>"* %1, i14* %residual, %"struct.ap_ufixed<14, 1>"* %3, i14* %predicted)
  call void @neuron_predictor_fixpt_wrapper_hw_stub(%"struct.ap_int<11>"* %x_in, i1 %reset_rsvd, %"struct.ap_ufixed<14, 1>"* %1, %"struct.ap_ufixed<14, 1>"* %3)
  call void @copy_in(%"struct.ap_ufixed<14, 1>"* %1, i14* %residual, %"struct.ap_ufixed<14, 1>"* %3, i14* %predicted)
  call void @free(i8* %0)
  call void @free(i8* %2)
  ret void
}

attributes #0 = { noinline willreturn "fpga.wrapper.func"="wrapper" }
attributes #1 = { argmemonly noinline norecurse willreturn "fpga.wrapper.func"="copyin" }
attributes #2 = { argmemonly noinline norecurse willreturn "fpga.wrapper.func"="copyout" }
attributes #3 = { argmemonly noinline norecurse willreturn "fpga.wrapper.func"="onebyonecpy_hls" }
attributes #4 = { "fpga.wrapper.func"="stub" }

!llvm.dbg.cu = !{}
!llvm.ident = !{!0, !0, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1}
!llvm.module.flags = !{!2, !3, !4}
!blackbox_cfg = !{!5}

!0 = !{!"AMD/Xilinx clang version 16.0.6"}
!1 = !{!"clang version 7.0.0 "}
!2 = !{i32 2, !"Dwarf Version", i32 4}
!3 = !{i32 2, !"Debug Info Version", i32 3}
!4 = !{i32 1, !"wchar_size", i32 4}
!5 = !{}
