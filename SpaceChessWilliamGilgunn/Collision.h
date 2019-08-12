#pragma once
// Include libraries and header files
#include "Rook.h"
#include "Queen.h"
#include "Bishop.h"
#include "Piece.h"
#include <cmath>
/**
 Author: William Gilgunn (160371509)
 File: Collision.h
 Description: Declaration class to declare all the methods used in the Collision.cpp.
 Email: w.gilgunn@ncl.ac.uk
*/

class Collision
{
public:
	// Constructors
	Collision();
	~Collision();

	/* Method to handle collisions between between pieces */
	static bool collide(Piece* p, Piece* p2);

	/* Square-square collisions (Rook - Rook) */
	static bool testForSquareSquareOverlap(const Rook& rook1, const Rook& rook2);

	/* Square-Circle collisions(Rook - Queen/bishop) */
	static bool testForSquareCircleOverlap(const Rook& rook1, Piece& circle);

	/* circle-circle collisions (Queen/Bishop - Queen/Bishop) collisions */
	static bool testForCircleCircleOverlap(const Piece& circle, const Piece& circle2);
};

