#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "int_array.h"

void print_int(int number) {
  printf("[%d] ", number);
}

int double_number(int number) {
  return number * 2;
} 

void random_fill(IntArray* arr, int min, int max) {
  srand(time(NULL));
  
  for (int i = 0; i < arr->length; i++) {
    arr->array[i] = (rand() % (max - min)) + min;
  }
}

int main(int argc, char* argv[]) {

  IntArray* arr = new_int_array(10);

  random_fill(arr, 1, 32);
  // arr->fill(arr, 10);

  arr->for_each(arr, &print_int);
  putchar('\n');

  arr->at(arr, 5);

  IntArray* mapped_array = arr->map(arr, &double_number);
  
  mapped_array->for_each(mapped_array, &print_int);
  putchar('\n');

  arr->destroy(arr);

  return 0;
}
