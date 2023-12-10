#ifndef NEURAL_H
#define NEURAL_H
#include "public.h"

static NE_TYPE calc(NE_TYPE x,NE_TYPE w,NE_TYPE b);

typedef struct NE_LINE_0 {
  NE_TYPE ARR[NE_NUM*IN_NUM][2];
} NE_LINE;

typedef struct NE_LINE_1 {
  NE_TYPE ARR[NE_NUM*NE_NUM][2];
} NE_LINE_1;

typedef struct NE_LINE_2 {
  NE_TYPE ARR[NE_NUM*OUT_NUM][2];
} NE_LINE_2;

#endif
