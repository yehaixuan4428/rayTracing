#ifndef LAMBERTIAN_H
#define LAMBERTIAN_H

#include "material.H"

class lambertian: public material {
 public:
     lambertian(const color& a): albedo(a) {}

     virtual bool scatter(
             const ray& r_in, 
             const hitRecord& rec, 
             color& attenuation, 
             ray& scattered) const;

 private:
     color albedo;

};



#endif

