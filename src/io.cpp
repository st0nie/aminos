#include "public.h"

double **get_inputs(double datas[][inputs + 1]) {
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
    for (i = 0; i < 39; i++) {
      double test = atof(token);
      if (j - 1 >= 0)
        datas[j - 1][i] = test;
      token = strtok(NULL, ",");
    }
    j++;
  }
  int i;
  fclose(file);
  return 0;
}