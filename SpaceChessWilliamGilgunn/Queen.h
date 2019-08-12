#pragma once

//Include header files
#include "Piece.h"

/**
 Author: William Gilgunn (160371509)
 Description: Declaration file for the queen class (Queen is CIRCLE).
 Date: 01/12/18
 Email:w.gilgunn@ncl.ac.uk
*/

// Queen inherits from Piece
class Queen: public Piece
{
public:
	// Constructors
	Queen();
	~Queen();
	Queen(const Position &position);


	/* Method to allow movement of queen piece diagonally, vertically or horizontally */
	virtual bool moveChessPiece(const int direction, const float distance);

	// Getter
	virtual int getMeasurement() const;

private:
	// Given radius
	const int radius = 1;
};

