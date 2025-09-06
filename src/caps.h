#ifndef CAPS_H
#define CAPS_H

#include <stdbool.h>

#include "tyydecl.h"
#include "device.h"

static const lytDeviceCaps ps_caps = {
  .can_unicode = true,
  .can_composite_glyphs = true,
  .can_variable_sizes = true,
  .can_slant = true,
  .can_height_adjust = true,
  .can_abs_pos = true,
  .can_rel_pos = true,
  .can_rules = true,
  .can_lines = true,
  .can_circles = true,
  .can_solid_circles = true,
  .can_ellipses = true,
  .can_solid_ellipses = true,
  .can_polygons = true,
  .can_solid_polygons = true,
  .can_arcs = true,
  .can_splines = true,
  .can_color = true,
  .can_fill = true,
  .can_pattern = true,
  .can_alpha = false,
  .can_embed_file = false,
  .can_embed_image = true,
  .can_specials = true,
  .can_exec_escapes = true,
  .can_page_size = true,
  .can_url_links = false,
  .min_linewidth = 0.01,
  .max_linewidth = 1000.0,
  .min_fontsize = 1.0,
  .max_fontsize = 500.0,
};

static const struct lytDeviceCaps pdf_caps = {
  .can_unicode = true,
  .can_composite_glyphs = true,
  .can_variable_sizes = true,
  .can_slant = true,
  .can_height_adjust = true,
  .can_abs_pos = true,
  .can_rel_pos = true,
  .can_rules = true,
  .can_lines = true,
  .can_circles = true,
  .can_solid_circles = true,
  .can_ellipses = true,
  .can_solid_ellipses = true,
  .can_polygons = true,
  .can_solid_polygons = true,
  .can_arcs = true,
  .can_splines = true,
  .can_color = true,
  .can_fill = true,
  .can_pattern = true,
  .can_alpha = true,
  .can_embed_file = false,
  .can_embed_image = true,
  .can_specials = true,
  .can_exec_escapes = true,
  .can_page_size = true,
  .can_url_links = false,
  .min_linewidth = 0.01,
  .max_linewidth = 1000.0,
  .min_fontsize = 1.0,
  .max_fontsize = 500.0,
};

static const lytDeviceCaps dvi_caps = {
    .can_unicode = false,
    .can_variable_sizes = false,
    .can_slant = false,
    .can_height_adjust = false,
    .can_abs_positioning = true,
    .can_rel_positioning = true,
    .can_rules = true,
    .can_specials = true,
    .min_linewidth = 0.1,
    .max_linewidth = 100.0,
    .min_font_size = 1.0,
    .max_font_size = 72.0
};


#endif

