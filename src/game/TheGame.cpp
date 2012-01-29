#include "TheGame.h"
#include <iostream>
#include <SDL/SDL_video.h>

TheGame::TheGame()
		: world(NULL), view(NULL), controller(NULL), isRunning(false) {
	SDL_Init(SDL_INIT_EVERYTHING);

	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;
	const int SCREEN_BPP = 32;
//	const int OFFSET_IN_PIXELS = 6;
//	const int KEY_REPEAT_DELAY = SDL_DEFAULT_REPEAT_DELAY;
//	const int KEY_REPEAT_INTERVAL = SDL_DEFAULT_REPEAT_INTERVAL;

	SDL_Surface* screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE | SDL_DOUBLEBUF);
	SDL_Flip(screen);
}

TheGame::~TheGame() {
	SDL_Quit();
}

void TheGame::start() {
	if (NULL == world || NULL == controller || NULL == view) {
		return;
	}
	SDL_Event event;
	isRunning = true;
	while (isRunning) {
		SDL_PollEvent(&event);
		switch (event.type) {
		case SDL_QUIT:
			isRunning = false;
			break;
		case SDL_KEYDOWN:
			const Command cmd = controller->resolve(event);
			world->act(cmd);
			break;
		}
	}
}
