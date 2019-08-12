// Include header file.
#include "Rook.h"


/**
 Author: William Gilgunn (160371509)
 Description: Definition file for the Rook class. (Rook is a SQUARE)
 Date 01/12/18
 Email:w.gilgunn@ncl.ac.uk
*/


/* Default Constructor that sets position to (0,0) */
Rook::Rook(): Piece()
{
}

/* Destructor */
Rook::~Rook()
{
}
/* Rook that takes a position as an argument */
Rook::Rook(const Position & position): Piece(position)
{
}
// implmentation to move the chess piece (0-N, 1-E, 2-S 3-W)
bool Rook::moveChessPiece(const int direction, const float distance)
{
	switch (direction) {
	//North
	case 0:
	{
		//Check to ensure it stays on board 
		float yPos = piecePosition.y + distance;
		if (yPos > BOARD_HEIGHT_MAX) // if piece will move of the board return false. 
			return false;

		//Increment position
		piecePosition.y += distance;
		break;
	}

	//East
	case 1:
	{
		//Check to ensure it stays on board 
		float xPos = piecePosition.x + distance;
		if (xPos > BOARD_WIDTH_MAX) // If piece will move of the board return false.
			return false;
		//Increment position
		piecePosition.x += distance;
		break;
	}
	//South
	case 2:
	{
		//Check to ensure it stays on board 
		float yPos = piecePosition.y - distance;
		if (yPos < BOARD_HEIGHT_MIN) // if piece will move of the board return false.
			return false;
		//Increment position
		piecePosition.y -= distance;
		break;
	}
	//West
	case 3:
	{
		//Check to ensure it stays on board 
		float xPos = piecePosition.x - distance;
		if (xPos < BOARD_WIDTH_MIN) // if piece will move of the board return false.
			return false;
		//Increment position
		piecePosition.x -= distance;
		break;
	}
	default:
		break;

	}
	// Move successful
	return true;


}
/* Get left coordinate of square */
Piece::Position Rook::getLeftPos() const
{
	Position pos = { piecePosition.x - getMeasurement() / 2, piecePosition.y };
	return pos;
}
/* Get right coordinate of square */
Piece::Position Rook::getRightPos() const
{
	Position pos = { piecePosition.x + getMeasurement() / 2, piecePosition.y };
	return pos;
}
/* Get top position of square */
Piece::Position Rook::getTopPos() const
{
	Position pos = { piecePosition.x, piecePosition.y + getMeasurement() / 2 };
	return pos;
}
/* Get bottom position of square */
Piece::Position Rook::getBottomPos() const
{
	Position pos = { piecePosition.x, piecePosition.y - getMeasurement() / 2 };
	return pos;
}
/* Returns the length of the side */
int Rook::getMeasurement() const
{
	return sideLength;
}



