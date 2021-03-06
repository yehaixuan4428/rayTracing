/********************************************************
*
*  Author: Hx Ye - hxye@umich.edu
*
*  Create: 2020-05-29 12:43
*
*  Last modified: 2020-05-29 12:43
*
*  Filename: color.H
*
*  Description: 
*
********************************************************/
#ifndef COLOR_H
#define COLOR_H

#include "vec3.H"
#include <fstream>
#include <iostream>
#include "rtweekend.H"

void write_color(ostream& os, const color& pixel) {
    os << int(256*clip(pixel.x(), 0.0, 0.999)) << " "
       << int(256*clip(pixel.y(), 0.0, 0.999)) << " "
       << int(256*clip(pixel.z(), 0.0, 0.999)) << '\n';
}

void write_color_toFile(ofstream& os, const color& pixel) {
    os << int(256*clip(pixel.x(), 0.0, 0.999)) << " "
       << int(256*clip(pixel.y(), 0.0, 0.999)) << " "
       << int(256*clip(pixel.z(), 0.0, 0.999)) << '\n';
}

void write_color(ostream& os, const color& pixel, int nSamples) {
    os << int(256*clip(sqrt(pixel.x()/nSamples), 0.0, 0.999)) << " "
       << int(256*clip(sqrt(pixel.y()/nSamples), 0.0, 0.999)) << " "
       << int(256*clip(sqrt(pixel.z()/nSamples), 0.0, 0.999)) << '\n';
}

void write_color_toFile(ofstream& os, const color& pixel, int nSamples) {
    os << int(256*clip(sqrt(pixel.x()/nSamples), 0.0, 0.999)) << " "
       << int(256*clip(sqrt(pixel.y()/nSamples), 0.0, 0.999)) << " "
       << int(256*clip(sqrt(pixel.z()/nSamples), 0.0, 0.999)) << '\n';
}

#endif
