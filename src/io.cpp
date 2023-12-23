#include "public.h"

int get_inputs(double datas[train_size][inputs + outputs]) {
  FILE *file = fopen("zhengqi_train.csv", "r");
  if (file == NULL) {
    printf("Error opening file\n");
    exit(1);
  }
  int j = 0, n;
  char line[1000];
  while (fgets(line, sizeof(line), file)) {
    char *token = strtok(line, ",");

    int i;
    for (i = 0; i < inputs + outputs; i++) {
      double token_double = atof(token);
      if (j - 1 >= 0)
        datas[j - 1][i] = token_double;
      token = strtok(NULL, ",");
    }
    j++;
  }
  fclose(file);
  return 0;
}
int standard_inputs(double datas[train_size][inputs + outputs]) {
  int i, j;
  for (j = 0; j < inputs + outputs; j++) {
    double sum = 0;
    for (i = 0; i < train_size; i++) {
      sum += datas[i][j];
    }
    double mean = sum / train_size;
    double variance = 0;
    for (i = 0; i < train_size; i++) {
      variance += pow(datas[i][j] - mean, 2);
    }
    double std = sqrt(variance / train_size);
    for (i = 0; i < train_size; i++) {
      datas[i][j] = (datas[i][j] - mean) / std;
    }
  }
  return 0;
}
