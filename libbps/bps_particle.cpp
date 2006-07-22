/*
   BPS - Basic Particle Simulations
   Copyright (C) 2005  Frank S. Thomas <frank@thomas-alfeld.de>

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

#include "bps_constants.h"
#include "bps_particle.h"
#include "bps_relativity.h"
#include "bps_vector.h"

namespace bps {

  Particle& Particle::updatePosition(const double dt) {
    velocity = SpecialRelativity::addVelocities(velocity, dv);
    position += velocity * dt;
    return *this;
  }

  Particle& Particle::gravitationalForce(Particle& p, const double dt) {
    if (mass == 0 || p.mass == 0) return *this;

    const double G = BPS_CONST_GRAVITATIONAL_CONSTANT;
    const Vector r = position - p.position;
    p.dv += dt*G*mass*r/std::pow(r.length(),3);
    return *this;
  }

  Particle& Particle::coloumbForce(Particle& p, const double dt) {
    if (charge == 0 || p.charge == 0) return *this;

    const double k = 1/(4*M_PI*BPS_CONST_VACUUM_PERMITTIVITY);
    const Vector r = p.position - position;
    p.dv += (dt/p.mass)*k*p.charge*charge*r/std::pow(r.length(),3);
    return *this;
  }

} // namespace bps
