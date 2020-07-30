#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float bspd=0.04; // speed


float px=50.0,py=0;// position co-ordinates

float hm=0.0;

int i=0,j=0,sci=2;float scf=1; 

char score[20],slevel[20];


int level=1,lflag=1,wflag=1; //level_flag & welcome_flag init w/ 1

void init(void)
{

    py=40;

glClearColor (0.74902,0.8,0.999,0.0);
glLoadIdentity ();
gluOrtho2D(0.0,200.0,0.0,150.0);
}


void showtext(float x,float y,float z,void *font,char*string)
{

char *c;

glRasterPos3f(x, y,z);        

for(c=string; *c != '\0'; c++)
{
glutBitmapCharacter(font, *c);
}
}
void menumouse(int btn,int state,int x,int y)
{
if(btn==GLUT_RIGHT_BUTTON&&state==GLUT_UP)
    exit(0);




}

void first()
{
glClear(GL_COLOR_BUFFER_BIT);
	    
        glColor3f(0,0,0);
          showtext(35,135,0,GLUT_BITMAP_HELVETICA_18,"JAWAHARLAL NEHRU NATIONAL COLLEGE OF ENGINEERING");
        showtext(55,125,0,GLUT_BITMAP_HELVETICA_18,"DEPARTMENT OF COMPUTER SCIENCE");
	    showtext(110,40,0,GLUT_BITMAP_HELVETICA_18,"Under the Guidence of:");
        showtext(38,100,0,GLUT_BITMAP_HELVETICA_18,"A mini project for Computer Graphics & Visualization Laboratery");
       showtext(120,30,0,GLUT_BITMAP_HELVETICA_18,"Mr Sathyanarayana S ,Assistant Professor");
       showtext(120,20,0,GLUT_BITMAP_HELVETICA_18,"Mrs Sushma R B ,Assistant Professor");
	   
	 glColor3f(1,1,1);
		glBegin(GL_QUADS);
			glVertex2i(70,68);    
			glVertex2i(130,68);
			glVertex2i(130,84);
			glVertex2i(70,84); 
			glEnd();

	    glColor3f(0,0,0);
	    showtext(79,75,0,GLUT_BITMAP_TIMES_ROMAN_24,"'BLACKEY JACK'");
		showtext(55,61,0,GLUT_BITMAP_HELVETICA_18,"[Press 'space bar' to see instructions or 's' to start]");
	    showtext(5,30,0,GLUT_BITMAP_HELVETICA_18,"Submitted by:");
	    showtext(10,20,0,GLUT_BITMAP_HELVETICA_18,"SHARADHI S S");
	    showtext(50,20,0,GLUT_BITMAP_HELVETICA_18,"[4JN17CS083]");
	    showtext(10,10,0,GLUT_BITMAP_HELVETICA_18,"VARSHA R S");
        showtext(50,10,0,GLUT_BITMAP_HELVETICA_18,"[4JN17CS109]");
	    
		glColor3f(1.0,0.0,0.0);
        showtext(160,4,0,GLUT_BITMAP_HELVETICA_18,"[PRESS esc to quit]");
		 glutSwapBuffers();
        glFlush();
}
      void menu()
	  {
        glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(1,1,1);
		glRectf(30,80,30,90);
		glColor3f(0.0f, 0.1f, 0.1f);
        showtext(85,135,0,GLUT_BITMAP_TIMES_ROMAN_24,"INSTRUCTIONS");
	    showtext(25,117,0,GLUT_BITMAP_HELVETICA_18,"THE GAME CONSIST OF 2 BOUNDERIES-TOP AND BOTTOM BOUNDARY.");
	    glRectf(-80,40,-83,44);
	    showtext(25,107,0,GLUT_BITMAP_HELVETICA_18,"BLACKEY WILL BE IN BETWEEN THE BOUNDARY");
	    glRectf(-80,30,-83,34);
	    showtext(25,97,0,GLUT_BITMAP_HELVETICA_18,"BLACKEY JUMPS BY CLICKING LEFT MOUSE BUTTON.");
	    glRectf(-80,20,-83,24);
	    showtext(25,87,0,GLUT_BITMAP_HELVETICA_18,"WITH EACH CLICK BLACKEY MOVES UPWARDS AND COMES BACK");
		glRectf(-80,10,-83,14);
	    showtext(25,77,0,GLUT_BITMAP_HELVETICA_18,"THE BLACKEY HAVE TO PASS THROUGH THE OBSTACLES.");
	    glRectf(-80,0,-83,4);
	    showtext(25,67,0,GLUT_BITMAP_HELVETICA_18,"ON PASSING THE EACH OBSTACLE SCORE INCREASES.");
	    glRectf(-80,-10,-83,-6);
	    showtext(25,57,0,GLUT_BITMAP_HELVETICA_18,"ON SCORING 100 POINTS THE LEVEL INCREASES.");
	    glRectf(-80,-24,-83,-20);
		showtext(25,47,0,GLUT_BITMAP_HELVETICA_18,"AFTER GETTING 1000 SCORE BLACKEY MEETS JACK");
	    showtext(25,37,0,GLUT_BITMAP_HELVETICA_18,"NOW START THE GAME");
	    glRectf(-30,-80,36.5,-60);
	    showtext(70,23,0,GLUT_BITMAP_HELVETICA_18,"[PRESS 's' START THE GAME]");
		glColor3f(1.0,0.0,0.0);
       showtext(160,4,0,GLUT_BITMAP_HELVETICA_18,"[PRESS esc to quit]");

        glutSwapBuffers();
        glFlush();

}


void drawmanblackey()
{
float x2,y2;
x2 = 25,y2=67;
float x3,y3,angle;
double radius0=6;
glColor3f(0.0,0.0,0.0);
glBegin(GL_TRIANGLE_FAN);
glVertex2f(x2,y2);
for (angle=1.0f;angle<361.0f;angle+=0.2)    //head of man
{
    x3 = x2+sin(angle)*radius0;
    y3  = y2+cos(angle)*radius0;
    glVertex2f(x3,y3);
}
  glEnd();


x2 = 25,y2=55;
double radius1=7;
glBegin(GL_TRIANGLE_FAN);
glVertex2f(x2,y2);

for (angle=1.0f;angle<361.0f;angle+=0.2)   //stomach of man
{
    x3 = x2+sin(angle)*radius1;
    y3  = y2+cos(angle)*radius1;
    glVertex2f(x3,y3);
}

glEnd();




	glColor3f(1.0,0.0,0.0);
		    glBegin(GL_QUADS);
			glVertex2i(19.5,68);    //man's band
			glVertex2i(30.9,70);
			glVertex2i(29.3,71.8);
			glVertex2i(20.05,70); 
			glEnd();


             glBegin(GL_TRIANGLES);
			glVertex2i(19.5,68);      //man's band lower leaf
			glVertex2i(20.05,69);
			glVertex2i(17,68);	
		glEnd();



             glBegin(GL_TRIANGLES);
			glVertex2i(19.5,69);      //man's band upper leaf
			glVertex2i(20.05,70);
			glVertex2i(17,70);	
		glEnd();
	


glColor3f( 0.92,0.78,0.62);
		    glBegin(GL_QUADS);
			glVertex2i(23,67.9);
			glVertex2i(23.7,66);     //man's eye part
			glVertex2i(31,66.1);
			glVertex2i(31,69.5);
		glEnd();


glColor3f(0.0,0.0,0.0);
x2 = 25.9,y2=66.8;
	double radius2=0.5;
	glBegin(GL_TRIANGLE_FAN);
glVertex2f(x2,y2);

for (angle=1.0f;angle<361.0f;angle+=0.2)   //left eye of man
{
    x3 = x2+sin(angle)*radius2;
    y3  = y2+cos(angle)*radius2;
    glVertex2f(x3,y3);
}

    glEnd();


	x2 = 29.3,y2=67.3;
	double radius3=0.5;
	glBegin(GL_TRIANGLE_FAN);
glVertex2f(x2,y2);

for (angle=1.0f;angle<361.0f;angle+=0.2)   //right eye of man
{
    x3 = x2+sin(angle)*radius3;
    y3  = y2+cos(angle)*radius3;
    glVertex2f(x3,y3);
}

    glEnd();


glLineWidth(1.0);
glBegin(GL_LINES);
glVertex2f(28.3,67.8);
glVertex2f(30.1,68);   //eyebrows
glVertex2f(24.9,66.9);
glVertex2f(26.7,67.5);

glEnd();



glColor3f( 0.92,0.78,0.62);

glBegin(GL_POLYGON);
			glVertex2i(27,56.5);
			glVertex2i(27.2,59.7);     //right hand
			glVertex2i(24.9,59.7);
			glVertex2i(24.7,54);
			glVertex2i(35,53.5);
			glVertex2i(35,55.5);
            glVertex2i(27,56.5);
glEnd();


glBegin(GL_QUADS);
			glVertex2i(32.5,57);
			glVertex2i(35,57);
			glVertex2i(35,59);    //left hand
			glVertex2i(31.3,59);
glEnd();


glColor3f(0.0,0.0,0.0);

glLineWidth(1.0);
glBegin(GL_LINES);
glVertex2f(33.5,57);
glVertex2f(33.3,59);   //hand lines
glVertex2f(33.3,53.3);
glVertex2f(33.5,55.2);

glEnd();



glBegin(GL_QUADS);
			glVertex2i(21,40);
			glVertex2i(23,40);
			glVertex2i(25,50);    //left leg
			glVertex2i(21,50);
glEnd();


glBegin(GL_QUADS);
			glVertex2i(26,40);
			glVertex2i(28,40);
			glVertex2i(29,50);    //right leg
			glVertex2i(25,50);
glEnd();

glColor3f(0.184314,0.184314,0.309804);
glRectf(21,40,25.5,42);//left foot
glRectf(26,40,30.3,42);//right foot

}

void drawmanjack(void)
{

float x2,y2;
x2 = 25,y2=67;
float x3,y3,angle;
double radius0=6;
glColor3f(1.0,0.0,0.0);
glBegin(GL_TRIANGLE_FAN);
glVertex2f(x2,y2);
for (angle=1.0f;angle<361.0f;angle+=0.2)    //head of man
{
    x3 = x2+sin(angle)*radius0;
    y3  = y2+cos(angle)*radius0;
    glVertex2f(x3,y3);
}
  glEnd();


x2 = 25,y2=55;
double radius1=7;
glBegin(GL_TRIANGLE_FAN);
glVertex2f(x2,y2);

for (angle=1.0f;angle<361.0f;angle+=0.2)   //stomach of man
{
    x3 = x2+sin(angle)*radius1;
    y3  = y2+cos(angle)*radius1;
    glVertex2f(x3,y3);
}

glEnd();




	glColor3f(0.184314,0.184314,0.309804);

		    glBegin(GL_QUADS);
			glVertex2i(19.5,68);    //man's band
			glVertex2i(30.9,70);
			glVertex2i(29.3,71.8);
			glVertex2i(20.05,70); 
			glEnd();

             glBegin(GL_TRIANGLES);
			glVertex2i(19.5,68);      //man's band lower leaf
			glVertex2i(20.05,69);
			glVertex2i(17,68);	
		glEnd();



             glBegin(GL_TRIANGLES);
			glVertex2i(19.5,69);      //man's band upper leaf
			glVertex2i(20.05,70);
			glVertex2i(17,70);	
		glEnd();
	


glColor3f( 0.92,0.78,0.62);
		    glBegin(GL_QUADS);
			glVertex2i(23,67.9);
			glVertex2i(23.7,66);     //man's eye part
			glVertex2i(31,66.1);
			glVertex2i(31,69.5);
		glEnd();


glColor3f(0.0,0.0,0.0);
x2 = 25.9,y2=66.8;
	double radius2=0.5;
	glBegin(GL_TRIANGLE_FAN);
glVertex2f(x2,y2);

for (angle=1.0f;angle<361.0f;angle+=0.2)   //left eye of man
{
    x3 = x2+sin(angle)*radius2;
    y3  = y2+cos(angle)*radius2;
    glVertex2f(x3,y3);
}

    glEnd();


	x2 = 29.3,y2=67.3;
	double radius3=0.5;
	glBegin(GL_TRIANGLE_FAN);
glVertex2f(x2,y2);

for (angle=1.0f;angle<361.0f;angle+=0.2)   //right eye of man
{
    x3 = x2+sin(angle)*radius3;
    y3  = y2+cos(angle)*radius3;
    glVertex2f(x3,y3);
}

    glEnd();


glLineWidth(6.0);
glBegin(GL_LINES);
glVertex2f(28.3,67.8);
glVertex2f(30.1,68);   //eyebrows
glVertex2f(24.9,66.9);
glVertex2f(26.7,67.5);

glEnd();



glColor3f( 0.92,0.78,0.62);

glBegin(GL_POLYGON);
			glVertex2i(27,56.5);
			glVertex2i(27.2,59.7);     //right hand
			glVertex2i(24.9,59.7);
			glVertex2i(24.7,54);
			glVertex2i(35,53.5);
			glVertex2i(35,55.5);
            glVertex2i(27,56.5);
glEnd();


glBegin(GL_QUADS);
			glVertex2i(32.5,57);
			glVertex2i(35,57);
			glVertex2i(35,59);    //left hand
			glVertex2i(31.3,59);
glEnd();


glColor3f(0.0,0.0,0.0);

glLineWidth(6.0);
glBegin(GL_LINES);
glVertex2f(33.5,57);
glVertex2f(33.3,59);   //hand lines
glVertex2f(33.3,53.3);
glVertex2f(33.5,55.2);

glEnd();

glColor3f(1.0,0.0,0.0);

glBegin(GL_QUADS);
			glVertex2i(21,40);
			glVertex2i(23,40);
			glVertex2i(25,50);    //left leg
			glVertex2i(21,50);
glEnd();


glBegin(GL_QUADS);
			glVertex2i(26,40);
			glVertex2i(28,40);
			glVertex2i(29,50);    //right leg
			glVertex2i(25,50);
glEnd();

glColor3f(0.184314,0.184314,0.309804);
glRectf(21,40,25.5,42);//left foot
glRectf(26,40,30.3,42);//right foot

}



                        /********man ends here******/
void gameover()
{
glClearColor (0.74902,0.8,0.999,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
glRectf(0.0,0.0,200.0,200.0);
glColor3f(1.0,1.0,1.0);
showtext(90,100,0,GLUT_BITMAP_HELVETICA_18,"GAME OVER!!!");
showtext(80,58,0,GLUT_BITMAP_TIMES_ROMAN_24,"YOU SCORED:");
showtext(120,58,0,GLUT_BITMAP_TIMES_ROMAN_24,score);
glColor3f(1.0,0.0,0.0);
showtext(150,30,0,GLUT_BITMAP_HELVETICA_18,"Press esc to exit");
glColor3f(0.0,0.0,0.0);
glutSwapBuffers();
glFlush();
	
}
void display()
{

	
if(((int)px==14||(int)px==6||(int)px==8) &&(int)py<=42+(int)hm  &&  (int)py+20>=42+(int)hm
|| ((int)px==-4) && (int)py<40+(int)hm)

{
glutMouseFunc(menumouse);	
gameover();
	

}
else if(level>10)
{
	
	glClearColor (0.74902,0.8,0.999,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	
glRectf(0.0,0.0,200.0,200.0);
glColor3f(1.0,1.0,1.0);
showtext(15,100,0,GLUT_BITMAP_TIMES_ROMAN_24,"YOU COMPLETED THE GAME AND FOUND JACK SUCCESSFULLY!!!");
showtext(75,58,0,GLUT_BITMAP_TIMES_ROMAN_24,"YOU SCORED:");
showtext(112,58,0,GLUT_BITMAP_TIMES_ROMAN_24,score);
showtext(150,30,0,GLUT_BITMAP_HELVETICA_18,"Press esc to exit");

drawmanjack();
glutSwapBuffers();
glFlush();
 
}
else
{
	glClear(GL_COLOR_BUFFER_BIT);
//on every increase by 100 in score in each level
if(sci%100==0&&lflag==1)
{
lflag=0;
                     //make level_flag=0
level++;//increase level by 1
bspd+=0.02;//increase block_dx_speed by 0.02

}


//within every level make level_flag=1
else if(sci%50!=0&&lflag!=1)
{
lflag=1;
}

glPushMatrix();

          glColor3f(1.0,0.25,0.0);
		  glRectf(0,130,200,150);//upper
	
		  glBegin(GL_QUADS);    //lower rect
		  glVertex2i(0,20);
		  glVertex2i(200,20);
		  glVertex2i(200,40);
	        glVertex2i(0,40);
			glEnd();
glColor3f(0.184314,0.184314,0.309804);                                     
glRectf(0,0,200,20);       //level and distance rectangle
glColor3f(1.0,1.0,1.0);   //score
showtext(1,6,0,GLUT_BITMAP_TIMES_ROMAN_24,"Distance:");

sprintf(slevel,"%d",level);   //level is stored in level variable and printed ,slevel->pointer
showtext(85,6,0,GLUT_BITMAP_TIMES_ROMAN_24,"Score:");

showtext(159,6,0,GLUT_BITMAP_TIMES_ROMAN_24,"Level:");
showtext(175,6,0,GLUT_BITMAP_TIMES_ROMAN_24,slevel);

scf+=0.025;              
sci=(int)scf;
sprintf(score,"%d",sci);


showtext(25,6,0,GLUT_BITMAP_TIMES_ROMAN_24,score);
showtext(102,6,0,GLUT_BITMAP_TIMES_ROMAN_24,score);


glTranslatef(0.0,hm,0.0);//man's translation up and down


drawmanblackey();



if(px<-10)
{

px=70;            
py=40;

}

else
px-=bspd;

glColor3f(0.0,0.0,0.0);
glTranslatef(px,-hm,0.0);

glBegin(GL_TRIANGLES);    //obstacle triangle
		  glVertex2i(px,py);
		  glVertex2i(px+5,py+20);
		  glVertex2i(px+10,py);
		  glEnd();
		  glPopMatrix();
glPushMatrix();
glTranslatef(px+35,0.0,0.0);
		  	
          glColor3f(0.0,0.0,0.0);
		  glBegin(GL_TRIANGLES);    //obstacle triangle
		  glVertex2i(px,py+90);
		  glVertex2i(px+5,py+70);
		  glVertex2i(px+10,py+90);
		  glEnd(); 


glutPostRedisplay();
glPopMatrix();

glutSwapBuffers();
glFlush();

}

}

void moveHeliU(void)
{
hm+=0.15;
glutPostRedisplay();

}

void moveHeliD(void)
{
hm-=0.15;
glutPostRedisplay();
}


void mouse(int button, int state, int x, int y)
{
switch (button)
{
case GLUT_LEFT_BUTTON:

if(state == GLUT_DOWN)
{for(i=0;i<300;i++)
      moveHeliU();
	}

else
{   
     for(j=0;j<300;j++)
      moveHeliD();
}
  break;
default: break;
}
}
void keys(unsigned char key,int x,int y) //function to handle "normal" key presses
{
	   switch(key)
	  {
        
		case 27:exit(0);
break;
	}
}

void mykey(unsigned char key,int x,int y) //function to handle "normal" key presses
{
	   switch(key)
	  {
		case 32:glutDisplayFunc(menu);   //ASCII value of space bar
				init();
				glutPostRedisplay();
	 	        break;
        
		case 27:exit(0);

		case 115:glutDisplayFunc(display);   //ASCII value of 's'
	            init();
				glutPostRedisplay();
				glutKeyboardFunc(keys);
	 	        break;
	}
}





void main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
    glutInitWindowSize(900,700);   
    glutInitWindowPosition(0,0);
    glutCreateWindow("Blackey jack");
	init();	
	glutDisplayFunc(first);
	glutKeyboardFunc(mykey);
    glutMouseFunc(mouse); 
    glEnable(GL_LINE_SMOOTH); 
    glutMainLoop();
}
