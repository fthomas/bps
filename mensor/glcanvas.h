/*
   BPS - Basic Particle Simulations
   Copyright (C) 2006  Frank S. Thomas <frank@thomas-alfeld.de>

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

#ifndef GLCANVAS_H
#define GLCANVAS_H

#include <QGLWidget>

class GLCanvas : public QGLWidget {
  Q_OBJECT

  public:
    GLCanvas(QWidget* parent = 0);
    ~GLCanvas();

  protected:
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();
};

#endif // GLCANVAS_H
