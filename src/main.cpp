#include <stdio.h>
#include "neural.h"
#include "public.h"


int main() {
  int hiddens = hidden_layer_number;
  int layer_number = 2 + hiddens;
  neural_layer layers[layer_number];
  int number = INPUT;
  init_layer(layers, number);
  int i;
  int units = hidden_layer_unit_number;
  for (i=1;i<1+hiddens;i++){
    init_layer(layers+i, units);
  }
  init_layer(layers+i, 1);
  int row = 1 + INPUT;
  double datas[3000][row];
}
