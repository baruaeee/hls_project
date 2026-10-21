; ModuleID = '/home/exotic/HLS_Thesis/Neuron/Vitis_HLS/neuron/hdlsrc/neuron/neuron/hls/.autopilot/db/a.g.ld.5.gdce.bc'
source_filename = "llvm-link"
target datalayout = "e-m:e-i64:64-i128:128-i256:256-i512:512-i1024:1024-i2048:2048-i4096:4096-n8:16:32:64-S128-v16:16-v24:32-v32:32-v48:64-v96:128-v192:256-v256:256-v512:512-v1024:1024"
target triple = "fpga64-xilinx-none"

%"struct.ap_uint<1>" = type { %"struct.ap_int_base<1, false>" }
%"struct.ap_int_base<1, false>" = type { %"struct.ssdm_int<1, false>" }
%"struct.ssdm_int<1, false>" = type { i1 }
%"struct.ap_fixed<14, 2>" = type { %"struct.ap_fixed_base<14, 2>" }
%"struct.ap_fixed_base<14, 2>" = type { %"struct.ssdm_int<14, true>" }
%"struct.ssdm_int<14, true>" = type { i14 }

; Function Attrs: inaccessiblemem_or_argmemonly noinline willreturn
define void @apatb_neuron_fixpt_wrapper_ir(%"struct.ap_fixed<14, 2>"* noalias nocapture nonnull readonly "fpga.decayed.dim.hint"="4" %x, %"struct.ap_fixed<14, 2>"* noalias nocapture nonnull readonly "fpga.decayed.dim.hint"="4" %w, %"struct.ap_uint<1>"* nocapture readonly %b, %"struct.ap_fixed<14, 2>"* noalias nocapture nonnull align 2 dereferenceable(2) %y) local_unnamed_addr #0 {
entry:
  %0 = bitcast %"struct.ap_fixed<14, 2>"* %x to [4 x %"struct.ap_fixed<14, 2>"]*
  %x_copy_0 = alloca i14, align 512
  %x_copy_1 = alloca i14, align 512
  %x_copy_2 = alloca i14, align 512
  %x_copy_3 = alloca i14, align 512
  %1 = bitcast %"struct.ap_fixed<14, 2>"* %w to [4 x %"struct.ap_fixed<14, 2>"]*
  %w_copy_0 = alloca i14, align 512
  %w_copy_1 = alloca i14, align 512
  %w_copy_2 = alloca i14, align 512
  %w_copy_3 = alloca i14, align 512
  %y_copy = alloca i14, align 512
  call void @copy_in([4 x %"struct.ap_fixed<14, 2>"]* nonnull %0, i14* nonnull align 512 %x_copy_0, i14* nonnull align 512 %x_copy_1, i14* nonnull align 512 %x_copy_2, i14* nonnull align 512 %x_copy_3, [4 x %"struct.ap_fixed<14, 2>"]* nonnull %1, i14* nonnull align 512 %w_copy_0, i14* nonnull align 512 %w_copy_1, i14* nonnull align 512 %w_copy_2, i14* nonnull align 512 %w_copy_3, %"struct.ap_fixed<14, 2>"* nonnull %y, i14* nonnull align 512 %y_copy)
  call void @apatb_neuron_fixpt_wrapper_hw(i14* %x_copy_0, i14* %x_copy_1, i14* %x_copy_2, i14* %x_copy_3, i14* %w_copy_0, i14* %w_copy_1, i14* %w_copy_2, i14* %w_copy_3, %"struct.ap_uint<1>"* %b, i14* %y_copy)
  call void @copy_back([4 x %"struct.ap_fixed<14, 2>"]* %0, i14* %x_copy_0, i14* %x_copy_1, i14* %x_copy_2, i14* %x_copy_3, [4 x %"struct.ap_fixed<14, 2>"]* %1, i14* %w_copy_0, i14* %w_copy_1, i14* %w_copy_2, i14* %w_copy_3, %"struct.ap_fixed<14, 2>"* %y, i14* %y_copy)
  ret void
}

; Function Attrs: argmemonly noinline norecurse willreturn
define internal fastcc void @"onebyonecpy_hls.p0struct.ap_fixed<14, 2>"(i14* noalias nocapture align 512 "unpacked"="0.0" %dst, %"struct.ap_fixed<14, 2>"* noalias readonly "unpacked"="1" %src) unnamed_addr #1 {
entry:
  %0 = icmp eq %"struct.ap_fixed<14, 2>"* %src, null
  br i1 %0, label %ret, label %copy

copy:                                             ; preds = %entry
  %src.0.0.03 = getelementptr %"struct.ap_fixed<14, 2>", %"struct.ap_fixed<14, 2>"* %src, i64 0, i32 0, i32 0, i32 0
  %1 = bitcast i14* %src.0.0.03 to i16*
  %2 = load i16, i16* %1
  %3 = trunc i16 %2 to i14
  store i14 %3, i14* %dst, align 512
  br label %ret

ret:                                              ; preds = %copy, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse willreturn
define internal fastcc void @"onebyonecpy_hls.p0struct.ap_fixed<14, 2>.5"(%"struct.ap_fixed<14, 2>"* noalias "unpacked"="0" %dst, i14* noalias nocapture readonly align 512 "unpacked"="1.0" %src) unnamed_addr #1 {
entry:
  %0 = icmp eq %"struct.ap_fixed<14, 2>"* %dst, null
  br i1 %0, label %ret, label %copy

copy:                                             ; preds = %entry
  %dst.0.0.04 = getelementptr %"struct.ap_fixed<14, 2>", %"struct.ap_fixed<14, 2>"* %dst, i64 0, i32 0, i32 0, i32 0
  %1 = bitcast i14* %src to i16*
  %2 = load i16, i16* %1
  %3 = trunc i16 %2 to i14
  store i14 %3, i14* %dst.0.0.04, align 2
  br label %ret

ret:                                              ; preds = %copy, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse willreturn
define void @"arraycpy_hls.p0a4struct.ap_fixed<14, 2>.16"(i14* nocapture "orig.arg.no"="0" "unpacked"="0.0.0" %dst_0, i14* nocapture "orig.arg.no"="0" "unpacked"="0.0.1" %dst_1, i14* nocapture "orig.arg.no"="0" "unpacked"="0.0.2" %dst_2, i14* nocapture "orig.arg.no"="0" "unpacked"="0.0.3" %dst_3, [4 x %"struct.ap_fixed<14, 2>"]* readonly "orig.arg.no"="1" "unpacked"="1" %src, i64 "orig.arg.no"="2" "unpacked"="2" %num) #2 {
entry:
  %0 = icmp eq [4 x %"struct.ap_fixed<14, 2>"]* %src, null
  br i1 %0, label %ret, label %copy

copy:                                             ; preds = %entry
  %for.loop.cond1 = icmp sgt i64 %num, 0
  br i1 %for.loop.cond1, label %for.loop.lr.ph, label %copy.split

for.loop.lr.ph:                                   ; preds = %copy
  br label %for.loop

for.loop:                                         ; preds = %dst.addr.0.0.06.exit, %for.loop.lr.ph
  %for.loop.idx2 = phi i64 [ 0, %for.loop.lr.ph ], [ %for.loop.idx.next, %dst.addr.0.0.06.exit ]
  %src.addr.0.0.05 = getelementptr [4 x %"struct.ap_fixed<14, 2>"], [4 x %"struct.ap_fixed<14, 2>"]* %src, i64 0, i64 %for.loop.idx2, i32 0, i32 0, i32 0
  %1 = bitcast i14* %src.addr.0.0.05 to i16*
  %2 = load i16, i16* %1
  %3 = trunc i16 %2 to i14
  switch i64 %for.loop.idx2, label %dst.addr.0.0.06.exit [
    i64 0, label %dst.addr.0.0.06.case.0
    i64 1, label %dst.addr.0.0.06.case.1
    i64 2, label %dst.addr.0.0.06.case.2
    i64 3, label %dst.addr.0.0.06.case.3
  ]

dst.addr.0.0.06.case.0:                           ; preds = %for.loop
  store i14 %3, i14* %dst_0, align 2
  br label %dst.addr.0.0.06.exit

dst.addr.0.0.06.case.1:                           ; preds = %for.loop
  store i14 %3, i14* %dst_1, align 2
  br label %dst.addr.0.0.06.exit

dst.addr.0.0.06.case.2:                           ; preds = %for.loop
  store i14 %3, i14* %dst_2, align 2
  br label %dst.addr.0.0.06.exit

dst.addr.0.0.06.case.3:                           ; preds = %for.loop
  store i14 %3, i14* %dst_3, align 2
  br label %dst.addr.0.0.06.exit

dst.addr.0.0.06.exit:                             ; preds = %dst.addr.0.0.06.case.3, %dst.addr.0.0.06.case.2, %dst.addr.0.0.06.case.1, %dst.addr.0.0.06.case.0, %for.loop
  %for.loop.idx.next = add nuw nsw i64 %for.loop.idx2, 1
  %exitcond = icmp ne i64 %for.loop.idx.next, %num
  br i1 %exitcond, label %for.loop, label %copy.split

copy.split:                                       ; preds = %dst.addr.0.0.06.exit, %copy
  br label %ret

ret:                                              ; preds = %copy.split, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse willreturn
define internal void @"onebyonecpy_hls.p0a4struct.ap_fixed<14, 2>"(i14* noalias nocapture align 512 "orig.arg.no"="0" "unpacked"="0.0.0" %dst_0, i14* noalias nocapture align 512 "orig.arg.no"="0" "unpacked"="0.0.1" %dst_1, i14* noalias nocapture align 512 "orig.arg.no"="0" "unpacked"="0.0.2" %dst_2, i14* noalias nocapture align 512 "orig.arg.no"="0" "unpacked"="0.0.3" %dst_3, [4 x %"struct.ap_fixed<14, 2>"]* noalias readonly "orig.arg.no"="1" "unpacked"="1" %src) #1 {
entry:
  %0 = icmp eq [4 x %"struct.ap_fixed<14, 2>"]* %src, null
  br i1 %0, label %ret, label %copy

copy:                                             ; preds = %entry
  call void @"arraycpy_hls.p0a4struct.ap_fixed<14, 2>.16"(i14* %dst_0, i14* %dst_1, i14* %dst_2, i14* %dst_3, [4 x %"struct.ap_fixed<14, 2>"]* nonnull %src, i64 4)
  br label %ret

ret:                                              ; preds = %copy, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse willreturn
define internal void @copy_in([4 x %"struct.ap_fixed<14, 2>"]* noalias readonly "orig.arg.no"="0" "unpacked"="0", i14* noalias nocapture align 512 "orig.arg.no"="1" "unpacked"="1.0.0" %_0, i14* noalias nocapture align 512 "orig.arg.no"="1" "unpacked"="1.0.1" %_1, i14* noalias nocapture align 512 "orig.arg.no"="1" "unpacked"="1.0.2" %_2, i14* noalias nocapture align 512 "orig.arg.no"="1" "unpacked"="1.0.3" %_3, [4 x %"struct.ap_fixed<14, 2>"]* noalias readonly "orig.arg.no"="2" "unpacked"="2", i14* noalias nocapture align 512 "orig.arg.no"="3" "unpacked"="3.0.0" %_01, i14* noalias nocapture align 512 "orig.arg.no"="3" "unpacked"="3.0.1" %_12, i14* noalias nocapture align 512 "orig.arg.no"="3" "unpacked"="3.0.2" %_23, i14* noalias nocapture align 512 "orig.arg.no"="3" "unpacked"="3.0.3" %_34, %"struct.ap_fixed<14, 2>"* noalias readonly "orig.arg.no"="4" "unpacked"="4", i14* noalias nocapture align 512 "orig.arg.no"="5" "unpacked"="5.0") #3 {
entry:
  call void @"onebyonecpy_hls.p0a4struct.ap_fixed<14, 2>"(i14* align 512 %_0, i14* align 512 %_1, i14* align 512 %_2, i14* align 512 %_3, [4 x %"struct.ap_fixed<14, 2>"]* %0)
  call void @"onebyonecpy_hls.p0a4struct.ap_fixed<14, 2>"(i14* align 512 %_01, i14* align 512 %_12, i14* align 512 %_23, i14* align 512 %_34, [4 x %"struct.ap_fixed<14, 2>"]* %1)
  call fastcc void @"onebyonecpy_hls.p0struct.ap_fixed<14, 2>"(i14* align 512 %3, %"struct.ap_fixed<14, 2>"* %2)
  ret void
}

; Function Attrs: argmemonly noinline norecurse willreturn
define void @"arraycpy_hls.p0a4struct.ap_fixed<14, 2>.23"([4 x %"struct.ap_fixed<14, 2>"]* "orig.arg.no"="0" "unpacked"="0" %dst, i14* nocapture readonly "orig.arg.no"="1" "unpacked"="1.0.0" %src_0, i14* nocapture readonly "orig.arg.no"="1" "unpacked"="1.0.1" %src_1, i14* nocapture readonly "orig.arg.no"="1" "unpacked"="1.0.2" %src_2, i14* nocapture readonly "orig.arg.no"="1" "unpacked"="1.0.3" %src_3, i64 "orig.arg.no"="2" "unpacked"="2" %num) #2 {
entry:
  %0 = icmp eq [4 x %"struct.ap_fixed<14, 2>"]* %dst, null
  br i1 %0, label %ret, label %copy

copy:                                             ; preds = %entry
  %for.loop.cond1 = icmp sgt i64 %num, 0
  br i1 %for.loop.cond1, label %for.loop.lr.ph, label %copy.split

for.loop.lr.ph:                                   ; preds = %copy
  br label %for.loop

for.loop:                                         ; preds = %src.addr.0.0.05.exit, %for.loop.lr.ph
  %for.loop.idx2 = phi i64 [ 0, %for.loop.lr.ph ], [ %for.loop.idx.next, %src.addr.0.0.05.exit ]
  %dst.addr.0.0.06 = getelementptr [4 x %"struct.ap_fixed<14, 2>"], [4 x %"struct.ap_fixed<14, 2>"]* %dst, i64 0, i64 %for.loop.idx2, i32 0, i32 0, i32 0
  switch i64 %for.loop.idx2, label %src.addr.0.0.05.exit [
    i64 0, label %src.addr.0.0.05.case.0
    i64 1, label %src.addr.0.0.05.case.1
    i64 2, label %src.addr.0.0.05.case.2
    i64 3, label %src.addr.0.0.05.case.3
  ]

src.addr.0.0.05.case.0:                           ; preds = %for.loop
  %1 = bitcast i14* %src_0 to i16*
  %2 = load i16, i16* %1
  %3 = trunc i16 %2 to i14
  br label %src.addr.0.0.05.exit

src.addr.0.0.05.case.1:                           ; preds = %for.loop
  %4 = bitcast i14* %src_1 to i16*
  %5 = load i16, i16* %4
  %6 = trunc i16 %5 to i14
  br label %src.addr.0.0.05.exit

src.addr.0.0.05.case.2:                           ; preds = %for.loop
  %7 = bitcast i14* %src_2 to i16*
  %8 = load i16, i16* %7
  %9 = trunc i16 %8 to i14
  br label %src.addr.0.0.05.exit

src.addr.0.0.05.case.3:                           ; preds = %for.loop
  %10 = bitcast i14* %src_3 to i16*
  %11 = load i16, i16* %10
  %12 = trunc i16 %11 to i14
  br label %src.addr.0.0.05.exit

src.addr.0.0.05.exit:                             ; preds = %src.addr.0.0.05.case.3, %src.addr.0.0.05.case.2, %src.addr.0.0.05.case.1, %src.addr.0.0.05.case.0, %for.loop
  %13 = phi i14 [ %3, %src.addr.0.0.05.case.0 ], [ %6, %src.addr.0.0.05.case.1 ], [ %9, %src.addr.0.0.05.case.2 ], [ %12, %src.addr.0.0.05.case.3 ], [ undef, %for.loop ]
  store i14 %13, i14* %dst.addr.0.0.06, align 2
  %for.loop.idx.next = add nuw nsw i64 %for.loop.idx2, 1
  %exitcond = icmp ne i64 %for.loop.idx.next, %num
  br i1 %exitcond, label %for.loop, label %copy.split

copy.split:                                       ; preds = %src.addr.0.0.05.exit, %copy
  br label %ret

ret:                                              ; preds = %copy.split, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse willreturn
define internal void @"onebyonecpy_hls.p0a4struct.ap_fixed<14, 2>.20"([4 x %"struct.ap_fixed<14, 2>"]* noalias "orig.arg.no"="0" "unpacked"="0" %dst, i14* noalias nocapture readonly align 512 "orig.arg.no"="1" "unpacked"="1.0.0" %src_0, i14* noalias nocapture readonly align 512 "orig.arg.no"="1" "unpacked"="1.0.1" %src_1, i14* noalias nocapture readonly align 512 "orig.arg.no"="1" "unpacked"="1.0.2" %src_2, i14* noalias nocapture readonly align 512 "orig.arg.no"="1" "unpacked"="1.0.3" %src_3) #1 {
entry:
  %0 = icmp eq [4 x %"struct.ap_fixed<14, 2>"]* %dst, null
  br i1 %0, label %ret, label %copy

copy:                                             ; preds = %entry
  call void @"arraycpy_hls.p0a4struct.ap_fixed<14, 2>.23"([4 x %"struct.ap_fixed<14, 2>"]* nonnull %dst, i14* %src_0, i14* %src_1, i14* %src_2, i14* %src_3, i64 4)
  br label %ret

ret:                                              ; preds = %copy, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse willreturn
define internal void @copy_out([4 x %"struct.ap_fixed<14, 2>"]* noalias "orig.arg.no"="0" "unpacked"="0", i14* noalias nocapture readonly align 512 "orig.arg.no"="1" "unpacked"="1.0.0" %_0, i14* noalias nocapture readonly align 512 "orig.arg.no"="1" "unpacked"="1.0.1" %_1, i14* noalias nocapture readonly align 512 "orig.arg.no"="1" "unpacked"="1.0.2" %_2, i14* noalias nocapture readonly align 512 "orig.arg.no"="1" "unpacked"="1.0.3" %_3, [4 x %"struct.ap_fixed<14, 2>"]* noalias "orig.arg.no"="2" "unpacked"="2", i14* noalias nocapture readonly align 512 "orig.arg.no"="3" "unpacked"="3.0.0" %_01, i14* noalias nocapture readonly align 512 "orig.arg.no"="3" "unpacked"="3.0.1" %_12, i14* noalias nocapture readonly align 512 "orig.arg.no"="3" "unpacked"="3.0.2" %_23, i14* noalias nocapture readonly align 512 "orig.arg.no"="3" "unpacked"="3.0.3" %_34, %"struct.ap_fixed<14, 2>"* noalias "orig.arg.no"="4" "unpacked"="4", i14* noalias nocapture readonly align 512 "orig.arg.no"="5" "unpacked"="5.0") #4 {
entry:
  call void @"onebyonecpy_hls.p0a4struct.ap_fixed<14, 2>.20"([4 x %"struct.ap_fixed<14, 2>"]* %0, i14* align 512 %_0, i14* align 512 %_1, i14* align 512 %_2, i14* align 512 %_3)
  call void @"onebyonecpy_hls.p0a4struct.ap_fixed<14, 2>.20"([4 x %"struct.ap_fixed<14, 2>"]* %1, i14* align 512 %_01, i14* align 512 %_12, i14* align 512 %_23, i14* align 512 %_34)
  call fastcc void @"onebyonecpy_hls.p0struct.ap_fixed<14, 2>.5"(%"struct.ap_fixed<14, 2>"* %2, i14* align 512 %3)
  ret void
}

declare i8* @malloc(i64)

declare void @free(i8*)

declare void @apatb_neuron_fixpt_wrapper_hw(i14* %x_0, i14* %x_1, i14* %x_2, i14* %x_3, i14* %w_0, i14* %w_1, i14* %w_2, i14* %w_3, %"struct.ap_uint<1>"* %b, i14* %y)

; Function Attrs: argmemonly noinline norecurse willreturn
define internal void @copy_back([4 x %"struct.ap_fixed<14, 2>"]* noalias "orig.arg.no"="0" "unpacked"="0", i14* noalias nocapture readonly align 512 "orig.arg.no"="1" "unpacked"="1.0.0" %_0, i14* noalias nocapture readonly align 512 "orig.arg.no"="1" "unpacked"="1.0.1" %_1, i14* noalias nocapture readonly align 512 "orig.arg.no"="1" "unpacked"="1.0.2" %_2, i14* noalias nocapture readonly align 512 "orig.arg.no"="1" "unpacked"="1.0.3" %_3, [4 x %"struct.ap_fixed<14, 2>"]* noalias "orig.arg.no"="2" "unpacked"="2", i14* noalias nocapture readonly align 512 "orig.arg.no"="3" "unpacked"="3.0.0" %_01, i14* noalias nocapture readonly align 512 "orig.arg.no"="3" "unpacked"="3.0.1" %_12, i14* noalias nocapture readonly align 512 "orig.arg.no"="3" "unpacked"="3.0.2" %_23, i14* noalias nocapture readonly align 512 "orig.arg.no"="3" "unpacked"="3.0.3" %_34, %"struct.ap_fixed<14, 2>"* noalias "orig.arg.no"="4" "unpacked"="4", i14* noalias nocapture readonly align 512 "orig.arg.no"="5" "unpacked"="5.0") #4 {
entry:
  call fastcc void @"onebyonecpy_hls.p0struct.ap_fixed<14, 2>.5"(%"struct.ap_fixed<14, 2>"* %2, i14* align 512 %3)
  ret void
}

declare void @neuron_fixpt_wrapper_hw_stub(%"struct.ap_fixed<14, 2>"* noalias nocapture nonnull readonly, %"struct.ap_fixed<14, 2>"* noalias nocapture nonnull readonly, %"struct.ap_uint<1>"* nocapture readonly, %"struct.ap_fixed<14, 2>"* noalias nocapture nonnull)

define void @neuron_fixpt_wrapper_hw_stub_wrapper(i14* %x_0, i14* %x_1, i14* %x_2, i14* %x_3, i14* %w_0, i14* %w_1, i14* %w_2, i14* %w_3, %"struct.ap_uint<1>"* %b, i14* %y) #5 {
entry:
  %0 = call i8* @malloc(i64 8)
  %1 = bitcast i8* %0 to [4 x %"struct.ap_fixed<14, 2>"]*
  %2 = call i8* @malloc(i64 8)
  %3 = bitcast i8* %2 to [4 x %"struct.ap_fixed<14, 2>"]*
  %4 = call i8* @malloc(i64 2)
  %5 = bitcast i8* %4 to %"struct.ap_fixed<14, 2>"*
  call void @copy_out([4 x %"struct.ap_fixed<14, 2>"]* %1, i14* %x_0, i14* %x_1, i14* %x_2, i14* %x_3, [4 x %"struct.ap_fixed<14, 2>"]* %3, i14* %w_0, i14* %w_1, i14* %w_2, i14* %w_3, %"struct.ap_fixed<14, 2>"* %5, i14* %y)
  %6 = bitcast [4 x %"struct.ap_fixed<14, 2>"]* %1 to %"struct.ap_fixed<14, 2>"*
  %7 = bitcast [4 x %"struct.ap_fixed<14, 2>"]* %3 to %"struct.ap_fixed<14, 2>"*
  call void @neuron_fixpt_wrapper_hw_stub(%"struct.ap_fixed<14, 2>"* %6, %"struct.ap_fixed<14, 2>"* %7, %"struct.ap_uint<1>"* %b, %"struct.ap_fixed<14, 2>"* %5)
  call void @copy_in([4 x %"struct.ap_fixed<14, 2>"]* %1, i14* %x_0, i14* %x_1, i14* %x_2, i14* %x_3, [4 x %"struct.ap_fixed<14, 2>"]* %3, i14* %w_0, i14* %w_1, i14* %w_2, i14* %w_3, %"struct.ap_fixed<14, 2>"* %5, i14* %y)
  call void @free(i8* %0)
  call void @free(i8* %2)
  call void @free(i8* %4)
  ret void
}

attributes #0 = { inaccessiblemem_or_argmemonly noinline willreturn "fpga.wrapper.func"="wrapper" }
attributes #1 = { argmemonly noinline norecurse willreturn "fpga.wrapper.func"="onebyonecpy_hls" }
attributes #2 = { argmemonly noinline norecurse willreturn "fpga.wrapper.func"="arraycpy_hls" }
attributes #3 = { argmemonly noinline norecurse willreturn "fpga.wrapper.func"="copyin" }
attributes #4 = { argmemonly noinline norecurse willreturn "fpga.wrapper.func"="copyout" }
attributes #5 = { "fpga.wrapper.func"="stub" }

!llvm.dbg.cu = !{}
!llvm.ident = !{!0, !0, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1, !1}
!llvm.module.flags = !{!2, !3, !4}
!blackbox_cfg = !{!5}
!datalayout.transforms.on.top = !{!6, !16}

!0 = !{!"AMD/Xilinx clang version 16.0.6"}
!1 = !{!"clang version 7.0.0 "}
!2 = !{i32 2, !"Dwarf Version", i32 4}
!3 = !{i32 2, !"Debug Info Version", i32 3}
!4 = !{i32 1, !"wchar_size", i32 4}
!5 = !{}
!6 = !{!7, !9, !11}
!7 = !{!8}
!8 = !{!"0.0", [4 x i14]* null}
!9 = !{!10}
!10 = !{!"array_partition", !"type=Complete", !"dim=1"}
!11 = !{!12, !13, !14, !15}
!12 = !{!"0.0.0", i14* null}
!13 = !{!"0.0.1", i14* null}
!14 = !{!"0.0.2", i14* null}
!15 = !{!"0.0.3", i14* null}
!16 = !{!17, !9, !19}
!17 = !{!18}
!18 = !{!"1.0", [4 x i14]* null}
!19 = !{!20, !21, !22, !23}
!20 = !{!"1.0.0", i14* null}
!21 = !{!"1.0.1", i14* null}
!22 = !{!"1.0.2", i14* null}
!23 = !{!"1.0.3", i14* null}
