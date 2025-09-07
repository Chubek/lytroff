#ifndef LIGATURE_H
#define LIGATURE_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "font.h"
#include "tyydecl.h"

#define LYT_LIGF_DISCRETIONARY (1U << 0)
#define LYT_LIGF_END_OF_WORD (1U << 1)
#define LYT_LIGF_REQUIRES_KERN (1U << 2)
#define LYT_LIGF_LEGACY_ONLY (1U << 3)
#define LYT_LIGF_MANDATORY (1U << 4)
#define LYT_LIGF_SYNTHETIC (1U << 5)

struct lytLigature
{
  char sequence[8];
  char32_t codepoint;

  const char *glyph_name;
  int glyph_id;

  double advance_x;
  double advance_y;

  lytFont *parent_font;
  unsigned flags;

  lytLigature *next;
};

struct lytLigatureList
{
  lytLigature *head;
  lytLigature *tail;
};

struct lytLigatureVector
{
  lytLigature **data;
  size_t capacity;
  size_t count;
};

#endif
