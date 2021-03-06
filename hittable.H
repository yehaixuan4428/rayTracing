#ifndef HITTABLE_H
#define HITTABLE_H

#include "rtweekend.H"
#include "ray.H"

class material;

struct hitRecord {
    point3 p;
    vec3 normal;
    shared_ptr<material> matPtr;
    double t;
    bool front_face;

    inline void set_face_normal(const ray& r, const vec3& outward_normal) {
        front_face = dot(r.direction(), outward_normal) < 0;
        normal = front_face ? outward_normal :-outward_normal;
    }
};

class hittable {
    public:
        virtual bool hit(const ray& r, double t_min, double t_max, hitRecord& rec) const = 0;
};

#endif
