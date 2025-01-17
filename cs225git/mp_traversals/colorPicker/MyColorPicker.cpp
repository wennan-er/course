#include "../cs225/HSLAPixel.h"
#include "../Point.h"

#include "ColorPicker.h"
#include "MyColorPicker.h"

using namespace cs225;

/**
 * Picks the color for pixel (x, y).
 * Using your own algorithm
 */
HSLAPixel MyColorPicker::getColor(unsigned x, unsigned y) {
  /* @todo [Part 3] */
  HSLAPixel pixel(hue, 0.8, 0.8);
  hue += increment;
  if (hue >= 360) { hue -= 360; }
  return pixel;
}

MyColorPicker::MyColorPicker(double increment)
  : hue(55), increment(increment) { }
