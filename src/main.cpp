#include "io.h"
#include "neural.h"
#include "public.h"
#include <cmath>
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
  standard_inputs(datas);
  int j, k;
  for (k = 0; k < 30; k++) {
    double sum = 0;
    int n = 0;
    for (j = 0; j < train_size; j++) {
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
      double output_gradient = (output - target) * activation_deriv(output);
      output_layer->units->gradient = output_gradient;
      for (i = layer_number - 1; i >= 1; i--) {
        backward_propagation(layers + i, layers + i - 1);
      }
      for (i = 0; i < layer_number - 1; i++) {
        soviet_w(layers + i);
        soviet_b(layers + i);
      }
      n++;
      double L = loss(target, output);
      sum += L;
      printf("loss: %lf target: %lf output: %lf\n", L, target, output);
      if (n == 50) {
        printf("avg_loss: %lf \n\n", sum / n);
        n = 0;
        sum = 0;
      }
    }
  }
}
