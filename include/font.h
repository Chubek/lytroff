#ifndef FONT_H
#define FONT_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tyydecl.h"

#define MAX_FONT_NAME 8
#define MAX_FONT_FULL_NAME 64
#define MAX_FONT_SPECIAL_NAME 64

struct lytFont
{
  int mount_idx;

  char name[MAX_FONT_NAME + 1];
  char full_name[MAX_FONT_FULL_NAME + 1];
  char internal_name[MAX_FONT_SPECIAL_NAME + 1];

  enum
  {
    FONTFACE_Roman,
    FONTFACE_Italic,
    FONTFACE_Bold,
    FONTFACE_BoldItalic,
    FONTFACE_Symbol,
    FONTFACE_Custom,
  } face;

  bool special;
  bool color;

  double design_size;
  double space_width;
  double ascent;
  double descent;
  double em_width;
  double units_per_point;

  size_t max_ligature_len;

  lytGlyphVector *glyphs;
  lytLigatureVector *ligatures;
  lytUnicodeVector *unicode_to_gid;
  lytSpecialMapVector *special_map;

  lytDeviceDriver *device_ptr;

  bool reencodable;
  bool synthetic_metrics;

  lytFont *next;
};

struct lytFontList
{
  lytFont *head;
  lytFont *tail;
};

struct lytFontVector
{
  lytFont **data;
  size_t capacity;
  size_t count;
};

struct lytUnicodeVector
{
  char32_t *data;
  size_t capacity;
  size_t count;
};

#endif
