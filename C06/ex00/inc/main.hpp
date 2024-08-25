#pragma once

enum PseudoLiterals
{
	NEG_INFF,
	POS_INFF,
	NEG_INF,
	POS_INF,
	NAN,
	NUM_PSEUDO_LITERALS
};

enum literalType
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDOLITERAL,
	UNKNOWN
};