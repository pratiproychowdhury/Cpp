#include<stdio.h>
#include<math.h>

// task: count leading zeros in different ways.

int test_vals[] = {0x0FFFFFFF, 1, 2, 3, 4, 5, 6, 7, 8, 16, 32, 64, 128, 256, 512, 1024, 2147483647, -1};

int* count_zeros(int* vals) {
  int size = 18;
  int* results = (int*) malloc (size * sizeof(int));
  int sznum = sizeof(int) * 8 -1;
  
  for (int a=0; a<size; a++) {
  
      while ((vals[a]) && (!(vals[a] & (1 << sznum)))) {
        results[a]++;
        vals[a] <<= 1;  
      }
  }
  
  return results;
}

int* count_zeros(int* vals) {
  int size = 18;
  int* results = (int*) malloc (size * sizeof(int));
  int sznum = sizeof(int) * 8 -1;
  
  for (int a=0; a<size; a++) {
    results[a] = __lzcnt(vals[a]); // visual studio intrinsic, uses BSF assembly instruction
  }
  
  return results;
}

int main() {
  
  int* res = count_zeros(test_vals);
  int size = 18;
  printf("Number of zeros: ");
  for (int a=0; a<size; a++) {
   printf("%i,", res[a]); 
  }
  free(res);
  return 0;
}

