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

#include "bps_n-vector.h"

namespace bps {

  class Quaternion : public Vector<double, 4> {
    public:
      inline Quaternion(double _re = 0, double _im1 = 0, double _im2 = 0,
                        double _im3 = 0) {
        x[0] = _re;
        x[1] = _im1;
        x[2] = _im2;
        x[3] = _im3;
      }

      inline Quaternion(double _re, const Vector<double, 3>& im) {
        x[0] = _re;
        x[1] = im[0];
        x[2] = im[1];
        x[3] = im[2];
      }

      // getter
      inline double getRe()  const { return x[0]; }
      inline double getIm1() const { return x[1]; }
      inline double getIm2() const { return x[2]; }
      inline double getIm3() const { return x[3]; }

      // setter
      inline Quaternion& set(Quaternion a) {
        x[0] = a[0];
        x[1] = a[1];
        x[2] = a[2];
        x[3] = a[3];
        return *this;
      }

      inline Quaternion& set(double _re, double _im1, double _im2,
                             double _im3) {
        x[0] = _re;
        x[1] = _im1;
        x[2] = _im2;
        x[3] = _im3;
        return *this;
      }

      inline Quaternion& setRe(double _re) { x[0] = _re; return *this; }
      inline Quaternion& setIm1(double _im1) { x[1] = _im1; return *this; }
      inline Quaternion& setIm2(double _im2) { x[2] = _im2; return *this; }
      inline Quaternion& setIm3(double _im3) { x[3] = _im3; return *this; }

      // conjugate
      inline Quaternion& conjugate() {
        x[1] = -x[1];
        x[2] = -x[2];
        x[3] = -x[3];
        return *this;
      }

      inline Quaternion conjugated() const {
        return Quaternion(x[0], -x[1], -x[2], -x[3]);
      }
  };

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

  std::ostream& operator<<(std::ostream&, const Quaternion&);

} // namesapce bps

#endif // BPS_QUATERNION_H
