#include "neural.h"

NE_TYPE sigmoid(NE_TYPE x){
  return 1/(1+exp(-x));
}

NE_TYPE fitting(NE_TYPE x){
  return sigmoid((x + rand_gauss())*rand_gauss());
}
