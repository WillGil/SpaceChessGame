// Include header file
#include "Bishop.h"

/**
 Author: William Gilgunn (160371509)
 Description: Definition file for the bishop class. (Bishop is a CIRCLE)
 Date 01/12/18
 Email: w.gilgunn@ncl.ac.uk
*/

/*
	Default constructor calls piece and sets Position to be (0,0)
*/
Bishop::Bishop(): Piece()
{
}

/*
	Destructor 
*/
Bishop::~Bishop()
{
}
/*
	Constructor that takes a position as a argument 
*/
Bishop::Bishop(const Position & position) : Piece(position)
{
}
/*
Method to move the bishop piece in a given direction (0-NE, 1-SE, 2-SW 3-NW)
*/
bool Bishop::moveChessPiece(const int direction, const float distance)
{
	switch (direction) {
	// NE 
	case 0:
	{
		//Check to ensure it stays on board 
		float xPos = piecePosition.x + distance;
		float yPos = piecePosition.y + distance;
		if (xPos > BOARD_WIDTH_MAX || yPos > BOARD_HEIGHT_MAX)
			return false;

		//Increment x and y by distance
		piecePosition.x += distance;
		piecePosition.y += distance;
		break;
	}
	// SE 
	case 1:
	{
		//Check to ensure it stays on board 
		float xPos = piecePosition.x + distance;
		float yPos = piecePosition.y - distance;
		if (xPos > BOARD_WIDTH_MAX || yPos < BOARD_HEIGHT_MIN)
			return false;

		piecePosition.x += distance;
		piecePosition.y -= distance;
		break;
	}
	// SW
	case 2: 
	{
		//Check to ensure it stays on board 
		float xPos = piecePosition.x - distance;
		float yPos = piecePosition.y - distance;
		if (xPos < BOARD_WIDTH_MIN || yPos < BOARD_HEIGHT_MIN)
			return false;

		piecePosition.x -= distance;
		piecePosition.y -= distance;
		break;
	}
	// NW 
	case 3:
	{
		//Check to ensure it stays on board 
		float xPos = piecePosition.x - distance;
		float yPos = piecePosition.y + distance;
		if (xPos < BOARD_WIDTH_MIN || yPos > BOARD_HEIGHT_MAX)
			return false;

		piecePosition.x -= distance;
		piecePosition.y += distance;
		break;
	}
	default:
		break;
	}
	return true;
}
/*
Returns radius of circle
*/
int Bishop::getMeasurement() const
{
	return radius;
}

