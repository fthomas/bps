#include <bps_n-vector.h>
#include <bps_3-vector.h>
#include <bps_quaternion.h>
#include <iostream>

using namespace std;
using namespace bps;

int main(int argc, char* argv[]) {

Vector<double, 3> u,v,w;
ThreeVector a = ThreeVector(1,0,0);
ThreeVector b = ThreeVector(1,1,1);

v[0] = 1;
v[1] = 2;
v[2] = 3;

ThreeVector c = b.normalized();
cout << c;
Quaternion p = Quaternion(1, c);
cout << p;
}
