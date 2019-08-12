// Include header file
#include "Collision.h"

/*
 Author: William Gilgunn
 File: Collision.CPP
 Description: Definition file to define all the methods declared in the Collisions.h class.
*/


/* Defalt Constructor */
Collision::Collision()
{
}

/* Destructor */
Collision::~Collision()
{
}
/* Method to handle all collisions */
bool Collision::collide(Piece * p, Piece * p2)
{
	if (dynamic_cast<Bishop*>(p)){ // Test to see if p is a Bishop.
		if (dynamic_cast<Bishop*>(p2)) {//Test to see if p2 is a Bishop.
			Bishop* b = dynamic_cast<Bishop*>(p);
			Bishop* b2 = dynamic_cast<Bishop*>(p2);
			return testForCircleCircleOverlap(*b, *b2);
		}

		if (dynamic_cast<Rook*>(p2)) { // Test to see if p2 is a Rook.
			Bishop* b = dynamic_cast<Bishop*>(p);
			Rook* r = dynamic_cast<Rook*>(p2);
			return testForSquareCircleOverlap(*r, *b);
		}

		if (dynamic_cast<Queen*>(p2)) { //Test to see if p2 is a Queen.
			Bishop* b = dynamic_cast<Bishop*>(p);
			Queen* q = dynamic_cast<Queen*>(p2);
			return testForCircleCircleOverlap(*b, *q);
		}

	}

	if (dynamic_cast<Rook*>(p)) { // Test to see if p is a Rook.
		if (dynamic_cast<Bishop*>(p2)) { // Test to see if p2 is a Bishop. 
			Rook* r = dynamic_cast<Rook*>(p);
			Bishop* b = dynamic_cast<Bishop*>(p2);
			return testForSquareCircleOverlap(*r, *b);
		}

		if (dynamic_cast<Rook*>(p2)) { // Test to see if p2 is a rook.
			Rook* r = dynamic_cast<Rook*>(p);
			Rook* r2 = dynamic_cast<Rook*>(p2);
			return testForSquareSquareOverlap(*r, *r2);
		}

		if (dynamic_cast<Queen*>(p2)) { // Test to see if p2 is a Queen.
			Rook* r = dynamic_cast<Rook*>(p);
			Queen* q = dynamic_cast<Queen*>(p2);
			return testForSquareCircleOverlap(*r, *q);
		}
	}

	if (dynamic_cast<Queen*>(p)) { // Test to see if p is a Queen.
		if (dynamic_cast<Bishop*>(p2)) { // Test to see if p2 is a Bishop.
			Queen* q = dynamic_cast<Queen*>(p);
			Bishop* b = dynamic_cast<Bishop*>(p2);
			return testForCircleCircleOverlap(*q, *b);
		}

		if (dynamic_cast<Rook*>(p2)) { // Test to see if p2 is a Rook.
			Queen* q = dynamic_cast<Queen*>(p);
			Rook* r = dynamic_cast<Rook*>(p2);
			return testForSquareCircleOverlap(*r, *q);

		}

		if (dynamic_cast<Queen*>(p2)) { // Test to see if p2 is a Queen.
			Queen* q = dynamic_cast<Queen*>(p);
			Queen* q2 = dynamic_cast<Queen*>(p2);
			return testForCircleCircleOverlap(*q, *q2);
		}
	}
	return NULL; // Return null to ensure all paths return a value. 
}



/* Square-square collisions (Rook - Rook) */
bool Collision::testForSquareSquareOverlap(const Rook & rook1, const Rook & rook2)
{
	/*Compare coordinates against eachother and return boolean*/
	return rook1.getLeftPos().x <= rook2.getRightPos().x && rook1.getRightPos().x >= rook2.getLeftPos().x &&
		rook1.getTopPos().y >= rook2.getBottomPos().y && rook1.getBottomPos().y <= rook2.getTopPos().y;
}

/* Square-Circle collisions(Rook - Queen/bishop) */
bool Collision::testForSquareCircleOverlap(const Rook & rook, Piece & circle)
{
	//Define constants so they don't have to be called again. 
	const int circleRadius = circle.getMeasurement();
	const int squareSide = rook.getMeasurement();
	const float circleX = circle.getPosition().x;
	const float circleY = circle.getPosition().y;
	const float squareX = rook.getPosition().x;
	const float squareY = rook.getPosition().y;


	/* Gets the difference between the x values abs svalue (x1-x2) and difference in y values (y1-y2) */
	float distanceX = abs(circleX - squareX); // X distance between points 
	float distanceY = abs(circleY - squareY); // Y distance between points

	/* Easy cases where the circle is too far away to collide. */
	if (distanceX > (squareSide / 2 + circleRadius)) { return false; } // If the distance between x and y coordinates are greater than
	if (distanceY > (squareSide / 2 + circleRadius)) { return false; } // the length to the edge of the square plus the circle radius then they cannot collide.

	/* Check to see if the circle is inside if the distance is less than half the side then they are colliding: Easy case */
	if (distanceX <= (squareSide / 2)) { return true; }
	if (distanceY <= (squareSide / 2)) { return true; }

	/* Uses pythagoras to work out the distance from the corner to the circle center.
	If the distance is less than the radius (c^2) then a collision had occured at a corner.*/
	float distanceFromCorner = pow((distanceX - squareSide / 2), 2) +
		pow((distanceY - squareSide / 2), 2);

	return (distanceFromCorner <= pow(circleRadius ,2));

}

/* Circle-circle collisions (Queen/Bishop - Queen/Bishop) collisions */
bool Collision::testForCircleCircleOverlap(const Piece & circle, const Piece & circle2)
{
	// Use pythagoras to see if the radius' touch .
	return pow((circle2.getPosition().x - circle.getPosition().x), 2) + pow(circle.getPosition().y - circle2.getPosition().y, 2) <= pow(circle.getMeasurement() + circle2.getMeasurement(),2);
}