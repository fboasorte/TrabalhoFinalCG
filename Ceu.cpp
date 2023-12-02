#include "Ceu.hpp"

float angleSun = 0.0;

void Circulo(int raio, int x, int y, GLubyte r, GLubyte g, GLubyte b){
	glBegin(GL_POLYGON );
		glColor3ub(r, g, b);
		for(int i = 0; i <= 40; i++){
			glVertex3f(x + (float)(raio*sin((i/40.0)*6.28)), y + (float)(raio*cos((i/40.0)*6.28)),0.0 );
		}
			
	glEnd();
}

void RaiosSol(int raio, int x, int y, GLubyte r, GLubyte g, GLubyte b){

    glBegin(GL_LINES);
    glColor3ub(r, g, b);
    for (int i = 0; i <= 12; i++) // 12 raios
    {
        float rayAngle = angleSun + i * (360.0 / 12);
        float rayLength = 2.0 * raio;  // comprimento dos raios

        float x1 = x + (float)(raio * sin(rayAngle * M_PI / 180.0));
        float y1 = y + (float)(raio * cos(rayAngle * M_PI / 180.0));

        float x2 = x + (float)(rayLength * sin(rayAngle * M_PI / 180.0));
        float y2 = y + (float)(rayLength * cos(rayAngle * M_PI / 180.0));

        glVertex3f(x1, y1, 0.0);
        glVertex3f(x2, y2, 0.0);
    }
    glEnd();
}

/**
 * Desenha um sol no ceu com raios girando ao seu redor
 */	
void Sol(){
	glPushMatrix();
	
	int raio = 10;
	int x = 60;
	int y = 60;
	GLubyte r = 255;
	GLubyte g = 165;
	GLubyte b = 0;
	
	Circulo(raio, x, y, r, g, b);
	RaiosSol(raio, x, y, r, g, b);

    angleSun += 0.1;
    
    glPopMatrix();
}

void Lua(){
	int raio = 10;
	int x = 60;
	int y = 60;
	GLubyte r = 238;
	GLubyte g = 210;
	GLubyte b = 2;
	
	Circulo(raio, x, y, r, g, b);
}

void Nuvem(){
	int raio = 5;

	float x = -60;
	float y = 60;
	GLubyte r = 255;
	GLubyte g = 255;
	GLubyte b = 255;
	
	Circulo(raio, x, y, r, g, b);
	

	x = -55;
	y = 60;
	Circulo(raio, x, y, r, g, b);
	
	x = -53;
	y = 64;
	Circulo(raio, x, y, r, g, b);
}

void Nuvens(){
	glPushMatrix();
		Nuvem();
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(50, -15, 0);
		glRotatef(15, 0, 0, 1);
		Nuvem();
	glPopMatrix();
}

void Estrela(float x, float y, float radius) {
    const float angle = M_PI / 5.0f; // ?ngulo entre os raios da estrela

    glColor3ub(255, 255, 255); // Branco
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // Centro da estrela

    for (int i = 0; i < 10; ++i) {
        float currentAngle = i * 2.0f * angle;
        float xPos = x + radius * cos(currentAngle);
        float yPos = y + radius * sin(currentAngle);
        glVertex2f(xPos, yPos);

        currentAngle += angle;
        xPos = x + (radius / 2.0f) * cos(currentAngle);
        yPos = y + (radius / 2.0f) * sin(currentAngle);
        glVertex2f(xPos, yPos);
    }

    glEnd();
}

