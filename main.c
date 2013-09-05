#include "main.h" 

#define HEIGHT 640
#define WIDTH 480
#define BITSPERPIXEL 0

int main(int argc, char *argv[]){
    
    init("SDL Test"); 
    setBackgroundColor(255, 105, 108); 
    render(); 
    sleep(1);
    cleanup(); 

    exit(0); 
}

void init(char *title) {

    if (SDL_Init(SDL_INIT_VIDEO) <  0){
        printf("Could not init SDL: %s\n", SDL_GetError()); 
        exit(1);
    }

    screen = SDL_SetVideoMode(HEIGHT, WIDTH, BITSPERPIXEL, SDL_HWPALETTE); 

    if(screen == NULL) {
        printf("Unable to set video mode to %d x %d, %s\n", HEIGHT,
                WIDTH, SDL_GetError()); 
    }

    SDL_WM_SetCaption(title, NULL);

}

void setBackgroundColor(int r, int g, int b){

    screenRect.x = screenRect.y = 0;
    screenRect.w = screen->w;
    screenRect.h = screen->h;
    clearColor = SDL_MapRGB(screen->format, r,g,b);
}

void render(){
    SDL_FillRect(screen, &screenRect, clearColor);
    SDL_Flip(screen);
}

void cleanup (void) {
    SDL_Quit(); 
}
