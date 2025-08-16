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
    //Black Background
    IntRect BBQ = IntRect(0, 200, 200, 200), BBK = IntRect(200, 200, 200, 200), BBB = IntRect(400, 200, 200, 200), BBN = IntRect(600, 200, 200, 200), BBR = IntRect(800, 200, 200, 200), BBP = IntRect(1000, 200, 200, 200);
    IntRect BWQ = IntRect(0, 0, 200, 200), BWK = IntRect(200, 0, 200, 200), BWB = IntRect(400, 0, 200, 200), BWN = IntRect(600, 0, 200, 200), BWR = IntRect(800, 0, 200, 200), BWP = IntRect(1000, 0, 200, 200);
    //White Background
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

class ChessCell : public RectangleShape {
   public:
    void setColor(bool ColorValue) {
        BackgroundColor = ColorValue;
    }

    bool GetBackgroundColor() {
        return BackgroundColor;
    }

    void setPiece(char Piece) {
        PieceName = Piece;
    }

    char getPiece() {
        return PieceName;
    }

    void setIsSelected(bool State) {
        isSelected = State;
    }

    bool getIsSelected() {
        return isSelected;
    }

    void setPreviousColor(Color color) {
        PreviousColor = color;
    }

    Color getPreviousColor() {
        return PreviousColor;
    }

    void setRootIndex(int root) {
        rootIndex = root;
    }

    void resetRootIndex() {
        rootIndex = 64;
    }

    int getRootIndex() {
        return rootIndex;
    }

    void resetPiece() {
        PieceName = 'E';
    }

    void setDisplayingMoves(bool State) {
        displayingMoves = true;
    }

    bool getDisplayMoves() {
        return displayingMoves;
    }

    void setTeam(bool TeamValue) {
        team = TeamValue;
    }

    bool getTeam() {
        return team;
    }

    void updateNoMoves() {
        ++noMoves;
    }

    void setNoMoves(int Moves) {
        noMoves = Moves;
    }

    int getNoMoves() {
        return noMoves;
    }

    void resetNoMoves() {
        noMoves = 0;
    }

    void setColorType(char Type) {
        colorType = Type;
    }

    char getColorType() {
        return colorType;
    }

   private:
    Color PreviousColor;
    bool isSelected = false;
    bool displayingMoves = false;
    int rootIndex = 64;          /* 64 - No root index */
    bool team = true;            /* True - White Team False - Black Team */
    bool BackgroundColor = true; /* True - White False - Black */
    char PieceName = 'E';        /* k - Black King q - Black Queen n - Black Knight b - Black Bishop r - Black Rook p - Black Pawn K - White King Q - White Queen N - White Knight B - White Bishop R - White Rook      P - White Pawn E - Empty or Vacant */
    int noMoves = 0;             /* Keeps track of how many moves the piece has made */
    char colorType;              /* Keeps track of the target coloring */
};

void clearIsSelected(vector<ChessCell> &ChessBoard) {
    for (int i = 0; i < SIZE * SIZE; i++) {
        ChessBoard[i].setIsSelected(false);
        ChessBoard[i].setRootIndex(64);
        ChessBoard[i].setFillColor(Color(255, 255, 255, 255));
    }
}

void ClearBoard(vector<ChessCell> &ChessBoard, ChessPiece ChessPieceIndex) {
    for (int i = 0; i < 64; i++) {
        if (ChessBoard[i].GetBackgroundColor()) {
            ChessBoard[i].setTextureRect(ChessPieceIndex.WNone);
        } else {
            ChessBoard[i].setTextureRect(ChessPieceIndex.BNone);
        }
    }
}

void setTeam(vector<ChessCell> &ChessBoard) {
    for (int Index = 0; Index < SIZE * SIZE; Index++) {
        if (islower(ChessBoard[Index].getPiece())) {
            ChessBoard[Index].setTeam(false);
        } else {
            ChessBoard[Index].setTeam(true);
        }
    }
}

void ParseFEN(vector<ChessCell> &ChessBoard, string FEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR") {
    ChessPiece ChessPieceIndex;
    int Offset = 0;
    int X = 0, Y = 0;
    ClearBoard(ChessBoard, ChessPieceIndex);
    for (int i = 0; i < FEN.length(); i++) {
        switch (FEN[i]) {
            case 'k':
                ChessBoard[Offset].setPiece('k');
                if (ChessBoard[Offset].GetBackgroundColor()) {
                    ChessBoard[Offset].setTextureRect(ChessPieceIndex.WBK);
                } else {
                    ChessBoard[Offset].setTextureRect(ChessPieceIndex.BBK);
                }
                Offset++;
                break;
            case 'q':
                ChessBoard[Offset].setPiece('q');
                if (ChessBoard[Offset].GetBackgroundColor()) {
                    ChessBoard[Offset].setTextureRect(ChessPieceIndex.WBQ);
                } else {
                    ChessBoard[Offset].setTextureRect(ChessPieceIndex.BBQ);
                }
                Offset++;
                break;
            case 'n':
                ChessBoard[Offset].setPiece('n');
                if (ChessBoard[Offset].GetBackgroundColor()) {
                    ChessBoard[Offset].setTextureRect(ChessPieceIndex.WBN);
                } else {
                    ChessBoard[Offset].setTextureRect(ChessPieceIndex.BBN);
                }
                Offset++;
                break;
            case 'r':
                ChessBoard[Offset].setPiece('r');
                if (ChessBoard[Offset].GetBackgroundColor()) {
                    ChessBoard[Offset].setTextureRect(ChessPieceIndex.WBR);
                } else {
                    ChessBoard[Offset].setTextureRect(ChessPieceIndex.BBR);
                }
                Offset++;
                break;
            case 'b':
                ChessBoard[Offset].setPiece('b');
                if (ChessBoard[Offset].GetBackgroundColor()) {
                    ChessBoard[Offset].setTextureRect(ChessPieceIndex.WBB);
                } else {
                    ChessBoard[Offset].setTextureRect(ChessPieceIndex.BBB);
                }
                Offset++;
                break;
            case 'p':
                ChessBoard[Offset].setPiece('p');
                if (ChessBoard[Offset].GetBackgroundColor()) {
                    ChessBoard[Offset].setTextureRect(ChessPieceIndex.WBP);
                } else {
                    ChessBoard[Offset].setTextureRect(ChessPieceIndex.BBP);
                }
                Offset++;
                break;
            case 'K':
                ChessBoard[Offset].setPiece('K');
                if (ChessBoard[Offset].GetBackgroundColor()) {
                    ChessBoard[Offset].setTextureRect(ChessPieceIndex.WWK);
                } else {
                    ChessBoard[Offset].setTextureRect(ChessPieceIndex.BWK);
                }
                Offset++;
                break;
            case 'Q':
                ChessBoard[Offset].setPiece('Q');
                if (ChessBoard[Offset].GetBackgroundColor()) {
                    ChessBoard[Offset].setTextureRect(ChessPieceIndex.WWQ);
                } else {
                    ChessBoard[Offset].setTextureRect(ChessPieceIndex.BWQ);
                }
                Offset++;
                break;
            case 'N':
                ChessBoard[Offset].setPiece('N');
                if (ChessBoard[Offset].GetBackgroundColor()) {
                    ChessBoard[Offset].setTextureRect(ChessPieceIndex.WWN);
                } else {
                    ChessBoard[Offset].setTextureRect(ChessPieceIndex.BWN);
                }
                Offset++;
                break;
            case 'R':
                ChessBoard[Offset].setPiece('R');
                if (ChessBoard[Offset].GetBackgroundColor()) {
                    ChessBoard[Offset].setTextureRect(ChessPieceIndex.WWR);
                } else {
                    ChessBoard[Offset].setTextureRect(ChessPieceIndex.BWR);
                }
                Offset++;
                break;
            case 'B':
                ChessBoard[Offset].setPiece('B');
                if (ChessBoard[Offset].GetBackgroundColor()) {
                    ChessBoard[Offset].setTextureRect(ChessPieceIndex.WWB);
                } else {
                    ChessBoard[Offset].setTextureRect(ChessPieceIndex.BWB);
                }
                Offset++;
                break;
            case 'P':
                ChessBoard[Offset].setPiece('P');
                if (ChessBoard[Offset].GetBackgroundColor()) {
                    ChessBoard[Offset].setTextureRect(ChessPieceIndex.WWP);
                } else {
                    ChessBoard[Offset].setTextureRect(ChessPieceIndex.BWP);
                }
                Offset++;
                break;
        }
        if (isdigit(FEN[i])) {
            Offset += FEN[i] - 48;
        }
    }
    setTeam(ChessBoard);
}

void RemovePiece(vector<ChessCell> &ChessBoard, int Index) {
    ChessPiece ChessPieceIndex;

    if (ChessBoard[Index].GetBackgroundColor()) {
        ChessBoard[Index].setTextureRect(ChessPieceIndex.WNone);
    } else {
        ChessBoard[Index].setTextureRect(ChessPieceIndex.BNone);
    }
    ChessBoard[Index].setRootIndex(64);
    ChessBoard[Index].setIsSelected(false);
}

IntRect ReturnRect(vector<ChessCell> ChessBoard, int RootIndex, int CurrentIndex) {
    ChessPiece ChessPieceIndex;

    switch (ChessBoard[RootIndex].getPiece()) {
        case 'k':
            if (ChessBoard[CurrentIndex].GetBackgroundColor()) {
                return ChessPieceIndex.WBK;
            } else {
                return ChessPieceIndex.BBK;
            }
            break;
        case 'q':
            if (ChessBoard[CurrentIndex].GetBackgroundColor()) {
                return ChessPieceIndex.WBQ;
            } else {
                return ChessPieceIndex.BBQ;
            }
            break;
        case 'b':
            if (ChessBoard[CurrentIndex].GetBackgroundColor()) {
                return ChessPieceIndex.WBB;
            } else {
                return ChessPieceIndex.BBB;
            }
            break;
        case 'r':
            if (ChessBoard[CurrentIndex].GetBackgroundColor()) {
                return ChessPieceIndex.WBR;
            } else {
                return ChessPieceIndex.BBR;
            }
            break;
        case 'n':
            if (ChessBoard[CurrentIndex].GetBackgroundColor()) {
                return ChessPieceIndex.WBN;
            } else {
                return ChessPieceIndex.BBN;
            }
            break;
        case 'p':
            if (ChessBoard[CurrentIndex].GetBackgroundColor()) {
                return ChessPieceIndex.WBP;
            } else {
                return ChessPieceIndex.BBP;
            }
            break;
        case 'K':
            if (ChessBoard[CurrentIndex].GetBackgroundColor()) {
                return ChessPieceIndex.WWK;
            } else {
                return ChessPieceIndex.WWK;
            }
            break;
        case 'Q':
            if (ChessBoard[CurrentIndex].GetBackgroundColor()) {
                return ChessPieceIndex.WWQ;
            } else {
                return ChessPieceIndex.WWQ;
            }
            break;
        case 'B':
            if (ChessBoard[CurrentIndex].GetBackgroundColor()) {
                return ChessPieceIndex.WWB;
            } else {
                return ChessPieceIndex.BWB;
            }
            break;
        case 'R':
            if (ChessBoard[CurrentIndex].GetBackgroundColor()) {
                return ChessPieceIndex.WWR;
            } else {
                return ChessPieceIndex.BWR;
            }
            break;
        case 'N':
            if (ChessBoard[CurrentIndex].GetBackgroundColor()) {
                return ChessPieceIndex.WWN;
            } else {
                return ChessPieceIndex.BWN;
            }
            break;
        case 'P':
            if (ChessBoard[CurrentIndex].GetBackgroundColor()) {
                return ChessPieceIndex.WWP;
            } else {
                return ChessPieceIndex.BWP;
            }
            break;
    }

    if (ChessBoard[CurrentIndex].GetBackgroundColor()) {
        return ChessPieceIndex.WNone;
    }
    return ChessPieceIndex.BNone;
}

void swapData(vector<ChessCell> &ChessBoard, int currentIndex) {
    int rootIndex = ChessBoard[currentIndex].getRootIndex();

    //Moving and updating data from the root index to the current index
    ChessBoard[currentIndex].setTextureRect(ReturnRect(ChessBoard, rootIndex, currentIndex));
    ChessBoard[currentIndex].setTeam(ChessBoard[rootIndex].getTeam());
    ChessBoard[currentIndex].setPiece(ChessBoard[rootIndex].getPiece());
    ChessBoard[currentIndex].setNoMoves(ChessBoard[rootIndex].getNoMoves());
    ChessBoard[currentIndex].updateNoMoves();
    ChessBoard[currentIndex].resetRootIndex();

    //Resetting the original state of the cell and updating the texture
    ChessBoard[rootIndex].resetNoMoves();
    ChessBoard[rootIndex].resetPiece();
    RemovePiece(ChessBoard, rootIndex);
}