#ifndef VEC3_H
#define VEC3_H

#include<cmath>
#include<iostream>
#include "rtweekend.H"

using namespace std;

class vec3 {
 public:
     inline vec3();
     inline vec3(double e1, double e2, double e3);

     inline double x() const;
     inline double y() const;
     inline double z() const;

     inline vec3 operator-() const;
     inline double operator[](int i) const;
     inline double& operator[](int i);

     inline vec3& operator+=(const vec3& v);
     inline vec3& operator*=(double t);
     inline vec3& operator/=(double t);
     inline double length() const;
     inline double lengthSqr() const;

     double e[3];
};

#include "vec3I.H"

using point3 = vec3;
using color = vec3;

#endif
