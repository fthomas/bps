/*
   BPS - Basic Particle Simulations
   Copyright (C) 2005, 2006  Frank S. Thomas <frank@thomas-alfeld.de>

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

#ifndef BPS_3_VECTOR_H
#define BPS_3_VECTOR_H

#include <cmath>
#include <ostream>

#include "bps_n-vector.h"

namespace bps {

  class ThreeVector : public Vector<double, 3> {
    public:
      inline ThreeVector(double _x = 0, double _y = 0, double _z = 0) { 
        x[0] = _x;
        x[1] = _y;
        x[2] = _z;
      }

      template<class T, int n>
      inline ThreeVector(const Vector<T, n>& v) {
        int m = std::min(size(), n);
        for (int i = 0; i < m; i++)
          x[i] = v[i];
      }

      template<class T, int n>
      inline ThreeVector& operator=(const Vector<T, n>& v) {
        int m = std::min(size(), n);
        for (int i = 0; i < m; i++)
          x[i] = v[i];
        return *this;
      }

      // getter
      inline double getX() const { return x[0]; }
      inline double getY() const { return x[1]; }
      inline double getZ() const { return x[2]; }

      // setter
      inline ThreeVector& set(ThreeVector v) {
        x[0] = v[0];
        x[1] = v[1];
        x[2] = v[2];
        return *this;
      }

      inline ThreeVector& set(double _x, double _y, double _z) {
        x[0] = _x;
        x[1] = _y;
        x[2] = _z;
        return *this;
      }

      inline ThreeVector& setX(double _x) { x[0] = _x; return *this; }
      inline ThreeVector& setY(double _y) { x[1] = _y; return *this; }
      inline ThreeVector& setZ(double _z) { x[2] = _z; return *this; }

      // rotation
      ThreeVector& rotate(const ThreeVector& axis, const double angle);
  };

  // cross product
  inline ThreeVector cross(const ThreeVector& v, const ThreeVector& w) {
    return ThreeVector(v.getY()*w.getZ() - v.getZ()*w.getY(),
                       v.getZ()*w.getX() - v.getX()*w.getZ(),
                       v.getX()*w.getY() - v.getY()*w.getX());
  }

  // angle between two vectors
  inline double angleBetween(const ThreeVector& v, const ThreeVector& w) {
    return std::acos((v*w)/(v.length()*w.length()));
  }

  std::ostream& operator<<(std::ostream& os, const ThreeVector& v) {
    return os << "ThreeVector(" << v.getX() << ", "
                                << v.getY() << ", "
                                << v.getZ() << ")";
  }

} // namesapce bps

#endif // BPS_3_VECTOR_H
