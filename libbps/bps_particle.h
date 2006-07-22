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

#ifndef BPS_PARTICLE_H
#define BPS_PARTICLE_H

#include "bps_vector.h"

namespace bps {

  class Particle {
    public:
      Vector position;
      Vector velocity, dv;

      double mass;
      double charge;

    public:
      inline Particle(const Vector& p = Vector(0,0,0),
                      const Vector& v = Vector(0,0,0),
                      double m = 0, double q = 0)
              : position(p), velocity(v), mass(m), charge(q) {}

      Particle& updatePosition(const double dt);

      Particle& gravitationalForce(Particle& p, const double dt);
      Particle& coloumbForce(Particle& p, const double dt);
  };

} // namespace bps

#endif // BPS_PARTICLE_H
