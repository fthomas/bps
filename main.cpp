#include <bps_n-vector.h>
#include <bps_3-vector.h>
#include <iostream>

using namespace std;
using namespace bps;

int main(int argc, char* argv[]) {

Vector<double, 3> u,v,w;
ThreeVector a = ThreeVector(1,0,0);
ThreeVector b = ThreeVector(0,1,0);

v[0] = 1;
v[1] = 2;
v[2] = 3;

w = v;
u = (v + w);

cout << a[0];

}
