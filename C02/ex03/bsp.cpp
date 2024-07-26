#include "Point.hpp"
#include "Fixed.hpp"


/**========================================================================
 *                             BSP
 *  produit vectoriel 2D
 *  (Bx−Ax)⋅(Py−Ay)−(By−Ay)⋅(Px−Ax)
 *  
 *  
 *========================================================================**/

int	cross_product_2d(int x[], int y[], int z[]){
	return ((y[0]-x[0])*(z[1]-x[1])-(y[1]-x[1])*(z[0]-x[0]));
}

void	initializeArray(int array[], Point const p)
{
	array[0] = p.get_x().getRawBits();
	array[1] = p.get_y().getRawBits();
}

bool haveSameSign(int x, int y)
{
	if ((x > 0 && y > 0) || (x < 0 && y < 0))
		return (true);
	return (false);
}

bool bsp( Point const a, Point const b, Point const c, Point const point){
	int A[2], B[2], C[2], P[2];
	initializeArray(A, a);
	initializeArray(B, b);
	initializeArray(C, c);
	initializeArray(P, point);

	bool sameSign1 = haveSameSign(cross_product_2d(A, B, C), cross_product_2d(A, B, P));
	bool sameSign2 = haveSameSign(cross_product_2d(A, C, B), cross_product_2d(A, C, P));
	bool sameSign3 = haveSameSign(cross_product_2d(B, C, A), cross_product_2d(B, C, P));
	
	std::cout << sameSign1 << ", " << sameSign2 << ", " << sameSign3 << std::endl;
	
	return (sameSign1 && sameSign2 && sameSign3);
}
