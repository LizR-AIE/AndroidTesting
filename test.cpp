#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "SDL2/SDL.h"
#include "SDL_test_common.h"
#include "SDL_opengles.h" 

// Global variables
SDL_Window * window = nullptr;
SDL_Surface * surface = nullptr;
bool quit = false;
SDL_Event e;

// Function prototypes
void Begin();
void Run();
void End();

int main()
{
	Begin();
	Run();
	End();
	
	return 0;
}

void Begin()
{
	// Init SDL
	if ( SDL_Init( SDL_INIT_VIDEO) < 0)
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		// Create Window
		window = SDL_CreateWindow( "SDL Testing", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
		if( window == nullptr)
		{
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			surface = SDL_GetWindowSurface( window );
			
			SDL_FillRect( surface, NULL, SDL_MapRGB( surface->format, 0xFF, 0xFF, 0xFF ));
			
			SDL_UpdateWindowSurface( window);
		}
	}
}

void Run()
{
	while(!quit)
	{
		// Poll Events
		while( SDL_PollEvent( &e ) != 0)
		{
			if( e.type == SDL_QUIT)
			{
				quit = true;
			}
		}
		
		// Update the window
		SDL_UpdateWindowSurface( window); 
	}
}

void End()
{
	SDL_DestroyWindow( window);
	
	SDL_Quit();
}