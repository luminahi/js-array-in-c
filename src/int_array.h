#ifndef _INT_ARRAY_H
#define _INT_ARRAY_H

#include <stdbool.h>

typedef struct IntArray {
  int* array;
  int length;
  int max_length;
  void (*for_each)(struct IntArray*, void (*)(int));
  struct IntArray* (*map)(struct IntArray*, int (*)(int));
  struct IntArray* (*filter)(struct IntArray*, bool (*)(int));
  char* (*join)(struct IntArray*, const char*);
  void (*fill)(struct IntArray*, int);
  int (*at)(struct IntArray*, int);
  void (*destroy)(struct IntArray*);

  int (*push)(struct IntArray*, int);
  int (*pop)(struct IntArray*);
} IntArray;

struct IntArray* new_int_array(int);

#endif
