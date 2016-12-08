#include <Game.h>

bool flip = false;
int current = 1;

Game::Game() : window(VideoMode(800, 600), "OpenGL Cube")
{
}

Game::~Game() {}

MyVector3 corner1 = MyVector3(1.0f, 1.0f, -5.0f);
MyVector3 corner2 = MyVector3(-1.0f, 1.0f, -5.0f);
MyVector3 corner3 = MyVector3(-1.0f, -1.0f, -5.0f);
MyVector3 corner4 = MyVector3(1.0f, -1.0f, -5.0f);
MyVector3 corner5 = MyVector3(1.0f, 1.0f, -15.0f);
MyVector3 corner6 = MyVector3(-1.0f, 1.0f, -15.0f);
MyVector3 corner7 = MyVector3(-1.0f, -1.0f, -15.0f);
MyVector3 corner8 = MyVector3(1.0f, -1.0f, -15.0f);
////Back Face
//float vertices[] = { corner1.getX(), corner1.getY(), corner1.getZ(), corner2.getX(), corner2.getY(), corner2.getZ(), corner3.getX(), corner3.getY(), corner3.getZ() };
//float vertices2[] = { corner1.getX(), corner1.getY(), corner1.getZ(), corner4.getX(), corner4.getY(), corner4.getZ() , corner3.getX(), corner3.getY(), corner3.getZ() };
//
////Front Face
//float vertices3[] = { corner5.getX(), corner5.getY(), corner5.getZ(), corner6.getX(), corner6.getY(), corner6.getZ(), corner7.getX(), corner7.getY(), corner7.getZ() };
//float vertices4[] = { corner5.getX(), corner5.getY(), corner5.getZ(), corner8.getX(), corner8.getY(), corner8.getZ(), corner7.getX(), corner7.getY(), corner7.getZ() };
//
////Top Face
//float vertices5[] = { corner6.getX(), corner6.getY(), corner6.getZ(), corner5.getX(), corner5.getY(), corner5.getZ(), corner1.getX(), corner1.getY(), corner1.getZ() };
//float vertices6[] = { corner6.getX(), corner6.getY(), corner6.getZ(), corner2.getX(), corner2.getY(), corner2.getZ(), corner1.getX(), corner1.getY(), corner1.getZ() };
//
////Bottom Face
//float vertices7[] = { corner3.getX(), corner3.getY(), corner3.getZ(), corner4.getX(), corner4.getY(), corner4.getZ(), corner8.getX(), corner8.getY(), corner8.getZ() };
//float vertices8[] = { corner3.getX(), corner3.getY(), corner3.getZ(), corner7.getX(), corner7.getY(), corner7.getZ(), corner8.getX(), corner8.getY(), corner8.getZ() };
//
////Left Face
//float vertices9[] = { corner2.getX(), corner2.getY(), corner2.getZ(), corner6.getX(), corner6.getY(), corner6.getZ(), corner7.getX(), corner7.getY(), corner7.getZ() };
//float vertices10[] = { corner2.getX(), corner2.getY(), corner2.getZ(), corner3.getX(), corner3.getY(), corner3.getZ(), corner7.getX(), corner7.getY(), corner7.getZ() };
//
////Right Face
//float vertices11[] = { corner1.getX(), corner1.getY(), corner1.getZ(), corner5.getX(), corner5.getY(), corner5.getZ(), corner8.getX(), corner8.getY(), corner8.getZ() };
//float vertices12[] = { corner1.getX(), corner1.getY(), corner1.getZ(), corner4.getX(), corner4.getY(), corner4.getZ(), corner8.getX(), corner8.getY(), corner8.getZ() };

float colors[] = { 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f };
unsigned int vertex_index[] = { 0, 1, 2 };

void Game::run()
{

	initialize();

	Event event;

	while (isRunning) {

		cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		render();
	}

}

void Game::initialize()
{
	isRunning = true;
	
	//glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
	scale = scale.scale(99.9f, 99.9f);
	rot = rot.rotationZ(rotationAngle);
	translate = translate.translateX(0.0001f, 0.00011f);
	mold = rot * translate * scale;
}

void Game::update()
{
	elapsed = clock.getElapsedTime();

	

	corner1 = mold * corner1;
	corner2 = mold * corner2;
	corner3 = mold * corner3;
	corner4 = mold * corner4;
	corner5 = mold * corner5;
	corner6 = mold * corner6;
	corner7 = mold * corner7;
	corner8 = mold * corner8;

	cout << "Update up" << endl;
}

void Game::render()
{
	cout << "Drawing" << endl;

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);


	glColorPointer(3, GL_FLOAT, 0, &colors);

	//Back Face
	float vertices[] =  { corner1.getX(), corner1.getY(), corner1.getZ(), corner2.getX(), corner2.getY(), corner2.getZ(), corner3.getX(), corner3.getY(), corner3.getZ() };
	float vertices2[] = { corner1.getX(), corner1.getY(), corner1.getZ(), corner4.getX(), corner4.getY(), corner4.getZ() , corner3.getX(), corner3.getY(), corner3.getZ() };
	
	//Front Face
	float vertices3[] = { corner5.getX(), corner5.getY(), corner5.getZ(), corner6.getX(), corner6.getY(), corner6.getZ(), corner7.getX(), corner7.getY(), corner7.getZ() };
	float vertices4[] = { corner5.getX(), corner5.getY(), corner5.getZ(), corner8.getX(), corner8.getY(), corner8.getZ(), corner7.getX(), corner7.getY(), corner7.getZ() };
	
	//Top Face
	float vertices5[] = { corner6.getX(), corner6.getY(), corner6.getZ(), corner5.getX(), corner5.getY(), corner5.getZ(), corner1.getX(), corner1.getY(), corner1.getZ() };
	float vertices6[] = { corner6.getX(), corner6.getY(), corner6.getZ(), corner2.getX(), corner2.getY(), corner2.getZ(), corner1.getX(), corner1.getY(), corner1.getZ() };
	
	//Bottom Face
	float vertices7[] = { corner3.getX(), corner3.getY(), corner3.getZ(), corner4.getX(), corner4.getY(), corner4.getZ(), corner8.getX(), corner8.getY(), corner8.getZ() };
	float vertices8[] = { corner3.getX(), corner3.getY(), corner3.getZ(), corner7.getX(), corner7.getY(), corner7.getZ(), corner8.getX(), corner8.getY(), corner8.getZ() };
	
	//Left Face
	float vertices9[] = { corner2.getX(), corner2.getY(), corner2.getZ(), corner6.getX(), corner6.getY(), corner6.getZ(), corner7.getX(), corner7.getY(), corner7.getZ() };
	float vertices10[] = { corner2.getX(), corner2.getY(), corner2.getZ(), corner3.getX(), corner3.getY(), corner3.getZ(), corner7.getX(), corner7.getY(), corner7.getZ() };
	
	//Right Face
	float vertices11[] = { corner1.getX(), corner1.getY(), corner1.getZ(), corner5.getX(), corner5.getY(), corner5.getZ(), corner8.getX(), corner8.getY(), corner8.getZ() };
	float vertices12[] = { corner1.getX(), corner1.getY(), corner1.getZ(), corner4.getX(), corner4.getY(), corner4.getZ(), corner8.getX(), corner8.getY(), corner8.getZ() };
	

	//glDrawArrays(GL_TRIANGLES, 0, 3);

	//Back Face
	glVertexPointer(3, GL_FLOAT, 0, &vertices);
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, &vertex_index);
	
	glVertexPointer(3, GL_FLOAT, 0, &vertices2);
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, &vertex_index);

	//Front Face
	glVertexPointer(3, GL_FLOAT, 0, &vertices3);
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, &vertex_index);

	glVertexPointer(3, GL_FLOAT, 0, &vertices4);
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, &vertex_index);

	//Top Face
	glVertexPointer(3, GL_FLOAT, 0, &vertices5);
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, &vertex_index);

	glVertexPointer(3, GL_FLOAT, 0, &vertices6);
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, &vertex_index);

	//Bottom Face
	glVertexPointer(3, GL_FLOAT, 0, &vertices7);
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, &vertex_index);

	glVertexPointer(3, GL_FLOAT, 0, &vertices8);
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, &vertex_index);

	//Left Face
	glVertexPointer(3, GL_FLOAT, 0, &vertices9);
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, &vertex_index);

	glVertexPointer(3, GL_FLOAT, 0, &vertices10);
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, &vertex_index);

	//Right Face
	glVertexPointer(3, GL_FLOAT, 0, &vertices11);
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, &vertex_index);

	glVertexPointer(3, GL_FLOAT, 0, &vertices12);
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, &vertex_index);

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);

	window.display();

}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}

