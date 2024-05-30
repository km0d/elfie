#ifndef _MAIN_H
#define _MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct arg {
  const char *name;
  void (*func)(elf_t *);
} arg_t;

#endif