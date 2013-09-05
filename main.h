#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "unistd.h"

SDL_Surface *screen;
Uint32 clearColor;
SDL_Rect screenRect;


int main(int argc, char *argv[]);
void init(char *title);
void cleanup(void); 
void setBackgroundColor(int r, int g, int b); 
void render(void); 
