#pragma once

#include "Fixed.hpp"
#include "Point.hpp"

bool	bsp( Point const a, Point const b, Point const c, Point const point);
void	printB(std::string str);
void	getInput(std::string str, float *f);
void	readPoint(Point &p);
void	print(std::string str);
void	fire( Point const a, Point const b, Point const c, Point const point );
void	pause();
void	printB(std::string str);