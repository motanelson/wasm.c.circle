// Copyright 2011 The Emscripten Authors.  All rights reserved.
// Emscripten is available under two separate licenses, the MIT license and the
// University of Illinois/NCSA Open Source License.  Both these licenses can be
// found in the LICENSE file.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <time.h>
#include <math.h>
#include "SDLs.h"
#include <SDL_image.h>
#include <emscripten.h>
SDL_Surface *screen = NULL;

void kernel_main(){
   printf("ok\n");
  
  
       
     
     
   

  


}

int main() {
  SDL_Init(SDL_INIT_VIDEO);
  screen =(SDL_Surface *) SDL_SetVideoMode(800,600, 32, SDL_SWSURFACE);
#ifdef TEST_SDL_LOCK_OPTS
  EM_ASM("SDL.defaults.copyOnLock = false; SDL.defaults.discardOnLock = true; SDL.defaults.opaqueFrontBuffer = false;");
#endif
  
  if (SDL_MUSTLOCK(screen)) SDL_LockSurface(screen);
  clears(screen, 255, 255, 0);
  for(int x=0;x<800;x=x+20)line(screen,x,0,x,600,0,0,0);
  for(int y=0;y<600;y=y+20)line(screen,0,y,800,y,0,0,0);

  printf("\n\nxxxx\n ");
  
  if (SDL_MUSTLOCK(screen)) SDL_UnlockSurface(screen);     
  SDL_Flip(screen);
     
  return 0;
}
