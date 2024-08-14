#include "Point.hpp"
#include "Fixed.hpp"
#include <cstdio>

bool haveSameSign(float x, float y);
float cross_product_2d(float x[], float y[], float z[]);
void	initializeArray(int array[], Point const p);

float	cross_product_2d(float x[], float y[], float z[]){
	return ((y[0]-x[0])*(z[1]-x[1])-(y[1]-x[1])*(z[0]-x[0]));
}

void	initializeArray(float array[], Point const p)
{
	array[0] = p.get_x().toFloat();
	array[1] = p.get_y().toFloat();
}

bool haveSameSign(float x, float y)
{
	if ((x > 0 && y > 0) || (x < 0 && y < 0))
		return (true);
	return (false);
}

/**========================================================================
 *                           BSP
 * comparing the cross product of AB and C with the CP of P with all sides,
 * we make sure that P is on the same side and hence, within the triangle
 *========================================================================**/
bool bsp( Point const a, Point const b, Point const c, Point const point){
	
	float A[2], B[2], C[2], P[2];
	
	initializeArray(A, a);
	initializeArray(B, b);
	initializeArray(C, c);
	initializeArray(P, point);

	float cp1 = cross_product_2d(A, B, C);
	float cp2 = cross_product_2d(A, B, P);
	float cp3 = cross_product_2d(B, C, P);
	float cp4 = cross_product_2d(C, A, P);

	bool sameSign1 = haveSameSign(cp1, cp2);
	bool sameSign2 = haveSameSign(cp1, cp3);
	bool sameSign3 = haveSameSign(cp1, cp4);

	return (sameSign1 && sameSign2 && sameSign3);
}
