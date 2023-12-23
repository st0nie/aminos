#ifndef NEURAL_H
#define NEURAL_H
#include "public.h"

typedef struct neural_unit {
  double bias;
  double output;
  double gradient;
  int index;
} neural_unit;

typedef struct neural_layer {
  neural_unit *units;
  int number;
  double weight[max_layer_unit_number][max_layer_unit_number];   // 权重
  double delta_weight[max_layer_unit_number][max_layer_unit_number]; // 梯度
  double delta_bias[max_layer_unit_number];                        // b的梯度
} neural_layer;

neural_layer *forward_propagation(neural_layer *layer,
                                  neural_layer *layer_next); // 向前传递
double forward_propagation_unit(neural_layer *layer,
                                neural_unit *unit); // 向前传递(单元)

neural_layer *
forward_propagation_output(neural_layer *layer,
                           neural_layer *layer_next); // 向前传递_output
double
forward_propagation_unit_output(neural_layer *layer,
                                neural_unit *unit); // 向前传递(单元)_output

double activation(double num);
neural_unit *init_unit(neural_unit *unit_p, int index); // 初始化神经元
neural_layer *init_layer(neural_layer *layer_p, int number); // 初始化层
neural_layer *process_input(neural_layer *input_layer,
                            double array[]); // 处理输入，给输入层用
neural_unit *
process_output_layer_w(neural_layer *previous_layer, neural_unit *output_unit,
                       double sample); // 处理最后一个层和输出层之间的w
neural_unit *
process_output_layer_b(neural_layer *previous_layer, neural_unit *output_unit,
                       double sample); // 处理最后一个层和输出层之间的b
void backward_propagation(neural_layer *current,
                          neural_layer *before);    // 反向传递_b
neural_layer *traverse_layer(neural_layer *layer); // 遍历层

double rand_gause(); // 高斯随机

void soviet_w(neural_layer *layer); // 修正w
void soviet_b(neural_layer *layer); // 修正b

int reset_layer(neural_layer *layer); // 清理层

double activation_deriv(double num); // relu 求导
double loss(double target,double output);
#endif
