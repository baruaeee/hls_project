; ModuleID = '/home/exotic/HLS_Thesis/Data_Compression_Decompression/codegen/split_quotient_remainder/hdlsrc/hls_component/hls_component/hls/.autopilot/db/a.g.ld.5.gdce.bc'
source_filename = "llvm-link"
target datalayout = "e-m:e-i64:64-i128:128-i256:256-i512:512-i1024:1024-i2048:2048-i4096:4096-n8:16:32:64-S128-v16:16-v24:32-v32:32-v48:64-v96:128-v192:256-v256:256-v512:512-v1024:1024"
target triple = "fpga64-xilinx-none"

%"struct.ap_uint<10>" = type { %"struct.ap_int_base<10, false>" }
%"struct.ap_int_base<10, false>" = type { %"struct.ssdm_int<10, false>" }
%"struct.ssdm_int<10, false>" = type { i10 }
%"struct.ap_uint<4>" = type { %"struct.ap_int_base<4, false>" }
%"struct.ap_int_base<4, false>" = type { %"struct.ssdm_int<4, false>" }
%"struct.ssdm_int<4, false>" = type { i4 }
%"struct.ap_uint<7>" = type { %"struct.ap_int_base<7, false>" }
%"struct.ap_int_base<7, false>" = type { %"struct.ssdm_int<7, false>" }
%"struct.ssdm_int<7, false>" = type { i7 }
%"struct.ap_uint<8>" = type { %"struct.ap_int_base<8, false>" }
%"struct.ap_int_base<8, false>" = type { %class.split_quotient_remainder_fixptClass }
%class.split_quotient_remainder_fixptClass = type { i8 }

; Function Attrs: argmemonly noinline willreturn
define void @apatb_split_quotient_remainder_fixpt_wrapper_ir(%"struct.ap_uint<10>"* nocapture readonly %u_in, %"struct.ap_uint<4>"* nocapture readonly %k_in, %"struct.ap_uint<7>"* noalias nocapture nonnull align 1 dereferenceable(1) %q_out, %"struct.ap_uint<8>"* noalias nocapture nonnull align 1 dereferenceable(1) %r_out) local_unnamed_addr #0 {
entry:
  %q_out_copy = alloca i7, align 512
  %r_out_copy = alloca i8, align 512
  call fastcc void @copy_in(%"struct.ap_uint<7>"* nonnull %q_out, i7* nonnull align 512 %q_out_copy, %"struct.ap_uint<8>"* nonnull %r_out, i8* nonnull align 512 %r_out_copy)
  call void @apatb_split_quotient_remainder_fixpt_wrapper_hw(%"struct.ap_uint<10>"* %u_in, %"struct.ap_uint<4>"* %k_in, i7* %q_out_copy, i8* %r_out_copy)
  call void @copy_back(%"struct.ap_uint<7>"* %q_out, i7* %q_out_copy, %"struct.ap_uint<8>"* %r_out, i8* %r_out_copy)
  ret void
}

; Function Attrs: argmemonly noinline norecurse willreturn
define internal fastcc void @copy_in(%"struct.ap_uint<7>"* noalias readonly "unpacked"="0", i7* noalias nocapture align 512 "unpacked"="1.0", %"struct.ap_uint<8>"* noalias readonly "unpacked"="2", i8* noalias nocapture align 512 "unpacked"="3.0") unnamed_addr #1 {
entry:
  call fastcc void @"onebyonecpy_hls.p0struct.ap_uint<7>.28"(i7* align 512 %1, %"struct.ap_uint<7>"* %0)
  call fastcc void @"onebyonecpy_hls.p0struct.ap_uint<8>"(i8* align 512 %3, %"struct.ap_uint<8>"* %2)
  ret void
}

; Function Attrs: argmemonly noinline norecurse willreturn
define internal fastcc void @"onebyonecpy_hls.p0struct.ap_uint<7>"(%"struct.ap_uint<7>"* noalias "unpacked"="0" %dst, i7* noalias nocapture readonly align 512 "unpacked"="1.0" %src) unnamed_addr #2 {
entry:
  %0 = icmp eq %"struct.ap_uint<7>"* %dst, null
  br i1 %0, label %ret, label %copy

copy:                                             ; preds = %entry
  %dst.0.0.04 = getelementptr %"struct.ap_uint<7>", %"struct.ap_uint<7>"* %dst, i64 0, i32 0, i32 0, i32 0
  %1 = bitcast i7* %src to i8*
  %2 = load i8, i8* %1
  %3 = trunc i8 %2 to i7
  store i7 %3, i7* %dst.0.0.04, align 1
  br label %ret

ret:                                              ; preds = %copy, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse willreturn
define internal fastcc void @"onebyonecpy_hls.p0struct.ap_uint<8>"(i8* noalias nocapture align 512 "unpacked"="0.0" %dst, %"struct.ap_uint<8>"* noalias readonly "unpacked"="1" %src) unnamed_addr #2 {
entry:
  %0 = icmp eq %"struct.ap_uint<8>"* %src, null
  br i1 %0, label %ret, label %copy

copy:                                             ; preds = %entry
  %src.0.0.03 = getelementptr %"struct.ap_uint<8>", %"struct.ap_uint<8>"* %src, i64 0, i32 0, i32 0, i32 0
  %1 = load i8, i8* %src.0.0.03, align 1
  store i8 %1, i8* %dst, align 512
  br label %ret

ret:                                              ; preds = %copy, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse willreturn
define internal fastcc void @copy_out(%"struct.ap_uint<7>"* noalias "unpacked"="0", i7* noalias nocapture readonly align 512 "unpacked"="1.0", %"struct.ap_uint<8>"* noalias "unpacked"="2", i8* noalias nocapture readonly align 512 "unpacked"="3.0") unnamed_addr #3 {
entry:
  call fastcc void @"onebyonecpy_hls.p0struct.ap_uint<7>"(%"struct.ap_uint<7>"* %0, i7* align 512 %1)
  call fastcc void @"onebyonecpy_hls.p0struct.ap_uint<8>.20"(%"struct.ap_uint<8>"* %2, i8* align 512 %3)
  ret void
}

; Function Attrs: argmemonly noinline norecurse willreturn
define internal fastcc void @"onebyonecpy_hls.p0struct.ap_uint<8>.20"(%"struct.ap_uint<8>"* noalias "unpacked"="0" %dst, i8* noalias nocapture readonly align 512 "unpacked"="1.0" %src) unnamed_addr #2 {
entry:
  %0 = icmp eq %"struct.ap_uint<8>"* %dst, null
  br i1 %0, label %ret, label %copy

copy:                                             ; preds = %entry
  %dst.0.0.04 = getelementptr %"struct.ap_uint<8>", %"struct.ap_uint<8>"* %dst, i64 0, i32 0, i32 0, i32 0
  %1 = load i8, i8* %src, align 512
  store i8 %1, i8* %dst.0.0.04, align 1
  br label %ret

ret:                                              ; preds = %copy, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse willreturn
define internal fastcc void @"onebyonecpy_hls.p0struct.ap_uint<7>.28"(i7* noalias nocapture align 512 "unpacked"="0.0" %dst, %"struct.ap_uint<7>"* noalias readonly "unpacked"="1" %src) unnamed_addr #2 {
entry:
  %0 = icmp eq %"struct.ap_uint<7>"* %src, null
  br i1 %0, label %ret, label %copy

copy:                                             ; preds = %entry
  %src.0.0.03 = getelementptr %"struct.ap_uint<7>", %"struct.ap_uint<7>"* %src, i64 0, i32 0, i32 0, i32 0
  %1 = bitcast i7* %src.0.0.03 to i8*
  %2 = load i8, i8* %1
  %3 = trunc i8 %2 to i7
  store i7 %3, i7* %dst, align 512
  br label %ret

ret:                                              ; preds = %copy, %entry
  ret void
}

declare i8* @malloc(i64)

declare void @free(i8*)

declare void @apatb_split_quotient_remainder_fixpt_wrapper_hw(%"struct.ap_uint<10>"* %u_in, %"struct.ap_uint<4>"* %k_in, i7* %q_out, i8* %r_out)

; Function Attrs: argmemonly noinline norecurse willreturn
define internal fastcc void @copy_back(%"struct.ap_uint<7>"* noalias "unpacked"="0", i7* noalias nocapture readonly align 512 "unpacked"="1.0", %"struct.ap_uint<8>"* noalias "unpacked"="2", i8* noalias nocapture readonly align 512 "unpacked"="3.0") unnamed_addr #3 {
entry:
  call fastcc void @"onebyonecpy_hls.p0struct.ap_uint<7>"(%"struct.ap_uint<7>"* %0, i7* align 512 %1)
  call fastcc void @"onebyonecpy_hls.p0struct.ap_uint<8>.20"(%"struct.ap_uint<8>"* %2, i8* align 512 %3)
  ret void
}

declare void @split_quotient_remainder_fixpt_wrapper_hw_stub(%"struct.ap_uint<10>"* nocapture readonly, %"struct.ap_uint<4>"* nocapture readonly, %"struct.ap_uint<7>"* noalias nocapture nonnull, %"struct.ap_uint<8>"* noalias nocapture nonnull)

define void @split_quotient_remainder_fixpt_wrapper_hw_stub_wrapper(%"struct.ap_uint<10>"* %u_in, %"struct.ap_uint<4>"* %k_in, i7* %q_out, i8* %r_out) #4 {
entry:
  %0 = call i8* @malloc(i64 1)
  %1 = bitcast i8* %0 to %"struct.ap_uint<7>"*
  %2 = call i8* @malloc(i64 1)
  %3 = bitcast i8* %2 to %"struct.ap_uint<8>"*
  call void @copy_out(%"struct.ap_uint<7>"* %1, i7* %q_out, %"struct.ap_uint<8>"* %3, i8* %r_out)
  call void @split_quotient_remainder_fixpt_wrapper_hw_stub(%"struct.ap_uint<10>"* %u_in, %"struct.ap_uint<4>"* %k_in, %"struct.ap_uint<7>"* %1, %"struct.ap_uint<8>"* %3)
  call void @copy_in(%"struct.ap_uint<7>"* %1, i7* %q_out, %"struct.ap_uint<8>"* %3, i8* %r_out)
  call void @free(i8* %0)
  call void @free(i8* %2)
  ret void
}

attributes #0 = { argmemonly noinline willreturn "fpga.wrapper.func"="wrapper" }
attributes #1 = { argmemonly noinline norecurse willreturn "fpga.wrapper.func"="copyin" }
attributes #2 = { argmemonly noinline norecurse willreturn "fpga.wrapper.func"="onebyonecpy_hls" }
attributes #3 = { argmemonly noinline norecurse willreturn "fpga.wrapper.func"="copyout" }
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
