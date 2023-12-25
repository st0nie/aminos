#include "neural.h"
#include "public.h"
#include <chrono>
#include <math.h>
#include <random>
#include <stdio.h>

double activation(double num) { return atan(num); }

double activation_deriv(double num) { return 1.0 / (1 + pow(tan(num), 2)); }

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
    sum += layer->weight[i][unit->index] * layer->units[i].output;
  }
  sum += unit->bias;
  return (unit->output = activation(sum));
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
  for (j = 0; j < max_layer_unit_number; j++) {
    for (i = 0; i < max_layer_unit_number; i++) {
      layer_p->weight[i][j] = rand_gause();
    }
  }
  return layer_p;
}

neural_unit *init_unit(neural_unit *unit_p, int index) {
  unit_p->bias = rand_gause();
  unit_p->index = index;
  unit_p->output = 0;
  unit_p->gradient = 0;
  return unit_p;
}

double rand_gause() {
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
      printf("gradient: %lf\n", layer->units[i].gradient);
      putchar('\n');
    }
  } else {
    printf("layer not found\n");
  }
  return layer;
}

void soviet_w(neural_layer *layer) {
  int i, j;
  for (i = 0; i < max_layer_unit_number; i++) {
    for (j = 0; j < max_layer_unit_number; j++) {
      layer->weight[i][j] -= learning_rate * layer->delta_weight[i][j];
    }
  }
}
void soviet_b(neural_layer *layer) {
  int i;
  for (i = 0; i < layer->number; i++) {
    layer->units[i].bias -= learning_rate * layer->delta_bias[i];
  }
}

int reset_layer(neural_layer *layer) {
  int i, j;
  for (i = 0; i < max_layer_unit_number; i++) {
    for (j = 0; j < max_layer_unit_number; j++) {
      layer->delta_weight[i][j] = 0;
    }
  }
  for (i = 0; i < layer->number; i++) {
    layer->units[i].output = 0;
    layer->units[i].gradient = 0;
    layer->delta_bias[i] = 0;
  }
  return 0;
}

double loss(double target, double output) {
  return 0.5 * (output - target) * (output - target);
}

void backward_propagation(neural_layer *current, neural_layer *before) {
  int i, j;
  for (i = 0; i < before->number; i++) {
    for (j = 0; j < current->number; j++) {
      before->units[i].gradient += current->units[j].gradient *
                                   before->weight[i][j] *
                                   activation_deriv(before->units[i].output);
    }
  }
  for (i = 0; i < before->number; i++) {
    for (j = 0; j < current->number; j++) {
      before->delta_weight[i][j] +=
          current->units[j].gradient * before->units[i].output;
      before->delta_bias[i] += current->units[j].gradient;
    }
  }
}
