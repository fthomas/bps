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

#include <cmath>

#include "bps_3-vector.h"
#include "bps_quaternion.h"

namespace bps {

  ThreeVector& ThreeVector::rotate(const ThreeVector& axis,
                                   const double angle) {
    ThreeVector n = axis.normalized();
    Quaternion q = Quaternion(std::cos(angle/2), std::sin(angle/2)*n);

    Quaternion p1 = Quaternion(0,x[0],x[1],x[2]);
    Quaternion p2 = q*p1*q.conjugated();

    x[0] = p2.getIm1();
    x[1] = p2.getIm2();
    x[2] = p2.getIm3();
    return *this;
  }

} // namespace bps
