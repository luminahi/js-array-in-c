#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
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

IntArray* filter(IntArray* self, bool (*predicate)(int)) {
  int temp[self->length];
  int i = 0;
  int j = 0;
  
  while (i < self->length) {
    if (predicate(self->array[i])) {
      temp[j] = self->array[i];
      j++;
    }

    i++;
  }

  IntArray* filtered = new_int_array(j);
  for (int i = 0; i < j; i++) filtered->array[i] = temp[i];

  return filtered;
}

char* join(IntArray* self, const char* separator) {
  int separator_length = strlen(separator);
  
  char* string = (char*) malloc(sizeof(char) * self->length * separator_length * 10 + 1);  
  char number[separator_length + 10 + 1];
  string[0] = '\0';

  int i = 0;
  int string_length = 0;
  int number_length = 0;

  while (i < self->length) {
    number_length = sprintf(number, "%d", self->array[i]);
    string_length += number_length + separator_length;

    strcat(number, separator);
    strcat(string, number);

    i++;
  }
  
  string[string_length - separator_length] = '\0';
  return string;
}

void fill(IntArray* self, int value) {
  for (int i = 0; i < self->length; i++) 
    self->array[i] = value;
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
  arr->filter = &filter;
  arr->join = &join;
  arr->fill = &fill;
  arr->at = &at;
  arr->destroy = &destroy;

  return arr;
}
