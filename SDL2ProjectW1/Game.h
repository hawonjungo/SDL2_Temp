#pragma once
//using SDL

#include <SDL.h>

class Game
{
public:
	Game();
	// create the renderer
	// initial allocation of the object are done here
	bool Start();

	// handles any user input has happend since the last call
	void ProcessInput();
	// advances the game simulation, it run AI, physical, player movement
	void Update();
	// draws the game so the player can see what happend
	void Draw();
	// deallocates the objects created
	void ShutDown();

	// @briefcreates a window and begin the game loop
	//it first calls the start once and after it is successful,
	//it calls the ProcessInput(), Update() and Draw() in the gameloop,
	// and ends with calling ShutDown() after the game loop hasended.
	// @param title - title for the window
	// @param width - width of the window
	// @param height - height of the window
	// @param fullscreen - enables or disables fullscreen for the window

	void Run(const char*, int width, int height, bool fullscreen);

	// delete the window and the renderer when closing the application
	// shutdown the SDL framework
	void Destroy();


	~Game();

private:
	// the window we will be rendering to
	SDL_Window* sdlWindow;
	// 2D rendering context for a window
	SDL_Renderer* sdlRenderer;
	// flag for the game loop
	bool isGameOver;

};

