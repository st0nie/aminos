#ifndef NEURAL_H
#define NEURAL_H
#include "public.h"

typedef struct neural_unit {
  double bias;
  double output;
  int index;
} neural_unit;

typedef struct neural_layer {
  neural_unit* units;
  int number;
  double k[max_layer_unit_number][max_layer_unit_number];
} neural_layer;

neural_layer *forward_propagation(neural_layer* layer, neural_layer *layer_next); //向前传递
double forward_propagation_unit(neural_layer* layer, neural_unit* unit); //向前传递(单元)
double sigmoid(double num);
neural_unit *init_unit(neural_unit *unit_p,int index); //初始化神经元
neural_layer *init_layer(neural_layer *layer_p,int number); //初始化层
neural_layer *process_input(neural_layer* input_layer,double array[]); //处理输入，给输入层用
neural_layer *traverse_layer(neural_layer* layer); //遍历层

double rand_gause(); //高斯随机

#endif
