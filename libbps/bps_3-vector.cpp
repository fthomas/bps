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

#include <ostream>

#include "bps_vector.h"
//#include "bps_quaternion.h"

namespace bps {

  /*Vector& Vector::rotate(const Vector& axis, const double angle) {
    Vector n = axis.normalized();
    Quaternion q = Quaternion(std::cos(angle/2), std::sin(angle/2)*n);

    Quaternion p1 = Quaternion(0,x,y,z);
    Quaternion p2 = q*p1*q.conjugated();

    x = p2.getIm1();
    y = p2.getIm2();
    z = p2.getIm3();
    return *this;
  }*/

  template<class T, int n>
  std::ostream& operator<<(std::ostream& os, const Vector<T, n>& v) {
    for (int i = 0; i < n; i ++)
        os << v[i];
    return os;
    /*return os << "Vector(" << v.getX() << ", "
                           << v.getY() << ", "
                           << v.getZ() << ")";*/
  }

} // namespace bps
