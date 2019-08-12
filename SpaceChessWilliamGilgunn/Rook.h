#pragma once
// Include header files
#include "Piece.h"

/**
 Author: William Gilgunn (160371509)
 Description: Declaration file for the Rook class. (Rook is a SQUARE)
 Date 01/12/18
 Email:w.gilgunn@ncl.ac.uk
*/

// Rook inherits from Piece. 
class Rook: public Piece
{
public:
	// Constructors 
	Rook();
	~Rook();
	Rook(const Position &position);

	// Method to move the chess piece (0-N, 1-E, 2-S 3-W)
	virtual bool moveChessPiece(const int direction, const float distance);

	// Method to obtain coordinates
	Position getLeftPos() const;
	Position getRightPos() const;
	Position getTopPos() const;
	Position getBottomPos() const;

	// Getter for the side length
	virtual int getMeasurement() const;


private:
	// Length of the side of Square. 
	const int sideLength = 2;
};

