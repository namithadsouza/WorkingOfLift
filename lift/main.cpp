#include<windows.h>
#include<iostream>
#include<GL/glut.h>
#include<math.h>
#include<unistd.h>
#define PI 3.1415926535898
float yr=0,b2=0,b4=0,pr=0,x=0,y=0,counter=600;
void *currentfont;
GLint flag=0;
void navigation_background()
{
 glBegin(GL_POLYGON);
    glColor3f(0,0.2,0.5);
    glVertex2i(0,0);
    glColor3f(1,0.2,0.3);
    glVertex2i(1346,0);
    glColor3f(0,0.2,0.5);
    glVertex2i(1346,728);
    glColor3f(1,0.2,0.3);
    glVertex2i(0,728);
glEnd();
}

void lift_background()
{
 glBegin(GL_POLYGON);
    glColor3f(0,0.9,1.0);
    glVertex2i(0,0);
    glColor3f(1,0.2,0.3);
    glVertex2i(1346,0);
    glColor3f(1,0.2,0.5);
    glVertex2i(1346,728);
    glColor3f(1,0.2,0.3);
    glVertex2i(0,728);
 glEnd();
}

void setFont(void *font)
{
	currentfont=font;
}
void drawstring(float x,float y,float z,char *string)
{
	char *c;
	glRasterPos3f(x,y,z);
    for(c=string;*c!='\0';c++)
	{
        glutBitmapCharacter(currentfont,*c);
	}
}

void frontscreen()
{
    setFont(GLUT_BITMAP_TIMES_ROMAN_24);
    navigation_background();
    glColor3f(1,1,0);   //yellow
    drawstring(310.0,696.0,0.0,"MANGALORE INSTITUTE OF TECHNOLOGY AND ENGINEERING");
    glColor3f(0.9,0,0.8);   //purple
    drawstring(330,650,0.0,"DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING");
    glColor3f(1,0,0.5);    //pink
    drawstring(550,580,0.0,"A MINI PROJECT ON");
    glColor3f(0,0.7,1);     //blue
    drawstring(470,530,0.0,"GRAPHICAL SIMULATION OF LIFT");
    drawstring(470,528,0.0,"_______________________________");
    glColor3f(1,0.5,0);  //orange
    drawstring(667,480,0.0,"BY");
    glColor3f(0.9,0,0.8);  //purple
    drawstring(350,430,0.0,"NAMITHA DSOUZA                                                4MT16CS047");
    drawstring(350,380,0.0,"PAVITRA NAYAK                                                    4MT16CS056");
    glColor3f(1, 0.5, 0);  //orange
    drawstring(540,320,0.0,"UNDER THE GUIDANCE OF ");
    glColor3f(0.8,0.8,0);    //yellow
    drawstring(190,270,0.0,"MR PRASHANTH B S");
    drawstring(190,230,0.0,"ASSISTANT PROFESSOR");
    drawstring(190,190,0.0,"DEPARTMENT OF CS&E,");
    drawstring(190,150,0.0,"M.I.T.E, MOODABIDRI");
    drawstring(980,270.0,0,"MRS SARANYA BABU");
    drawstring(980,230,0.0,"ASSISTANT PROFESSOR");
    drawstring(980,190,0.0,"DEPARTMENT OF CS&E,");
    drawstring(980,150,0.0,"M.I.T.E, MOODABIDRI");
    glFlush();
}
void helpscreen()
{
    setFont(GLUT_BITMAP_TIMES_ROMAN_24);
    glClear(GL_COLOR_BUFFER_BIT);
    navigation_background();
    glColor3f(0,1,1);
    drawstring(550.0,640.0,0.0,"NAVIGATIONS");
    drawstring(550.0,638.0,0.0,"_____________");
    glColor3f(1,1,0);
    drawstring(350.0,540.0,0.0,"FIRST FLOOR                                             PRESS '1'");
    drawstring(350.0,440.0,0.0,"SECOND FLOOR                                        PRESS '2'");
    drawstring(350.0,340.0,0.0,"GROUND FLOOR                                      PRESS 'g'");
    drawstring(350.0,240.0,0.0,"STOP AND EXIT                                       PRESS 'Esc'");
    drawstring(350.0,140.0,0.0,"NEXT SCENE                                            PRESS 'Enter'");
    glFlush();
}
void rect(int x1,int y1,int x2,int y2)
{
    glBegin(GL_POLYGON);
        glVertex2f(x1,y1);
        glVertex2f(x1,y2);
        glVertex2f(x2,y2);
        glVertex2f(x2,y1);
    glEnd();
}
void font_mall()
{
    setFont(GLUT_BITMAP_HELVETICA_18);
    glColor3f(1,1,1);
    drawstring(498.0,580.0,0.0,"MALL");
}
void font1()
{
    setFont(GLUT_BITMAP_HELVETICA_18);
    glColor3f(1,1,1);
    usleep(1000);
    drawstring(478.0,100.0,0.0,"PRESS ENTER FOR VIEWING THE DESCRIPTION OF LIFT PARTS");
}

void man_body(int a,int b,int c,int d,int e,int f,int g,int h)
{
     glBegin(GL_LINES);
    //middle line
    glVertex2f(a,b);
    glVertex2f(a,c);
    //left leg
    glVertex2f(a,c);
    glVertex2f(d,e);
    //right leg
    glVertex2f(a,c);
    glVertex2f(f,e);
    //left hand
    glVertex2f(a,g);
    glVertex2f(d,h);
    //right hand
    glVertex2f(a,g);
    glVertex2f(f,h);
    glEnd();
}
void circle(float x,float y,float r)
{
    float theta;
    int i;
    glBegin(GL_POLYGON);
        for(i=0;i<360;i++)
        {
              theta=(i*PI)/180;
              glVertex2f(x+r*cos(theta),y+r*sin(theta));
        }
    glEnd();
}
void man1()
{
    glColor3f(0.0, 0.0, 0.0 );
    circle(435,124,14.3);
    glLineWidth(2.2);
    man_body(435,120,80,417,60,453,92,110);
    glFlush();
}
void man2()
{
    glColor3f(0.0, 0.0, 0.0 );
    circle(365,124,14.3);
    glLineWidth(2.2);
    man_body(365,120,80,345,60,385,92,110);
    glFlush();
}
void man3()
{
    glColor3f(0.0, 0.0, 0.0 );
    circle(435+700,124,14.3);
    glLineWidth(2.2);
    man_body(1135,120,80,1115,60,1155,92,110);
    glFlush();
}
void rectangle()
{
    glColor3f(0.8,0.5,0.0);
    glBegin(GL_POLYGON);
        glVertex2f(150,150);
        glVertex2f(150,600);
        glVertex2f(900,600);
        glVertex2f(900,150);
        glVertex2f(50,200);
        glVertex2f(50,650);
        glVertex2f(800,650);
        glVertex2f(900,600);
    glEnd();
    font_mall();
}
void lines()
{
  glColor3f(1.0,1.0,0.0);
  glLineWidth(4);
  glBegin(GL_LINE_LOOP);
    glVertex2i(150,150);
    glVertex2i(50,200);
    glVertex2i(50,650);
    glVertex2i(150,600);
    glVertex2i(150,150);
    glVertex2i(900,150);
    glVertex2i(900,600);
    glVertex2i(800,650);
    glVertex2i(50,650);
    glVertex2i(150,600);
    glVertex2i(900,600);
    glVertex2i(900,150);
glEnd();
}
void road()
{
    glColor3f(0.0,0.3,0.01);
    rect(0,50,1346,200);
    glColor3f(0,0,0);
    rect(0,0,1346,50);
}
void tree()
{
    glColor3f(0.2,0,0);
    rect(1160,150,1195,380);
    glColor3f(0.0,0.3,0.01);
    circle(1200,400,50);
    circle(1180,390,50);
    circle(1120,420,50);
    circle(1148,480,50);
    circle(1222,450,50);
    circle(1230,400,40);
}
void pillor()
{
    glColor3f(1.0, 1.0, 0.0 );
    glLineWidth(3.2);
    glBegin(GL_LINES);
    glVertex2f(425,150);
    glVertex2f(425,600);
    glVertex2f(625,150);
    glVertex2f(625,600);
    glVertex2f(150,300);
    glVertex2f(900,300);
    glVertex2f(150,450);
    glVertex2f(900,450);
    glVertex2f(150,300);
    glVertex2f(50,350);
    glVertex2f(150,450);
    glVertex2f(50,500);
    glEnd();
}
void doors()
{

    glColor3f(1.0, 1.0, 0.0 );
     rect(475,150,575,270);
    rect(475,300,575,420);
    rect(475,450,575,570);
    glBegin(GL_POLYGON);
        glVertex2f(80,183);
        glVertex2f(80,300);
        glVertex2f(120,280);
        glVertex2f(120,163);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(80,333);
        glVertex2f(80,450);
        glVertex2f(120,430);
        glVertex2f(120,317);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(80,483);
        glVertex2f(80,600);
        glVertex2f(120,580);
        glVertex2f(120,467);
    glEnd();
}
void windows()
{
    glColor3f(1.0, 1.0, 0.0 );
    rect(160,220,220,270);
    rect(240,220,300,270);
    rect(320,220,380,270);
    rect(160,370,220,420);
    rect(240,370,300,420);
    rect(320,370,380,420);
    rect(160,520,220,570);
    rect(240,520,300,570);
    rect(320,520,380,570);
    rect(635,220,695,270);
    rect(715,220,775,270);
    rect(795,220,855,270);
    rect(635,370,695,420);
    rect(715,370,775,420);
    rect(795,370,855,420);
    rect(635,570,695,520);
    rect(715,570,775,520);
    rect(795,570,855,520);
}
void display_mall()
{
    glClearColor(0.8,0.8,1.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    road();
    rectangle();
    lines();
    pillor();
    doors();
    windows();
    tree();
    man1();
    man2();
    man3();
    font1();
    glFlush();
}
void description_background()
{
    glBegin(GL_POLYGON);
        glColor3f(1,1,0);
        glVertex2i(0,0);
        glColor3f(0,0,1);
        glVertex2i(1346,0);
        glColor3f(1,1,0);
        glVertex2i(1346,728);
        glColor3f(0,0,1);
        glVertex2i(0,728);
    glEnd();
}
void circle1(float x, float y, float r)
{
    float theta;
    glBegin(GL_LINE_LOOP);
    int i;
    for ( i=0 ; i< 360 ;i++)
    {
        theta=i*PI/180;
        glVertex2f(x+r*cos(theta),y+r*sin(theta));
    }
    glEnd();
}
void lineloop(int x1,int y1,int x2,int y2)
{
    glBegin(GL_LINE_LOOP);
        glVertex2f(x1,y1);
        glVertex2f(x1,y2);
        glVertex2f(x2,y2);
        glVertex2f(x2,y1);
    glEnd();
}
void scketch()
{
    description_background();
    glColor3f(0,0,0);
    glBegin(GL_LINES);
        glVertex2f(400,250);
        glVertex2f(400,600);
    glEnd();
    lineloop(360,200,440,230);
    lineloop(360,170,440,180);
    lineloop(360,180,440,190);
    lineloop(360,190,440,200);
    lineloop(360,200,440,210);
    lineloop(360,210,440,220);
    lineloop(360,220,440,230);
    lineloop(360,230,440,240);
    lineloop(360,240,440,250);
    circle1(425,600,25);
    glBegin(GL_LINES);
        glVertex2f(425,600);
        glVertex2f(425,660);
    glEnd();
    glBegin(GL_LINES);
        glVertex2f(410,660);
        glVertex2f(440,660);
    glEnd();
    glBegin(GL_LINES);
        glVertex2f(450,600);
        glVertex2f(450,500);
    glEnd();
    circle1(470,498,20);
    glBegin(GL_LINES);
        glVertex2f(490,498);
        glVertex2f(490,600);
    glEnd();
    circle1(525,600,35);
    circle1(525,600,45);
    circle1(470,498,5);
    glBegin(GL_LINES);
            glVertex2f(465,498);
        glVertex2f(460,460);
        glVertex2f(475,498);
        glVertex2f(480,460);
        glVertex2f(460,460);
        glVertex2f(480,460);
        glVertex2f(470,460);
        glVertex2f(470,430);
    glEnd();
    lineloop(460,430,480,300);
    lineloop(430,300,460,420);
    lineloop(480,300,510,420);
    lineloop(230,100,750,710);
    glFlush();

}
void desclift()
{
    setFont(GLUT_BITMAP_HELVETICA_18);
    glColor3f(1,1,0);
    drawstring(390.0,680.0,0.0,"IMPORTANT PARTS OF LIFT");
    drawstring(390.0,678.0,0.0,"_________________________");
    glColor3f(1,0,0.5);
    drawstring(325,600,0,"Pulley -> ");
    drawstring(270,200,0,"Counter ");
    drawstring(275,180,0,"Weight -> ");
    drawstring(513,350,0,"<--- Car");
    drawstring(513,300,0,"<--- Platform");
    drawstring(480,390,0,"<------ Sling");
    drawstring(470,440,0,"<---- Crosshead");
    drawstring(490,520,0,"<--- Cable");
    drawstring(570,600,0,"<-- Electric Motor");
}
void principle()
{
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
    glColor3f(0.7,0,1);  //purple
    drawstring(800.0,680.0,0.0,"PULLEY:");
    setFont(GLUT_BITMAP_HELVETICA_18);
    glColor3f(0.6, 0.3, 0.1);
    drawstring(830.0,650.0,0.0,"Pulley's are used to evenly balance the counterweight and");
    drawstring(819.0,630,0.0,"the elevator car.Pulley in elevators reduces the friction and");
    drawstring(818.0,610.0,0.0,"which in turn reduces the strain on the electric motor.");
    setFont(GLUT_BITMAP_TIMES_ROMAN_24);
    glColor3f(0.7,0,1);  //purple
    drawstring(800.0,560.0,0.0,"COUNTER WEIGHT:");
    setFont(GLUT_BITMAP_HELVETICA_18);
    glColor3f(0.6, 0.3, 0.1);
    drawstring(830.0,530.0,0.0,"A counterweight is a weight that, by exerting an opposite");
    drawstring(820.0,510,0.0,"force,provides balance and stability of a mechanical system.");
    drawstring(820.0,490.0,0.0,"It's purpose is to make lifting the load more efficient, which");
    drawstring(820.0,470.0,0.0,"saves energy and is less taxing on the lifting machine.");
    setFont(GLUT_BITMAP_TIMES_ROMAN_24);
    glColor3f(0.7,0,1);  //purple
    drawstring(800.0,410.0,0.0,"ELECTRIC MOTOR:");
    setFont(GLUT_BITMAP_HELVETICA_18);
    glColor3f(0.6, 0.3, 0.1);
    drawstring(830.0,380.0,0.0,"Electric motor is the device which converts Electrical energy");
    drawstring(820.0,360.0,0.0,"to Mechanical energy. In simple way, we give electrical energy");
    drawstring(820.0,340.0,0.0,"to the system and extracts mechanical energy. The mechanical");
    drawstring(820.0,320.0,0.0,"energy output can be used for the movement of load.");
}
void font_d()
{
    setFont(GLUT_BITMAP_HELVETICA_18);
    glColor3f(0,0,0);
    drawstring(500.0,50.0,0.0,"PRESS ENTER FOR VIEWING THE WORKING OF LIFT");
}
void display_working()
{
    lift_background();
    glClearColor(0.9,0.98,0.98,1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    scketch();
    desclift();
    principle();
    font_d();
    glFlush();
}
void font_f()
{
    setFont(GLUT_BITMAP_HELVETICA_18);
    glColor3f(0,1,1);
    drawstring(1000.0,330.0,0.0,"FIRST FLOOR");
}
void font_p()
{
    setFont(GLUT_BITMAP_HELVETICA_18);
    glColor3f(0,1,1);
    drawstring(500.0,710.0,0.0,"PULLEY");
}
void font_g()
{
    setFont(GLUT_BITMAP_HELVETICA_18);
    glColor3f(0,1,1);
    drawstring(1000.0,120.0,0.0,"GROUND FLOOR");
}
void font_s()
{
    setFont(GLUT_BITMAP_HELVETICA_18);
    glColor3f(0,1,1);
    drawstring(1000.0,560.0,0.0,"SECOND FLOOR");
}
void font_load()
{
    setFont(GLUT_BITMAP_HELVETICA_18);
    glColor3f(0,1,1);
    drawstring(300.0,320.0+pr,0.0,"LOAD");
}
void font_lift()
{
    setFont(GLUT_BITMAP_HELVETICA_18);
    glColor3f(1,1,1);
    drawstring(605.0,432.0+yr,0.0,"LIFT");
}
void pulley_lines()
{

    glColor3f(0.8, 0.5, 0.5);                                           //red for pulley strip
    glBegin(GL_POLYGON);                                            //left pulley strip
        glVertex2i(395,710);
        glVertex2i(393,710);
        glVertex2i(393,420+b2);
        glVertex2i(395,420+b2);
    glEnd();
    glBegin(GL_POLYGON);                                            //right pulley strip
        glVertex2i(447,710);
        glVertex2i(449,710);
        glVertex2i(449,420+b4);
        glVertex2i(447,420+b4);
    glEnd();
}
void floor_distinguish()
{
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);                                      //boundary between first and ground floor
        glVertex2i(451,2);
        glVertex2i(1200,2);
    glEnd();
    glBegin(GL_LINES);                                      //boundary between first and second floor
        glVertex2i(451,230);
        glVertex2i(1200,230);
    glEnd();
    glBegin(GL_LINES);                                       //boundary between second and third floor
        glVertex2i(451,460);
        glVertex2i(1200,460);
    glEnd();
    glBegin(GL_LINES);                                        //upper boundary..i,e end of 3rd floor
        glVertex2i(451,690);
        glVertex2i(1200,690);
    glEnd();
}


void lift_box()
{
  glColor3f(0.3,0.3,0.0);
    glBegin(GL_POLYGON);
    usleep(100000);                                    //for trapezoidal like structure above the lift
        glVertex2i(500,420+yr);
        glVertex2i(745,420+yr);
        glVertex2i(700,460+yr);
        glVertex2i(545,460+yr);
    glEnd();
    font_lift();
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_POLYGON);                                                 //for rectangle like structure
        glVertex2i(445,230+yr);
        glVertex2i(800,230+yr);
        glVertex2i(800,420+yr);
        glVertex2i(445,420+yr);
    glEnd();
    glColor3f(0.0,0.5,1.0);                                              //baby blue
    glBegin(GL_POLYGON);                                                //left door
        glVertex2i(500,230+yr);
        glVertex2i(575+50,230+yr);
        glVertex2i(575+50,420+yr);
        glVertex2i(500,420+yr);
    glEnd();
    glBegin(GL_POLYGON);                                               //right door
        glVertex2i(576+50,230+yr);
        glVertex2i(745,230+yr);
        glVertex2i(745,420+yr);
        glVertex2i(576+50,420+yr);
    glEnd();
    glFlush();
}

void load()
{
    glColor3f(0.6, 0.3, 0.1);
    glBegin(GL_POLYGON);
        glVertex2i(250,230+pr);
        glVertex2i(400,230+pr);
        glVertex2i(400,420+pr);
        glVertex2i(250,420+pr);
    glEnd();
    font_load();
}
void pulley()                                                       //function for pulley
{
    glColor3f(0.0,1.0,0.0);
    circle(421,700,27);                                              //first call bigger pulley and then smaller one;
    glColor3f(0.5,0.5,0.5);
    circle(421,700,10);
    font_p();
}

void display_lift()
{
    //glClearColor(0.0,0.0,0.0,1.0);
    //glClear(GL_COLOR_BUFFER_BIT);
    //description_background();
    lift_background();
    floor_distinguish();
    pulley_lines();
    lift_box();
    load();
    pulley();
    pulley_lines();
    font_g();
    font_f();
    font_s();
    glFlush();
}
void mydisplay()
{
    if(flag==0)
        frontscreen();
    if(flag==1)
        helpscreen();
    if(flag==2)
        display_mall();
    if(flag==3)
        display_working();
    if(flag==4)
        display_lift();
    glutSwapBuffers();
}
void mykeyboard( unsigned char key, int x, int y )
{
    int i;
    switch(key)
    {
    case 13:    if(flag==0)
                {
                    flag=1;
                    mydisplay();
                }
                else if(flag==1)
                {
                    flag=2;
                    mydisplay();
                }
                else if(flag==2)
                {
                    flag=3;
                    mydisplay();
                }
                 else if(flag==3)
                {
                    flag=4;
                    mydisplay();
                }
                break;
    case  'g':  if(yr==0)
                {
                    for(i=0;i<230;i++)
                    {

                        yr--;
                        pr++;
                        b2++;
                        b4--;
                        glutPostRedisplay();
                    }
                }
                else if(yr==230||yr==229)
                {
                    for(i=0;i<460;i++)
                    {

                        yr--;
                        pr++;
                        b2++;
                        b4--;
                        glutPostRedisplay();
                    }
                }

                break;
    case '1'   :if(yr==-230||yr==-229)
                {
                    for(i=0;i<230;i++)
                    {
                        yr++;
                        pr--;
                        b2--;
                        b4++;
                        glutPostRedisplay();
                    }
                }
                else if(yr==230||yr==229)
                {
                    for(i=0;i<230;i++)
                    {
                        yr--;
                        pr++;
                        b2++;
                        b4--;
                        glutPostRedisplay();
                    }
                }
                break;
    case    '2' :if(yr==-230||yr==-229)
                {
                    for(i=0;i<460;i++)
                    {
                        //usleep(100);
                        yr++;
                        pr--;
                        b2--;
                        b4++;
                        glutPostRedisplay();
                    }
                }
                else if(yr==0)
                {
                    for(i=0;i<230;i++)
                    {
                        yr++;
                        pr--;
                        b2--;
                        b4++;
                        glutPostRedisplay();
                    }
                }
                break;
    case 27    :exit(0);
    default     :glutPostRedisplay() ;
}
}
void myinit()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,1346.0,0.0,728.0);
}
int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1346,728);
    glutInitWindowPosition(0,0);
    glutCreateWindow("GRAPHICAL SIMULATION OF WORKING OF LIFT");
    glutFullScreen();
    glutDisplayFunc(mydisplay);
    glutKeyboardFunc(mykeyboard);
    myinit();
    glutMainLoop();
}
