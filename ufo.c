#include <stdio.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

int windowWidth = 800;
int windowHeight = 800;
int windowX = 100;
int windowY = 100;
float ufoAngle = 0.0;

void ufo(float size) {
    ufoAngle += 1.0;
    if (ufoAngle > 360.0)
        ufoAngle = 0.0;

    // glScalef(size, size, size);

    // Top
    glPushMatrix();
    // glScalef(size, size, size);
    glRotatef(ufoAngle, 0.0, 1.0, 0.0);
    glBegin(GL_TRIANGLES);
        glColor3f(0.75, 0.1, 0.45);
        glVertex3f(1.0, 0.0, 0.0);
        glVertex3f(0.7071, 0.0, 0.7071);
        glVertex3f(0.0, 0.5, 0.0);

        glVertex3f(0.7071, 0.0, 0.7071);
        glVertex3f(0.0, 0.0, 1.0);
        glVertex3f(0.0, 0.5, 0.0);

        glVertex3f(0.0, 0.0, 1.0);
        glVertex3f(-0.7071, 0.0, 0.7071);
        glVertex3f(0.0, 0.5, 0.0);

        glVertex3f(-0.7071, 0.0, 0.7071);
        glVertex3f(-1.0, 0.0, 0.0);
        glVertex3f(0.0, 0.5, 0.0);

        glVertex3f(-1.0, 0.0, 0.0);
        glVertex3f(-0.7071, 0.0, -0.7071);
        glVertex3f(0.0, 0.5, 0.0);

        glVertex3f(-0.7071, 0.0, -0.7071);
        glVertex3f(0.0, 0.0, -1.0);
        glVertex3f(0.0, 0.5, 0.0);

        glVertex3f(0.0, 0.0, -1.0);
        glVertex3f(0.7071, 0.0, -0.7071);
        glVertex3f(0.0, 0.5, 0.0);

        glVertex3f(0.7071, 0.0, -0.7071);
        glVertex3f(1.0, 0.0, 0.0);
        glVertex3f(0.0, 0.5, 0.0);
    glEnd();
    glPopMatrix();

    // Bottom
    glPushMatrix();
    // glRotatef(ufoAngle, 0.0, 1.0, 0.0);
    // glScalef(size, size, size);
    glBegin(GL_TRIANGLES);
        glColor3f(0.62, 0.8, 0.70);
        glVertex3f(1.0, 0.0, 0.0);
        glVertex3f(0.7071, 0.0, 0.7071);
        glVertex3f(0.0, -0.5, 0.0);

        glVertex3f(0.7071, 0.0, 0.7071);
        glVertex3f(0.0, 0.0, 1.0);
        glVertex3f(0.0, -0.5, 0.0);

        glVertex3f(0.0, 0.0, 1.0);
        glVertex3f(-0.7071, 0.0, 0.7071);
        glVertex3f(0.0, -0.5, 0.0);

        glVertex3f(-0.7071, 0.0, 0.7071);
        glVertex3f(-1.0, 0.0, 0.0);
        glVertex3f(0.0, -0.5, 0.0);

        glVertex3f(-1.0, 0.0, 0.0);
        glVertex3f(-0.7071, 0.0, -0.7071);
        glVertex3f(0.0, -0.5, 0.0);

        glVertex3f(-0.7071, 0.0, -0.7071);
        glVertex3f(0.0, 0.0, -1.0);
        glVertex3f(0.0, -0.5, 0.0);

        glVertex3f(0.0, 0.0, -1.0);
        glVertex3f(0.7071, 0.0, -0.7071);
        glVertex3f(0.0, -0.5, 0.0);

        glVertex3f(0.7071, 0.0, -0.7071);
        glVertex3f(1.0, 0.0, 0.0);
        glVertex3f(0.0, -0.5, 0.0);
    glEnd();
    glPopMatrix();
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, -1.0,
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);

    ufo(2);

    glTranslatef(-2.0, 2.0, 2.0);
    ufo(1.5);

    // glPushMatrix();
    // ufo(2);
    // glPopMatrix();
    // // glLoadIdentity();

    // glPushMatrix();
    // glTranslatef(0.0, 2.0, 0.0);
    // // glPopMatrix();
    // ufo(1.5);
    // glPopMatrix();


    glutSwapBuffers();
}

void reshape(int w, int h) {
    if (h == 0)
        h = 1;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1.0, 1.0, -1.0, 1.0, 0.1, 50.0);
    glMatrixMode(GL_MODELVIEW);
    windowWidth = w;
    windowHeight = h;
}

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    // glDepthFunc(GL_LEQUAL);
    // glEnable(GL_CULL_FACE);
    // glFrontFace(GL_CW);
    // glCullFace(GL_FRONT);
}

// void mouse(int button, int state, int x, int y) {
//     switch (button) {
//         case GLUT_LEFT_BUTTON :
//             if (state == GLUT_DOWN)
//                 changeEye(-5.0,5.0);
//             if (state == GLUT_UP)
//                 changeEye(0.0,0.0);
//             break;
//         case GLUT_MIDDLE_BUTTON :
//         case GLUT_RIGHT_BUTTON :
//             if (state == GLUT_DOWN)
//                 changeEye(5.0,5.0);
//             if (state == GLUT_UP)
//                 changeEye(0.0,0.0);
//             break;
//         default:
//             break;
//    }
// }

void keyboard(unsigned char key, int x, int y) {
    // switch(key) {
    //     case 32 : //space bar
    //         spin[0] = 1;
    //         spin[1] = 1;
    //         spin[2] = 1;
    //         break;
    //     case 97 : // a
    //         spin[0] = 1;
    //         spin[1] = 0;
    //         spin[2] = 1;
    //         break;
    //     case 113 : // q
    //         spin[0] = 0;
    //         spin[1] = 0;
    //         spin[2] = 0;
    //         break;
    //     case 122 : // z
    //         spin[0] = 0;
    //         spin[1] = 1;
    //         spin[2] = 1;
    //         break;
    //     default :
    //         printf ("KP: No action for %d.\n", key);
    //         break;
    // }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(windowWidth, windowHeight);
    glutInitWindowPosition(windowX, windowY);
    glutCreateWindow (argv[0]);
    init();
    glutIdleFunc(display);
    glutReshapeFunc(reshape);
    // glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
