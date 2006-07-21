/*
   BPS - Basic Particle Simulations
   Copyright (C) 2005  Frank S. Thomas

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

#ifndef BPS_QUATERNION_H
#define BPS_QUATERNION_H

#include <cmath>
#include <ostream>

#include "bps_vector.h"

namespace bps {

  class Quaternion {
    private:
      double re, im1, im2, im3;

    public:
      inline Quaternion(double _re = 0, double _im1 = 0, double _im2 = 0,
                        double _im3 = 0)
              : re(_re), im1(_im1), im2(_im2), im3(_im3) {}

      inline Quaternion(double _re = 0, const Vector& im = Vector(0,0,0))
              : re(_re), im1(im.getX()), im2(im.getY()), im3(im.getZ()) {}

      // getter
      inline double getRe()  const { return re; }
      inline double getIm1() const { return im1; }
      inline double getIm2() const { return im2; }
      inline double getIm3() const { return im3; }

      // setter
      inline Quaternion& set(Quaternion a) {
        re  = a.re;
        im1 = a.im1;
        im2 = a.im2;
        im3 = a.im3;
        return *this;
      }

      inline Quaternion& set(double _re, double _im1, double _im2,
                             double _im3) {
        re  = _re;
        im1 = _im1;
        im2 = _im2;
        im3 = _im3;
        return *this;
      }

      inline Quaternion& setRe(double _re) { re = _re; return *this; }
      inline Quaternion& setIm1(double _im1) { im1 = _im1; return *this; }
      inline Quaternion& setIm2(double _im2) { im2 = _im2; return *this; }
      inline Quaternion& setIm3(double _im3) { im3 = _im3; return *this; }

      // norm
      inline double norm() const {
        return std::sqrt((re*re) + (im1*im1) + (im2*im2) + (im3*im3));
      }

      inline Quaternion& normalize() {
        double n = norm();
        re /= n; im1 /= n; im2 /= n; im3 /= n;
        return *this;
      }

      inline Quaternion normalized() const {
        double n = norm();
        return Quaternion(re/n, im1/n, im2/n, im3/n);
      }

      // operators
      inline Quaternion& operator+=(const Quaternion& a) {
        re  += a.getRe();
        im1 += a.getIm1();
        im2 += a.getIm2();
        im3 += a.getIm3();
        return *this;
      }

      inline Quaternion& operator-=(const Quaternion& a) {
        re  -= a.getRe();
        im1 -= a.getIm1();
        im2 -= a.getIm2();
        im3 -= a.getIm3();
        return *this;
      }

      inline Quaternion& operator*=(const double f) {
        re *= f; im1 *= f; im2 *= f; im3 *= f;
        return *this;
      }

      inline Quaternion& operator/=(const double f) {
        re /= f; im1 /= f; im2 /= f; im3 /= f;
        return *this;
      }

      // sign
      inline Quaternion operator+() const { return Quaternion(re,im1,im2,im3); }
      inline Quaternion operator-() const { return Quaternion(-re,-im1,-im2,-im3); }

      // conjugate
      inline Quaternion& conjugate() {
        im1 = -im1; im2 = -im2; im3 = -im3;
        return *this;
      }

      inline Quaternion conjugated() const {
        return Quaternion(re,-im1,-im2,-im3);
      }
  };

  // multiplication with a scalar
  inline Quaternion operator*(const Quaternion& a, const double f) {
    return Quaternion(a.getRe()*f, a.getIm1()*f, a.getIm2()*f, a.getIm3()*f);
  }

  inline Quaternion operator*(const double f, const Quaternion& a) {
    return Quaternion(a.getRe()*f, a.getIm1()*f, a.getIm2()*f, a.getIm3()*f);
  }

  inline Quaternion operator/(const Quaternion& a, const double f) {
    return Quaternion(a.getRe()/f, a.getIm1()/f, a.getIm2()/f, a.getIm3()/f );
  }

  // addition and subtraction
  inline Quaternion operator+(const Quaternion& a, const Quaternion& b) {
    return Quaternion(a.getRe()  + b.getRe(),
                      a.getIm1() + b.getIm1(),
                      a.getIm2() + b.getIm2(),
                      a.getIm3() + b.getIm3());
  }

  inline Quaternion operator-(const Quaternion& a, const Quaternion& b) {
    return a + (-b);
  }

  // product
  inline Quaternion operator*(const Quaternion& a, const Quaternion& b) {
    return Quaternion(
      a.getRe() *b.getRe()  -
      a.getIm1()*b.getIm1() -
      a.getIm2()*b.getIm2() -
      a.getIm3()*b.getIm3(),

      a.getRe() *b.getIm1() +
      a.getIm1()*b.getRe()  +
      a.getIm2()*b.getIm3() -
      a.getIm3()*b.getIm2(),

      a.getRe() *b.getIm2() -
      a.getIm1()*b.getIm3() +
      a.getIm2()*b.getRe()  +
      a.getIm3()*b.getIm1(),

      a.getRe() *b.getIm3() +
      a.getIm1()*b.getIm2() -
      a.getIm2()*b.getIm1() +
      a.getIm3()*b.getRe());
  }

  // comparison
  inline bool operator==(const Quaternion& a, const Quaternion& b) {
    return a.getRe()  == b.getRe()  &&
           a.getIm1() == b.getIm1() &&
           a.getIm2() == b.getIm2() &&
           a.getIm3() == b.getIm3();
  }

  inline bool operator!=(const Quaternion& a, const Quaternion& b) {
    return !(a == b);
  }

  std::ostream& operator<<(std::ostream&, const Quaternion&);

} // namesapce bps

#endif // BPS_QUATERNION_H
