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
 
#include "color.H"
#include <string>

using namespace std;
 
int main() {
    const int imageWidth = 256;
    const int imageHeight = 256;

    ofstream writer("sampleImage.ppm");
    writer << "P3" << endl;
    writer << imageWidth << " " << imageHeight << endl;
    writer << "255" << endl;

    for (int j = imageHeight - 1; j >= 0; j--) {
        cerr << "\rScanlines remaining: " << j << ' ' << flush;
        for (int i = 0; i < imageWidth; i++) {

            color pixel(double(i)/(imageWidth - 1.0), double(j)/(imageHeight - 1.0), 0.25);

            write_color_toFile(writer, pixel);
        }
    }

    return 0;
}
