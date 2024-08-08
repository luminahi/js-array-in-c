#include <stdlib.h>
#include <stdio.h>
#include "int_array.h"

void for_each(IntArray* self, void (*consumer)(int)) {
  if (!consumer) return;
  
  for (int i = 0; i < self->length; i++) {
    consumer(self->array[i]);
  }
}

IntArray* map(IntArray* self, int (*function)(int)) {
  IntArray* new = new_int_array(self->length);
  
  for (int i = 0; i < self->length; i++) {
    new->array[i] = function(self->array[i]);
  }

  return new;
}

void fill(IntArray* self, int value) {
  for (int i = 0; i < self->length; i++) self->array[i] = value;
}

int at(IntArray* self, int index) {
  return self->array[index];
}

void destroy(IntArray* self) {
  free(self->array);
  free(self);
}

IntArray* new_int_array(int size) {
  IntArray* arr = (IntArray*) malloc(sizeof(IntArray));

  arr->array = (int*) malloc(sizeof(int) * size); 
  arr->length = size;
  arr->for_each = &for_each;
  arr->map = &map;
  arr->fill = &fill;
  arr->at = &at;
  arr->destroy = &destroy;

  return arr;
}
