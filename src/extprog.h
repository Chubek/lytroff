#ifndef EXTPROG_H
#define EXTPROG_H

#define POSIX_C_SOURCE
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LYT_EXTPROG_PREPROCESSOR (1U << 0)
#define LYT_EXTPROG_POSTPROCESSOR (1U << 1)
#define LYT_EXTPROG_SHELL (1U << 2)
#define LYT_EXTPROG_FILTER (1U << 3)
#define LYT_EXTPROG_IMAGEGEN (1U << 4)
#define LYT_EXTPROG_REQUIRED (1U << 5)
#define LYT_EXTPROG_OPTIONAL (1U << 6)
#define LYT_EXTPROG_INTERNAL (1U << 7)

#define MAX_EXTPROG_NAME 32
#define MAX_EXTPROG_PATH MAX_PATH

struct lytExtProg
{
  char name[MAX_EXTPROG_NAME + 1];
  char path[MAX_EXTPROG_PATH + 1];
  char **argv;
  char **envp;
  unsigned flags;
  bool available;
  unsigned timeout_sec;
  int last_status;
  void *owner;
  lytExtProg *next;
};

struct lytExtProgList
{
  lytExtProg *head;
  lytExtProg *tail;
};

#endif
