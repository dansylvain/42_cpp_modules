#pragma once

#include "Point.hpp"
#include "Fixed.hpp"
#include <cstdio>

bool	haveSameSign(float x, float y);
float	cross_product_2d(float x[], float y[], float z[]);
void	initializeArray(float array[], Point const p);