#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <limits>

#include <glut.h>

// dimensiunea ferestrei in pixeli
#define dim 300

unsigned char prevKey;

// concoida lui Nicomede (concoida dreptei)
// $x = a + b \cdot cos(t), y = a \cdot tg(t) + b \cdot sin(t)$. sau
// $x = a - b \cdot cos(t), y = a \cdot tg(t) - b \cdot sin(t)$. unde
// $t \in (-\pi / 2, \pi / 2)$
void Display1() {
    double xmax, ymax, xmin, ymin;
    double a = 1, b = 2;
    double pi = 4 * atan(1);
    double ratia = 0.05;

    // calculul valorilor maxime/minime ptr. x si y
    // aceste valori vor fi folosite ulterior la scalare
    xmax = a - b - 1;
    xmin = a + b + 1;
    ymax = ymin = 0;
    for (double t = -pi / 2 + ratia; t < pi / 2; t += ratia) {
        double x1, y1, x2, y2;
        x1 = a + b * cos(t);
        xmax = (xmax < x1) ? x1 : xmax;
        xmin = (xmin > x1) ? x1 : xmin;

        x2 = a - b * cos(t);
        xmax = (xmax < x2) ? x2 : xmax;
        xmin = (xmin > x2) ? x2 : xmin;

        y1 = a * tan(t) + b * sin(t);
        ymax = (ymax < y1) ? y1 : ymax;
        ymin = (ymin > y1) ? y1 : ymin;

        y2 = a * tan(t) - b * sin(t);
        ymax = (ymax < y2) ? y2 : ymax;
        ymin = (ymin > y2) ? y2 : ymin;
    }

    xmax = (fabs(xmax) > fabs(xmin)) ? fabs(xmax) : fabs(xmin);
    ymax = (fabs(ymax) > fabs(ymin)) ? fabs(ymax) : fabs(ymin);

    // afisarea punctelor propriu-zise precedata de scalare
    glColor3f(1, 0.1, 0.1); // rosu
    glBegin(GL_LINE_STRIP);
    for (double t = -pi / 2 + ratia; t < pi / 2; t += ratia) {
        double x1, y1, x2, y2;
        x1 = (a + b * cos(t)) / xmax;
        x2 = (a - b * cos(t)) / xmax;
        y1 = (a * tan(t) + b * sin(t)) / ymax;
        y2 = (a * tan(t) - b * sin(t)) / ymax;

        glVertex2f(x1, y1);
    }
    glEnd();

    glBegin(GL_LINE_STRIP);
    for (double t = -pi / 2 + ratia; t < pi / 2; t += ratia) {
        double x1, y1, x2, y2;
        x1 = (a + b * cos(t)) / xmax;
        x2 = (a - b * cos(t)) / xmax;
        y1 = (a * tan(t) + b * sin(t)) / ymax;
        y2 = (a * tan(t) - b * sin(t)) / ymax;

        glVertex2f(x2, y2);
    }
    glEnd();
}

// graficul functiei 
// $f(x) = \bar sin(x) \bar \cdot e^{-sin(x)}, x \in \langle 0, 8 \cdot \pi \rangle$, 
void Display2() {
    double pi = 4 * atan(1);
    double xmax = 8 * pi;
    double ymax = exp(1.1);
    double ratia = 0.05;

    // afisarea punctelor propriu-zise precedata de scalare
    glColor3f(1, 0.1, 0.1); // rosu
    glBegin(GL_LINE_STRIP);
    for (double x = 0; x < xmax; x += ratia) {
        double x1, y1;
        x1 = x / xmax;
        y1 = (fabs(sin(x)) * exp(-sin(x))) / ymax;

        glVertex2f(x1, y1);
    }
    glEnd();
}

void Display3() {
    double xmax = 20;
    double ymax = 0;
    double ymin = 0;
    double ratia = 0.05;
    double x1, y1;
    for (double x = 0; x < 21; x+=ratia) {
        if (x == 0) {
        x1 = x;
        y1 = 1;
        ymax = (ymax < y1) ? y1 : ymax;
        ymin = (ymin > y1) ? y1 : ymin;
        }
        else
        {
            x1 = x;
            y1 = fabs(x - round(x))/x;
            ymax = (ymax < y1) ? y1 : ymax;
            ymin = (ymin > y1) ? y1 : ymin;
        }
    }


    ymax = (fabs(ymax) > fabs(ymin)) ? fabs(ymax) : fabs(ymin);

    glColor3f(1, 0.1, 0.1); // rosu
    glBegin(GL_LINE_STRIP);
    for (double x = 0; x < 21; x+=ratia) {
        if (x == 0) {
            x1 = x/xmax;
            y1 = 1/ymax;
        }
        else
        {
            x1 = x/xmax;
            y1 = fabs(x - round(x)) / x / ymax;
        }
        glVertex2f(x1, y1);
    }
    glEnd();
}

void Display4() {
    //afisarea melcul lui Pascal
    double pi = 4 * atan(1);
    double a = 0.3;
    double b = 0.2;
    double ratia = 0.05;

    // afisarea punctelor propriu-zise precedata de scalare
    glColor3f(1, 0.1, 0.1); // rosu
    glBegin(GL_LINE_STRIP);
    for (double t = -pi + ratia; t < pi; t += ratia) {
        double x1, y1;
        x1 = 2* (b + a * cos(t)) * cos(t);
        y1 = 2* (b + a * cos(t)) * sin(t);
       
        glVertex2f(x1, y1);
    }
    glEnd();
}

void Display5() {
    //afisarea trisectoarea lui Longchamps
    double pi = 4 * atan(1);
    double a = 0.2;
    double ratia = 0.05;


    // afisarea punctelor propriu-zise precedata de scalare
    glColor3f(1, 0.1, 0.1); // rosu
    glBegin(GL_LINE_STRIP);
    for (double t = -pi / 2 + ratia; t < pi / 2 + ratia; t += ratia)
    {

        if ((t != -pi / 6) && (t != pi / 6)) {
            double x1, y1;
            x1 = a/(4 * cos(t)* cos(t) -3);
            y1 = (a * tan(t)) / (4 * cos(t) * cos(t) - 3);
            if (x1 <= 0 && y1 >= 0)
            {
                glVertex2f(x1, y1);
            }
        }
    }
    glEnd();

    glColor3f(0.2, 0.15, 0.88);
    glBegin(GL_TRIANGLE_FAN);
    for (double t = -pi / 2 + 2*ratia; t < pi / 2 + ratia; t += 2*ratia)
    {
       
        if ((t != -pi / 6) && (t != pi / 6)) {
            double x1, y1, x2, y2;
            x1 = a / (4 * cos(t) * cos(t) - 3);
            y1 = (a * tan(t)) / (4 * cos(t) * cos(t) - 3);
            x2 = a / (4 * cos(t+ratia) * cos(t+ratia) - 3);
            y2 = (a * tan(t + ratia)) / (4 * cos(t + ratia) * cos(t + ratia) - 3);
            if (x1 <= 0 && y1 >= 0 && x2 <= 0 && y2 >= 0)
            {
                glVertex2f(-1,1);
                glVertex2f(x1, y1);
                glVertex2f(x2, y2);
            }
        }
    }
    glEnd();
}


void Display6() {
    //afisarea cicloida
    double pi = 4 * atan(1);
    double a = 0.1;
    double b = 0.2;
    double ratia = 0.05;
   
    // afisarea punctelor propriu-zise precedata de scalare
    glColor3f(1, 0.1, 0.1); // rosu
    glBegin(GL_LINE_STRIP);
    for (double t = -8*pi+ratia; t < 8*pi; t += ratia) {
        double x1, y1;
        x1 = a * t -b * sin(t);
        y1 = a - b * cos(t);

        glVertex2f(x1, y1);
    }
    glEnd();
}


void Display7(){
    // epiciloida
    double pi = 4 * atan(1);
    double R = 0.1;
    double r = 0.3;
    double ratia = 0.05;

    // afisarea punctelor propriu-zise precedata de scalare
    glColor3f(1, 0.1, 0.1); // rosu
    glBegin(GL_LINE_STRIP);
    for (double t = 0; t <= 2 * pi; t += ratia) {
        double x1, y1;
        x1 = (R + r) * cos((r / R) * t)  - r * cos(t + t * (r / R));
        y1 = (R + r) * sin((r / R) * t)  - r * sin(t + t * (r / R));
        glVertex2f(x1, y1);
    }
    glEnd();
}

void Display8() {
    // hipociloida
    double pi = 4 * atan(1);
    double R = 0.1;
    double r = 0.3;
    double ratia = 0.05;

    // afisarea punctelor propriu-zise precedata de scalare
    glColor3f(1, 0.1, 0.1); // rosu
    glBegin(GL_LINE_STRIP);
    for (double t = 0; t <= 2 * pi; t += ratia) {
        double x1, y1;
        x1 = (R - r) * cos((r / R) * t) - r * cos(t - t * (r / R));
        y1 = (R - r) * sin((r / R) * t) - r * sin(t - t * (r / R));
        glVertex2f(x1, y1);
    }
    glEnd();
}

void Display9() {
    double pi = 4 * atan(1);
    double a = 0.4;
    double ratia = 0.05;

    // afisarea punctelor propriu-zise precedata de scalare
    glColor3f(1, 0.1, 0.1); // rosu
    glBegin(GL_LINE_STRIP);
    for (double t = -pi/4 ; t < pi/4; t += ratia) {
        double x1, y1, r;
        //r = a * sqrt(2 * cos(2 * t));
        r = sqrt(2 * a * a * cos(2 * t));
        x1 = r * cos(t);
        y1 = r*sin(t);
        glVertex2f(x1, y1);
    }
    glEnd();
    glBegin(GL_LINE_STRIP);
    for (double t = -pi / 4 ; t < pi / 4; t += ratia) {
        double r, x2, y2;
        //r = -a * sqrt(2 * cos(2 * t));
        r = -sqrt(2 * a * a * cos(2 * t));
        x2 = r * cos(t);
        y2 = r * sin(t);
        glVertex2f(x2, y2);
    }
    glEnd();
}

void DisplayA() {
    double pi = 4 * atan(1);
    double a = 0.02;
    double ratia = 0.05;

    // afisarea punctelor propriu-zise precedata de scalare
    glColor3f(1, 0.1, 0.1); // rosu
    glBegin(GL_LINE_STRIP);
    for (double t = 0 + ratia; t < 8*pi; t += ratia) {
        double x1, y1, r;
        r = a*exp(1+t);
        x1 = r * cos(t);
        y1 = r * sin(t);
        glVertex2f(x1, y1);
    }
    glEnd();
    
}
void Init(void) {

    glClearColor(1.0, 1.0, 1.0, 1.0);

    glLineWidth(1);

    //   glPointSize(4);

    glPolygonMode(GL_FRONT, GL_LINE);
}

void Display(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    switch (prevKey) {
    case '1':
        Display1();
        break;
    case '2':
        Display2();
        break;
    case '3':
        Display3();
        break;
    case '4':
        //melcul lui Pascal
        Display4();
        break;
    case '5':
        //trisectoarea lui Longchamps:
        Display5();
        break;
    case '6':
        Display6();
        break;
    case '7':
        Display7();
        break;
    case '8':
        Display8();
        break;
    case '9':
        Display9();
        break;
    case 'A':
        DisplayA();
        break;
    default:
        break;
    }

    glFlush();
}

void Reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
}

void KeyboardFunc(unsigned char key, int x, int y) {
    prevKey = key;
    if (key == 27) // escape
        exit(0);
    glutPostRedisplay();
}

void MouseFunc(int button, int state, int x, int y) {
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);

    glutInitWindowSize(dim, dim);

    glutInitWindowPosition(100, 100);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutCreateWindow(argv[0]);

    Init();

    glutReshapeFunc(Reshape);

    glutKeyboardFunc(KeyboardFunc);

    glutMouseFunc(MouseFunc);

    glutDisplayFunc(Display);

    glutMainLoop();

    return 0;
}