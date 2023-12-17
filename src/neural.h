#ifndef NEURAL_H
#define NEURAL_H

typedef struct neural_unit {
  double bias;
  double output;
  int index;
} neural_unit;

typedef struct neural_layer {
  neural_unit* units;
  int number;
  double k[50][50];
} neural_layer;

double forward_propagation(neural_layer layer, neural_unit unit); //向前传递
double sigmoid(double num);
neural_unit *init_unit(neural_unit *unit_p,int index); //初始化神经元
neural_layer *init_layer(neural_layer *layer_p,int number); //初始化层
double process_input(neural_layer* input_layer,double array[],int array_length); //处理输入，给输入层用
neural_layer *traverse_layer(neural_layer* layer); //遍历层

double rand_gause(); //高斯随机

#endif
