
#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP

#include "body.hpp"
#include <SDL2/SDL.h>
#include <vector>

void drawBodies(SDL_Renderer *renderer, const std::vector<Body> &bodies);
void fadeTraces(SDL_Renderer *renderer);

#endif
