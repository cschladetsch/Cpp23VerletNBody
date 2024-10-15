
#include "physics.hpp"
#include <cmath>

const double G = 1e-1;  // Gravitational constant

void applyGravity(const Body &a, const Body &b, double &ax, double &ay) {
    double dx = b.x - a.x;
    double dy = b.y - a.y;
    double dist = std::sqrt(dx * dx + dy * dy);

    // Prevent singularities by setting a minimum distance threshold
    const double minDist = 10.0;
    if (dist < minDist) dist = minDist;  // Prevent bodies from collapsing

    double force = G * a.mass * b.mass / (dist * dist);
    ax = force * dx / dist / a.mass;
    ay = force * dy / dist / a.mass;
}

void updateBodiesVerlet(std::vector<Body> &bodies, double DT) {
    std::vector<std::pair<double, double>> accelerations(bodies.size(), {0.0, 0.0});

    // Compute accelerations for all pairs of bodies
    for (size_t i = 0; i < bodies.size(); ++i) {
        for (size_t j = i + 1; j < bodies.size(); ++j) {
            double ax1 = 0.0, ay1 = 0.0, ax2 = 0.0, ay2 = 0.0;
            applyGravity(bodies[i], bodies[j], ax1, ay1);
            applyGravity(bodies[j], bodies[i], ax2, ay2);

            accelerations[i].first += ax1;
            accelerations[i].second += ay1;
            accelerations[j].first += ax2;
            accelerations[j].second += ay2;
        }
    }

    // Update positions using Verlet integration and handle bouncing off walls
    for (size_t i = 0; i < bodies.size(); ++i) {
        Body &body = bodies[i];
        double new_x = 2 * body.x - body.prev_x + accelerations[i].first * DT * DT;
        double new_y = 2 * body.y - body.prev_y + accelerations[i].second * DT * DT;

        // Check for wall collision and reverse velocity
        if (new_x - body.radius < 0 || new_x + body.radius > 800) {
            body.prev_x = body.x;
            new_x = (new_x < 0) ? body.radius : 800 - body.radius;
        }
        if (new_y - body.radius < 0 || new_y + body.radius > 800) {
            body.prev_y = body.y;
            new_y = (new_y < 0) ? body.radius : 800 - body.radius;
        }

        body.prev_x = body.x;
        body.prev_y = body.y;
        body.x = new_x;
        body.y = new_y;
    }
}
