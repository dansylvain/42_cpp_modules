#include "Point.hpp"
#include "Fixed.hpp"
#include <cstdio>

bool haveSameSign(int x, int y);
int	cross_product_2d(int x[], int y[], int z[]);
void	initializeArray(int array[], Point const p);

int	cross_product_2d(int x[], int y[], int z[]){
	return ((y[0]-x[0])*(z[1]-x[1])-(y[1]-x[1])*(z[0]-x[0]));
}

void	initializeArray(int array[], Point const p)
{
	array[0] = p.get_x().toInt();
	array[1] = p.get_y().toInt();
}

bool haveSameSign(int x, int y)
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
	
	int A[2], B[2], C[2], P[2];
	
	initializeArray(A, a);
	initializeArray(B, b);
	initializeArray(C, c);
	initializeArray(P, point);

	int cp1 = cross_product_2d(A, B, C);
	int cp2 = cross_product_2d(A, B, P);
	int cp3 = cross_product_2d(B, C, P);
	int cp4 = cross_product_2d(C, A, P);

	bool sameSign1 = haveSameSign(cp1, cp2);
	bool sameSign2 = haveSameSign(cp1, cp3);
	bool sameSign3 = haveSameSign(cp1, cp4);

	return (sameSign1 && sameSign2 && sameSign3);
}
