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
  int j = 0;
  datas[j][inputs] = sigmoid(datas[j][inputs]);
  process_input(layers, datas[j]);
  for (i = 0; i < layer_number - 1; i++) {
    forward_propagation(layers + i, layers + i + 1);
  }
  process_output_layer_w(layers + i - 1, &(layers + i)->units[0],
                         datas[j][inputs]);
  for (i = layer_number - 2; i >= 1; i--) {
    backward_propagation(layers + i, layers + i - 1, layers + i + 1);
  }
  for (i=0;i<layer_number-1;i++){
    for (j=0;j<50;j++){
      for (int k=0;k<50;k++){
        if ((layers+i)->t[j][k]!=0)
          printf("%d %d %d %lf \n",i,j,k,(layers+i)->t[j][k]);
      }
    }
    putchar('\n');
  }
}
