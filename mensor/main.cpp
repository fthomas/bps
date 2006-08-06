#include <QtGui/QApplication>
#include <QtGui/QMainWindow>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  QMainWindow *mw = new QMainWindow;

  Ui_MainWindow hello;
  hello.setupUi(wm);
  mw->show();

  return app.exec();
}
