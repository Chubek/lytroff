#ifndef LYTROFF_H
#define LYTROFF_H

#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tyydecl.h"

struct lytDeviceProto
{
  const char *descpath;
  const char *fontpath;
  const char *devname;

  void (*dd_init_device) (const lytDeviceSpecs *desc);
  void (*dd_pause) (void);
  void (*dd_stop) (void);
  void (*dd_gen_trailer_info) (void);
  void (*dd_begin_page) (size_t pagenum);
  void (*dd_end_of_line) (size_t wsbefore, size_t wsafter);
  void (*dd_set_font) (int fontid, double size);
  void (*dd_set_fontsize) (int size);
  void (*dd_set_fontstyle) (lytFontStyle fs);
  void (*dd_set_line_thickness) (size_t thk);
  void (*dd_set_bgcolor) (lytColorScheme schm, const lytColor *color);
  void (*dd_set_fgcolor) (lytColorScheme schm, const lytColor *color);
  void (*dd_set_strokecolor) (lytColorScheme schm, const lytcolor *color);
  void (*dd_set_fillcolor) (lytColorScheme schm, const lytColor *color);
  void (*dd_draw_char) (const lytGlyph *glyph);
  void (*dd_print_namedchar) (const char *nm);
  void (*dd_print_idxchar) (size_t idx);
  void (*dd_print_word) (lytWord *word);
  void (*dd_print_kernword) (lytWord *word, size_t kern);
  void (*dd_goto_horizpos) (size_t pos, bool abs);
  void (*dd_goto_vertpos) (size_t pos, bool abs);
  void (*dd_move_and_print) (size_t motion, lytGlyph *glyph);
  void (*dd_draw_line) (double w, double h);
  void (*dd_draw_circle) (double d);
  void (*dd_draw_solid_circle) (double d);
  void (*dd_draw_arc) (double dh1, double dv1, double dh2, double dv2);
  void (*dd_draw_ellipse) (double dh1, double dv2);
  void (*dd_draw_spline) (size_t npairs, ...);
  void (*dd_draw_poly) (size_t npairs, ...);
  void (*dd_draw_solid_poly) (size_t npairs, ...);
  void (*dd_set_glyph_height) (size_t h);
  void (*dd_set_glyph_slant) (size_t s);
  void (*dd_set_glyph_underlined) (void);
  void (*dd_set_res) (size_t n, size_t h, size_t v);
  void (*dd_set_output_driver) (const char *nm);
  void (*dd_emit_escape) (const char *esc);
};

#endif
