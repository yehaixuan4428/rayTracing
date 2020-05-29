/********************************************************
*
*  Author: Hx Ye - hxye@umich.edu
*
*  Create: 2020-05-29 12:04
*
*  Last modified: 2020-05-29 12:04
*
*  Filename: vec3I.H
*
*  Description: 
*
********************************************************/

inline vec3::vec3():e{0, 0, 0} {}

inline vec3::vec3(double e1, double e2, double e3):e{e1, e2, e3} {}

inline double vec3::x() const {return e[0];}
inline double vec3::y() const {return e[1];}
inline double vec3::z() const {return e[2];}

inline vec3 vec3::operator-() const {return vec3(-e[0], -e[1], -e[2]);}
inline double vec3::operator[](int i) const {return e[i];}
inline double& vec3::operator[](int i) {return e[i];}

inline vec3& vec3::operator+=(const vec3& v) {
    e[0] += v.e[0];
    e[1] += v.e[1];
    e[2] += v.e[2];
    return *this;
}

inline vec3& vec3::operator*=(double t) {
    e[0] *= t;
    e[1] *= t;
    e[2] *= t;
    return *this;
}

inline vec3& vec3::operator/=(double t) {
    *this *= (1.0/t);
    return *this;
}

inline double vec3::length() const {
    return sqrt(lengthSqr());
}
inline double vec3::lengthSqr() const {
    return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
}


inline vec3 operator+(const vec3& u, const vec3& v) {
    return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

inline vec3 operator-(const vec3& u, const vec3& v) {
    return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

inline vec3 operator*(const vec3& u, const vec3& v) {
    return vec3(u.e[0]*v.e[0], u.e[1]* v.e[1], u.e[2]*v.e[2]);
}
inline vec3 operator*(double t, const vec3& v) {
    return vec3(t*v.e[0], t*v.e[1], t*v.e[2]);
}
inline vec3 operator*(const vec3& v, double t) {
    return t*v;
}
inline vec3 operator/(const vec3& v, double t) {
    return (1.0/t)*v;
}


inline double dot(const vec3& u, const vec3& v) {
    return u.e[0]*v.e[0] + u.e[1]*v.e[1] + u.e[2]*v.e[2];
}
inline vec3 cross(const vec3& u, const vec3& v) {
    return vec3 ( u.e[1]*v.e[2] - u.e[2]*v.e[1], u.e[2]*v.e[0] - u.e[0]*v.e[2], u.e[0]*v.e[1] - u.e[1]*v.e[0]);
}
inline vec3 unit(const vec3& v) {
    return v/v.length();
}

inline ostream& operator<<(ostream& os, const vec3& v) {
    os << v.e[0] << " " << v.e[1] << " " << v.e[2];
    return os;
}

inline static vec3 randomInUnitSphere() {
    while (true) {
        vec3 p(random_double(-1.0, 1.0), random_double(-1.0, 1.0), random_double(-1.0, 1.0));
        if (p.lengthSqr() < 1) return p;
    }
}

