#include <iostream>
#include <SDL.h>
#include "Game.h"

SDL_Window* g_pWindow = 0;
SDL_Renderer* g_pRenderer = 0;

using namespace std;
int main(int argc, char** argv){
	/*if (SDL_Init(SDL_INIT_EVERYTHING) >= 0){
		g_pWindow = SDL_CreateWindow("Hello SDL",
			SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,640,480,SDL_WINDOW_SHOWN);
		if (g_pWindow != 0) {
			g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
		}
		else {
			return 1;
		}
		SDL_SetRenderDrawColor(g_pRenderer, 16, 05, 94, 255);
		SDL_RenderClear(g_pRenderer);
		SDL_RenderPresent(g_pRenderer);
		SDL_Delay(5000);
		SDL_Quit();
	
	}
*/
	

	// allocate the object of the game class
	Game* game = new Game();
	// run the game
	game->Run("Hello SDL2", 800, 800, false);
	delete game;

	return 0;
}