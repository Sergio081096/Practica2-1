//Semestre 2018-1
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************	Cano Olguin Luis Sergio ******//
//*************	Version de trabajo Visual 2012 ******//
//************************************************************//
#include "Main.h"
void InitGL ( GLvoid )     // Inicializamos parametros
{
	//glShadeModel(GL_FLAT);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	//glClearDepth(1.0f);									// Configuramos Depth Buffer
	//glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	//glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	
	
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();									// Reinicializamos la actual matriz Modelview

	//Poner aqui codigo ha dibujar
	//glPointSize(10.0);//tama�o del punto
	glBegin(GL_LINE_LOOP);//pluar,puntos(GL_POINTS), lineas(GL_LINES), todos unicdos(GL_LINE_LOOP),triangulos(GL_TRIANGLES),poligono(GL_POLYGON)
	glColor3f(1.0,0.0,0.0);//desde aqui empieza el color y continua hasta que encuentre otro color
	glVertex3f(-9.0, 1.0, -1.2);//1  3 ejes de coordenadas ---flotantes
	glVertex3f(-9.0, 9.0, -1.2);//2
	glVertex3f(-3.0, 9.0, -1.2);//3
	glVertex3f(-3.0, 7.0, -1.2);//4
	glVertex3f(-7.0, 7.0, -1.2);//5/*	
	glVertex3f(-7.0, 3.0, -1.2);//6
	glVertex3f(-3.0, 3.0, -1.2);//7
	glVertex3f(-3.0, 1.0, -1.2);//8
	glEnd();//termina
	glFlush();
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
	if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Ortogonal
	glOrtho(-20,20,-20,20,0.1,2);//dimenciones
	//horizontal, vertical,---

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();									
}

// Termina la ejecucion del programa cuando se presiona ESC
void keyboard(unsigned char key, int x, int y)
{
	 switch (key) 
	 {
		case 27: exit(0);
				 break;
	 }
	  glutPostRedisplay();
}    

int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
  glutInitWindowSize  (500, 500);	// Tama�o de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 2"); // Nombre de la Ventana
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut funci�n de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut funci�n en caso de cambio de tamano
  glutKeyboardFunc	  (keyboard);	//Indicamos a Glut funci�n de manejo de teclado
  glutMainLoop        ( );          // 

  return 0;
}
