#include "LiteralValue.hpp"

template<typename T>
LiteralValue<T>::~LiteralValue() {}

template<typename T>
int	LiteralValue<T>::toInt() const
{
	return (static_cast<int>(_value));
}

template<typename T>
float		LiteralValue<T>::toFloat() const
{
	return (static_cast<float>(_value));
}

template<typename T>
double		LiteralValue<T>::toDouble() const
{
	return (static_cast<double>(_value));
}

template<typename T>
std::string	LiteralValue<T>::toString() const
{
	std::ostringstream oss;
	oss << _value;
	return oss.str();
}

