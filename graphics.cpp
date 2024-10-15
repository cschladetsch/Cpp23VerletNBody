
#include "graphics.hpp"

void drawBodies(SDL_Renderer *renderer, const std::vector<Body> &bodies) {
    const double visualSizeScale = 0.4;  // Scale the body radius to 40% of its original size

    for (const auto &body : bodies) {
        SDL_SetRenderDrawColor(renderer, body.color.r, body.color.g, body.color.b, 255);

        // Apply visual scaling to the body's radius
        double scaledRadius = body.radius * visualSizeScale;

        for (int w = 0; w < scaledRadius * 2; w++) {
            for (int h = 0; h < scaledRadius * 2; h++) {
                int dx = scaledRadius - w;
                int dy = scaledRadius - h;
                if ((dx * dx + dy * dy) <= (scaledRadius * scaledRadius)) {
                    SDL_RenderDrawPoint(renderer, body.x + dx, body.y + dy);
                }
            }
        }
    }
}

void fadeTraces(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 3);  // Slow fading for visible trails
    SDL_Rect fadeRect = {0, 0, 800, 800};  // Full screen fade
    SDL_RenderFillRect(renderer, &fadeRect);
}
