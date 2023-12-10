#ifndef NEURAL_H
#define NEURAL_H
#include "public.h"
#include <math.h>
#include "rand.h"

NE_TYPE calculate(NE_TYPE x,NE_TYPE w,NE_TYPE b);

NE_TYPE sigmoid(NE_TYPE x);

NE_TYPE fitting(NE_TYPE x);

typedef struct NE_LINE_IN {
  NE_TYPE ARR[NE_NUM*IN_NUM][2];
} NE_LINE_IN;

typedef struct NE_LINE_MID {
  NE_TYPE ARR[NE_NUM*NE_NUM][2];
} NE_LINE_MID;

typedef struct NE_LINE_OUT {
  NE_TYPE ARR[NE_NUM*OUT_NUM][2];
} NE_LINE_OUT;

#endif
