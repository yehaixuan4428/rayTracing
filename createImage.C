/********************************************************
*
*  Author: Hx Ye - hxye@umich.edu
*
*  Create: 2020-05-29 11:38
*
*  Last modified: 2020-05-29 11:38
*
*  Filename: createImage.C
*
*  Description: 
*
********************************************************/

#include "rtweekend.H"
#include "hittables.H"
#include "sphere.H"
#include "ray.H"
#include "color.H"
#include "camera.H"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
 
color rayColor(const ray& r, const hittable& world, int depth) {
    if (depth <= 0) return color(0, 0, 0);

    hitRecord rec;
    if (world.hit(r, 0.001, infinity, rec)) {
        ray scattered;
        color attenuation;
        if (rec.matPtr->scatter(r, rec, attenuation, scattered)) {
            return attenuation*rayColor(scattered, world, depth - 1);
        }
        return color(0, 0, 0);
        /* point3 target = rec.p + rec.normal + randomUnitVector();
         * return 0.5*rayColor(ray(rec.p, target - rec.p), world, depth - 1); */
    }

    vec3 unitDir = unit(r.direction());
    double t = 0.5*(unitDir.y() + 1.0);
    return (1.0 - t)*color(1.0, 1.0, 1.0) + t*color(0.5, 0.7, 1.0);
}
 
int main() {
    const double aspectRatio = 16.0/9.0;
    const int imageWidth = 384;
    const int imageHeight = int(imageWidth/aspectRatio);
    const int nSamples = 100;
    const int maxDepth = 50;

    ofstream writer("sampleImage.ppm");
    writer << "P3" << endl;
    writer << imageWidth << " " << imageHeight << endl;
    writer << "255" << endl;

    hittables world;
    world.add(make_shared<sphere>(point3(0, 0, -1), 0.5));
    world.add(make_shared<sphere>(point3(0, -100.5, -1), 100));

    camera cam;

    for (int j = imageHeight - 1; j >= 0; j--) {
        cerr << "\rScanlines remaining: " << j << ' ' << flush;
        for (int i = 0; i < imageWidth; i++) {
            color pixelColor(0.0, 0.0, 0.0);
            for (int s = 0; s < nSamples; s++) {
                double u = (double(i) + random_double())/(imageWidth - 1.0);
                double v = (double(j) + random_double())/(imageHeight - 1.0);
                ray r = cam.getRay(u, v);
                pixelColor += rayColor(r, world, maxDepth);
            }
            write_color_toFile(writer, pixelColor, nSamples);
        }
    }

    std::cerr << "\nDone.\n";

    return 0;
}
