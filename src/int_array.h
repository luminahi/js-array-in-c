#ifndef _INT_ARRAY_H
#define _INT_ARRAY_H

#include <stdbool.h>

typedef struct IntArray IntArray;

struct IntArray {
  int* array;
  int length;
  void (*for_each)(IntArray*, void (*)(int));
  IntArray* (*map)(IntArray*, int (*)(int));
  IntArray* (*filter)(IntArray*, bool (*)(int));
  char* (*join)(IntArray*, const char*);
  void (*fill)(IntArray*, int);
  int (*at)(IntArray*, int);
  void (*destroy)(IntArray*);
};

IntArray* new_int_array(int);

#endif
