/*
   BPS - Basic Particle Simulations
   Copyright (C) 2006  Frank S. Thomas <frank@thomas-alfeld.de>

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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "glcanvas.h"
#include "ui_main_window.h"

class MainWindow : public QMainWindow {
  Q_OBJECT

  public:
    MainWindow();
    ~MainWindow();

  private:
    Ui::MainWindow gui;
    GLCanvas glCanvas;
};

#endif // MAINWINDOW_H
