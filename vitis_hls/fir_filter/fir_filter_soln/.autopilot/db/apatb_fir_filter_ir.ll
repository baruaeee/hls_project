; ModuleID = '/home/ipad/HLS_Thesis/vitis_hls/fir_filter/fir_filter_soln/.autopilot/db/a.g.ld.5.gdce.bc'
source_filename = "llvm-link"
target datalayout = "e-m:e-i64:64-i128:128-i256:256-i512:512-i1024:1024-i2048:2048-i4096:4096-n8:16:32:64-S128-v16:16-v24:32-v32:32-v48:64-v96:128-v192:256-v256:256-v512:512-v1024:1024"
target triple = "fpga64-xilinx-none"

%"struct.ap_fixed<16, 8, AP_TRN, AP_WRAP, 0>" = type { %"struct.ap_fixed_base<16, 8, true, AP_TRN, AP_WRAP, 0>" }
%"struct.ap_fixed_base<16, 8, true, AP_TRN, AP_WRAP, 0>" = type { %"struct.ssdm_int<16, true>" }
%"struct.ssdm_int<16, true>" = type { i16 }

; Function Attrs: noinline
define void @apatb_fir_filter_ir(%"struct.ap_fixed<16, 8, AP_TRN, AP_WRAP, 0>"* noalias nocapture nonnull %y, %"struct.ap_fixed<16, 8, AP_TRN, AP_WRAP, 0>"* nocapture readonly %x, %"struct.ap_fixed<16, 8, AP_TRN, AP_WRAP, 0>"* noalias nocapture nonnull readonly "fpga.decayed.dim.hint"="4" "partition" %h) local_unnamed_addr #0 {
entry:
  %y_copy = alloca i16, align 512
  %h_copy_0 = alloca i16, align 512
  %h_copy_1 = alloca i16, align 512
  %h_copy_2 = alloca i16, align 512
  %h_copy_3 = alloca i16, align 512
  %0 = bitcast %"struct.ap_fixed<16, 8, AP_TRN, AP_WRAP, 0>"* %h to [4 x %"struct.ap_fixed<16, 8, AP_TRN, AP_WRAP, 0>"]*
  call void @copy_in(%"struct.ap_fixed<16, 8, AP_TRN, AP_WRAP, 0>"* nonnull %y, i16* nonnull align 512 %y_copy, [4 x %"struct.ap_fixed<16, 8, AP_TRN, AP_WRAP, 0>"]* nonnull %0, i16* nonnull align 512 %h_copy_0, i16* nonnull align 512 %h_copy_1, i16* nonnull align 512 %h_copy_2, i16* nonnull align 512 %h_copy_3)
  call void @apatb_fir_filter_hw(i16* %y_copy, %"struct.ap_fixed<16, 8, AP_TRN, AP_WRAP, 0>"* %x, i16* %h_copy_0, i16* %h_copy_1, i16* %h_copy_2, i16* %h_copy_3)
  call void @copy_back(%"struct.ap_fixed<16, 8, AP_TRN, AP_WRAP, 0>"* %y, i16* %y_copy, [4 x %"struct.ap_fixed<16, 8, AP_TRN, AP_WRAP, 0>"]* %0, i16* %h_copy_0, i16* %h_copy_1, i16* %h_copy_2, i16* %h_copy_3)
  ret void
}

; Function Attrs: argmemonly noinline norecurse
define internal fastcc void @"onebyonecpy_hls.p0struct.ap_fixed<16, 8, AP_TRN, AP_WRAP, 0>"(%"struct.ap_fixed<16, 8, AP_TRN, AP_WRAP, 0>"* noalias "unpacked"="0" %dst, i16* noalias nocapture readonly align 512 "unpacked"="1.0" %src) unnamed_addr #1 {
entry:
  %0 = icmp eq %"struct.ap_fixed<16, 8, AP_TRN, AP_WRAP, 0>"* %dst, null
  br i1 %0, label %ret, label %copy

copy:                                             ; preds = %entry
  %dst.0.0.04 = getelementptr %"struct.ap_fixed<16, 8, AP_TRN, AP_WRAP, 0>", %"struct.ap_fixed<16, 8, AP_TRN, AP_WRAP, 0>"* %dst, i64 0, i32 0, i32 0, i32 0
  %1 = load i16, i16* %src, align 512
  store i16 %1, i16* %dst.0.0.04, align 2
  br label %ret

ret:                                              ; preds = %copy, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse
define internal fastcc void @"onebyonecpy_hls.p0struct.ap_fixed<16, 8, AP_TRN, AP_WRAP, 0>.16"(i16* noalias nocapture align 512 "unpacked"="0.0" %dst, %"struct.ap_fixed<16, 8, AP_TRN, AP_WRAP, 0>"* noalias readonly "unpacked"="1" %src) unnamed_addr #1 {
entry:
  %0 = icmp eq %"struct.ap_fixed<16, 8, AP_TRN, AP_WRAP, 0>"* %src, null
  br i1 %0, label %ret, label %copy

copy:                                             ; preds = %entry
  %src.0.0.03 = getelementptr %"struct.ap_fixed<16, 8, AP_TRN, AP_WRAP, 0>", %"struct.ap_fixed<16, 8, AP_TRN, AP_WRAP, 0>"* %src, i64 0, i32 0, i32 0, i32 0
  %1 = load i16, i16* %src.0.0.03, align 2
  store i16 %1, i16* %dst, align 512
  br label %ret

ret:                                              ; preds = %copy, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse
define void @"arraycpy_hls.p0a4struct.ap_fixed<16, 8, AP_TRN, AP_WRAP, 0>"(i16* nocapture "orig.arg.no"="0" "unpacked"="0.0.0" %dst_0, i16* nocapture "orig.arg.no"="0" "unpacked"="0.0.1" %dst_1, i16* nocapture "orig.arg.no"="0" "unpacked"="0.0.2" %dst_2, i16* nocapture "orig.arg.no"="0" "unpacked"="0.0.3" %dst_3, [4 x %"struct.ap_fixed<16, 8, AP_TRN, AP_WRAP, 0>"]* readonly "orig.arg.no"="1" "unpacked"="1" %src, i64 "orig.arg.no"="2" "unpacked"="2" %num) #2 {
entry:
  %0 = icmp eq [4 x %"struct.ap_fixed<16, 8, AP_TRN, AP_WRAP, 0>"]* %src, null
  br i1 %0, label %ret, label %copy

copy:                                             ; preds = %entry
  %for.loop.cond1 = icmp sgt i64 %num, 0
  br i1 %for.loop.cond1, label %for.loop.lr.ph, label %copy.split

for.loop.lr.ph:                                   ; preds = %copy
  br label %for.loop

for.loop:                                         ; preds = %dst.addr.0.0.06.exit, %for.loop.lr.ph
  %for.loop.idx2 = phi i64 [ 0, %for.loop.lr.ph ], [ %for.loop.idx.next, %dst.addr.0.0.06.exit ]
  %1 = trunc i64 %for.loop.idx2 to i2
  %src.addr.0.0.05 = getelementptr [4 x %"struct.ap_fixed<16, 8, AP_TRN, AP_WRAP, 0>"], [4 x %"struct.ap_fixed<16, 8, AP_TRN, AP_WRAP, 0>"]* %src, i64 0, i64 %for.loop.idx2, i32 0, i32 0, i32 0
  %2 = load i16, i16* %src.addr.0.0.05, align 2
  switch i2 %1, label %dst.addr.0.0.06.case.3 [
    i2 0, label %dst.addr.0.0.06.case.0
    i2 1, label %dst.addr.0.0.06.case.1
    i2 -2, label %dst.addr.0.0.06.case.2
  ]

dst.addr.0.0.06.case.0:                           ; preds = %for.loop
  store i16 %2, i16* %dst_0, align 2
  br label %dst.addr.0.0.06.exit

dst.addr.0.0.06.case.1:                           ; preds = %for.loop
  store i16 %2, i16* %dst_1, align 2
  br label %dst.addr.0.0.06.exit

dst.addr.0.0.06.case.2:                           ; preds = %for.loop
  store i16 %2, i16* %dst_2, align 2
  br label %dst.addr.0.0.06.exit

dst.addr.0.0.06.case.3:                           ; preds = %for.loop
  store i16 %2, i16* %dst_3, align 2
  br label %dst.addr.0.0.06.exit

dst.addr.0.0.06.exit:                             ; preds = %dst.addr.0.0.06.case.3, %dst.addr.0.0.06.case.2, %dst.addr.0.0.06.case.1, %dst.addr.0.0.06.case.0
  %for.loop.idx.next = add nuw nsw i64 %for.loop.idx2, 1
  %exitcond = icmp ne i64 %for.loop.idx.next, %num
  br i1 %exitcond, label %for.loop, label %copy.split

copy.split:                                       ; preds = %dst.addr.0.0.06.exit, %copy
  br label %ret

ret:                                              ; preds = %copy.split, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse
define internal void @"onebyonecpy_hls.p0a4struct.ap_fixed<16, 8, AP_TRN, AP_WRAP, 0>"(i16* noalias nocapture align 512 "orig.arg.no"="0" "unpacked"="0.0.0" %dst_0, i16* noalias nocapture align 512 "orig.arg.no"="0" "unpacked"="0.0.1" %dst_1, i16* noalias nocapture align 512 "orig.arg.no"="0" "unpacked"="0.0.2" %dst_2, i16* noalias nocapture align 512 "orig.arg.no"="0" "unpacked"="0.0.3" %dst_3, [4 x %"struct.ap_fixed<16, 8, AP_TRN, AP_WRAP, 0>"]* noalias readonly "orig.arg.no"="1" "unpacked"="1" %src) #1 {
entry:
  %0 = icmp eq [4 x %"struct.ap_fixed<16, 8, AP_TRN, AP_WRAP, 0>"]* %src, null
  br i1 %0, label %ret, label %copy

copy:                                             ; preds = %entry
  call void @"arraycpy_hls.p0a4struct.ap_fixed<16, 8, AP_TRN, AP_WRAP, 0>"(i16* %dst_0, i16* %dst_1, i16* %dst_2, i16* %dst_3, [4 x %"struct.ap_fixed<16, 8, AP_TRN, AP_WRAP, 0>"]* nonnull %src, i64 4)
  br label %ret

ret:                                              ; preds = %copy, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse
define internal void @copy_in(%"struct.ap_fixed<16, 8, AP_TRN, AP_WRAP, 0>"* noalias readonly "orig.arg.no"="0" "unpacked"="0", i16* noalias nocapture align 512 "orig.arg.no"="1" "unpacked"="1.0", [4 x %"struct.ap_fixed<16, 8, AP_TRN, AP_WRAP, 0>"]* noalias readonly "orig.arg.no"="2" "unpacked"="2", i16* noalias nocapture align 512 "orig.arg.no"="3" "unpacked"="3.0.0" %_0, i16* noalias nocapture align 512 "orig.arg.no"="3" "unpacked"="3.0.1" %_1, i16* noalias nocapture align 512 "orig.arg.no"="3" "unpacked"="3.0.2" %_2, i16* noalias nocapture align 512 "orig.arg.no"="3" "unpacked"="3.0.3" %_3) #3 {
entry:
  call fastcc void @"onebyonecpy_hls.p0struct.ap_fixed<16, 8, AP_TRN, AP_WRAP, 0>.16"(i16* align 512 %1, %"struct.ap_fixed<16, 8, AP_TRN, AP_WRAP, 0>"* %0)
  call void @"onebyonecpy_hls.p0a4struct.ap_fixed<16, 8, AP_TRN, AP_WRAP, 0>"(i16* align 512 %_0, i16* align 512 %_1, i16* align 512 %_2, i16* align 512 %_3, [4 x %"struct.ap_fixed<16, 8, AP_TRN, AP_WRAP, 0>"]* %2)
  ret void
}

; Function Attrs: argmemonly noinline norecurse
define void @"arraycpy_hls.p0a4struct.ap_fixed<16, 8, AP_TRN, AP_WRAP, 0>.9"([4 x %"struct.ap_fixed<16, 8, AP_TRN, AP_WRAP, 0>"]* "orig.arg.no"="0" "unpacked"="0" %dst, i16* nocapture readonly "orig.arg.no"="1" "unpacked"="1.0.0" %src_0, i16* nocapture readonly "orig.arg.no"="1" "unpacked"="1.0.1" %src_1, i16* nocapture readonly "orig.arg.no"="1" "unpacked"="1.0.2" %src_2, i16* nocapture readonly "orig.arg.no"="1" "unpacked"="1.0.3" %src_3, i64 "orig.arg.no"="2" "unpacked"="2" %num) #2 {
entry:
  %0 = icmp eq [4 x %"struct.ap_fixed<16, 8, AP_TRN, AP_WRAP, 0>"]* %dst, null
  br i1 %0, label %ret, label %copy

copy:                                             ; preds = %entry
  %for.loop.cond1 = icmp sgt i64 %num, 0
  br i1 %for.loop.cond1, label %for.loop.lr.ph, label %copy.split

for.loop.lr.ph:                                   ; preds = %copy
  br label %for.loop

for.loop:                                         ; preds = %src.addr.0.0.05.exit, %for.loop.lr.ph
  %for.loop.idx2 = phi i64 [ 0, %for.loop.lr.ph ], [ %for.loop.idx.next, %src.addr.0.0.05.exit ]
  %1 = trunc i64 %for.loop.idx2 to i2
  %dst.addr.0.0.06 = getelementptr [4 x %"struct.ap_fixed<16, 8, AP_TRN, AP_WRAP, 0>"], [4 x %"struct.ap_fixed<16, 8, AP_TRN, AP_WRAP, 0>"]* %dst, i64 0, i64 %for.loop.idx2, i32 0, i32 0, i32 0
  switch i2 %1, label %src.addr.0.0.05.case.3 [
    i2 0, label %src.addr.0.0.05.case.0
    i2 1, label %src.addr.0.0.05.case.1
    i2 -2, label %src.addr.0.0.05.case.2
  ]

src.addr.0.0.05.case.0:                           ; preds = %for.loop
  %_0 = load i16, i16* %src_0, align 2
  br label %src.addr.0.0.05.exit

src.addr.0.0.05.case.1:                           ; preds = %for.loop
  %_1 = load i16, i16* %src_1, align 2
  br label %src.addr.0.0.05.exit

src.addr.0.0.05.case.2:                           ; preds = %for.loop
  %_2 = load i16, i16* %src_2, align 2
  br label %src.addr.0.0.05.exit

src.addr.0.0.05.case.3:                           ; preds = %for.loop
  %_3 = load i16, i16* %src_3, align 2
  br label %src.addr.0.0.05.exit

src.addr.0.0.05.exit:                             ; preds = %src.addr.0.0.05.case.3, %src.addr.0.0.05.case.2, %src.addr.0.0.05.case.1, %src.addr.0.0.05.case.0
  %2 = phi i16 [ %_0, %src.addr.0.0.05.case.0 ], [ %_1, %src.addr.0.0.05.case.1 ], [ %_2, %src.addr.0.0.05.case.2 ], [ %_3, %src.addr.0.0.05.case.3 ]
  store i16 %2, i16* %dst.addr.0.0.06, align 2
  %for.loop.idx.next = add nuw nsw i64 %for.loop.idx2, 1
  %exitcond = icmp ne i64 %for.loop.idx.next, %num
  br i1 %exitcond, label %for.loop, label %copy.split

copy.split:                                       ; preds = %src.addr.0.0.05.exit, %copy
  br label %ret

ret:                                              ; preds = %copy.split, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse
define internal void @"onebyonecpy_hls.p0a4struct.ap_fixed<16, 8, AP_TRN, AP_WRAP, 0>.6"([4 x %"struct.ap_fixed<16, 8, AP_TRN, AP_WRAP, 0>"]* noalias "orig.arg.no"="0" "unpacked"="0" %dst, i16* noalias nocapture readonly align 512 "orig.arg.no"="1" "unpacked"="1.0.0" %src_0, i16* noalias nocapture readonly align 512 "orig.arg.no"="1" "unpacked"="1.0.1" %src_1, i16* noalias nocapture readonly align 512 "orig.arg.no"="1" "unpacked"="1.0.2" %src_2, i16* noalias nocapture readonly align 512 "orig.arg.no"="1" "unpacked"="1.0.3" %src_3) #1 {
entry:
  %0 = icmp eq [4 x %"struct.ap_fixed<16, 8, AP_TRN, AP_WRAP, 0>"]* %dst, null
  br i1 %0, label %ret, label %copy

copy:                                             ; preds = %entry
  call void @"arraycpy_hls.p0a4struct.ap_fixed<16, 8, AP_TRN, AP_WRAP, 0>.9"([4 x %"struct.ap_fixed<16, 8, AP_TRN, AP_WRAP, 0>"]* nonnull %dst, i16* %src_0, i16* %src_1, i16* %src_2, i16* %src_3, i64 4)
  br label %ret

ret:                                              ; preds = %copy, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse
define internal void @copy_out(%"struct.ap_fixed<16, 8, AP_TRN, AP_WRAP, 0>"* noalias "orig.arg.no"="0" "unpacked"="0", i16* noalias nocapture readonly align 512 "orig.arg.no"="1" "unpacked"="1.0", [4 x %"struct.ap_fixed<16, 8, AP_TRN, AP_WRAP, 0>"]* noalias "orig.arg.no"="2" "unpacked"="2", i16* noalias nocapture readonly align 512 "orig.arg.no"="3" "unpacked"="3.0.0" %_0, i16* noalias nocapture readonly align 512 "orig.arg.no"="3" "unpacked"="3.0.1" %_1, i16* noalias nocapture readonly align 512 "orig.arg.no"="3" "unpacked"="3.0.2" %_2, i16* noalias nocapture readonly align 512 "orig.arg.no"="3" "unpacked"="3.0.3" %_3) #4 {
entry:
  call fastcc void @"onebyonecpy_hls.p0struct.ap_fixed<16, 8, AP_TRN, AP_WRAP, 0>"(%"struct.ap_fixed<16, 8, AP_TRN, AP_WRAP, 0>"* %0, i16* align 512 %1)
  call void @"onebyonecpy_hls.p0a4struct.ap_fixed<16, 8, AP_TRN, AP_WRAP, 0>.6"([4 x %"struct.ap_fixed<16, 8, AP_TRN, AP_WRAP, 0>"]* %2, i16* align 512 %_0, i16* align 512 %_1, i16* align 512 %_2, i16* align 512 %_3)
  ret void
}

declare void @apatb_fir_filter_hw(i16*, %"struct.ap_fixed<16, 8, AP_TRN, AP_WRAP, 0>"*, i16*, i16*, i16*, i16*)

; Function Attrs: argmemonly noinline norecurse
define internal void @copy_back(%"struct.ap_fixed<16, 8, AP_TRN, AP_WRAP, 0>"* noalias "orig.arg.no"="0" "unpacked"="0", i16* noalias nocapture readonly align 512 "orig.arg.no"="1" "unpacked"="1.0", [4 x %"struct.ap_fixed<16, 8, AP_TRN, AP_WRAP, 0>"]* noalias "orig.arg.no"="2" "unpacked"="2", i16* noalias nocapture readonly align 512 "orig.arg.no"="3" "unpacked"="3.0.0" %_0, i16* noalias nocapture readonly align 512 "orig.arg.no"="3" "unpacked"="3.0.1" %_1, i16* noalias nocapture readonly align 512 "orig.arg.no"="3" "unpacked"="3.0.2" %_2, i16* noalias nocapture readonly align 512 "orig.arg.no"="3" "unpacked"="3.0.3" %_3) #4 {
entry:
  call fastcc void @"onebyonecpy_hls.p0struct.ap_fixed<16, 8, AP_TRN, AP_WRAP, 0>"(%"struct.ap_fixed<16, 8, AP_TRN, AP_WRAP, 0>"* %0, i16* align 512 %1)
  ret void
}

define void @fir_filter_hw_stub_wrapper(i16*, %"struct.ap_fixed<16, 8, AP_TRN, AP_WRAP, 0>"*, i16*, i16*, i16*, i16*) #5 {
entry:
  %6 = alloca %"struct.ap_fixed<16, 8, AP_TRN, AP_WRAP, 0>"
  %7 = alloca [4 x %"struct.ap_fixed<16, 8, AP_TRN, AP_WRAP, 0>"]
  call void @copy_out(%"struct.ap_fixed<16, 8, AP_TRN, AP_WRAP, 0>"* %6, i16* %0, [4 x %"struct.ap_fixed<16, 8, AP_TRN, AP_WRAP, 0>"]* %7, i16* %2, i16* %3, i16* %4, i16* %5)
  %8 = bitcast [4 x %"struct.ap_fixed<16, 8, AP_TRN, AP_WRAP, 0>"]* %7 to %"struct.ap_fixed<16, 8, AP_TRN, AP_WRAP, 0>"*
  call void @fir_filter_hw_stub(%"struct.ap_fixed<16, 8, AP_TRN, AP_WRAP, 0>"* %6, %"struct.ap_fixed<16, 8, AP_TRN, AP_WRAP, 0>"* %1, %"struct.ap_fixed<16, 8, AP_TRN, AP_WRAP, 0>"* %8)
  call void @copy_in(%"struct.ap_fixed<16, 8, AP_TRN, AP_WRAP, 0>"* %6, i16* %0, [4 x %"struct.ap_fixed<16, 8, AP_TRN, AP_WRAP, 0>"]* %7, i16* %2, i16* %3, i16* %4, i16* %5)
  ret void
}

declare void @fir_filter_hw_stub(%"struct.ap_fixed<16, 8, AP_TRN, AP_WRAP, 0>"*, %"struct.ap_fixed<16, 8, AP_TRN, AP_WRAP, 0>"*, %"struct.ap_fixed<16, 8, AP_TRN, AP_WRAP, 0>"*)

attributes #0 = { noinline "fpga.wrapper.func"="wrapper" }
attributes #1 = { argmemonly noinline norecurse "fpga.wrapper.func"="onebyonecpy_hls" }
attributes #2 = { argmemonly noinline norecurse "fpga.wrapper.func"="arraycpy_hls" }
attributes #3 = { argmemonly noinline norecurse "fpga.wrapper.func"="copyin" }
attributes #4 = { argmemonly noinline norecurse "fpga.wrapper.func"="copyout" }
attributes #5 = { "fpga.wrapper.func"="stub" }

!llvm.dbg.cu = !{}
!llvm.ident = !{!0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0}
!llvm.module.flags = !{!1, !2, !3}
!blackbox_cfg = !{!4}
!datalayout.transforms.on.top = !{!5}

!0 = !{!"clang version 7.0.0 "}
!1 = !{i32 2, !"Dwarf Version", i32 4}
!2 = !{i32 2, !"Debug Info Version", i32 3}
!3 = !{i32 1, !"wchar_size", i32 4}
!4 = !{}
!5 = !{!6, !8, !10}
!6 = !{!7}
!7 = !{!"2.0", [4 x i16]* null}
!8 = !{!9}
!9 = !{!"array_partition", !"type=Complete", !"dim=1"}
!10 = !{!11, !12, !13, !14}
!11 = !{!"2.0.0", i16* null}
!12 = !{!"2.0.1", i16* null}
!13 = !{!"2.0.2", i16* null}
!14 = !{!"2.0.3", i16* null}
