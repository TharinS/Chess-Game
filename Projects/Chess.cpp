#include <stdio.h>

#include <iostream>

#include "Headers/ChessMain.hpp"
#include "Headers/ChessPiece.hpp"

using namespace sf;
using namespace std;

void displayRound(int roundNum) {
    printf("Round - %d\r", roundNum);
}

int main() {
    bool State_select = false;
    bool State_displayingMoves = false;
    bool State_hoveringoverMove = false;

    //Starting player scores
    int Player1 = 16, Player2 = 16;

    RenderWindow MainWindow(VideoMode(800, 800), "Chess Game", Style::Close | Style::Titlebar);

    ChessPiece ChessPieceIndex;

    /* Loading font file into application */
    Font font;
    if (!font.loadFromFile("Projects\\Resources\\Font\\Blackwood Castle.ttf")) {
        cout << "Failed to load font file" << endl;
    }

    /* Loading in icon image file */
    Image icon;
    if (!icon.loadFromFile("Projects\\Resources\\Icon.png")) {
        cout << "Failed to load icon file" << endl;
    }

    MainWindow.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    //Loading in the Main texture file for the chess pieces
    Texture ChessPieces;
    if (!ChessPieces.loadFromFile("Projects\\Resources\\ChessPieces.png")) {
        cout << "Failed to load chess pieces file" << endl;
    }

    ChessPieces.setSmooth(true);

    int X = 0, Y = 0;
    int cellID = 0;
    vector<ChessCell> ChessBoard(SIZE * SIZE);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cellID = SIZE * i + j;
            ChessBoard[cellID].setTexture(&ChessPieces);
            if ((i + j) % 2 == 0) {
                ChessBoard[cellID].setTextureRect(ChessPieceIndex.WNone);
                ChessBoard[cellID].setColor(true);
            } else {
                ChessBoard[cellID].setTextureRect(ChessPieceIndex.BNone);
                ChessBoard[cellID].setColor(false);
            }
            ChessBoard[cellID].setOutlineColor(Color(98, 59, 27, 255));
            ChessBoard[cellID].setOutlineThickness(1);
            ChessBoard[cellID].setSize(Vector2f(100, 100));
            ChessBoard[cellID].setPosition(Vector2f(X, Y));
            X += 100;
        }
        Y += 100;
        X = 0;
    }

    ParseFEN(ChessBoard);

    Event SystemEvent;
    while (MainWindow.isOpen()) {
        displayRound(Round);
        while (MainWindow.pollEvent(SystemEvent)) {
            if (SystemEvent.type == SystemEvent.Closed) {
                MainWindow.close();
            }

            if (SystemEvent.type == SystemEvent.KeyPressed) {
                if (Keyboard::isKeyPressed(Keyboard::E)) {
                    clearIsSelected(ChessBoard);
                }
                if (Keyboard::isKeyPressed(Keyboard::Escape)) {
                    MainWindow.close();
                }

                if (Keyboard::isKeyPressed(Keyboard::R)) {
                    ParseFEN(ChessBoard);
                }
            }
            
            for (int CurrentIndex = 0; CurrentIndex < SIZE * SIZE; CurrentIndex++) {
                if (SystemEvent.type == SystemEvent.MouseButtonPressed) {
                    if (((((ChessBoard[CurrentIndex].getIsSelected()) && (ChessBoard[CurrentIndex].getGlobalBounds().contains(Mouse::getPosition(MainWindow).x, Mouse::getPosition(MainWindow).y)))) && State_displayingMoves) && ((Mouse::isButtonPressed(Mouse::Left)) && (ChessBoard[CurrentIndex].getGlobalBounds().contains(Mouse::getPosition(MainWindow).x, Mouse::getPosition(MainWindow).y)))) {
                        swapData(ChessBoard, CurrentIndex);
                        clearIsSelected(ChessBoard);

                        State_displayingMoves = false;
                        State_hoveringoverMove = false;
                        Round++;
                        break;
                    }

                    if ((!State_displayingMoves) && ((Mouse::isButtonPressed(Mouse::Left)) && (ChessBoard[CurrentIndex].getGlobalBounds().contains(Mouse::getPosition(MainWindow).x, Mouse::getPosition(MainWindow).y)))) {
                        DisplayPossibleMoves(ChessBoard, CurrentIndex);
                        State_displayingMoves = true;
                        break;
                    }

                    if (State_displayingMoves && ((Mouse::isButtonPressed(Mouse::Left)) && (ChessBoard[CurrentIndex].getGlobalBounds().contains(Mouse::getPosition(MainWindow).x, Mouse::getPosition(MainWindow).y)))) {
                        clearIsSelected(ChessBoard);
                        State_displayingMoves = false;
                        break;
                    }
                }
                if ((ChessBoard[CurrentIndex].getIsSelected()) && (ChessBoard[CurrentIndex].getGlobalBounds().contains(Mouse::getPosition(MainWindow).x, Mouse::getPosition(MainWindow).y))) {
                    ChessBoard[CurrentIndex].setFillColor(getTargetColor('S'));
                    State_hoveringoverMove = true;
                }

                if ((ChessBoard[CurrentIndex].getIsSelected()) && !(ChessBoard[CurrentIndex].getGlobalBounds().contains(Mouse::getPosition(MainWindow).x, Mouse::getPosition(MainWindow).y))) {
                    ChessBoard[CurrentIndex].setFillColor(getTargetColor(ChessBoard[CurrentIndex].getColorType()));
                    State_hoveringoverMove = false;
                }
            }
        }

        /* Resetting everything after the end of the round */
        if (deltaRound != Round) {
            clearIsSelected(ChessBoard);
            State_select = false;
            State_displayingMoves = false;
            State_hoveringoverMove = false;
        }

        MainWindow.clear(Color::Black);
        for (int i = 0; i < SIZE * SIZE; i++) {
            MainWindow.draw(ChessBoard[i]);
        }
        MainWindow.display();
        deltaRound = Round;
    }
}