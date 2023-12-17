#include <stdio.h>
#include "neural.h"
#include "public.h"
#include "io.h"

int main() {
  int layer_number = 2 + hidden_layer_number;
  neural_layer layers[layer_number];
  init_layer(layers, inputs);
  int i;
  for (i=1;i<1+hidden_layer_number;i++){
    init_layer(layers+i, hidden_layer_unit_number);
  }
  init_layer(layers+i, 1);
  for (i=0;i<layer_number;i++){
    traverse_layer(layers+i);
  }
  double datas[3000][1+inputs];
  get_inputs(datas);
  for (i=0;i<2300;i++){
    int j;
    for (j=0;j<1+inputs;j++){
      printf("%lf ",datas[i][j]);
    }
    putchar('\n');
  }
}
