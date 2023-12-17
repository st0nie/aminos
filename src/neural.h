#ifndef NEURAL_H
#define NEURAL_H
#include "public.h"

typedef struct neural_unit {
  double bias;
  double output;
  int index;
} neural_unit;

typedef struct neural_layer {
  neural_unit *units;
  int number;
  double w[max_layer_unit_number][max_layer_unit_number]; // 权重
  double t[max_layer_unit_number][max_layer_unit_number]; // 梯度
} neural_layer;

neural_layer *forward_propagation(neural_layer *layer,
                                  neural_layer *layer_next); // 向前传递
double forward_propagation_unit(neural_layer *layer,
                                neural_unit *unit); // 向前传递(单元)

void backward_propagation(neural_layer *current, neural_layer *before,
                          neural_layer *after); // 反向传递
double sigmoid(double num);
neural_unit *init_unit(neural_unit *unit_p, int index); // 初始化神经元
neural_layer *init_layer(neural_layer *layer_p, int number); // 初始化层
neural_layer *process_input(neural_layer *input_layer,
                            double array[]); // 处理输入，给输入层用
neural_unit *
process_output_layer_w(neural_layer *previous_layer, neural_unit *output_unit,
                       double sample); // 处理最后一个层和输出层之间的w
neural_layer *traverse_layer(neural_layer *layer); // 遍历层

double rand_gause(); // 高斯随机

#endif
