/*
   BPS - Basic Particle Simulations
   Copyright (C) 2005, 2006  Frank S. Thomas <frank@thomas-alfeld.de>

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

#ifndef BPS_N_VECTOR_H
#define BPS_N_VECTOR_H

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

      template<class S> Vector(const S& v) : x(n) {
        for (int i = 0; i < n; i++)
          x[i] = v[i];
      }

      // operators
      template<class S> Vector& operator=(const S& v) {
        for (int i = 0; i < n; i++)
          x[i] = v[i];
        return *this;
      }

      value_type& operator[](int i) {
        return x[i];
      }

      const value_type& operator[](int i) const {
        return x[i];
      }

      Vector& operator+=(const Vector& v) {
        int m = std::min(n, v.size());
        for (int i = 0; i < m; i++)
          x[i] += v[i];
        return *this;
      }

      Vector& operator-=(const Vector& v) {
        int m = std::min(n, v.size());
        for (int i = 0; i < m; i++)
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

  // multiplication with a scalar
  template<class T, int n>
  Vector<T, n> operator*(const Vector<T, n>& v, const T& f) {
    Vector<T, n> w;
    for (int i = 0; i < n; i++)
      w[i] = v[i]*f;
    return w;
  }

  template<class T, int n>
  Vector<T, n> operator*(const T& f, const Vector<T, n>& v) {
    Vector<T, n> w;
    for (int i = 0; i < n; i++)
      w[i] = v[i]*f;
    return w;
  }

  template<class T, int n>
  Vector<T, n> operator/(const Vector<T, n>& v, const T& f) {
    Vector<T, n> w;
    for (int i = 0; i < n; i++)
      w[i] = v[i]/f;
    return w;
  }

  // addition and subtraction
  template<class T, int n>
  Vector<T, n> operator+(const Vector<T, n>& v, const Vector<T, n>& w) {
    Vector<T, n> u;
    for (int i = 0; i < n; i++)
      u[i] = v[i]+w[i];
    return u;
  }

  template<class T, int n>
  Vector<T, n> operator-(const Vector<T, n>& v, const Vector<T, n>& w) {
    return v + (-w);
  }

  // scalar product
  template<class T, int n>
  double operator*(const Vector<T, n>& v, const Vector<T, n>& w) {
    double res = 0;
    for (int i = 0; i < n; i++)
      res += v[i]*w[i];
    return res;
  }

  // comparison
  template<class T, int n>
  bool operator==(const Vector<T, n>& v, const Vector<T, n>& w) {
    for (int i = 0; i < n; i++)
      if (v[i] != w[i]) return false;
    return true;
  }

  template<class T, int n>
  bool operator!=(const Vector<T, n>& v, const Vector<T, n>& w) {
    return !(v == w);
  }

  template<class T, int n>
  std::ostream& operator<<(std::ostream& os, const Vector<T, n>& v) {
    os << "Vector(";
    for (int i = 0; i < n; i++) {
      os << v[i];
      if (i < n-1) os << ", ";
    }
    return os << ")";
  }

} // namesapce bps

#endif // BPS_N_VECTOR_H
