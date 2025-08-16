g++ -I src/include -c Projects/Chess.cpp -o Main.o
g++ Main.o -o ChessGame -L src/lib -lsfml-graphics -lsfml-window -lsfml-system
ChessGame.exe