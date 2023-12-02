#include <iostream>
#include "Ceu.hpp"

using namespace std;
float angle = 0.0f;

bool dia = true;
float posCarros = 0;
GLfloat r;
GLfloat g;
GLfloat b;

void init(void)
{
    glClearColor(r, g, b, 1.0f);
    glOrtho(-100,100,-100,100, -100, 100);
    
    glEnable(GL_BLEND);    //Ativar o alpha do glColor
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);//Ativa pixels aritméticos
}

/**
 * Desenha a grama na parte de baixo da imagem
 */
void DesenhaGrama(){
	glPushMatrix();

	glBegin ( GL_QUADS );
	    glColor3ub  ( 0, 255, 0) ;
		glVertex2f (-100, -100 ) ;
		glVertex2f (-100, -80 ) ;
		glVertex2f (100, -80 ) ;
	    glVertex2f (100, -100 ) ;    
	glEnd ();

	glPopMatrix();
}

/**
 * Desenha a estrada
 */
void DesenhaEstrada(){
	glPushMatrix();

	glBegin ( GL_QUADS );
	    glColor3ub  ( 1, 50, 32) ;
		glVertex3f (-100, -80, 0);
		glVertex3f (-100, -50, 0 );
		glVertex3f (100, -50, 0 );
	    glVertex3f (100, -80, 0 );    
	glEnd ();
	
	glBegin ( GL_QUADS );
	    glColor3ub  ( 238, 210, 2) ;
		glVertex3f (-100, -70, 0);
		glVertex3f (-100, -68, 0 );
		glVertex3f (100, -68, 0 );
	    glVertex3f (100, -70, 0 );    
	glEnd ();

	glPopMatrix();
}

/**
 * Desenha uma montanha com um tamanho fixo
 */
void DesenhaUmaMontanha(){
	glBegin(GL_TRIANGLES );
		glColor3ub  ( 0, 255, 0) ;
		glVertex3f (-120, -50, 0);
		glVertex3f (-10, -50, 0);
		glVertex3f (-65, 0, 0);
	glEnd();
}

/**
 * Desenha 3 montanhas chamando a funcao de desenhar uma montanha e fazendo
 * rotacao, translacao ou alterando a escala para cada uma
 */
void DesenhaMontanhas(){
	glPushMatrix();
		DesenhaUmaMontanha();
	glPopMatrix();
	
	glPushMatrix();
		glScalef(1.7, 1.7, 0);
		glTranslatef(60, 16, 0);
		DesenhaUmaMontanha();
	glPopMatrix();
	
	
	glPushMatrix();
		glScalef(0.8, 0.8, 0);
		glTranslatef(150, -12, 0);
		glRotatef(5, 0, 0, 1);
		DesenhaUmaMontanha();
	glPopMatrix();
}


void Carro(float x, float y){
    // Desenha o corpo do carro
    glColor3f(0.0f, 0.0f, 1.0f); // Azul
    glBegin(GL_POLYGON);
    glVertex2f(x, y);          // Canto inferior esquerdo
    glVertex2f(x + 20.0, y);          // Canto inferior direito
    glVertex2f(x + 20.0, y + 10);    // Canto medio direito
    glVertex2f(x + 15, y + 10);    // Canto superior medio direito
    glVertex2f(x + 15, y + 15);     // Canto superior direito 
    glVertex2f(x + 5, y + 15);     // Canto superior esquerdo
    glVertex2f(x, y + 10);    // Canto medio esquerdo
    glEnd();

    //Contorno do carro
    glColor3f(0.0f, 0.0f, 0.0f); // Preto
    glLineWidth(3.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(x, y);          // Canto inferior esquerdo
    glVertex2f(x + 20, y);          // Canto inferior direito
    glVertex2f(x + 20, y + 10);    // Canto medio direito
    glVertex2f(x + 15, y + 10);    // Canto superior medio direito
    glVertex2f(x + 15, y + 15);     // Canto superior direito
    glVertex2f(x + 5, y + 15);     // Canto superior esquerdo
    glVertex2f(x, y + 10);    // Canto medio esquerdo
    glEnd();

    Circulo(2, x + 5, y, 0, 0, 0);
    Circulo(2, x + 15, y, 0, 0, 0);


    Circulo(1, x + 5, y, 1, 1, 1);
    Circulo(1, x + 15, y, 1, 1, 1);

    Circulo(1, x + 19, y + 8, 255, 255, 255);
}

void Carros(){
	glPushMatrix();
		glTranslatef(-5 + posCarros, 0, 0);
		Carro(-150, -68);
		
		Carro(-100, -68);
	glPopMatrix();
	posCarros += 1;
	if(posCarros > 270)
		posCarros = 0;
}

/**
 * Desenha um fundo azul em toda a tela
 */	
void MudaCorCeu(char c){
	if(c == 'd'){
 		r = 0.678;
		g = 0.847;
		b = 0.902;
	} else if(c == 'n'){
		r = 0.043;
		g = 0.043;
		b = 0.271;
	}
	glClearColor(r, g, b, 1.0f);
}

void DesenhaPasCatavento(int x, int y){
	float x1 = x;
    float y1 = y;
        
    float x2 = x + 10;
    float y2 = y + 4;

    float x3 = x + 30;
    float y3 = y;
        
    float x4 = x + 10;
    float y4 = y - 4;

	glPushMatrix();
		glTranslatef(x, y, 0.0);
		
		glRotatef(angle, 0, 0, 1);
		glTranslatef(-x, -y, 0.0);
	    glBegin( GL_QUADS );
    		glColor4ub(0, 0, 0, 132);

    		glVertex3f(x1, y1, 1.0);
    		glVertex3f(x2, y2, 1.0);
    		glVertex3f(x3, y3, 1.0);
    		glVertex3f(x4, y4, 1.0);
    	glEnd();
	glPopMatrix();
	
	
	x1 = x;
    y1 = y;
        
    x2 = x - 10;
    y2 = y - 4;

    x3 = x - 30;
    y3 = y;
        
    x4 = x - 10;
    y4 = y + 4;

	glPushMatrix();
		glTranslatef(x, y, 0.0);
		
		glRotatef(angle, 0, 0, 1);
		glTranslatef(-x, -y, 0.0);
	    glBegin( GL_QUADS );
    		glColor4ub(0, 0, 0, 132);

    		glVertex3f(x1, y1, -1.0);
    		glVertex3f(x2, y2, -1.0);
    		glVertex3f(x3, y3, -1.0);
    		glVertex3f(x4, y4, -1.0);
    	glEnd();
	glPopMatrix();
	
	x1 = x;
    y1 = y;
        
    x2 = x + 4;
    y2 = y + 10;

    x3 = x;
    y3 = y + 30;
        
    x4 = x - 4;
    y4 = y + 10;

	glPushMatrix();
		glTranslatef(x, y, 0.0);
		
		glRotatef(angle, 0, 0, 1);
		glTranslatef(-x, -y, 0.0);
	    glBegin( GL_QUADS );
    		glColor4ub(0, 0, 0, 132);

    		glVertex3f(x1, y1, -1.0);
    		glVertex3f(x2, y2, -1.0);
    		glVertex3f(x3, y3, -1.0);
    		glVertex3f(x4, y4, -1.0);
    	glEnd();
	glPopMatrix();

	x1 = x;
    y1 = y;
        
    x2 = x - 4;
    y2 = y - 10;

    x3 = x;
    y3 = y - 30;
        
    x4 = x + 4;
    y4 = y - 10;

	glPushMatrix();
		glTranslatef(x, y, 0.0);
		
		glRotatef(angle, 0, 0, 1);
		glTranslatef(-x, -y, 0.0);
	    glBegin( GL_QUADS );
    		glColor4ub(0, 0, 0, 132);

    		glVertex3f(x1, y1, 1.0);
    		glVertex3f(x2, y2, 1.0);
    		glVertex3f(x3, y3, 1.0);
    		glVertex3f(x4, y4, 1.0);
    	glEnd();
	glPopMatrix();
}

void DesenhaUmCatavento(){
	glBegin ( GL_QUADS );
	    glColor3ub  ( 0, 0, 0) ;
		glVertex2f (-80, -20 ) ;
		glVertex2f (-78, -20 ) ;
		glVertex2f (-78, 40 ) ;
		glVertex2f (-80, 40 ) ;
	glEnd ();
	
	DesenhaPasCatavento(-79, 40);
}

void DesenhaCataventos(){
	glPushMatrix();
		DesenhaUmCatavento();
	glPopMatrix();
	
	glPushMatrix();
		glScalef(0.8, 0.8, 0);
		glTranslatef(30, 16, 0);
		DesenhaUmCatavento();
	glPopMatrix();
	
	
	glPushMatrix();
		glScalef(1.1, 1.1, 0);
		glTranslatef(100, -5, 0);
		DesenhaUmCatavento();
	glPopMatrix();
}

void MudaParaDia(){
	MudaCorCeu('d');
	Sol();
	Nuvens();
}

void MudaParaNoite(){
	MudaCorCeu('n');
	Lua();
	Estrela(-50, 60, 5);
}

void Menu(int value){
	switch ( value )
	{
		case 0:
			dia = !dia;
			break;
		case 1:
			exit(0);
			break;
	}
}

void CriaMenu(){
	int menu;
	    
    menu = glutCreateMenu(Menu);
    glutAddMenuEntry("Dia/Noite", 0);
    glutAddMenuEntry("Sair", 1);
    
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void display( void )
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	if(dia){
		MudaParaDia();
	} else {
		MudaParaNoite();
	}
	
	DesenhaGrama();
	
	DesenhaMontanhas();
	DesenhaEstrada();
	
	DesenhaCataventos();
	Carros();
	glutSwapBuffers();
	glutPostRedisplay();
	
	angle += 0.2;
}

void keyboard ( unsigned char key, int x, int y )
{
	switch ( key )
	{
		case 'd':
			dia = true;
			break;
		case 'n':
			dia = false;
			break;
		case 27:
			exit(0);
			break;
		default:
			break;
	}
	glutPostRedisplay();	//atualizar informação da janela
}

// Função callback chamada para gerenciar eventos do mouse
void GerenciaMouse(int button, int state, int x, int y)
{        
    if (button == GLUT_RIGHT_BUTTON)
         if (state == GLUT_DOWN) 
            CriaMenu();
         
    glutPostRedisplay();
}


int  main ( int argc, char** argv )
{
    glutInit ( &argc, argv );	//Usada apra iniciar o ambiente Glut
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB );
    glutInitWindowPosition (1,1);
    glutInitWindowSize ( 650, 500);
    glutCreateWindow ("Trabalho Final");
    init();
    glutDisplayFunc (display);
    glutKeyboardFunc (keyboard);
    glutMouseFunc(GerenciaMouse); 
    glutMainLoop ( );
    return 0;
}



