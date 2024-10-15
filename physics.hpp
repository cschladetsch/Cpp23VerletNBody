
#ifndef PHYSICS_HPP
#define PHYSICS_HPP

#include "body.hpp"
#include <vector>

void applyGravity(const Body &a, const Body &b, double &ax, double &ay);
void updateBodiesVerlet(std::vector<Body> &bodies, double DT);

#endif
