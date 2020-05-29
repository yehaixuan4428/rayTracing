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

void write_color(ostream& os, const color& pixel) {
    os << int(255.999*pixel.x()) << " "
       << int(255.999*pixel.y()) << " "
       << int(255.999*pixel.z()) << '\n';
}

void write_color_toFile(ofstream& os, const color& pixel) {
    os << int(255.999*pixel.x()) << " "
       << int(255.999*pixel.y()) << " "
       << int(255.999*pixel.z()) << '\n';
}

#endif
