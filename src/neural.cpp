#include "neural.h"
#include <chrono>
#include <math.h>
#include <random>
#include <stdio.h>

double sigmoid(double num) { return 1 / (1 + exp(-num)); }

neural_layer *forward_propagation(neural_layer *layer,
                                  neural_layer *layer_next) {
  int i;
  for (i = 0; i < layer_next->number; i++) {
    forward_propagation_unit(layer, &layer_next->units[i]);
  }
  return layer_next;
}

double forward_propagation_unit(neural_layer *layer, neural_unit *unit) {
  int i;
  double sum = 0;
  for (i = 0; i < layer->number; i++) {
    sum += layer->k[i][unit->index] * layer->units[i].output;
  }
  sum += unit->bias;
  return (unit->output = sigmoid(sum));
}

neural_layer *process_input(neural_layer *input_layer, double array[]) {
  int i;
  for (i = 0; i < input_layer->number; i++) {
    input_layer->units[i].output = array[i];
  }
  return input_layer;
}

neural_layer *init_layer(neural_layer *layer_p, int number) {
  layer_p->units = (neural_unit *)malloc(sizeof(neural_unit[number]));
  neural_unit *p = layer_p->units;
  int i;
  for (i = 0; i < number; i++) {
    init_unit(p, i);
    p++;
  }
  layer_p->number = number;
  int j;
  for (j = 0; j < 50; j++) {
    for (i = 0; i < 50; i++) {
      layer_p->k[i][j] = rand_gause();
    }
  }
  return layer_p;
}

neural_unit *init_unit(neural_unit *unit_p, int index) {
  unit_p->bias = rand_gause();
  unit_p->index = index;
  unit_p->output = 0;
  return unit_p;
}

double rand_gause() {
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::default_random_engine gen(seed);
  std::normal_distribution<double> distribution(0, 1);
  return distribution(gen);
}

neural_layer *traverse_layer(neural_layer *layer) {
  if (layer) {
    int i;
    printf("unit_numbers: %d\n", layer->number);
    putchar('\n');
    for (i = 0; i < layer->number; i++) {
      printf("unit: %d\n", layer->units[i].index);
      printf("bias: %lf\n", layer->units[i].bias);
      printf("output: %lf\n", layer->units[i].output);
      putchar('\n');
    }
  } else {
    printf("layer not found\n");
  }
  return layer;
}
