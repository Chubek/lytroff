#ifndef LYTCOLOR_H
#define LYTCOLOR_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tyydecl.h"

#define LYT_COLORF_DEFAULT (1U << 0)
#define LYT_COLORF_NAMED (1U << 1)
#define LYT_COLORF_DEVICE_DIRECT (1U << 2)
#define LYT_COLORF_CONVERTED (1U << 3)
#define LYT_COLORF_SYNTHETIC (1U << 4)
#define LYT_COLORF_HAS_ALPHA (1U << 5)
#define LYT_COLORF_SPOT (1U << 6)

#define MAX_COLOR_NAME 64
#define MAX_COLOR_COMP 4

struct lytColor
{
  enum lytColorSpace
  {
    LYT_COLORSPACE_DEVICEGRAY = 0,
    LYT_COLORSPACE_DEVICERGB,
    LYT_COLORSPACE_DEVICECMYK,
    LYT_COLORSPACE_CIELAB,
    LYT_COLORSPACE_CALRGB,
    LYT_COLORSPACE_ICCBASED,
    LYT_COLORSPACE_PATTERN,
    LYT_COLORSPACE_UNDEFINED,
    LYT_COLORSPACE_SIZE,
  } space;

  char name[MAX_COLOR_NAME + 1];

  double comp[MAX_COLOR_COMP];
  double alpha;

  lytDeviceCommand *device_cmd;
  lytDeviceDriver *owner_device;

  unsigned flags;

  struct lytColor *next;
};

#endif
