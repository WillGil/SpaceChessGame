#pragma once

// Include header files
#include "Piece.h"

/**
 Author: William Gilgunn (160371509)
 Description:  Declaration file for the bishop class. (Bishop is a CIRCLE)
 Date 01/12/18
 Email: w.gilgunn@ncl.ac.uk
*/

// Bishop inherits from Piece 
class Bishop: public Piece
{
public:
	// Constructors
	Bishop();
	~Bishop();
	Bishop(const Position &position);

	// Method to move the chess piece (0-NE, 1-SE, 2-SW 3-NW)
	virtual bool moveChessPiece(const int direction, const float distance);

	// Getter for measurement radius 
	virtual int getMeasurement() const;

private:
	// Given radius
	const int radius = 1;
};

