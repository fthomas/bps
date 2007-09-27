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

#include "glcanvas.h"
#include "glcanvas.moc"

GLCanvas::GLCanvas(QWidget* parent) : QGLWidget(parent) {
}

GLCanvas::~GLCanvas() {
  makeCurrent();
}

void GLCanvas::initializeGL() {
  glClearColor(0.5, 0.5, 0.5, 0.0);
  glEnable(GL_DEPTH_TEST);
}

void GLCanvas::resizeGL(int width, int height) {

        int side = qMin(width, height);
        glViewport((width - side) / 2, (height - side) / 2, side, side);

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-0.5, +0.5, +0.5, -0.5, 4.0, 15.0);
        glMatrixMode(GL_MODELVIEW);
}

void GLCanvas::paintGL() {


        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();
        glTranslated(0.0, 0.0, -10.0);
        glRotated(1. / 16.0, 1.0, 0.0, 0.0);
        glRotated(1. / 16.0, 0.0, 1.0, 0.0);
        glRotated(1. / 16.0, 0.0, 0.0, 1.0);

    glBegin (GL_QUADS);
      glColor3f (0.0, 0.0, 0.0); glVertex3f (0.0, 0.0, 0.0);   /* unten */
      glColor3f (1.0, 0.0, 0.0); glVertex3f (1.0, 0.0, 0.0);
      glColor3f (1.0, 0.0, 1.0); glVertex3f (1.0, 0.0, 1.0);
      glColor3f (0.0, 0.0, 1.0); glVertex3f (0.0, 0.0, 1.0);
  
      glColor3f (0.0, 1.0, 0.0); glVertex3f (0.0, 1.0, 0.0);   /* oben */
      glColor3f (0.0, 1.0, 1.0); glVertex3f (0.0, 1.0, 1.0);
      glColor3f (1.0, 1.0, 1.0); glVertex3f (1.0, 1.0, 1.0);
      glColor3f (1.0, 1.0, 0.0); glVertex3f (1.0, 1.0, 0.0);
    glEnd ();


}
