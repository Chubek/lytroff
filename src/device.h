#ifndef LYTROFF_H
#define LYTROFF_H

#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tyydecl.h"

struct lytDeviceDesc
{
  lytFontFamily default_font_family;
  lytFontVector *mounted_founts;
  lytExtProgList *img_generator;
  lytExtProgList *preprocessors;
  lytExtProgList *postprocssors;
  lytExtProgList *printer;
  lytPaperSize *paper_size;

  bool pass_filenames;
  bool tcmd;
  bool unicode;
  bool unscaled_charwidths;
  bool use_charnm_in_special;

  size_t uniwidth;
  size_t resolution;
  size_t paper_length;
  size_t paper_width;
  size_t horiz_quantum;
  size_t vert_quantum;
  size_t size_scale;
};

struct lytDeviceFont
{
  const char *name;
  size_t space_width;
  size_t slant;
  bool specials;
  lytLigatureList *ligatures;
  lytDeviceFont *next;
};

struct lytDeviceFontList
{
  lytDeviceFont *head;
  lytDeviceFont *tail;
};

struct lytDeviceProto
{
  void (*dd_init_device) (void);
  void (*dd_pause) (void);
  void (*dd_stop) (void);
  void (*dd_gen_trailer_info) (void);
  void (*dd_begin_page) (size_t page_num);
  void (*dd_end_of_line) (size_t ws_before, size_t ws_after);
  void (*dd_set_font) (int id, double size, lytFontStyle style);
  void (*dd_set_line_thickness) (size_t thickness);
  void (*dd_set_bgcolor) (lytColorScheme schm, const lytColor *color);
  void (*dd_set_fgcolor) (lytColorScheme schm, const lytColor *color);
  void (*dd_set_stroke_color) (lytColorScheme schm, const lytcolor *color);
  void (*dd_set_fill_color) (lytColorScheme schm, const lytColor *color);
  void (*dd_draw_char) (const lytGlyph *glyph);
  void (*dd_print_named_char) (const char *name);
  void (*dd_print_indexed_char) (size_t idx);
  void (*dd_print_word) (lytWord *word);
  void (*dd_print_kern_word) (lytWord *word, size_t kern);
  void (*dd_goto_horiz_pos) (size_t pos, bool abs);
  void (*dd_goto_vert_pos) (size_t pos, bool abs);
  void (*dd_move_and_print) (size_t motion, lytGlyph *glyph);
  void (*dd_draw_line) (double w, double h);
  void (*dd_draw_circle) (double d, bool solid);
  void (*dd_draw_ellipse) (double dh1, double dv2, bool solid);
  void (*dd_draw_rule) (double w, double h, bool solid);
  void (*dd_draw_poly) (bool solid, size_t npairs, ...);
  void (*dd_draw_arc) (double dh1, double dv1, double dh2, double dv2);
  void (*dd_draw_spline) (size_t npairs, ...);
  void (*dd_set_glyph_height) (size_t h);
  void (*dd_set_glyph_slant) (size_t s);
  void (*dd_set_glyph_underlined) (void);
  void (*dd_set_res) (size_t n, size_t h, size_t v);
  void (*dd_emit_specials) (const char *spec);
  void (*dd_emit_escape) (const char *esc);
  void (*dd_embed_img) (const char *path, lytImageType type);
  void (*dd_embed_file) (const char *path);
};

struct lytDeviceCaps
{
  bool can_unicode;
  bool can_composite_glyphs;
  bool can_variable_sizes;
  bool can_slant;
  bool can_height_adjust;

  bool can_abs_pos;
  bool can_rel_pos;

  bool can_rules;
  bool can_lines;
  bool can_circles;
  bool can_solid_circles;
  bool can_ellipses;
  bool can_solid_ellipses;
  bool can_polygons;
  bool can_solid_polygons;
  bool can_arcs;
  bool can_splines;

  bool can_color;
  bool can_fill;
  bool can_pattern;
  bool can_alpha;

  bool can_embed_file;
  bool can_embed_image;

  bool can_specials;
  bool can_exec_escapes;
  bool can_page_size;
  bool can_url_links;

  double min_linewidth;
  double max_linewidth;
  double min_fontsize;
  double max_fontsize;
};

struct lytDeviceDriver
{
  lytDeviceDesc desc;
  lytDeviceFontList fonts;
  lytDeviceProto proto;
  lytDeviceCaps caps;
};

#endif
