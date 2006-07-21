//#include <qapplication.h>

//#include "canvas3d.h"
#include <bps_n-vector.h>
#include <iostream>

using namespace std;
using namespace bps;

int main(int argc, char* argv[]) {

Vector<double, 3> u,v,w;

v[0] = 1;
v[1] = 2;
v[2] = 3;

//w = v;
//u = (v + w);

cout << v;

/*QApplication app(argc, argv);
  Canvas3D canvas;
  canvas.setCaption("BSP - 3D Canvas");
  canvas.resize(640, 480);

  app.setMainWidget(&canvas);
  canvas.show();

  return app.exec();
*/
}
