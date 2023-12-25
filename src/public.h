#ifndef PUBLIC_H
#define PUBLIC_H
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int hidden_layer_number = 2; //隐藏层的个数
const int hidden_layer_unit_number = 19; //隐藏层的元素个数
const int epoch = 75; //迭代次数
const double learning_rate = exp(-5); //学习率
const int inputs = 38; //输入层的元素个数
const int outputs = 1; //输出层的元素个数
const int train_size = 2310; //训练集大小
const int seed = 2310; //随机数种子
const int max_layer_unit_number = 50;

#endif
