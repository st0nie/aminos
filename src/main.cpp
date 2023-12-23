#include "io.h"
#include "neural.h"
#include "public.h"
#include <cstring>
#include <stdio.h>

int main() {
  int layer_number = 2 + hidden_layer_number;
  neural_layer layers[layer_number];
  init_layer(layers, inputs);
  int i;
  for (i = 1; i < 1 + hidden_layer_number; i++) {
    init_layer(layers + i, hidden_layer_unit_number);
  }
  init_layer(layers + i, outputs);
  double datas[3000][outputs + inputs];
  get_inputs(datas);
  int j,k;
  for (j = 0; j < 2300; j++) {
    neural_layer *output_layer = layers + layer_number - 1;
    for (i = 0; i < layer_number - 1; i++) {
      reset_layer(layers + i);
    }
    process_input(layers, datas[j]);
    for (i = 0; i < layer_number - 1; i++) {
      forward_propagation(layers + i, layers + i + 1);
    }
    double target = datas[j][38];
    double output = output_layer->units->output;
    double output_gradient = (output - target) * sigmoid_deriv(output);
    output_layer->units->gradient = output_gradient;
    for (i = layer_number - 1; i >= 1; i--) {
      backward_propagation(layers + i, layers + i - 1);
    }
    for (i = 0; i < layer_number - 1; i++) {
      soviet_w(layers + i);
      soviet_b(layers + i);
    }
    printf("%lf %lf %lf\n",loss(target, output),target,output);
  }
}
