#include "lambertian.H"

bool lambertian::scatter(
        const ray& r_in, 
        const hitRecord& rec, 
        color& attenuation, 
        ray& scattered) const {
    vec3 scatterDir = rec.normal + randomUnitVector();
    scattered = ray(rec.p, scatterDir);
    attenuation = albedo;
    return true;
}
