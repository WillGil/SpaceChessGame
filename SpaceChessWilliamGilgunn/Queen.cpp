//include header files
#include "Queen.h"

/**
 Author: William Gilgunn (160371509)
 Description: Definition file of the Queen.h file 
 Date: 01/12/18
 Email: w.gilgunn@ncl.ac.uk
*/

/* Default constructor makes a Queen piece at position (0,0)*/
Queen::Queen() : Piece()
{
}

/* Destructor */
Queen::~Queen()
{
}
/* Queen constructor that takes a position */
Queen::Queen(const Position & position): Piece(position)
{
}

/*  Move like a bishop: moveSet = 0, Move like a rook: moveSet = 1
	Method to move the queen piece in a given diagonal direction (0-NE, 1-SE, 2-SW 3-NW)
	else if
	method to move queen piece in a given horizontal or vertical direction (0-N, 1-E, 2-S, 3-W)*/
bool Queen::moveChessPiece(const int direction, const float distance)
{
	// Generate random number (0,1)
	int moveSet = rand() % 2;
	//Move diagonally
	if (moveSet == 0) {
		switch (direction) {
		// NE 
		case 0:
		{
			// Check to ensure it stays on board 
			float xPos = piecePosition.x + distance;
			float yPos = piecePosition.y + distance;
			if (xPos > BOARD_WIDTH_MAX || yPos > BOARD_HEIGHT_MAX) // If it is going to move off board return false.
				return false;

			//Increment x and y by distance
			piecePosition.x += distance;
			piecePosition.y += distance;
			break;
		}
		// SE 
		case 1:
		{
			// Check to ensure it stays on board 
			float xPos = piecePosition.x + distance;
			float yPos = piecePosition.y - distance;
			if (xPos > BOARD_WIDTH_MAX || yPos < BOARD_HEIGHT_MIN) // If it is going to move off board return false.
				return false;

			//Increment x and y by distance
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
			if (xPos < BOARD_WIDTH_MIN || yPos < BOARD_HEIGHT_MIN) // If it is going to move off board return false.
				return false;

			//Increment x and y by distance
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
			if (xPos < BOARD_WIDTH_MIN || yPos > BOARD_HEIGHT_MAX) // If it is going to move off board return false.
				return false;

			//Increment x and y by distance
			piecePosition.x -= distance;
			piecePosition.y += distance;
			break;
		}

		default:
			break;
		}
	}
	else {
		//Move Vertical or horizontal
		if (moveSet == 1) {
			switch (direction) {
			//North
			case 0:
			{
				//Check to ensure it stays on board 
				float yPos = piecePosition.y + distance;
				if (yPos > BOARD_HEIGHT_MAX) // If it is going to move off board return false.
					return false;

				piecePosition.y += distance;
				break;
			}
			//East
			case 1:
			{
				//Check to ensure it stays on board 
				float xPos = piecePosition.x + distance;
				if (xPos > BOARD_WIDTH_MAX) // If it is going to move off board return false.
					return false;

				// Increment position
				piecePosition.x += distance;
				break;
			}
			//South
			case 2:
			{
				//Check to ensure it stays on board 
				float yPos = piecePosition.y - distance;
				if (yPos < BOARD_HEIGHT_MIN) // If it is going to move off board return false.
					return false;

				// Increment position
				piecePosition.y -= distance;
				break;
			}
			//West
			case 3:
			{
				//Check to ensure it stays on board 
				float xPos = piecePosition.x - distance;
				if (xPos < BOARD_WIDTH_MIN) // If it is going to move off board return false.
					return false;
				// Increment position
				piecePosition.x -= distance;
				break;
			}
			// Otherwise break
			default:
				break;
			
			}

		}
	}
	// Move successful
	return true;
}
/* Getter for the radius of the circle */
int Queen::getMeasurement() const
{
	return radius;
}


