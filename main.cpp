
#include <SDL2/SDL.h>
#include "body.hpp"
#include "physics.hpp"
#include "graphics.hpp"
#include <vector>
#include <string>  // For std::stoi and std::stod

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 800;

int main(int argc, char* argv[]) {
    int numBodies = 4;  // Default to 4 bodies
    double speedMultiplier = 1.0;  // Default speed multiplier (1x speed)

    // Command-line argument parsing
    if (argc >= 2) {
        numBodies = std::stoi(argv[1]);  // First argument is number of bodies
    }
    if (argc >= 3) {
        speedMultiplier = std::stod(argv[2]);  // Second argument is speed multiplier
    }

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("N-Body Simulation", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                          SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    std::vector<Body> bodies;

    // Initialize bodies with random values
    initializeBodies(bodies, numBodies, SCREEN_WIDTH, SCREEN_HEIGHT, speedMultiplier);

    bool quit = false;
    SDL_Event e;

    Uint64 previousTime = SDL_GetPerformanceCounter();
    Uint64 currentTime;
    double deltaTime;

    while (!quit) {
        currentTime = SDL_GetPerformanceCounter();
        deltaTime = (double)(currentTime - previousTime) / SDL_GetPerformanceFrequency();
        previousTime = currentTime;

        // Adjust the time step (DT) based on the speed multiplier
        double DT = deltaTime * speedMultiplier;

        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        updateBodiesVerlet(bodies, DT);  // Update bodies using Verlet integration

        fadeTraces(renderer);
        drawBodies(renderer, bodies);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
