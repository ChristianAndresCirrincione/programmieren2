#include "Vector.h"

#include <stddef.h> // size_t
#include <stdio.h>  // printf
#include <stdlib.h> //malloc

// TODO: add required includes here

typedef struct Vector vector_t; //

void vector_init(struct Vector *self, size_t n, const T *init)
{
  // TODO
  if (!self) // prevent null pointer
    return;
  if (self->data) // check if vector is already initialized to prevent memory
                  // leak
    return;
  self->data = malloc(n * sizeof(T));
  self->size = n;
  for (int i = 0; i < n; i++)
  {
    self->data[i] = *init;
  }
}

void vector_free(struct Vector *self)
{
  // TODO
  if (!self)
    return;
  free(self->data);
  self->size = 0; // reset vector size
  self->data = NULL;
}

void vector_push_back(struct Vector *self, const T *value)
{
  T* data_temp =  realloc(self->data, (self->size+ 1)*sizeof(T) );
  if (!data_temp)
  {
    printf("Error!");
    return;
  }

}

void vector_pop_back(struct Vector *self)
{
  // TODO
}

void vector_push_front(struct Vector *self, const T *value)
{
  // TODO
}

void vector_pop_front(struct Vector *self)
{
  // TODO
}

void vector_insert_before(struct Vector *self, size_t n, const T *value)
{
  // TODO
}

void vector_erase(struct Vector *self, size_t n)
{
  // TODO
}

void vector_reverse(struct Vector *self)
{
  // TODO
}

void vector_print(const struct Vector *self)
{
  printf("Vector(size=%li, data=%p): ", self->size, (void *)self->data);
  for (size_t i = 0; i != self->size; ++i)
  {
    printf("%f ", self->data[i]);
  }
  printf("\n");
}

int main()
{
  vector_t*  vec = malloc(sizeof(vector_t));
  //vec->data = 0;
  T init = 2; 
  vector_init(vec, 10, &init);
  vector_print (vec);

  vector_free(vec);
}