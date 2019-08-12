//Include header file
#include "Piece.h"
/**
 Author: William Gilgunn (160371509)
 Description: Definitions for the piece header file.
 Date: 01/12/18
 Email:w.gilgunn@ncl.ac.uk
*/

//avoids use of std::
using namespace std;

/* Default pieces with no assigned location. */
Piece::Piece()
{
	piecePosition.x = 0;
	piecePosition.y = 0;
}
/* Copy constuctor */
Piece::Piece(const Piece & src)
{
	piecePosition.x = src.piecePosition.x;
	piecePosition.y = src.piecePosition.y;
}
/* Constructor to create a piece with a certain position */
Piece::Piece(const Position & positiion)
{
	piecePosition.x = positiion.x;
	piecePosition.y = positiion.y;
}

/* Assign one piece to another 
Slicing occurs if derived class is assigned to a piece */
Piece & Piece::operator=(const Piece & rhs)
{
	piecePosition.x = rhs.piecePosition.x;
	piecePosition.y = rhs.piecePosition.y;
	return *this;
}

/* Destructor */
Piece::~Piece()
{
	piecePosition.x = 0;
	piecePosition.y = 0;
}

/* Return position struct */
Piece::Position Piece::getPosition() const
{
	return piecePosition;
}


//Output operator 
std::ostream & operator<<(std::ostream & outStream, const Piece & piece)
{
	// Removes extra characters in front of typeid.name()
	string classType;
	string actualType = typeid(piece).name();
	for (size_t i = 6; i < actualType.length(); i++) {
		classType.push_back(actualType[i]);
	}

	// String outputted 
	outStream <<left << setw(6) << classType << " -> (" << left << setw(8) << piece.getPosition().x<<"," << left << setw(6) <<piece.getPosition().y<<")";
	return outStream;
}
