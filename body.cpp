
#include "body.hpp"
#include <cstdlib>
#include <cmath>

Body::Body(double x, double y, double vx, double vy, double mass, SDL_Color color)
    : x(x), y(y), mass(mass), color(color) {
    radius = std::cbrt(mass) * 2;
    prev_x = x - vx * (1.0 / 60.0);  // Initialize previous position based on velocity and 60Hz
    prev_y = y - vy * (1.0 / 60.0);
}

void initializeBodies(std::vector<Body> &bodies, int numBodies, int screenWidth, int screenHeight, double speedMultiplier) {
    for (int i = 0; i < numBodies; ++i) {
        double x = std::rand() % screenWidth;
        double y = std::rand() % screenHeight;

        // Set velocities for visible movement
        double vx = ((std::rand() % 200) - 100) / 10.0 * speedMultiplier;
        double vy = ((std::rand() % 200) - 100) / 10.0 * speedMultiplier;

        double mass = (std::rand() % 300) + 100;  // Mass for gravitational effect
        SDL_Color color = { (Uint8)(std::rand() % 255), (Uint8)(std::rand() % 255), (Uint8)(std::rand() % 255), 255 };
        bodies.emplace_back(x, y, vx, vy, mass, color);
    }
}
