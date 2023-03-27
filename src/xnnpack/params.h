// Copyright (c) Facebook, Inc. and its affiliates.
// All rights reserved.
//
// Copyright 2019 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include <xnnpack.h>
#include <xnnpack/common.h>
#include <xnnpack/microfnptr.h>
#include <xnnpack/microparams.h>
#include <xnnpack/config.h>

struct spmm_parameters {
  xnn_spmm_ukernel_fn ukernel;
  union {
    xnn_init_f16_minmax_params_fn f16;
    xnn_init_f32_minmax_params_fn f32;
  } init;
  // Number of M-dimension elements in a tile.
  // Corresponds to a block of pixels in 1x1 Convolution and a block of batch size in Fully Connected operator.
  uint8_t mr;
  // Number of N-dimension elements in a tile.
  // Corresponds to a block of output channels/features in 1x1 Convolution and Fully Connected operator.
  uint8_t nr;
};

struct conv_hwc2chw_parameters {
  xnn_conv_hwc2chw_ukernel_fn ukernel_with_symm_padding;
  union {
    xnn_init_f16_minmax_params_fn f16;
    xnn_init_f32_minmax_params_fn f32;
  } init;
  // Number of output channels in a tile.
  // This parameter must be passed as is to weight packing function.
  uint8_t output_channel_tile;
  // Number of output height pixels in a tile.
  // For best efficiency, micro-kernel must produce a multiple of this number of rows in each call.
  uint8_t output_height_tile;
  // Number of output width pixels in a tile.
  uint8_t output_width_tile;
};

struct dwconv2d_chw_parameters {
  xnn_dwconv2d_chw_ukernel_fn ukernel;
  union {
    xnn_init_f16_chw_params_fn f16;
    xnn_init_f32_chw_params_fn f32;
  } init;
  union {
    xnn_update_f16_chw_params_fn f16;
    xnn_update_f32_chw_params_fn f32;
  } update;
  // Number of output width pixels in a tile.
  uint8_t output_width_tile;
  // Number of output height pixels in a tile.
  // For best efficiency, micro-kernel must produce a multiple of this number of rows in each call.
  uint8_t output_height_tile;
};

struct argmaxpool_parameters {
  union {
    xnn_argmaxpool_unipass_ukernel_fn up;
    xnn_argmaxpool_multipass_ukernel_fn mp;
  };
  uint8_t mr;
  uint8_t qr;
};

struct maxpool_parameters {
  xnn_maxpool_ukernel_fn ukernel;
  union {
    xnn_init_s8_minmax_params_fn s8;
    xnn_init_u8_minmax_params_fn u8;
    xnn_init_f32_minmax_params_fn f32;
    xnn_init_f16_minmax_params_fn f16;
  } init;
  uint8_t mr;
  uint8_t qr;
};

struct zip_parameters {
  xnn_zipc_ukernel_fn x2;
  xnn_zipc_ukernel_fn x3;
  xnn_zipc_ukernel_fn x4;
  xnn_zipv_ukernel_fn xm;
};

struct raddstoreexpminusmax_parameters {
  xnn_raddstoreexpminusmax_ukernel_fn ukernel;
  union {
    xnn_init_f16_expminus_params_fn f16;
    xnn_init_f32_expminus_params_fn f32;
  } init;
  // Number of elements in a tile.
  // For best efficiency, micro-kernel must process a multiple of this number of elements in each call.
  uint8_t element_tile;
};

struct vmulcaddc_parameters {
  xnn_vmulcaddc_ukernel_fn ukernel;
  union {
    xnn_init_f16_minmax_params_fn f16;
    xnn_init_f32_minmax_params_fn f32;
  } init;
  uint8_t channel_tile;
  uint8_t row_tile;
};

#define XNN_MAX_F32_ARGMAXPOOL_UKERNELS 3

// Indicates that XNNPACK as a whole has initialized.
// This does not guarantee that any particular microkernels are available.
#define XNN_INIT_FLAG_XNNPACK    0x00000001
// Indicates that F32 XNNPACK microkernels are available for use.
#define XNN_INIT_FLAG_F32        0x00000002
// Indicates that X32 XNNPACK microkernels are available for use.
#define XNN_INIT_FLAG_X32        0x00000004
// Indicates that F16 XNNPACK microkernels are available for use.
#define XNN_INIT_FLAG_F16        0x00000008
// Indicates that F16 XNNPACK microkernels are natively supported by the hardware.
#define XNN_INIT_FLAG_F16_NATIVE 0x00000010
// Indicates that X16 XNNPACK microkernels are available for use.
#define XNN_INIT_FLAG_X16        0x00000020
// Indicates that QC8 XNNPACK microkernels are available for use.
#define XNN_INIT_FLAG_QC8        0x00000040
// Indicates that QS8 XNNPACK microkernels are available for use.
#define XNN_INIT_FLAG_QS8        0x00000080
// Indicates that QU8 XNNPACK microkernels are available for use.
#define XNN_INIT_FLAG_QU8        0x00000100
// Indicates that S8 XNNPACK microkernels are available for use.
#define XNN_INIT_FLAG_S8         0x00000200
// Indicates that U8 XNNPACK microkernels are available for use.
#define XNN_INIT_FLAG_U8         0x00000400
// Indicates that X8 XNNPACK microkernels are available for use.
#define XNN_INIT_FLAG_X8         0x00000800
// Indicates that VCVT XNNPACK microkernels are available for use.
#define XNN_INIT_FLAG_VCVT       0x00002000
// Indicates that CHW XNNPACK microkernels are optimized for the host platform.
#define XNN_INIT_FLAG_CHW_OPT    0x00004000
// Indicates that TRANSPOSE XNNPACK microkernels are available for use.
#define XNN_INIT_FLAG_TRANSPOSE  0x00008000

struct xnn_parameters {
  // Bitwise combination of XNN_INIT_FLAG_* flags
  uint32_t init_flags;
  struct xnn_allocator allocator;
  struct {
    struct maxpool_parameters maxpool;
  } s8;
  struct {
    struct maxpool_parameters maxpool;
    xnn_u8_lut32norm_ukernel_fn lut32norm;
    xnn_u8_rmax_ukernel_fn rmax;
  } u8;
  struct {
    struct zip_parameters zip;
  } x8;
  struct {
    struct maxpool_parameters maxpool;
    struct vmulcaddc_parameters vmulcaddc;
    struct raddstoreexpminusmax_parameters raddstoreexpminusmax;
    xnn_rmax_ukernel_fn rmax;
    // Sparse Matrix-Dense Matrix Multiplication (NR=1 block).
    struct spmm_parameters spmm;
    // Direct 3x3 stride-2 Convolution with 3 input channels and HWC->CHW layout conversion.
    struct conv_hwc2chw_parameters conv_hwc2chw_3x3c3s2;
    // Direct 3x3 stride-1 Convolution with padding 1 on left and right in CHW layout.
    struct dwconv2d_chw_parameters dwconv2d_chw_3x3;
    // Direct 3x3 stride-2 Convolution with padding 1 on left and right in CHW layout.
    struct dwconv2d_chw_parameters dwconv2d_chw_3x3s2;
    // Direct 5x5 stride-1 Convolution with padding 2 on left and right in CHW layout.
    struct dwconv2d_chw_parameters dwconv2d_chw_5x5;
    // Direct 5x5 stride-2 Convolution with padding 2 on left and right in CHW layout.
    struct dwconv2d_chw_parameters dwconv2d_chw_5x5s2;
  } f16;
  struct {
    struct maxpool_parameters maxpool;
    struct argmaxpool_parameters argmaxpool[XNN_MAX_F32_ARGMAXPOOL_UKERNELS];
    struct vmulcaddc_parameters vmulcaddc;
    struct raddstoreexpminusmax_parameters raddstoreexpminusmax;
    xnn_rmax_ukernel_fn rmax;
    // Sparse Matrix-Dense Matrix Multiplication (NR=1 block).
    struct spmm_parameters spmm;
    // Sparse Matrix-Dense Matrix Multiplication (NR=2 block).
    struct spmm_parameters spmm2;
    // Sparse Matrix-Dense Matrix Multiplication (NR=4 block).
    struct spmm_parameters spmm4;
    // Direct 3x3 stride-2 Convolution with 3 input channels and HWC->CHW layout conversion.
    struct conv_hwc2chw_parameters conv_hwc2chw_3x3c3s2;
    // Direct 3x3 stride-1 Convolution with padding 1 on left and right in CHW layout.
    struct dwconv2d_chw_parameters dwconv2d_chw_3x3;
    // Direct 3x3 stride-2 Convolution with padding 1 on left and right in CHW layout.
    struct dwconv2d_chw_parameters dwconv2d_chw_3x3s2;
    // Direct 5x5 stride-1 Convolution with padding 2 on left and right in CHW layout.
    struct dwconv2d_chw_parameters dwconv2d_chw_5x5;
    // Direct 5x5 stride-2 Convolution with padding 2 on left and right in CHW layout.
    struct dwconv2d_chw_parameters dwconv2d_chw_5x5s2;
  } f32;
  struct {
    xnn_unpool_ukernel_fn unpool;
    struct zip_parameters zip;
  } x32;
};

#ifdef __cplusplus
extern "C" XNN_INTERNAL struct xnn_parameters xnn_params;
#else
extern XNN_INTERNAL struct xnn_parameters xnn_params;
#endif
