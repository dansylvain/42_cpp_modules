#pragma once

#include <iostream>
#include <string>
#include <sstream>

template <typename T>
class LiteralValue
{
	protected:
		T	_value;
	public:
		LiteralValue();
		LiteralValue(T value);
		LiteralValue(const LiteralValue&);
		virtual const LiteralValue& operator=(const LiteralValue& rhs);
		virtual ~LiteralValue();

		virtual int			toInt() const;
		virtual float		toFloat() const;
		virtual double		toDouble() const;
		virtual std::string	toString() const;
};

#include "LiteralValue.tpp"