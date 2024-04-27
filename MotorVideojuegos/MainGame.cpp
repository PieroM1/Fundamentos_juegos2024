#include "MainGame.h"
#include "Sprite.h"

#include <cstdlib>
#include <ctime>
#include <list>

using namespace std;

void MainGame::init()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("GAAA", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
	//es validar si hubo error
	SDL_GLContext glContext = SDL_GL_CreateContext(window);
	GLenum error = glewInit();
	if (error != GLEW_OK) {
		//falta validar el estado del glew
	}
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	initShaders();
}

void MainGame::initShaders()
{
	program.compileShaders("Shaders/colorShaderVert.txt", "Shaders/colorShaderFrag.txt");
	program.addAtribute("vertexPosition");
	program.addAtribute("vertexColor");
	program.linkShader();
}

MainGame::MainGame()
{
	window = nullptr;
	width = 1920;
	height = 1080;
	gameState = GameState::PLAY;

}

void MainGame::draw()
{
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	program.use();

	GLuint timeLocation = program.getUniformLocation("time");
	glUniform1f(timeLocation, time);
	time += 0.020;

	//spriteAdd();
	//spritesDraw();

	sprite.draw();
	program.unuse();
	SDL_GL_SwapWindow(window);
}

void MainGame::run()
{
	init();
	sprite.init( randomCoordinated(), randomCoordinated(), 0.20, 0.20);///
	update();

}


void MainGame::update()
{
	
	while (gameState != GameState::EXIT) {
		processInput();
		//spritesDraw();
		draw();
	}

}


float MainGame::randomCoordinated()
{
	float random_num = (float)rand();
	random_num /= RAND_MAX;
	random_num = random_num * 2.0 - 1.0;
	return random_num;
}

void MainGame::spriteAdd()
{
	Sprite newSprite;
	newSprite.init(randomCoordinated(), randomCoordinated(), 0.20, 0.20);
	sprites.push_back(newSprite);
	
}

void MainGame::spritesDraw()
{
	for (Sprite sprite: sprites) {
		sprite.draw();
	}
}


void MainGame::processInput()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type)
		{
		case SDL_QUIT:
			gameState = GameState::EXIT;
			break;

		case SDL_MOUSEMOTION:
			cout << "Posicion en X" << event.motion.x << " Position en Y" << event.motion.y << endl;
			break;
	
		}
	}
}



MainGame::~MainGame()
{
}

