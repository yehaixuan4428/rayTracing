#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.H"
#include "vec3.H"

class sphere: public hittable {
    public:
        sphere() {}
        sphere(point3 cen, double r, shared_ptr<material> m) : center(cen), radius(r), matPtr(m) {};

        virtual bool hit(const ray& r, double tmin, double tmax, hitRecord& rec) const;

    private:
        point3 center;
        double radius;
        shared_ptr<material> matPtr;
};

bool sphere::hit(const ray& r, double t_min, double t_max, hitRecord& rec) const {
    vec3 oc = r.origin() - center;
    auto a = r.direction().lengthSqr();
    auto half_b = dot(oc, r.direction());
    auto c = oc.lengthSqr() - radius*radius;
    auto discriminant = half_b*half_b - a*c;

    if (discriminant > 0) {
        auto root = sqrt(discriminant);
        auto temp = (-half_b - root)/a;
        if (temp < t_max && temp > t_min) {
            rec.t = temp;
            rec.p = r.at(rec.t);
            vec3 outward_normal = (rec.p - center) / radius;
            rec.set_face_normal(r, outward_normal);
            rec.matPtr = matPtr;
            return true;
        }
        temp = (-half_b + root) / a;
        if (temp < t_max && temp > t_min) {
            rec.t = temp;
            rec.p = r.at(rec.t);
            vec3 outward_normal = (rec.p - center) / radius;
            rec.set_face_normal(r, outward_normal);
            rec.matPtr = matPtr;
            return true;
        }
    }
    return false;
}


#endif
