// Include headers and libraries
#include "Piece.h"
#include "Bishop.h"
#include "Queen.h"
#include "Rook.h"
#include <vector>
#include <random>
#include "Collision.h"
#include <string>
#include <ctime>
#include "ConfigureGame.h"

/**
 Author: William Gilgunn (160371509)
 File: Game.cpp
 Description: Method to run the Space Chess game.
 Email: w.gilgunn@ncl.ac.uk
 Note: Run from this class. 
*/

// Do not have to use std::
using namespace std;


//Arrays (Bishop, Queen, Rook)
int numberOfPieces[3] = { 0,0,0 };
int scores[3] = { 0,0,0 };

/* Vector to store all the pieces within. */
vector<Piece*> pieceVector;

/* Setup Pieces on the board */
void setUpPieces() {
	/* Run for the number of shapes specified in ConfigureGame.h */
	for (int x = 0; x < NUMBER_OF_SHAPES; x++) {

		// Random piece 
		int pieceNum = rand() % 3;

		// X and Y starting position
		float xPos,yPos;
		switch (pieceNum) 
		{
		//Bishop
		case 0:
		{
			// Generate random position
			xPos = static_cast <float> (rand()) / static_cast <float> (RAND_MAX / BOARD_WIDTH_MAX);
			yPos = static_cast <float> (rand()) / static_cast <float> (RAND_MAX / BOARD_HEIGHT_MAX);
			Piece::Position p = { xPos,yPos };
			pieceVector.push_back(new Bishop(p)); // Add Bishop to vector. 
			break;
		}
		//Rook 
		case 1:
		{
			// Generate random position
			xPos = static_cast <float> (rand()) / static_cast <float> (RAND_MAX / BOARD_WIDTH_MAX);
			yPos = static_cast <float> (rand()) / static_cast <float> (RAND_MAX / BOARD_HEIGHT_MAX);
			Piece::Position p = { xPos,yPos };
			pieceVector.push_back(new Rook(p)); // Add Rook to vector.
			break;
		}
		//Queen
		case 2:
		{
			// Generate random position
			xPos = static_cast <float> (rand()) / static_cast <float> (RAND_MAX / BOARD_WIDTH_MAX);
			yPos = static_cast <float> (rand()) / static_cast <float> (RAND_MAX / BOARD_HEIGHT_MAX);
			Piece::Position p = { xPos,yPos };
			pieceVector.push_back(new Queen(p)); // Add Queen to vector.
			break;
		}
		default:
			break;
		}
	}

}

/* Print all the pieces in the game */
void printPieces() {
	for (size_t x = 0; x < pieceVector.size(); x++) {
		cout << *pieceVector[x] << endl;
	}
}
/* Check for collisions between two pieces.
   initialCollisions: Is it the starting collisions of the game.
   p: piece on the board you are checking for collisions upon
   index: index of piece passed in.
*/
void checkCollisions(bool initalCollisions, Piece* p, int index) {
	// Create iterator 
	vector<Piece*>::iterator iter = pieceVector.begin();
	
	// Create a pointer to the piece passed in
	Piece* comparison = pieceVector[index];
	/* Run while there are still objects in the piecevector*/
	while (iter != pieceVector.end())
	{
		/* Check to see that it isn't being compared againt itself*/
		if (*iter != comparison) {
			/* Check for collision between pieces */
			if (Collision::collide(p, *iter))
			{
				// Check to see if bishop collided while moving
				if (dynamic_cast<Bishop*>(p)) {
					if (!initalCollisions) // If initial collision do not add to score
						scores[0]++;

				}
				// Check to see if Queen collided while moving
				if (dynamic_cast<Queen*>(p)) {
					if (!initalCollisions) // If initial collision do not add to score
						scores[1]++;

				}
				// Check to see if rook collided while moving
				if (dynamic_cast<Rook*>(p)) {
					if (!initalCollisions) // If initial collision do not add to score
						scores[2]++;

				}
				// Print out collision
				cout << "Collision between :" << *p << " and " << **iter << endl << "REMOVING: " << **iter << " From the game" << endl << endl;

				delete *iter;  // Delete assigned memory 
				iter = pieceVector.erase(iter); // erase returns the new iterator when everything is shifted. 

			}
			// If it doesn't collide increment iterator
			else{ ++iter; }
		// If it is the same object increment to check next piece. 
		}else{ ++iter; }
	}
}

/* Count number of each piece in the game*/
void countTypesOfEach(vector<Piece*> p) {
	//Reset array 
	numberOfPieces[0] = 0;
	numberOfPieces[1] = 0;
	numberOfPieces[2] = 0;

	/* For-loop running through all pieces */
	for (size_t x = 0; x < p.size(); x++) {
		if (dynamic_cast<Bishop*>(p[x])) { // Check if it is a Bishop
			numberOfPieces[0]++;
		}
		if (dynamic_cast<Queen*>(p[x])) { // Check if it is a Queen
			numberOfPieces[1]++;
		}
		if (dynamic_cast<Rook*>(p[x])) { // Check if it is a Rook.
			numberOfPieces[2]++;
		}
		
	}

}

/* Method to move a specific piece on the board */
void movePiece(Piece* p) {
	if (dynamic_cast<Bishop*>(p)) { // Check if it is a Bishop 
		Bishop* b = dynamic_cast<Bishop*>(p); 
		bool successfulMove;
		do {  // Keep moving piece until it has a valid move 
			float distance = static_cast <float> (rand()) / static_cast <float> (RAND_MAX / MAX_DISTANCE);
			int randomDir = rand() % 4;
			successfulMove = b->moveChessPiece(randomDir, distance); // Move piece and assign boolean 
		} while (successfulMove == false); // Repeat if move isn't valid. 
	}

	if (dynamic_cast<Queen*>(p)) {  // Check if it is a Queen
		Queen* q = dynamic_cast<Queen*>(p);
		bool successfulMove;
		do { // Keep moving piece until it has a valid move 
			float distance = static_cast <float> (rand()) / static_cast <float> (RAND_MAX / MAX_DISTANCE);
			int randomDir = rand() % 4;
			successfulMove = q->moveChessPiece(randomDir, distance); // Move piece and assign boolean 
		} while (successfulMove == false); // Repeat if move isn't valid. 
	}

	if (dynamic_cast<Rook*>(p)) {  // Check if it is a Rook
		Rook* r = dynamic_cast<Rook*>(p);
		bool successfulMove;
		do { // Keep moving piece until it has a valid move 
			float distance = static_cast <float> (rand()) / static_cast <float> (RAND_MAX / MAX_DISTANCE);
			int randomDir = rand() % 4;
			successfulMove = r->moveChessPiece(randomDir, distance); // Move piece and assign boolean 
		} while (successfulMove == false); // Repeat if move isn't valid. 
	}
}
/* Find the winner of the game */
string findWinners() {
	/* Create variables needed */
	string result;
	int *x = max_element(begin(scores), end(scores));

	// No winner 
	if (scores[0] == 0 && scores[1] == 0 && scores[2] == 0) {
		result = string("NO WINNERS! ") + to_string(scores[0]);
		return result;
	}
	// All equal
	if (scores[0] == scores[1] == scores[2]) {
		result = string("DRAW BETWEEN BISHOP, QUEEN AND ROOK. SCORE: ") + to_string(scores[0]);
		return result;
	}
	// Bishop == Queen and theyare the biggest scores.
	if (scores[0] == scores[1] && *x == scores[0]) {
		result = string("DRAW BETWEEN BISHOP AND QUEEN. SCORE: ") + to_string(scores[0]);
		return result;
	}
	// Queen == Rook and they are the biggest scores.
	if (scores[1] == scores[2] && *x == scores[1]) {
		result = string("DRAW BETWEEN QUEEN AND ROOK. SCORE: ") + to_string(scores[1]);
		return result;
	}
	// Bishop == Rook and they are the biggest scores.
	if (scores[0] == scores[2] && *x == scores[0]) {
		result = string("DRAW BETWEEN BISHOP AND ROOK. SCORE: ") + to_string(scores[0]);
		return result;
	}

	// Case where one is equal
	// Run through all different pieces(Rook, Bishop and Queen) 
	int maxValue = 0;
	int index = 0;

	/* Run through all pieces and find max index and value */
	for (size_t x = 0; x < 3; x++) {
		if (scores[x] >= maxValue) {
			maxValue = scores[x];
			index = x;
		}
	}

	switch (index) {
	//Bishop
	case 0:
	{
		result = string("BISHOP IS THE WINNER WITH A SCORE OF: ") + to_string(scores[0]);
		return result;
		break;
	}
	//Queen
	case 1:
	{
		result = string("QUEEN IS THE WINNER WITH A SCORE OF: ") + to_string(scores[1]);
		return result;
		break;
	}
	//Rook
	case 2: 
	{
		result = string("ROOK IS THE WINNER WITH A SCORE OF: ") + to_string(scores[2]);
		return result;
		break;
	}
	}
	// Ensure all control paths return a value.
	return NULL;
}
/*
 Method to clear all memeory allocated 
*/
void clearMemory() {
	for (int i = 0; i < pieceVector.size(); i++)
	{
		delete pieceVector[i];
	}
	pieceVector.clear();
}
/* Main method to run game */
int main() {
	pieceVector.reserve(NUMBER_OF_SHAPES); // Reserve n number of elements within vector 
	srand((unsigned int)time(NULL));
	setUpPieces();	// Setup pieces on the board 
	pieceVector.shrink_to_fit(); // Reduce unnessisary space within vector 

	cout << "=============================================     PIECES GENERATED     =============================================" << endl;
	printPieces(); // Print all pieces on the board. 


	cout << "=============================================    INITIAL COLLISIONS    =============================================" << endl;
	bool initialCollisions = true;
	/* Run through all pieces and check initial collisions */
	for (size_t x = 0; x < pieceVector.size(); x++) {
		checkCollisions(initialCollisions, pieceVector[x], x);
	}
	// No longer initial collisions
	initialCollisions = false;

	cout << "============================================= PIECES STARTING THE GAME =============================================" << endl;
	countTypesOfEach(pieceVector); // Count each type of piece before the game
	cout << "Bishops:  " << numberOfPieces[0] << " Queens:  " << numberOfPieces[1] << "  Rooks:  " << numberOfPieces[2] << endl;

	cout << "=============================================      START THE GAME      =============================================" << endl;
	
	// Move each of the pieces 
	int counter = 0;
	for (size_t x = 0; x < MAX_MOVES && pieceVector.size() > 1; x++) {
		for (size_t y = 0; y < pieceVector.size(); y++) {
			movePiece(pieceVector[y]);
			checkCollisions(initialCollisions, pieceVector[y], y);
			//Count moves made. 
			counter++;
		}
	}

	countTypesOfEach(pieceVector);
	cout << "===========================================        END OF GAME        =============================================" << endl;
	cout << "NUMBER OF PIECES :" << "Bishops:  " << numberOfPieces[0] << "  Queens:  " << numberOfPieces[1] << "  Rooks:  " << numberOfPieces[2] << endl;
	cout << "SCORES           :" << "Bishops: " << scores[0] << "  Queen:" << scores[1] << "  Rook:" << scores[2] << endl;
	cout << "MOVES MADE: " << counter << endl;
	cout <<"==============                     => "  << findWinners() << " <=                     ==============" << endl;
	cout << "===================================================================================================================" << endl;

	// Free up memory 
	clearMemory();
	system("pause");
}


