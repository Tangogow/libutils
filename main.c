#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

void *xmalloc(unsigned int size){
  void *new_mem = (void *)malloc(size);

  if (new_mem == NULL) {
    fprintf(stderr, "fatal: memory exhausted (xmalloc of %u bytes).\n", size);
    exit(-1);
  }
  return new_mem;
}

void getTypeSize() {
  int i;
  char c;
  float f;
  double d;

  printf("int: %ld\n", sizeof(i));
  printf("char: %ld\n", sizeof(c));
  printf("float: %ld\n", sizeof(f));
  printf("double: %ld\n", sizeof(d));
}

int floatlen(float i) { /*without .00*/
  return floor(log10(abs(i))) + 1;
}

int intlen(int i) {
  return floor(log10(abs(i))) + 1;
}

char *itoa(int i) { /*need strcpy*/
  char *str = malloc(intlen(i) * sizeof(char));

  snprintf(str, sizeof(str), "%d", i);
  return str;
}

// atof atoi atol ltoa already exist
double itof(int i) {
  return (float)i;
}

double itod(int i) {
  return (double)i;
}
