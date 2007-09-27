/*
   BPS - Basic Particle Simulations
   Copyright (C) 2005  Frank S. Thomas <frank@thomas-alfeld.de>

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <cmath>

#include "bps_constants.h"
#include "bps_relativity.h"
#include "bps_vector.h"

namespace bps {

  Vector SpecialRelativity::addVelocities(const Vector& v1, const Vector& v2) {
    const Vector n = v2.normalized();
    const Vector v1_parallel = (v1*n)*n;
    const Vector v1_perpendicular = v1 - v1_parallel;

    const double c_square = std::pow(BPS_CONST_SPEED_OF_LIGHT,2);
    const double gamma = std::sqrt(1 - v2*v2/c_square);

    const double denominator = 1 + v1*v2/c_square;
    const Vector numerator = v1_parallel + v2 + gamma*v1_perpendicular;

    return numerator/denominator;
  }

} // namespace bps
