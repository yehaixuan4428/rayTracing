#ifndef METAL_H
#define METAL_H

#include "material.H"

class metal: public material {
 public:
     metal(const color& a): albedo(a) {}

     virtual bool scatter(
             const ray& r_in, 
             const hitRecord& rec, 
             color& attenuation, 
             ray& scattered) const;

 private:
     color albedo;

};



#endif

