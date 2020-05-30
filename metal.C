#include "metal.H"

bool metal::scatter(
        const ray& r_in, 
        const hitRecord& rec, 
        color& attenuation, 
        ray& scattered) const {
    vec3 scatterDir = reflect(unit(r_in.direction()), rec.normal);
    scattered = ray(rec.p, scatterDir + fuzz*randomInUnitSphere());
    attenuation = albedo;
    return (dot(scattered.direction(), rec.normal) > 0);
}
