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
  T *data_temp = realloc(self->data, (self->size + 1) * sizeof(T));
  if (!data_temp)
  {
    printf("Error!\n"); // check if self-data is NULL
    return;
  }
  self->data = data_temp;
  self->size += 1;
  self->data[self->size - 1] = *value;
}

void vector_pop_back(struct Vector *self)
{
  T *data_temp = realloc(self->data, (self->size - 1) * sizeof(T));
  if (!data_temp)
  {
    printf("Error!\n"); // check if self-data is NULL
    return;
  }
  self->size -= 1;
  self->data = data_temp;
}

void vector_push_front(struct Vector *self, const T *value)
{
  vector_insert_before(self, 0, value);
}

void vector_pop_front(struct Vector *self)
{

  vector_erase(self, 0);
}

void vector_insert_before(struct Vector *self, size_t n, const T *value)
{

  T *data_temp = realloc(self->data, (self->size + 1) * sizeof(T));
  if (!data_temp)
  {
    printf("Error!\n"); // check if self-data is NULL
    return;
  }
  self->data = data_temp;
  self->size += 1;
  for (int i = self->size - 1; i > n; i--)
  {
    self->data[i] = self->data[i - 1];
  }
  self->data[n] = *value;
}

void vector_erase(struct Vector *self, size_t n)
{
  for (int i = n; i < self->size - 1; i++)
  {
    self->data[i] = self->data[i + 1];
  }
  T *data_temp = realloc(self->data, (self->size - 1) * sizeof(T));
  if (!data_temp)
  {
    printf("Error!\n"); // check if self-data is NULL
    return;
  }
  self->data = data_temp;
  self->size -= 1;
}

void vector_reverse(struct Vector *self)
{
  T *data_temp = malloc(self->size *sizeof(T));
  if(!data_temp)
  return;

  for (int i = 0; i < self->size ; i++)
  {
    data_temp[i]= self->data[self->size-1-i];
  }
  free(self->data);
  self->data = data_temp;
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
  vector_t *vec = malloc(sizeof(vector_t));
  // vec->data = 0;
  T init = 2;
  vector_init(vec, 10, &init);
  vector_print(vec);

  vector_free(vec);
}