#include "Game.h"
#include <iostream>



Game::Game() {
	// set the SDL window poiter to null
	sdlWindow = nullptr;
	//set the SDL renderer pointer to null
	sdlRenderer = nullptr;
	
	//initialize SDL
	// if the initialization was not successful
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		// disable the game loop
		isGameOver = true;
		// print a failed message on the console window
		std::cout << "Initialize SDL - failed" << std::endl;
	}
	//if the initialization was successful
	else {
		//enable to game loop 
		isGameOver = false;
		//print a success message on the console window
		std::cout << "Initialize SDL - success" << std::endl;
	}
}
bool Game::Start() {
	// create the renderer for the window created
	sdlRenderer = SDL_CreateRenderer(sdlWindow, 0, -1);
	if (sdlRenderer != nullptr) {
		std::cout << "Create Renderer - success" << std::endl;
		// TODO: initialize object here

		return true;
	}
	std::cout << " Create Renderer - failed" << std::endl;
	return false;
}
void Game::Run(const char * title, int width, int height, bool fullscreen) {
	// maintain the creation flag
	int creationFlag = 0;

	// if the full screen is set to false, set to windowed mode
	if (!fullscreen) {
		creationFlag = SDL_WINDOW_SHOWN;
	}
	//if true, set to full screen mode
	else {
		creationFlag = SDL_WINDOW_FULLSCREEN;
	}

	// create the sdl window
	sdlWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, creationFlag);
	// if the window has been create successfully
	// create the renderer and start the game loop
	if (sdlWindow != nullptr && Start()) {
		// debug message if the window has been successfully created
		std::cout << "Create Window - success" << std::endl;
		//start the game loop
		while (!isGameOver) {
			// checks for input from user
			ProcessInput();

			// any chances to the AI , physics or player movement
			Update();

			// draws on the window
			Draw();
		}
		// debug message if the window has been successfully created
		std::cout << "Create Window - failed" << std::endl;
		// clean up
		ShutDown();
		Destroy();
	}
}

void Game::Draw() {
	//set the Draw color to black
	SDL_SetRenderDrawColor(sdlRenderer, 0, 0, 0, 255);
	// clears the render color with the color set above
	SDL_RenderClear(sdlRenderer);
	// sdl_renderer* draws to the hiden target
	// this function will take all of that and draws all of that in the window tied to renderer
	SDL_RenderPresent(sdlRenderer);

	// TODO : draw staff here
}
void Game::Destroy() {
	// deallocates the sdl_window*
	SDL_DestroyWindow(sdlWindow);
	// deallocates the SDL_Renderer*
	SDL_DestroyRenderer(sdlRenderer);
	// shut down the sdl framework
	SDL_Quit();
}
void Game::ProcessInput() {
	// ​TODO:​ Get the user input here
}
void Game::Update(){
	// ​TODO:​ update your stuff here
}
void Game::ShutDown() {
	// ​TODO:​ deallocate the stuff you created in Start()
}
 Game::~Game() {
	
}