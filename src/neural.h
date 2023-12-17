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

double forward_propagation(neural_layer layer, neural_unit unit);
double sigmoid(double num);
neural_unit *init_unit(neural_unit *unit_p,int index);
neural_layer *init_layer(neural_layer *layer_p,int number);
double process_input(neural_layer* input_layer,double array[],int array_length);

double rand_gause();

#endif
