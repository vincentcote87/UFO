#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <unistd.h>

int Window_Width = 800;
int Window_Height = 600;

float Pyr_Rot = 0.0f;
float Pyr_Speed = 0.5f;

float ufoVert = 1.0f;
float ufoHorizontal = 1.0f;
float ufoX = 0.0f;
float ufoY = 0.0f;
float ufoZ = 0.0f;
int ufoAngle = 0.0f;

float vSpeed = 0.02f;
float hSpeed = 0.0f;
GLfloat mat_specular2[] = {0.628281, 0.555802, 0.366065};
GLfloat mat_shininess2[] = { 0.4 * 128};
GLfloat mat_diffuse2[] = {1.0,   1.0,  1.0};
GLfloat mat_ambient2[] = {0.5,   0.5 ,  0.5, 1.0};
GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat mat_shininess[] = { 50.0 };
GLfloat light_position[] = { 0.0, 2.0, 0.0, 0.0 };
GLfloat light_position2[] = { 0.0, -3.0, -0.0, 0.0 };

void ufo(float s) {
    glBegin(GL_POLYGON);
        glColor3f(0.0, 1.0, 0.0);
        glVertex3f(s*-1.0f, 1.0f, s*0.25f);
        glVertex3f(s*-0.6f, 1.0f, s*-0.9f);
        glVertex3f( s*0.6f, 1.0f, s*-0.9f);
        glVertex3f( s*1.0f, 1.0f, s*0.25f);
        glVertex3f(0.0f, 1.0f, s*1.0f);
    glEnd();

    glBegin(GL_POLYGON);
        glNormal3f(0.0,1.0,0.0);
        glColor3f(0.00,0.60,0.90);
        glVertex3f( 0.0f, 1.5f, s*0.0f);
        glVertex3f( 0.0f, 1.0f,  s*1.0f);
        glVertex3f( s*1.0f, 1.0f,  s*0.25);
        glNormal3f(0.0,1.0,0.0);
        glVertex3f( 0.0f, 1.5f, 0.0f);
        glVertex3f( s*1.0f, 1.0f,  s*0.25f);
        glVertex3f( s*0.60f, 1.0f,  s*-0.9f);
        glNormal3f(0.0,1.0,0.0);
        glVertex3f( 0.0f, 1.5f, 0.0f);
        glVertex3f( s*0.60f, 1.0f,  s*-0.9f);
        glVertex3f( s*-0.60f, 1.0f,  s*-0.9f);
        glNormal3f(0.0,1.0,0.0);
        glVertex3f( 0.0f, 1.5f, 0.0f);
        glVertex3f( s*-0.60f, 1.0f, s*-0.9f);
        glVertex3f( s*-1.0f, 1.0f, s*0.25f);
        glNormal3f(0.0,1.0,0.0);
        glVertex3f( 0.0f, 1.5f, 0.0f);
        glVertex3f( s*-1.0f, 1.0f,  s*0.25f);
        glVertex3f( 0.0f, 1.0f,  s*1.0f);
    glEnd();
    glPopMatrix();
    glPushMatrix();

    if(ufoAngle == 1)
        glRotatef(Pyr_Rot,0.0f,1.0f,0.0f);

    glTranslatef(ufoX,ufoY,ufoZ);

   //Bottom half
    glBegin(GL_POLYGON);
        glNormal3f(0.0,-1.0,0.0);
        glColor3f(0.0, 1.0, 0.0);
        glVertex3f(s*-1.0f, 1.0f, s*0.25f);
        glVertex3f(s*-0.6f, 1.0f, s*-0.9f);
        glVertex3f( s*0.6f, 1.0f, s*-0.9f);
        glVertex3f( s*1.0f, 1.0f, s*0.25f);
        glVertex3f(0.0f, 1.0f, s*1.0f);
    glEnd();

    glBegin(GL_POLYGON);
        glNormal3f(0.0,-1.0,0.0);
        glVertex3f( 0.0f, 0.5f, 0.0f);
        glVertex3f( 0.0f, 1.0f,  s*1.0f);
        glVertex3f( s*1.0f, 1.0f,  s*0.25);
        glNormal3f(0.0,-1.0,0.0);
        glVertex3f( 0.0f, 0.5f, 0.0f);
        glVertex3f( s*1.0f, 1.0f,  s*0.25f);
        glVertex3f( s*0.60f, 1.0f,  s*-0.9f);
        glNormal3f(0.0,-1.0,0.0);
        glVertex3f( 0.0f, 0.5f, 0.0f);
        glVertex3f( s*0.60f, 1.0f,  s*-0.9f);
        glVertex3f( s*-0.60f, 1.0f,  s*-0.9f);
        glNormal3f(0.0,-1.0,0.0);
        glVertex3f( 0.0f, 0.5f, 0.0f);
        glVertex3f( s*-0.60f, 1.0f, s*-0.9f);
        glVertex3f( s*-1.0f, 1.0f, s*0.25f);
        glNormal3f(0.0,-1.0,0.0);
        glVertex3f( 0.0f, 0.5f, 0.0f);
        glVertex3f( s*-1.0f, 1.0f,  s*0.25f);
        glVertex3f( 0.0f, 1.0f,  s*1.0f);
    glEnd();
}

void lighting() {
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel (GL_SMOOTH);
    glLightfv(GL_LIGHT1, GL_AMBIENT, mat_ambient2);
    glLightfv(GL_LIGHT1, GL_SHININESS, mat_shininess2);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, mat_diffuse2);
    glLightfv(GL_LIGHT1, GL_POSITION, light_position2);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT1);

    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel (GL_SMOOTH);
    glLightfv(GL_LIGHT0, GL_SPECULAR, mat_specular);
    glLightfv(GL_LIGHT0, GL_SHININESS, mat_shininess);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
}

void display(void) {

    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glPopMatrix();

    // ufo's
    glPushMatrix();
    ufoX = -7.0f;
    ufoY = 4.0f;
    ufoZ = 0.0f;
    ufoAngle = 1;
    glRotatef(Pyr_Rot,0.0,1.0f,0.0f);
    glTranslatef(ufoX,ufoY,ufoZ);
    glRotatef(Pyr_Rot,0.0,1.0f,0.0f);
    glTranslatef(-ufoX,-ufoY,-ufoZ);
    glTranslatef(ufoX,ufoY,0.0);
    ufo(1.5);
    glPopMatrix();

    glPushMatrix();
    ufoX = 7.0f;
    ufoY = 4.0f;
    ufoZ = 0.0f;
    ufoAngle = 1;
    glRotatef(Pyr_Rot,0.0,1.0f,0.0f);
    glTranslatef(ufoX,ufoY,ufoZ);
    glRotatef(Pyr_Rot,0.0f,1.0f,0.0f);
    glTranslatef(-ufoX,-ufoY,-ufoZ);
    glTranslatef(ufoX,ufoY,ufoZ);
    ufo(1.0);
    glPopMatrix();

    glPushMatrix();
    ufoX = 1.0;
    ufoY = 4.0f;
    ufoZ = 1.0f;
    ufoAngle = 0;
    glTranslatef(ufoX,ufoY,ufoZ);
    glRotatef(Pyr_Rot,0.0f,1.0f,0.0f);
    glTranslatef(-ufoX,-ufoY,-ufoZ);
    glTranslatef(ufoX,ufoY,ufoZ);
    ufo(1);
    glPopMatrix();

    glPushMatrix();
    ufoX = -1.35;
    ufoY = 4.0;
    ufoZ = -1.35;
    glTranslatef(ufoZ,ufoY,ufoZ);
    glRotatef(Pyr_Rot,0.0f,1.0f,0.0f);
    glTranslatef(-ufoX,-ufoY,-ufoZ);
    glTranslatef(ufoX,ufoY,ufoZ);
    ufo(1.1);
    glPopMatrix();

    glPushMatrix();
    ufoX = -10.0;
    ufoY = ufoVert;
    ufoZ = ufoHorizontal;
    glTranslatef(ufoX,ufoVert,ufoHorizontal);
    glRotatef(Pyr_Rot,0.0f,1.0f,0.0f);
    glTranslatef(-ufoX,-ufoVert,-ufoHorizontal);
    glTranslatef(ufoX,ufoVert,ufoHorizontal);
    ufo(1.1);
    glPopMatrix();

    glPushMatrix();
    lighting();
    glPopMatrix();

    // Polyhydra 1
    glPushMatrix();
    glDisable(GL_CULL_FACE);
    glClearColor (0.0, 0.0, 0.0, 1.0);

    glBegin(GL_POLYGON);
        glNormal3f(0.0,-1.0,0.0);
        glColor3f(0.6,0.3,0.0);
        glVertex3f(-5,0,-1);
        glVertex3f(-5,0,-5);
        glVertex3f(-4,0,-5);
        glVertex3f(-4,0,-3);
    glEnd();

    glBegin(GL_POLYGON);
        glNormal3f(0.0,1.0,0.0);
        glColor3f(0.6,0.3,0.0);
        glVertex3f(-5,4,-1);
        glVertex3f(-5,4,-5);
        glVertex3f(-4,4,-5);
        glVertex3f(-4,4,-3);
    glEnd();

    glBegin(GL_POLYGON);
        glNormal3f(0.0,-1.0,0.0);
        glColor3f(0.6,0.3,0.0);
        glVertex3f(-4,0,-5);
        glVertex3f(-1,0,-5);
        glVertex3f(-3,0,-3);
        glVertex3f(-4,0,-3);
    glEnd();

    glBegin(GL_POLYGON);
        glNormal3f(0.0,1.0,0.0);
        glColor3f(0.6,0.3,0.0);
        glVertex3f(-4,4,-5);
        glVertex3f(-1,4,-5);
        glVertex3f(-3,4,-3);
        glVertex3f(-4,4,-3);
    glEnd();

    glBegin(GL_POLYGON);
        glNormal3f(0.0,0.0,-1.0);
        glColor3f(0.6,0.0,0.0);
        glVertex3f(-5,0,-5);
        glVertex3f(-5,4,-5);
        glVertex3f(-1,4,-5);
        glVertex3f(-1,0,-5);
    glEnd();

    glBegin(GL_POLYGON);
        glNormal3f(0.0,0.0,1.0);
        glColor3f(0.6,0.3,0.0);
        glVertex3f(-1,0,-5);
        glVertex3f(-1,4,-5);
        glVertex3f(-3,4,-3);
        glVertex3f(-3,0,-3);
    glEnd();

    glBegin(GL_POLYGON);
        glNormal3f(0.0,0.0,1.0);
        glColor3f(0.0,0.6,0.0);
        glVertex3f(-3,0,-3);
        glVertex3f(-3,4,-3);
        glVertex3f(-4,4,-3);
        glVertex3f(-4,0,-3);
    glEnd();

    glBegin(GL_POLYGON);
        glNormal3f(0.0,0.0,1.0);
        glColor3f(0.0,0.0,0.9);
        glVertex3f(-4,0,-3);
        glVertex3f(-4,4,-3);
        glVertex3f(-5,4,-1);
        glVertex3f(-5,0,-1);
    glEnd();

    glBegin(GL_POLYGON);
        glNormal3f(0.0,0.0,-1.0);
        glColor3f(0.9,0.0,0.9);
        glVertex3f(-5,0,-1);
        glVertex3f(-5,4,-1);
        glVertex3f(-5,4,-5);
        glVertex3f(-5,0,-5);
    glEnd();

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient2);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse2);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular2);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess2);
    glPopMatrix();

//    Polyhydra 2
    glPushMatrix();
    glClearColor (0.0, 0.0, 0.0, 1.0);
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient2);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse2);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular2);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess2);

    glBegin(GL_POLYGON);
        glNormal3f(0.0,-1.0,0.0);
        glColor3f(0.6,0.3,0.0);
        glVertex3f(1,0,0);
        glVertex3f(3,0,0);
        glVertex3f(3,0,3);
        glVertex3f(1,0,3);
    glEnd();

    glBegin(GL_POLYGON);
        glNormal3f(0.0,1.0,0.0);
        glColor3f(0.60,0.42,0.84);
        glVertex3f(1,4,0);
        glVertex3f(3,4,0);
        glVertex3f(3,4,3);
        glVertex3f(1,4,3);
    glEnd();

    glBegin(GL_POLYGON);
        glNormal3f(0.0,-1.0,0.0);
        glColor3f(0.6,0.3,0.0);
        glVertex3f(3,0,0);
        glVertex3f(4,0,0);
        glVertex3f(4,0,4);
        glVertex3f(3,0,4);
    glEnd();

    glBegin(GL_POLYGON);
        glNormal3f(0.0,1.0,0.0);
        glColor3f(0.60,0.42,0.84);
        glVertex3f(3,4,0);
        glVertex3f(4,4,0);
        glVertex3f(4,4,4);
        glVertex3f(3,4,4);
    glEnd();

    glBegin(GL_POLYGON);
        glNormal3f(0.0,0.0,-1.0);
        glColor3f(0.0,0.3,0.0);
        glVertex3f(1,0,0);
        glVertex3f(4, 0, 0);
        glVertex3f(4,4,0);
        glVertex3f(1,4,0);
    glEnd();

    glBegin(GL_POLYGON);
        glNormal3f(1.0,0.0,0.0);
        glColor3f(0.0,0.0,0.9);
        glVertex3f(4,0,0);
        glVertex3f(4,0,4);
        glVertex3f(4,4,4);
        glVertex3f(4,4,0);
    glEnd();

    glBegin(GL_POLYGON);
        glNormal3f(0.0,0.0,1.0);
        glColor3f(0.9,0.0,0.9);
        glVertex3f(4,0,4);
        glVertex3f(3,0,4);
        glVertex3f(3,4,4);
        glVertex3f(4,4,4);
    glEnd();

    glBegin(GL_POLYGON);
        glNormal3f(-1.0,0.0,0.0);
        glColor3f(0.9,0.9,0.0);
        glVertex3f(3,0,4);
        glVertex3f(3,0,3);
        glVertex3f(3,4,3);
        glVertex3f(3,4,4);
    glEnd();

    glBegin(GL_POLYGON);
        glNormal3f(0.0,0.0,-1.0);
        glColor3f(0.0,0.9,0.0);
        glVertex3f(1,0,3);
        glVertex3f(1,0,0);
        glVertex3f(1,4,0);
        glVertex3f(1,4,3);
    glEnd();

    glBegin(GL_POLYGON);
        glNormal3f(0.0,0.0,1.0);
        glColor3f(0.9,0.0,0.0);
        glVertex3f(3,0,3);
        glVertex3f(1,0,3);
        glVertex3f(1,4,3);
        glVertex3f(3,4,3);
    glEnd();
    glPopMatrix();

    // Polyhydra 3
    glPushMatrix();
    glClearColor (0.0, 0.0, 0.0, 1.0);
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient2);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse2);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular2);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess2);

    glBegin(GL_POLYGON);
        glNormal3f(0.0,-1.0,0.0);
        glColor3f(0.6,0.3,0.0);
        glVertex3f(-1,0,1);
        glVertex3f(-1,0,5);
        glVertex3f(-2,0,5);
        glVertex3f(-3,0,3);
        glVertex3f(-3,0,1);
    glEnd();

    glBegin(GL_POLYGON);
        glNormal3f(0.0,1.0,0.0);
        glColor3f(0.6,0.3,0.0);
        glVertex3f(-1,4,1);
        glVertex3f(-1,4,5);
        glVertex3f(-2,4,5);
        glVertex3f(-3,4,3);
        glVertex3f(-3,4,1);
    glEnd();

    glBegin(GL_POLYGON);
        glNormal3f(0.0,-1.0,0.0);
        glColor3f(0.6,0.3,0.0);
        glVertex3f(-3,0,3);
        glVertex3f(-4,0,5);
        glVertex3f(-5,0,5);
        glVertex3f(-5,0,1);
        glVertex3f(-3,0,1);
    glEnd();

    glBegin(GL_POLYGON);
        glNormal3f(0.0,1.0,0.0);
        glColor3f(0.6,0.3,0.0);
        glColor3f(0.6,0.3,0.0);
        glVertex3f(-3,4,3);
        glVertex3f(-4,4,5);
        glVertex3f(-5,4,5);
        glVertex3f(-5,4,1);
        glVertex3f(-3,4,1);
    glEnd();

    glBegin(GL_POLYGON);
        glNormal3f(0.0,0.0,-1.0);
        glColor3f(0.0,0.6,0.0);
        glVertex3f(-1,0,1);
        glVertex3f(-1, 0, 5);
        glVertex3f(-1,4,5);
        glVertex3f(-1,4,1);
    glEnd();

    glBegin(GL_POLYGON);
        glNormal3f(0.0,0.0,1.0);
        glColor3f(0.0,0.0,0.9);
        glVertex3f(-1,0,5);
        glVertex3f(-2,0,5);
        glVertex3f(-2,4,5);
        glVertex3f(-1,4,5);
    glEnd();

    glBegin(GL_POLYGON);
        glNormal3f(0.0,0.0,1.0);
        glColor3f(0.9,0.0,0.9);
        glVertex3f(-2,0,5);
        glVertex3f(-3,0,3);
        glVertex3f(-3,4,3);
        glVertex3f(-2,4,5);
    glEnd();

    glBegin(GL_POLYGON);
        glNormal3f(0.0,0.0,1.0);
        glColor3f(0.9,0.9,0.0);
        glVertex3f(-3,0,3);
        glVertex3f(-4,0,5);
        glVertex3f(-4,4,5);
        glVertex3f(-3,4,3);
    glEnd();

   glBegin(GL_POLYGON);
        glNormal3f(0.0,0.0,1.0);
        glColor3f(0.0,0.9,0.0);
        glVertex3f(-4,0,5);
        glVertex3f(-5,0,5);
        glVertex3f(-5,4,5);
        glVertex3f(-4,4,5);
    glEnd();

    glBegin(GL_POLYGON);
        glNormal3f(1.0,0.0,0.0);
        glColor3f(0.9,0.0,0.0);
        glVertex3f(-5,0,5);
        glVertex3f(-5,0,1);
        glVertex3f(-5,4,1);
        glVertex3f(-5,4,5);
    glEnd();

    glBegin(GL_POLYGON);
        glNormal3f(0.0,0.0,-1.0);
        glColor3f(0.1,0.5,0.5);
        glVertex3f(-5,0,1);
        glVertex3f(-1,0,1);
        glVertex3f(-1,4,1);
        glVertex3f(-5,4,1);
    glEnd();

    glEnable(GL_CULL_FACE);
    glPopMatrix();

    glPushMatrix();
    glLoadIdentity();
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glTranslatef(6.0f, Window_Height - 14, 0.0f);
    glPopMatrix();
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
    glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);
    glutSwapBuffers();
    glCullFace(GL_BACK);

    Pyr_Rot += Pyr_Speed;
    ufoVert += vSpeed;
    if((ufoVert > 4.0f) || (ufoVert < 0.0f))
        vSpeed = -vSpeed;

    ufoHorizontal += hSpeed;
    if((ufoHorizontal > 4.0f) || (ufoHorizontal < 0.0f))
        hSpeed = -hSpeed;
}

void init(int Width, int Height) {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);

    glClearColor(0.1f, 0.1f, 0.1f, 0.0f);
    glClearDepth(1.0);
    glDepthFunc(GL_LESS);
    glShadeModel(GL_SMOOTH);
}

void reshape(int w, int h) {
    if (h == 0)
        h = 1;

    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-16, 16, -12, 12, -100, 100);
    gluLookAt(1.5,1.0,-2.0,
              0.0,0.0,0.0,
              0.0,1.0,0.0);
    glMatrixMode(GL_MODELVIEW);
    Window_Width  = w;
    Window_Height = h;
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'u':
	        hSpeed = 0.0f;
            vSpeed = 0.02f;
	    break;
        case 'f':
            hSpeed = 0.02f;
            vSpeed = 0.0f;
	    break;
   }
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(Window_Width, Window_Height);
    glutCreateWindow("UFO");
    init(Window_Width, Window_Height);
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();

    return 0;
}
