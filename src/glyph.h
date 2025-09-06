#ifndef GLYPH_H
#define GLYPH_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <uchar.h>

#include "font.h"
#include "tyydecl.h"

struct lytGlyph
{
  char32_t codepoint;
  const char *name;
  int font_id;
  double point_size;
  double slant;
  double height;

  double width;
  double ascent;
  double descent;
  double bbox_xmin;
  double bbox_ymin;
  double bbox_xmax;
  double bbox_ymax;

  double pos_x;
  double pos_y;
  double advance_x;
  double advance_y;
  
  bool underline;
  bool overstrike;
  bool faux_bold;
  bool visible;
  bool broken;

  lytFont *parent_font;
  lytGlyph *next;
};

struct lytGlyphVector
{
  lytGlyph *data;
  size_t capacity;
  size_t count;
};

#endif
