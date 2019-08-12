# SpaceChessGame
An important topic in many computer games is determining when 2 object collide with one another.
Games looks poor if a car appears to drive into a wall or appear to collide with thin air. Physics Engines
devote considerable effort to solving this problem. In this Project we will start to consider this issue.

Implement an abstract base class Piece to represent moving chess pieces in a game. Derive classes
Rook, Bishop and Queen in an appropriate inheritance hierarchy from Piece with
appropriate information to store the positions on a flat, square 2_D surface. The classes should
provide methods to move the position of the piece by teleportation so that you are only interested in
the final position of the piece and not its journey through space to arrive there. A Rook moves
vertically or horizontally across the grid. A Bishop moves diagonally in any direction. A Queen can
move either like a Rook or a Bishop (as in real chess). Distances moved need not be integers.

In this game pieces capture by colliding with another piece during the course of their move. For the
purposes of capture, pieces are represented by 2 dimensional shapes (a circle for Bishops and Queen
and a Square for rooks). All pieces have a radius of 1 unit or a side length of 2 units in the case of the
rook. You will need to provide methods to detect when two pieces overlap whereupon the nonmoving piece is removed from the board. You will need to deal with overlap of 2 circles, 2 squares and
circle and square separately.

Write a test game program that creates several pieces and stores them in an array or list or other data
structure of your choosing. The program should then iterate through the data, move each shape by a
small random amount (but keeping them within a grid of a given size) and check to see if there are
any captures. Keep a score of the number of captures made by each of the 3 types of piece. If a capture
is detected then the non-moving piece should be removed from the data structure and the moving
piece should stop at the position where the capture is detected. The game should continue for a given
number of moves by each piece (say 100 or whatever you deem appropriate) but should terminate
earlier if at most one piece remains. 
