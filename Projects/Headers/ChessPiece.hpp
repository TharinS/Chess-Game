#pragma once
#include "ChessMain.hpp"



static void colorCell(vector<ChessCell> &ChessBoard, int IndexValue, int OffsetIndex, char Type) {
    switch (Type) {
        case 'E': /*Empty or Vacant*/
            ChessBoard[OffsetIndex].setFillColor(Color(0, 208, 36, 255));
            ChessBoard[OffsetIndex].setIsSelected(true);
            ChessBoard[OffsetIndex].setRootIndex(IndexValue);
            ChessBoard[OffsetIndex].setColorType(Type);
            break;
        case 'T': /*Target*/
            ChessBoard[OffsetIndex].setFillColor(Color(255, 0, 0, 255));
            ChessBoard[OffsetIndex].setIsSelected(true);
            ChessBoard[OffsetIndex].setRootIndex(IndexValue);
            ChessBoard[OffsetIndex].setColorType(Type);
            break;
        case 'P': /*Speacial Rule - En Passant*/
            break;
        case 'C': /*Special Rule - Castling */
            break;
    }
}

Color getTargetColor(char Type) {
    switch (Type) {
        case 'E':
            return Color(0, 208, 36, 255);
            break;
        case 'T':
            return Color(255, 0, 0, 255);
            break;
        case 'S':
            return Color(128, 255, 255, 255);
    }
    return Color(0, 208, 36, 255);
}

static void DisplayKingMoves(vector<ChessCell> &ChessBoard, int IndexValue) {
    int x = IndexValue % SIZE;
    int y = IndexValue / SIZE;
    int OffsetIndex = 0;

    if ((IndexValue - 8 < 64) && (IndexValue - 8 >= 0)) {
        if ((IndexValue + 1 < 64) && (IndexValue + 1 >= 0)) {
            OffsetIndex = IndexValue - 8;
            OffsetIndex = OffsetIndex - 1;
            if (ChessBoard[OffsetIndex].getPiece() == 'E') {
                colorCell(ChessBoard, IndexValue, OffsetIndex, 'E');
            } else if ((ChessBoard[OffsetIndex].getPiece() != 'E') && (ChessBoard[OffsetIndex].getTeam() != ChessBoard[IndexValue].getTeam())) {
                colorCell(ChessBoard, IndexValue, OffsetIndex, 'T');
            }
        }
        if ((IndexValue - 1 < 64) && (IndexValue - 1 >= 0)) {
            OffsetIndex = IndexValue - 8;
            OffsetIndex = OffsetIndex + 1;
            if (ChessBoard[OffsetIndex].getPiece() == 'E') {
                colorCell(ChessBoard, IndexValue, OffsetIndex, 'E');
            } else if ((ChessBoard[OffsetIndex].getPiece() != 'E') && (ChessBoard[OffsetIndex].getTeam() != ChessBoard[IndexValue].getTeam())) {
                colorCell(ChessBoard, IndexValue, OffsetIndex, 'T');
            }
        }
        OffsetIndex = IndexValue - 8;
        if (ChessBoard[OffsetIndex].getPiece() == 'E') {
            colorCell(ChessBoard, IndexValue, OffsetIndex, 'E');
        } else if ((ChessBoard[OffsetIndex].getPiece() != 'E') && (ChessBoard[OffsetIndex].getTeam() != ChessBoard[IndexValue].getTeam())) {
            colorCell(ChessBoard, IndexValue, OffsetIndex, 'T');
        }
    }

    if ((IndexValue + 8 < 64) && (IndexValue + 8 >= 0)) {
        if ((IndexValue + 1 < 64) && (IndexValue + 1 >= 0)) {
            OffsetIndex = IndexValue + 8;
            OffsetIndex = OffsetIndex - 1;
            if (ChessBoard[OffsetIndex].getPiece() == 'E') {
                colorCell(ChessBoard, IndexValue, OffsetIndex, 'E');
            } else if ((ChessBoard[OffsetIndex].getPiece() != 'E') && (ChessBoard[OffsetIndex].getTeam() != ChessBoard[IndexValue].getTeam())) {
                colorCell(ChessBoard, IndexValue, OffsetIndex, 'T');
            }
        }
        if ((IndexValue - 1 < 64) && (IndexValue - 1 >= 0)) {
            OffsetIndex = IndexValue + 8;
            OffsetIndex = OffsetIndex + 1;
            if (ChessBoard[OffsetIndex].getPiece() == 'E') {
                colorCell(ChessBoard, IndexValue, OffsetIndex, 'E');
            } else if ((ChessBoard[OffsetIndex].getPiece() != 'E') && (ChessBoard[OffsetIndex].getTeam() != ChessBoard[IndexValue].getTeam())) {
                colorCell(ChessBoard, IndexValue, OffsetIndex, 'T');
            }
        }
        OffsetIndex = IndexValue + 8;
        if (ChessBoard[OffsetIndex].getPiece() == 'E') {
            colorCell(ChessBoard, IndexValue, OffsetIndex, 'E');
        } else if ((ChessBoard[OffsetIndex].getPiece() != 'E') && (ChessBoard[OffsetIndex].getTeam() != ChessBoard[IndexValue].getTeam())) {
            colorCell(ChessBoard, IndexValue, OffsetIndex, 'T');
        }
    }

    if ((IndexValue - 1 < SIZE * SIZE) && (IndexValue - 1 >= 0)) {
        OffsetIndex = IndexValue - 1;
        if (ChessBoard[OffsetIndex].getPiece() == 'E') {
            colorCell(ChessBoard, IndexValue, OffsetIndex, 'E');
        } else if ((ChessBoard[OffsetIndex].getPiece() != 'E') && (ChessBoard[OffsetIndex].getTeam() != ChessBoard[IndexValue].getTeam())) {
            colorCell(ChessBoard, IndexValue, OffsetIndex, 'T');
        }
    }
    if ((IndexValue + 1 < SIZE * SIZE) && (IndexValue + 1 >= 0)) {
        OffsetIndex = IndexValue + 1;
        if (ChessBoard[OffsetIndex].getPiece() == 'E') {
            colorCell(ChessBoard, IndexValue, OffsetIndex, 'E');
        } else if ((ChessBoard[OffsetIndex].getPiece() != 'E') && (ChessBoard[OffsetIndex].getTeam() != ChessBoard[IndexValue].getTeam())) {
            colorCell(ChessBoard, IndexValue, OffsetIndex, 'T');
        }
    }
}

static void DisplayQueenMoves(vector<ChessCell> &ChessBoard, int IndexValue) {
    int x = IndexValue % SIZE;
    int y = IndexValue / SIZE;
    int OffsetIndex = 0;
    //Vertical
    //Up
    for (int i = 8; (IndexValue - i < 64) && (IndexValue - i >= 0); i += 8) {
        OffsetIndex = IndexValue - i;
        if (ChessBoard[OffsetIndex].getPiece() == 'E') {
            colorCell(ChessBoard, IndexValue, OffsetIndex, 'E');
        } else if ((ChessBoard[OffsetIndex].getPiece() != 'E') && (ChessBoard[OffsetIndex].getTeam() != ChessBoard[IndexValue].getTeam())) {
            colorCell(ChessBoard, IndexValue, OffsetIndex, 'T');
            break;
        } else {
            break;
        }
    }
    // //Down
    for (int i = 8; (IndexValue + i < 64) && (IndexValue + i >= 0); i += 8) {
        OffsetIndex = IndexValue + i;
        if (ChessBoard[OffsetIndex].getPiece() == 'E') {
            colorCell(ChessBoard, IndexValue, OffsetIndex, 'E');
        } else if ((ChessBoard[OffsetIndex].getPiece() != 'E') && (ChessBoard[OffsetIndex].getTeam() != ChessBoard[IndexValue].getTeam())) {
            colorCell(ChessBoard, IndexValue, OffsetIndex, 'T');
            break;
        } else {
            break;
        }
    }

    //Horizontal
    //Left
    for (int j = 1, i = x; i > 0; j++, i--) {
        OffsetIndex = IndexValue - j;
        if (ChessBoard[OffsetIndex].getPiece() == 'E') {
            colorCell(ChessBoard, IndexValue, OffsetIndex, 'E');
        } else if ((ChessBoard[OffsetIndex].getPiece() != 'E') && (ChessBoard[OffsetIndex].getTeam() != ChessBoard[IndexValue].getTeam())) {
            colorCell(ChessBoard, IndexValue, OffsetIndex, 'T');
            break;
        } else {
            break;
        }
    }
    //Right
    for (int count = 1, i = x + 1; i < 8; i++, count++) {
        OffsetIndex = IndexValue + count;
        if (ChessBoard[OffsetIndex].getPiece() == 'E') {
            colorCell(ChessBoard, IndexValue, OffsetIndex, 'E');
        } else if ((ChessBoard[OffsetIndex].getPiece() != 'E') && (ChessBoard[OffsetIndex].getTeam() != ChessBoard[IndexValue].getTeam())) {
            colorCell(ChessBoard, IndexValue, OffsetIndex, 'T');
            break;
        } else {
            break;
        }
    }

    //Diagonal
    //Up and Left
    for (int count = 1, j = x, i = 8; (((IndexValue - i < 64) && (IndexValue - i >= 0)) && (j > 0)); i += 8, count++, j--) {
        OffsetIndex = IndexValue - i;
        OffsetIndex -= count;
        if (ChessBoard[OffsetIndex].getPiece() == 'E') {
            colorCell(ChessBoard, IndexValue, OffsetIndex, 'E');
        } else if ((ChessBoard[OffsetIndex].getPiece() != 'E') && (ChessBoard[OffsetIndex].getTeam() != ChessBoard[IndexValue].getTeam())) {
            colorCell(ChessBoard, IndexValue, OffsetIndex, 'T');
            break;
        } else {
            break;
        }
    }
    //Down and Left
    for (int count = 1, j = x, i = 8; (((IndexValue + i < 64) && (IndexValue + i >= 0)) && (j > 0)); i += 8, count++, j--) {
        OffsetIndex = IndexValue + i;
        OffsetIndex -= count;
        if (ChessBoard[OffsetIndex].getPiece() == 'E') {
            colorCell(ChessBoard, IndexValue, OffsetIndex, 'E');
        } else if ((ChessBoard[OffsetIndex].getPiece() != 'E') && (ChessBoard[OffsetIndex].getTeam() != ChessBoard[IndexValue].getTeam())) {
            colorCell(ChessBoard, IndexValue, OffsetIndex, 'T');
            break;
        } else {
            break;
        }
    }
    //Up and Right
    for (int count = 1, j = x + 1, i = 8; (((IndexValue - i < 64) && (IndexValue - i >= 0)) && (j < 8)); i += 8, count++, j++) {
        OffsetIndex = IndexValue - i;
        OffsetIndex += count;
        if (ChessBoard[OffsetIndex].getPiece() == 'E') {
            colorCell(ChessBoard, IndexValue, OffsetIndex, 'E');
        } else if ((ChessBoard[OffsetIndex].getPiece() != 'E') && (ChessBoard[OffsetIndex].getTeam() != ChessBoard[IndexValue].getTeam())) {
            colorCell(ChessBoard, IndexValue, OffsetIndex, 'T');
            break;
        } else {
            break;
        }
    }
    //Down and Right
    for (int count = 1, j = x + 1, i = 8; (((IndexValue + i < 64) && (IndexValue + i >= 0)) && (j < 8)); i += 8, count++, j++) {
        OffsetIndex = IndexValue + i;
        OffsetIndex += count;
        if (ChessBoard[OffsetIndex].getPiece() == 'E') {
            colorCell(ChessBoard, IndexValue, OffsetIndex, 'E');
        } else if ((ChessBoard[OffsetIndex].getPiece() != 'E') && (ChessBoard[OffsetIndex].getTeam() != ChessBoard[IndexValue].getTeam())) {
            colorCell(ChessBoard, IndexValue, OffsetIndex, 'T');
            break;
        } else {
            break;
        }
    }
}

static void DisplayBishopMoves(vector<ChessCell> &ChessBoard, int IndexValue) {
    int x = IndexValue % SIZE;
    int y = IndexValue / SIZE;
    int OffsetIndex = 0;

    //Diagonal
    //Up and Left
    for (int count = 1, j = x, i = 8; (((IndexValue - i < 64) && (IndexValue - i >= 0)) && (j > 0)); i += 8, count++, j--) {
        OffsetIndex = IndexValue - i;
        OffsetIndex -= count;
        if (ChessBoard[OffsetIndex].getPiece() == 'E') {
            colorCell(ChessBoard, IndexValue, OffsetIndex, 'E');
        } else if ((ChessBoard[OffsetIndex].getPiece() != 'E') && (ChessBoard[OffsetIndex].getTeam() != ChessBoard[IndexValue].getTeam())) {
            colorCell(ChessBoard, IndexValue, OffsetIndex, 'T');
            break;
        } else {
            break;
        }
    }
    //Down and Left
    for (int count = 1, j = x, i = 8; (((IndexValue + i < 64) && (IndexValue + i >= 0)) && (j > 0)); i += 8, count++, j--) {
        OffsetIndex = IndexValue + i;
        OffsetIndex -= count;
        if (ChessBoard[OffsetIndex].getPiece() == 'E') {
            colorCell(ChessBoard, IndexValue, OffsetIndex, 'E');
        } else if ((ChessBoard[OffsetIndex].getPiece() != 'E') && (ChessBoard[OffsetIndex].getTeam() != ChessBoard[IndexValue].getTeam())) {
            colorCell(ChessBoard, IndexValue, OffsetIndex, 'T');
            break;
        } else {
            break;
        }
    }
    //Up and Right
    for (int count = 1, j = x + 1, i = 8; (((IndexValue - i < 64) && (IndexValue - i >= 0)) && (j < 8)); i += 8, count++, j++) {
        OffsetIndex = IndexValue - i;
        OffsetIndex += count;
        if (ChessBoard[OffsetIndex].getPiece() == 'E') {
            colorCell(ChessBoard, IndexValue, OffsetIndex, 'E');
        } else if ((ChessBoard[OffsetIndex].getPiece() != 'E') && (ChessBoard[OffsetIndex].getTeam() != ChessBoard[IndexValue].getTeam())) {
            colorCell(ChessBoard, IndexValue, OffsetIndex, 'T');
            break;
        } else {
            break;
        }
    }
    //Down and Right
    for (int count = 1, j = x + 1, i = 8; (((IndexValue + i < 64) && (IndexValue + i >= 0)) && (j < 8)); i += 8, count++, j++) {
        OffsetIndex = IndexValue + i;
        OffsetIndex += count;
        if (ChessBoard[OffsetIndex].getPiece() == 'E') {
            colorCell(ChessBoard, IndexValue, OffsetIndex, 'E');
        } else if ((ChessBoard[OffsetIndex].getPiece() != 'E') && (ChessBoard[OffsetIndex].getTeam() != ChessBoard[IndexValue].getTeam())) {
            colorCell(ChessBoard, IndexValue, OffsetIndex, 'T');
            break;
        } else {
            break;
        }
    }
}

static void DisplayRookMoves(vector<ChessCell> &ChessBoard, int IndexValue) {
    int x = IndexValue % SIZE;
    int y = IndexValue / SIZE;
    int OffsetIndex = 0;
    //Vertical
    //Up
    for (int i = 8; ((IndexValue - i) < 64) && ((IndexValue - i) >= 0); i += 8) {
        OffsetIndex = IndexValue - i;
        if (ChessBoard[OffsetIndex].getPiece() == 'E') {
            colorCell(ChessBoard, IndexValue, OffsetIndex, 'E');
        } else if ((ChessBoard[OffsetIndex].getPiece() != 'E') && (ChessBoard[OffsetIndex].getTeam() != ChessBoard[IndexValue].getTeam())) {
            colorCell(ChessBoard, IndexValue, OffsetIndex, 'T');
            break;
        } else {
            break;
        }
    }
    // //Down
    for (int i = 8; ((IndexValue + i) < 64) && ((IndexValue + i) >= 0); i += 8) {
        OffsetIndex = IndexValue + i;
        if (ChessBoard[OffsetIndex].getPiece() == 'E') {
            colorCell(ChessBoard, IndexValue, OffsetIndex, 'E');
        } else if ((ChessBoard[OffsetIndex].getPiece() != 'E') && (ChessBoard[OffsetIndex].getTeam() != ChessBoard[IndexValue].getTeam())) {
            colorCell(ChessBoard, IndexValue, OffsetIndex, 'T');
            break;
        } else {
            break;
        }
    }

    //Horizontal
    //Left
    for (int i = x, j = 1; i > 0; i--, j++) {
        OffsetIndex = IndexValue - j;
        if (ChessBoard[OffsetIndex].getPiece() == 'E') {
            colorCell(ChessBoard, IndexValue, OffsetIndex, 'E');
        } else if ((ChessBoard[OffsetIndex].getPiece() != 'E') && (ChessBoard[OffsetIndex].getTeam() != ChessBoard[IndexValue].getTeam())) {
            colorCell(ChessBoard, IndexValue, OffsetIndex, 'T');
            break;
        } else {
            break;
        }
    }
    //Right
    for (int count = 1, i = x + 1; i < 8; i++, count++) {
        OffsetIndex = IndexValue + count;
        if (ChessBoard[OffsetIndex].getPiece() == 'E') {
            colorCell(ChessBoard, IndexValue, OffsetIndex, 'E');
        } else if ((ChessBoard[OffsetIndex].getPiece() != 'E') && (ChessBoard[OffsetIndex].getTeam() != ChessBoard[IndexValue].getTeam())) {
            colorCell(ChessBoard, IndexValue, OffsetIndex, 'T');
            break;
        } else {
            break;
        }
    }
}

static void DisplayKnightMoves(vector<ChessCell> &ChessBoard, int IndexValue) {
    int x = IndexValue % SIZE;
    int y = IndexValue / SIZE;
    int OffsetIndex = 0;

    if ((IndexValue - 16 < 64) && (IndexValue - 16 >= 0)) {
        if ((IndexValue - 1 < 64) && (IndexValue - 1 >= 0)) {
            OffsetIndex = IndexValue - 16;
            OffsetIndex -= 1;
            if (ChessBoard[OffsetIndex].getPiece() == 'E') {
                colorCell(ChessBoard, IndexValue, OffsetIndex, 'E');
            } else if ((ChessBoard[OffsetIndex].getPiece() != 'E') && (ChessBoard[OffsetIndex].getTeam() != ChessBoard[IndexValue].getTeam())) {
                colorCell(ChessBoard, IndexValue, OffsetIndex, 'T');
            }
        }
        if ((IndexValue + 1 < 64) && (IndexValue + 1 >= 0)) {
            OffsetIndex = IndexValue - 16;
            OffsetIndex += 1;
            if (ChessBoard[OffsetIndex].getPiece() == 'E') {
                colorCell(ChessBoard, IndexValue, OffsetIndex, 'E');
            } else if ((ChessBoard[OffsetIndex].getPiece() != 'E') && (ChessBoard[OffsetIndex].getTeam() != ChessBoard[IndexValue].getTeam())) {
                colorCell(ChessBoard, IndexValue, OffsetIndex, 'T');
            }
        }
    }

    if ((IndexValue + 16 < 64) && (IndexValue + 16 >= 0)) {
        if ((IndexValue - 1 < 64) && (IndexValue - 1 >= 0)) {
            OffsetIndex = IndexValue + 16;
            OffsetIndex -= 1;
            if (ChessBoard[OffsetIndex].getPiece() == 'E') {
                colorCell(ChessBoard, IndexValue, OffsetIndex, 'E');
            } else if ((ChessBoard[OffsetIndex].getPiece() != 'E') && (ChessBoard[OffsetIndex].getTeam() != ChessBoard[IndexValue].getTeam())) {
                colorCell(ChessBoard, IndexValue, OffsetIndex, 'T');
            }
        }
        if ((IndexValue + 1 < 64) && (IndexValue + 1 >= 0)) {
            OffsetIndex = IndexValue + 16;
            OffsetIndex += 1;
            if (ChessBoard[OffsetIndex].getPiece() == 'E') {
                colorCell(ChessBoard, IndexValue, OffsetIndex, 'E');
            } else if ((ChessBoard[OffsetIndex].getPiece() != 'E') && (ChessBoard[OffsetIndex].getTeam() != ChessBoard[IndexValue].getTeam())) {
                colorCell(ChessBoard, IndexValue, OffsetIndex, 'T');
            }
        }
    }

    if ((x + 2 < 8) && (x + 2 >= 0)) {
        if ((IndexValue - 8 < 64) && (IndexValue - 8 >= 0)) {
            OffsetIndex = IndexValue + 2;
            OffsetIndex -= 8;
            if (ChessBoard[OffsetIndex].getPiece() == 'E') {
                colorCell(ChessBoard, IndexValue, OffsetIndex, 'E');
            } else if ((ChessBoard[OffsetIndex].getPiece() != 'E') && (ChessBoard[OffsetIndex].getTeam() != ChessBoard[IndexValue].getTeam())) {
                colorCell(ChessBoard, IndexValue, OffsetIndex, 'T');
            }
        }
        if ((IndexValue + 8 < 64) && (IndexValue + 8 >= 0)) {
            OffsetIndex = IndexValue + 2;
            OffsetIndex += 8;
            if (ChessBoard[OffsetIndex].getPiece() == 'E') {
                colorCell(ChessBoard, IndexValue, OffsetIndex, 'E');
            } else if ((ChessBoard[OffsetIndex].getPiece() != 'E') && (ChessBoard[OffsetIndex].getTeam() != ChessBoard[IndexValue].getTeam())) {
                colorCell(ChessBoard, IndexValue, OffsetIndex, 'T');
            }
        }
    }

    if ((x - 2 < 8) && (x - 2 >= 0)) {
        if ((IndexValue - 8 < 64) && (IndexValue - 8 >= 0)) {
            OffsetIndex = IndexValue - 2;
            OffsetIndex -= 8;
            if (ChessBoard[OffsetIndex].getPiece() == 'E') {
                colorCell(ChessBoard, IndexValue, OffsetIndex, 'E');
            } else if ((ChessBoard[OffsetIndex].getPiece() != 'E') && (ChessBoard[OffsetIndex].getTeam() != ChessBoard[IndexValue].getTeam())) {
                colorCell(ChessBoard, IndexValue, OffsetIndex, 'T');
            }
        }
        if ((IndexValue + 8 < 64) && (IndexValue + 8 >= 0)) {
            OffsetIndex = IndexValue - 2;
            OffsetIndex += 8;
            if (ChessBoard[OffsetIndex].getPiece() == 'E') {
                colorCell(ChessBoard, IndexValue, OffsetIndex, 'E');
            } else if ((ChessBoard[OffsetIndex].getPiece() != 'E') && (ChessBoard[OffsetIndex].getTeam() != ChessBoard[IndexValue].getTeam())) {
                colorCell(ChessBoard, IndexValue, OffsetIndex, 'T');
            }
        }
    }
}

static void DisplayAllWhitePawnMoves(vector<ChessCell> &ChessBoard, int IndexValue) {
    int x = IndexValue % SIZE;
    int y = IndexValue / SIZE;
    int OffsetIndex = 0;

    if ((IndexValue - 8 < 64) && (IndexValue - 8 >= 0)) {
        OffsetIndex = IndexValue - 8;
        if (ChessBoard[OffsetIndex].getPiece() == 'E') {
            colorCell(ChessBoard, IndexValue, OffsetIndex, 'E');

            if ((ChessBoard[IndexValue].getNoMoves() == 0) && ((IndexValue - 16 < 64) && (IndexValue - 16 >= 0))) {
                OffsetIndex = IndexValue - 16;
                if (ChessBoard[OffsetIndex].getPiece() == 'E') {
                    colorCell(ChessBoard, IndexValue, OffsetIndex, 'E');
                } else if ((ChessBoard[OffsetIndex].getPiece() != 'E') && !ChessBoard[OffsetIndex].getTeam()) {
                    colorCell(ChessBoard, IndexValue, OffsetIndex, 'T');
                }
            }

        } else if ((ChessBoard[OffsetIndex].getPiece() != 'E') && !ChessBoard[OffsetIndex].getTeam()) {
            colorCell(ChessBoard, IndexValue, OffsetIndex, 'T');
        }

        if ((x - 1 < 8) && (x - 1 >= 0)) {
            OffsetIndex = IndexValue - 8;
            OffsetIndex = OffsetIndex - 1;
            if ((ChessBoard[OffsetIndex].getPiece() != 'E') && !ChessBoard[OffsetIndex].getTeam()) {
                colorCell(ChessBoard, IndexValue, OffsetIndex, 'T');
            }
        }
        if ((x + 1 < 8) && (x + 1 >= 0)) {
            OffsetIndex = IndexValue - 8;
            OffsetIndex = OffsetIndex + 1;
            if ((ChessBoard[OffsetIndex].getPiece() != 'E') && !ChessBoard[OffsetIndex].getTeam()) {
                colorCell(ChessBoard, IndexValue, OffsetIndex, 'T');
            }
        }
    }
}

static void DisplayAllBlackPawnMoves(vector<ChessCell> &ChessBoard, int IndexValue) {
    int x = IndexValue % SIZE;
    int y = IndexValue / SIZE;
    int OffsetIndex = 0;

    if ((IndexValue + 8 < 64) && (IndexValue + 8 >= 0)) {
        OffsetIndex = IndexValue + 8;
        if (ChessBoard[OffsetIndex].getPiece() == 'E') {
            colorCell(ChessBoard, IndexValue, OffsetIndex, 'E');

            if ((ChessBoard[IndexValue].getNoMoves() == 0) && ((IndexValue + 16 < 64) && (IndexValue + 16 >= 0))) {
                OffsetIndex = IndexValue + 16;
                if (ChessBoard[OffsetIndex].getPiece() == 'E') {
                    colorCell(ChessBoard, IndexValue, OffsetIndex, 'E');
                } else if ((ChessBoard[OffsetIndex].getPiece() != 'E') && ChessBoard[OffsetIndex].getTeam()) {
                    colorCell(ChessBoard, IndexValue, OffsetIndex, 'T');
                }
                
            }

        } else if ((ChessBoard[OffsetIndex].getPiece() != 'E') && (ChessBoard[OffsetIndex].getTeam())) {
            colorCell(ChessBoard, IndexValue, OffsetIndex, 'T');
        }

        if ((x - 1 < 8) && (x - 1 >= 0)) {
            OffsetIndex = IndexValue + 8;
            OffsetIndex = OffsetIndex - 1;
            if ((ChessBoard[OffsetIndex].getPiece() != 'E') && ChessBoard[OffsetIndex].getTeam()) {
                colorCell(ChessBoard, IndexValue, OffsetIndex, 'T');
            }
        }

        if ((x + 1 < 8) && (x + 1 >= 0)) {
            OffsetIndex = IndexValue + 8;
            OffsetIndex = OffsetIndex + 1;
            if ((ChessBoard[OffsetIndex].getPiece() != 'E') && ChessBoard[OffsetIndex].getTeam()) {
                colorCell(ChessBoard, IndexValue, OffsetIndex, 'T');
            }
        }
    }
}

void DisplayPossibleMoves(vector<ChessCell> &ChessBoard, int IndexValue) {
    switch (ChessBoard[IndexValue].getPiece()) {
        case 'k':
        case 'K':
            ChessBoard[IndexValue].setDisplayingMoves(true);
            DisplayKingMoves(ChessBoard, IndexValue);
            break;
        case 'q':
        case 'Q':
            ChessBoard[IndexValue].setDisplayingMoves(true);
            DisplayQueenMoves(ChessBoard, IndexValue);
            break;
        case 'b':
        case 'B':
            ChessBoard[IndexValue].setDisplayingMoves(true);
            DisplayBishopMoves(ChessBoard, IndexValue);
            break;
        case 'r':
        case 'R':
            ChessBoard[IndexValue].setDisplayingMoves(true);
            DisplayRookMoves(ChessBoard, IndexValue);
            break;
        case 'n':
        case 'N':
            ChessBoard[IndexValue].setDisplayingMoves(true);
            DisplayKnightMoves(ChessBoard, IndexValue);
            break;
        case 'p':
            ChessBoard[IndexValue].setDisplayingMoves(true);
            DisplayAllBlackPawnMoves(ChessBoard, IndexValue);
            break;
        case 'P':
            ChessBoard[IndexValue].setDisplayingMoves(true);
            DisplayAllWhitePawnMoves(ChessBoard, IndexValue);
            break;
        case 'E':
            break;
    }
}

void disableMoveView(vector<ChessCell> &ChessBoard) {
    for (int Index = 0; Index < SIZE * SIZE; Index++) {
        ChessBoard[Index].setFillColor(Color(255, 255, 255, 255));
    }
}