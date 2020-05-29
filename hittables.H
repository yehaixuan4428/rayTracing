#ifndef HITTABLES_H
#define HITTABLES_H

#include <memory>
#include <vector>
#include "hittable.H"

using std::shared_ptr;
using std::make_shared;

class hittables: public hittable {

    public:
        hittables() {}
        hittables(shared_ptr<hittable> object) { add(object); }

        void clear() { objects.clear(); }
        void add(shared_ptr<hittable> object) { objects.push_back(object); }

        virtual bool hit(const ray& r, double tmin, double tmax, hitRecord& rec) const;

    private:
        std::vector<shared_ptr<hittable>> objects;
};


#endif
