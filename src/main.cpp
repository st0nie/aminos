#include "io.h"
#include "public.h"
#include "neural.h"

int main(){
  long double arr[LINE_SIZE][ARRANGE_SIZE]; 
  read_csv(arr);
  NE_LINE_IN weight_1;
  for (int i=0;i<NE_NUM*IN_NUM;i++){
    for (int j= 0 ;j<2;j++){
      weight_1.ARR[i][j] = rand_gauss();
    }
  }

  int count = 0;
  NE_TYPE x2[NE_NUM];
  for (int i = 0; i < NE_NUM; i++) {
    NE_TYPE sum = 0;
    for (int j = 0; j < IN_NUM; j++) {
      sum += calculate(arr[i][j], weight_1.ARR[count][0],weight_1.ARR[count][1]);
      count++;
    }
    x2[i] = fitting(sum);
  }

  NE_LINE_MID weight_2;
  
  for (int i=0;i<NE_NUM*NE_NUM;i++){
    for (int j= 0 ;j<2;j++){
      weight_2.ARR[i][j] = rand_gauss();
    }
  }

  count = 0;
  
  NE_TYPE x3[NE_NUM];
  for (int i = 0; i < NE_NUM; i++) {
    NE_TYPE sum = 0;
    for (int j = 0; j < NE_NUM; j++) {
      sum += calculate(arr[i][j], weight_2.ARR[count][0],weight_2.ARR[count][1]);
      count++;
    }
    x3[i] = fitting(sum);
  }

  NE_LINE_MID weight_3;
  
  for (int i=0;i<NE_NUM*NE_NUM;i++){
    for (int j= 0 ;j<2;j++){
      weight_3.ARR[i][j] = rand_gauss();
    }
  }

  count = 0;
  
  NE_TYPE x4[NE_NUM];
  for (int i = 0; i < NE_NUM; i++) {
    NE_TYPE sum = 0;
    for (int j = 0; j < NE_NUM; j++) {
      sum += calculate(arr[i][j], weight_3.ARR[count][0],weight_3.ARR[count][1]);
      count++;
    }
    x4[i] = fitting(sum);
  }


  NE_LINE_MID weight_4;
  
  for (int i=0;i<NE_NUM;i++){
    for (int j= 0 ;j<2;j++){
      weight_4.ARR[i][j] = rand_gauss();
    }
  }

  count = 0;
  
  NE_TYPE result;

  NE_TYPE sum = 0;
  for (int j = 0; j < NE_NUM; j++) {
    sum += calculate(arr[0][j], weight_4.ARR[count][0], weight_4.ARR[count][1]);
    count++;
  }
  result = fitting(sum);
}
