/*
   BPS - Basic Particle Simulations
   Copyright (C) 2005, 2006  Frank S. Thomas

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License
   as published by the Free Software Foundation; either version 2
   of the License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
   02110-1301, USA.
*/

#ifndef BPS_VECTOR_H
#define BPS_VECTOR_H

#include <vector>
#include <cmath>
#include <ostream>

namespace bps {

  template<class T, int n> class Vector {
    protected:
      std::vector<T> x;

    public:
      typedef T value_type;

      Vector() : x(n) {}

      template<class TT> Vector(const TT& v) : x(n) {
        for (int i = 0; i < n; i++)
          x[i] = v[i];
      }

      // operators
      template<class TT> Vector& operator=(const TT& v) {
        for (int i = 0; i < n; i++)
          x[i] = v[i];
        return *this;
      }

      value_type& operator[](int i) {
        return x[i];
      }

      Vector& operator+=(const Vector& v) {
        int m = std::min(n, v.size());
        for (int i = 0; i < m; i++)
          x[i] += v[i];
        return *this;
      }

      Vector& operator-=(const Vector& v) {
        for (int i = 0; i < n; i++)
          x[i] -= v[i];
        return *this;
      }

      Vector& operator*=(const value_type& f) {
        for (int i = 0; i < n; i++)
          x[i] *= f;
        return *this;
      }

      Vector& operator/=(const value_type& f) {
        for (int i = 0; i < n; i++)
          x[i] /= f;
        return *this;
      }

      // Euclidean norm
      double length() const {
        double sum = 0;
        for (int i = 0; i < n; i++)
          sum += x[i]*x[i];
        return std::sqrt(sum);
      }

      // p-norm
      double pNorm(const double p) const {
        double sum = 0;
        for (int i = 0; i < n; i++)
          sum += std::pow(x[i], p);
        return std::pow(sum, 1/p);
      }

      // maximum norm
      value_type maxNorm() const {
        if (n == 0) return 0;
        value_type max = x[0];
        for (int i = 1; i < n; i++)
          if (x[i] > max) max = x[i];
        return max;
      }

      // Euclidean distance
      double distanceTo(const Vector& v) const {
        double sum = 0;
        for (int i = 0; i < n; i++)
          sum += (x[i]-v[i])*(x[i]-v[i]);
        return std::sqrt(sum);
      }

      Vector& normalize() {
        double l = length();
        for (int i = 0; i < n; i++)
          x[i] /= l;
        return *this;
      }

      Vector normalized() const {
        Vector v;
        double l = length();
        for (int i = 0; i < n; i++)
          v[i] = x[i]/l;
        return v;
      }

      // sign
      Vector operator+() const {
        Vector v;
        for (int i = 0; i < n; i++)
          v[i] = +x[i];
        return v;
      }

      Vector operator-() const {
        Vector v;
        for (int i = 0; i < n; i++)
          v[i] = -x[i];
        return v;
      }

      int size() const { return n; }
  };

  // cross product
//  inline Vector cross(const Vector& v, const Vector& w) {
//    return Vector(v.getY()*w.getZ() - v.getZ()*w.getY(),
//                  v.getZ()*w.getX() - v.getX()*w.getZ(),
//                  v.getX()*w.getY() - v.getY()*w.getX());
//  }

/*
  class Vector {
    private:
      double x, y, z;

    public:
      inline Vector(double _x = 0, double _y = 0, double _z = 0)
              : x(_x), z(_z), y(_y) {}

      // getter
      inline double getX() const { return x; }
      inline double getY() const { return y; }
      inline double getZ() const { return z; }

      // setter
      inline Vector& set(Vector v) {
        x = v.x;
        y = v.y;
        z = v.z;
        return *this;
      }

      inline Vector& set(double _x, double _y, double _z) {
        x = _x;
        y = _y;
        z = _z;
        return *this;
      }

      inline Vector& setX(double _x) { x = _x; return *this; }
      inline Vector& setY(double _y) { y = _y; return *this; }
      inline Vector& setZ(double _z) { z = _z; return *this; }

      // Euclidean norm
      inline double length() const {
        return std::sqrt((x*x) + (y*y) + (z*z));
      }

      // p-norm
      inline double pNorm(const double p) const {
        return std::pow(std::pow(x,p)+
                        std::pow(y,p)+
                        std::pow(z,p), 1/p);
      }

      // maximum norm
      inline double maxNorm() const {
        return std::max(std::max(x,y),z);
      }

      // Euclidean distance
      inline double distanceTo(const Vector& v) const {
        return std::sqrt((x-v.x)*(x-v.x) +
                         (y-v.y)*(y-v.y) +
                         (z-v.z)*(z-v.z));
      }

      inline Vector& normalize() {
        double l = length();
        set(x/l, y/l, z/l);
        return *this;
      }

      inline Vector normalized() const {
        double l = length();
        return Vector(x/l, y/l, z/l);
      }

      // rotation
      Vector& rotate(const Vector& axis, const double angle);

      // operators
      inline Vector& operator+=(const Vector& v) {
        set(x+v.getX(), y+v.getY(), z+v.getZ());
        return *this;
      }

      inline Vector& operator-=(const Vector& v) {
        set(x-v.getX(), y-v.getY(), z-v.getZ());
        return *this;
      }

      inline Vector& operator*=(const double f) {
        set(x*f, y*f, z*f);
        return *this;
      }

      inline Vector& operator/=(const double f) {
        set(x/f, y/f, z/f);
        return *this;
      }

      // sign
      inline Vector operator+() const { return Vector(x,y,z); }
      inline Vector operator-() const { return Vector(-x,-y,-z); }
  };

  // multiplication with a scalar
  inline Vector operator*(const Vector& v, const double f) {
    return Vector(v.getX()*f, v.getY()*f, v.getZ()*f);
  }

  inline Vector operator*(const double f, const Vector& v) {
    return Vector(v.getX()*f, v.getY()*f, v.getZ()*f);
  }

  inline Vector operator/(const Vector& v, const double f) {
    return Vector(v.getX()/f, v.getY()/f, v.getZ()/f);
  }

  // addition and subtraction
  inline Vector operator+(const Vector& v, const Vector& w) {
    return Vector(v.getX() + w.getX(),
                  v.getY() + w.getY(),
                  v.getZ() + w.getZ());
  }

  inline Vector operator-(const Vector& v, const Vector& w) {
    return v + (-w);
  }

  // scalar product
  inline double operator*(const Vector& v, const Vector& w) {
    return (v.getX() * w.getX()) +
           (v.getY() * w.getY()) +
           (v.getZ() * w.getZ());
  }

  // cross product
  inline Vector cross(const Vector& v, const Vector& w) {
    return Vector(v.getY()*w.getZ() - v.getZ()*w.getY(),
                  v.getZ()*w.getX() - v.getX()*w.getZ(),
                  v.getX()*w.getY() - v.getY()*w.getX());
  }

  // angle between two vectors
  inline double angleBetween(const Vector& v, const Vector& w) {
    return std::acos((v*w)/(v.length()*w.length()));
  }

  // comparison
  inline bool operator==(const Vector& v, const Vector& w) {
    return v.getX() == w.getX() &&
           v.getY() == w.getY() &&
           v.getZ() == w.getZ();
  }

  inline bool operator!=(const Vector& v, const Vector& w) {
    return !(v == w);
  }

  std::ostream& operator<<(std::ostream&, const Vector&);
*/
} // namesapce bps

#endif // BPS_VECTOR_H
