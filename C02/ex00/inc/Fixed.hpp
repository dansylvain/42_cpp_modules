#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int					_value;
	static const int	_fractionalBits = 8;

public:
	// Constructors and destructor
	Fixed();
	Fixed(const Fixed &fixed);
	~Fixed();
	
	// Assignment operator
	Fixed &operator=(const Fixed &fixed);

	// Access and utility methods
	int		getRawBits(void)const;
	void	setRawBits(int const raw);
};

#endif