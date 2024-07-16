// Copyright 2022 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.
//
// Auto-generated file. Do not edit!
//   Specification: src/enums/operator-type.yaml
//   Generator: tools/generate-enum.py

#include <assert.h>
#include <stdint.h>

#include "xnnpack/operator-type.h"

static const uint16_t offset[167] = {
  0, 8, 22, 36, 50, 64, 78, 92, 119, 147, 175, 203, 230, 257, 289, 321, 364, 382, 400, 425, 451, 467, 483, 498, 513,
  535, 558, 581, 604, 627, 650, 673, 696, 719, 742, 760, 783, 806, 830, 848, 871, 895, 919, 943, 967, 1002, 1037, 1061,
  1085, 1109, 1123, 1138, 1153, 1173, 1199, 1225, 1262, 1288, 1318, 1344, 1376, 1408, 1434, 1461, 1488, 1505, 1522,
  1556, 1590, 1604, 1618, 1632, 1646, 1662, 1678, 1704, 1730, 1762, 1794, 1831, 1868, 1905, 1942, 1979, 2005, 2037,
  2063, 2078, 2112, 2146, 2180, 2214, 2248, 2282, 2312, 2342, 2362, 2382, 2403, 2424, 2445, 2466, 2480, 2504, 2528,
  2551, 2574, 2592, 2610, 2625, 2640, 2658, 2676, 2695, 2714, 2733, 2752, 2769, 2786, 2802, 2818, 2851, 2884, 2912,
  2940, 2968, 2996, 3023, 3050, 3067, 3084, 3125, 3166, 3184, 3202, 3220, 3238, 3253, 3269, 3285, 3303, 3321, 3339,
  3365, 3392, 3419, 3436, 3453, 3475, 3497, 3526, 3555, 3574, 3593, 3612, 3631, 3646, 3661, 3676, 3691, 3710, 3730,
  3750, 3770, 3791, 3812, 3834
};

static const char data[] =
  "Invalid\0"
  "Abs (NC, F16)\0"
  "Abs (NC, F32)\0"
  "Add (ND, F16)\0"
  "Add (ND, F32)\0"
  "Add (ND, QS8)\0"
  "Add (ND, QU8)\0"
  "ArgMax Pooling (NHWC, F32)\0"
  "Average Pooling (NHWC, F16)\0"
  "Average Pooling (NHWC, F32)\0"
  "Average Pooling (NHWC, QU8)\0"
  "Bankers Rounding (NC, F16)\0"
  "Bankers Rounding (NC, F32)\0"
  "Batch Matrix Multiply (NC, F16)\0"
  "Batch Matrix Multiply (NC, F32)\0"
  "Batch Matrix Multiply (NC, QD8, F32, QC8W)\0"
  "Ceiling (NC, F16)\0"
  "Ceiling (NC, F32)\0"
  "Channel Shuffle (NC, X8)\0"
  "Channel Shuffle (NC, X32)\0"
  "Clamp (NC, F16)\0"
  "Clamp (NC, F32)\0"
  "Clamp (NC, S8)\0"
  "Clamp (NC, U8)\0"
  "Constant Pad (ND, X8)\0"
  "Constant Pad (ND, X16)\0"
  "Constant Pad (ND, X32)\0"
  "Convert (NC, F16, F32)\0"
  "Convert (NC, F16, QD8)\0"
  "Convert (NC, F32, F16)\0"
  "Convert (NC, F32, QD8)\0"
  "Convert (NC, F32, QP8)\0"
  "Convert (NC, F32, QS8)\0"
  "Convert (NC, F32, QU8)\0"
  "Convert (NC, QS8)\0"
  "Convert (NC, QS8, F16)\0"
  "Convert (NC, QS8, F32)\0"
  "Convert (NC, QS16, QS8)\0"
  "Convert (NC, QU8)\0"
  "Convert (NC, QU8, F32)\0"
  "Convolution (NCHW, F16)\0"
  "Convolution (NCHW, F32)\0"
  "Convolution (NHWC, F16)\0"
  "Convolution (NHWC, F32)\0"
  "Convolution (NHWC, QD8, F16, QC8W)\0"
  "Convolution (NHWC, QD8, F32, QC8W)\0"
  "Convolution (NHWC, QC8)\0"
  "Convolution (NHWC, QS8)\0"
  "Convolution (NHWC, QU8)\0"
  "Copy (NC, X8)\0"
  "Copy (NC, X16)\0"
  "Copy (NC, X32)\0"
  "Copy Sign (NC, F32)\0"
  "Deconvolution (NHWC, F16)\0"
  "Deconvolution (NHWC, F32)\0"
  "Deconvolution (NHWC, QD8, F32, QC8W)\0"
  "Deconvolution (NHWC, QS8)\0"
  "Deconvolution (NC, QS8, QC8W)\0"
  "Deconvolution (NHWC, QU8)\0"
  "Depth To Space (NCHW2NHWC, X16)\0"
  "Depth To Space (NCHW2NHWC, X32)\0"
  "Depth To Space (NHWC, X8)\0"
  "Depth To Space (NHWC, X16)\0"
  "Depth To Space (NHWC, X32)\0"
  "Divide (ND, F16)\0"
  "Divide (ND, F32)\0"
  "Dynamic Fully Connected (NC, F16)\0"
  "Dynamic Fully Connected (NC, F32)\0"
  "ELU (NC, F16)\0"
  "ELU (NC, F32)\0"
  "ELU (NC, QS8)\0"
  "Exp (NC, F32)\0"
  "Floor (NC, F16)\0"
  "Floor (NC, F32)\0"
  "Fully Connected (NC, F16)\0"
  "Fully Connected (NC, F32)\0"
  "Fully Connected (NC, F32, QC4W)\0"
  "Fully Connected (NC, F32, QC8W)\0"
  "Fully Connected (NC, QD8, F16, QC8W)\0"
  "Fully Connected (NC, QD8, F16, QC4W)\0"
  "Fully Connected (NC, QD8, F32, QC4W)\0"
  "Fully Connected (NC, QD8, F32, QC8W)\0"
  "Fully Connected (NC, QP8, F32, QC4W)\0"
  "Fully Connected (NC, QS8)\0"
  "Fully Connected (NC, QS8, QC8W)\0"
  "Fully Connected (NC, QU8)\0"
  "GELU (NC, F32)\0"
  "Global Average Pooling (NCW, F16)\0"
  "Global Average Pooling (NCW, F32)\0"
  "Global Average Pooling (NWC, F16)\0"
  "Global Average Pooling (NWC, F32)\0"
  "Global Average Pooling (NWC, QS8)\0"
  "Global Average Pooling (NWC, QU8)\0"
  "Global Sum Pooling (NWC, F16)\0"
  "Global Sum Pooling (NWC, F32)\0"
  "HardSwish (NC, F16)\0"
  "HardSwish (NC, F32)\0"
  "Leaky ReLU (NC, F16)\0"
  "Leaky ReLU (NC, F32)\0"
  "Leaky ReLU (NC, QS8)\0"
  "Leaky ReLU (NC, QU8)\0"
  "Log (NC, F32)\0"
  "Max Pooling (NHWC, F16)\0"
  "Max Pooling (NHWC, F32)\0"
  "Max Pooling (NHWC, S8)\0"
  "Max Pooling (NHWC, U8)\0"
  "Maximum (ND, F16)\0"
  "Maximum (ND, F32)\0"
  "Mean (ND, F16)\0"
  "Mean (ND, F32)\0"
  "Minimum (ND, F16)\0"
  "Minimum (ND, F32)\0"
  "Multiply (ND, F16)\0"
  "Multiply (ND, F32)\0"
  "Multiply (ND, QS8)\0"
  "Multiply (ND, QU8)\0"
  "Negate (NC, F16)\0"
  "Negate (NC, F32)\0"
  "PReLU (NC, F16)\0"
  "PReLU (NC, F32)\0"
  "Reciprocal Square Root (NC, F16)\0"
  "Reciprocal Square Root (NC, F32)\0"
  "Resize Bilinear (NCHW, F16)\0"
  "Resize Bilinear (NCHW, F32)\0"
  "Resize Bilinear (NHWC, F16)\0"
  "Resize Bilinear (NHWC, F32)\0"
  "Resize Bilinear (NHWC, S8)\0"
  "Resize Bilinear (NHWC, U8)\0"
  "RoPE (NTHC, F16)\0"
  "RoPE (NTHC, F32)\0"
  "Scaled Dot-Product Attention (NHTC, F16)\0"
  "Scaled Dot-Product Attention (NHTC, F32)\0"
  "Sigmoid (NC, F16)\0"
  "Sigmoid (NC, F32)\0"
  "Sigmoid (NC, QS8)\0"
  "Sigmoid (NC, QU8)\0"
  "Slice (ND, X8)\0"
  "Slice (ND, X16)\0"
  "Slice (ND, X32)\0"
  "Softmax (NC, F16)\0"
  "Softmax (NC, F32)\0"
  "Softmax (NC, QU8)\0"
  "Space To Depth (NHWC, X8)\0"
  "Space To Depth (NHWC, X16)\0"
  "Space To Depth (NHWC, X32)\0"
  "Square (NC, F16)\0"
  "Square (NC, F32)\0"
  "Square Root (NC, F16)\0"
  "Square Root (NC, F32)\0"
  "Squared Difference (NC, F16)\0"
  "Squared Difference (NC, F32)\0"
  "Subtract (ND, F16)\0"
  "Subtract (ND, F32)\0"
  "Subtract (ND, QS8)\0"
  "Subtract (ND, QU8)\0"
  "Tanh (NC, F16)\0"
  "Tanh (NC, F32)\0"
  "Tanh (NC, QS8)\0"
  "Tanh (NC, QU8)\0"
  "Transpose (ND, X8)\0"
  "Transpose (ND, X16)\0"
  "Transpose (ND, X32)\0"
  "Transpose (ND, X64)\0"
  "Truncation (NC, F16)\0"
  "Truncation (NC, F32)\0"
  "Unpooling (NHWC, X32)\0"
  "Multiply (ND, S32)";

const char* xnn_operator_type_to_string(enum xnn_operator_type operator_type) {
  assert(operator_type >= xnn_operator_type_invalid);
  assert(operator_type <= xnn_operator_type_multiply_nd_s32);
  return &data[offset[operator_type]];
}
