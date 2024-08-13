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

bool is_even(int number) {
  return number % 2 == 0 ? true : false;
}

int main(int argc, char* argv[]) {

  IntArray* arr = new_int_array(0);

  for (int i = 0; i < 500; i++) arr->push(arr, i);
  for (int i = 0; i < 500; i++) arr->pop(arr);

  printf("Current Size: %d\n", arr->length);
  printf("Max Size: %d\n", arr->max_length);

  arr->for_each(arr, &print_int);

  arr->destroy(arr);

  return 0;
}
