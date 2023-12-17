#include "public.h"

int get_inputs(double datas[][inputs + outputs]) {
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
