#pragma once

//Imports
#include <iostream>
#include <string>
#include <stdio.h>
#include <iomanip> 
#include "ConfigureGame.h"

/**
 Author: William Gilgunn (160371509)
 Description: Declaration file for the Piece class 
 Date: 01/12/18
 Email: w.gilgunn@ncl.ac.uk
*/

class Piece
{
	
public:
	/* Struct to store a vector name Position*/
	typedef struct {
		float x;
		float y;
	}Position;

	// Constructors
	Piece();
	Piece(const Piece& src);
	Piece(const Position &positiion);

	// Assignment operator
	Piece& operator=(const Piece& rhs);

	// Destructor
	virtual ~Piece();

	// Getter 
	Position getPosition() const;

	// Method to move piece 
	virtual bool moveChessPiece(const int direction, const float distance) = 0;

	// Method to get side/radius of subclass 
	virtual int getMeasurement() const = 0;


protected:
	// Position of piece (Coordinates)
	Position piecePosition;
};

// Output operator
std::ostream & operator<<(std::ostream & outStream, const Piece& piece);
