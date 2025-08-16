#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

using namespace sf;
using namespace std;

#define SIZE 8

/* Global Variables */
int Round = 1;
int deltaRound = Round;

/*Corresponding texture coordinate for each piece with the various backgrounds*/
typedef struct chesspiece {
    // Black Background
    IntRect BBQ = IntRect(0, 200, 200, 200), BBK = IntRect(200, 200, 200, 200), BBB = IntRect(400, 200, 200, 200), BBN = IntRect(600, 200, 200, 200), BBR = IntRect(800, 200, 200, 200), BBP = IntRect(1000, 200, 200, 200);
    IntRect BWQ = IntRect(0, 0, 200, 200), BWK = IntRect(200, 0, 200, 200), BWB = IntRect(400, 0, 200, 200), BWN = IntRect(600, 0, 200, 200), BWR = IntRect(800, 0, 200, 200), BWP = IntRect(1000, 0, 200, 200);
    // White Background
    IntRect WBQ = IntRect(0, 606, 200, 200), WBK = IntRect(200, 606, 200, 200), WBB = IntRect(400, 606, 200, 200), WBN = IntRect(600, 606, 200, 200), WBR = IntRect(800, 606, 200, 200), WBP = IntRect(1000, 606, 200, 200);
    IntRect WWQ = IntRect(0, 406, 200, 200), WWK = IntRect(200, 406, 200, 200), WWB = IntRect(400, 406, 200, 200), WWN = IntRect(600, 406, 200, 200), WWR = IntRect(800, 406, 200, 200), WWP = IntRect(1000, 406, 200, 200);
    IntRect BNone = IntRect(1200, 0, 200, 200);
    IntRect WNone = IntRect(1200, 406, 200, 200);
} ChessPiece;

/*Basic value each chess piece is worth where 1 point is worth 1 pawn*/
typedef struct piecevalue {
    const int queenValue = 9;
    const int rookValue = 7;
    const int bishopValue = 3;
    const int knightValue = 3;
    const int pawnValue = 1;
} pieceValue;

class ChessPiece {
   private:
   
}