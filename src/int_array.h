#ifndef _INT_ARRAY_H
#define _INT_ARRAY_H

typedef struct IntArray IntArray;

struct IntArray {
  int* array;
  int length;
  void (*for_each)(IntArray*, void (*)(int));
  IntArray* (*map)(IntArray*, int (*)(int));
  void (*fill)(IntArray*, int);
  int (*at)(IntArray*, int);
  void (*destroy)(IntArray*);
};

void for_each(IntArray*, void (*)(int));

IntArray* map(IntArray*, int (*)(int));

void fill(IntArray*, int);

int at(IntArray*, int);

void destroy(IntArray*);

IntArray* new_int_array(int);

#endif
