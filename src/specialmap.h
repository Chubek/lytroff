#ifndef SPECIALMAP_H
#define SPECIALMAP_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tyydecl.h"

#define LYT_SPMF_SYNTHETIC (1U << 0)
#define LYT_SPMF_ALIAS (1U << 1)
#define LYT_SPMF_UNICODE_ONLY (1U << 2)
#define LYT_SPMF_LEGACY_ONLY (1U << 3)

#define MAX_SPECIALMAP_NAME 32

struct lytSpecialMap
{
  char name[MAX_SPECIALMAP_NAME + 1];
  char32_t codepoint;

  int glyph_id;
  const char *device_glyph_name;

  lytFont *parent_font;

  unsigned flags;

  lytSpecialMap *next;
};

struct lytSpecialMapList
{
  lytSpecialMap *head;
  lytSpecialMap *tail;
};

struct lytSpecialMapVector
{
  lytSpecialMap **data;
  size_t capacity;
  size_t count;
};

#endif
