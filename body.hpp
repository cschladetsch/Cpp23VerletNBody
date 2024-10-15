
#ifndef BODY_HPP
#define BODY_HPP

#include <SDL2/SDL.h>
#include <vector>

struct Body {
    double x, y;
    double prev_x, prev_y;
    double mass;
    double radius;
    SDL_Color color;

    Body(double x, double y, double vx, double vy, double mass, SDL_Color color);
};

// Initializes a set of bodies with random positions and velocities
void initializeBodies(std::vector<Body> &bodies, int numBodies, int screenWidth, int screenHeight, double speedMultiplier);

#endif
