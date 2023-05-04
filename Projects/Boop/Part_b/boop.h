#ifndef BOOP_H
#define BOOP_H

#include "game.h"
#include "space.h"

namespace main_savitch_14
{
    class Boop:public game{
        public:
            // Default Constructor
            Boop();

            // Have the next player make a specified move:
            void make_move(const std::string& move);

            void boopPieces(const char piece, int row, int col);

            void promotion(); // Promote 3 kittens to cats or 8 on a board to one cat
            void rowOf3(); // Check for victory then promote 3 kittens in a row
            void all8(); // Check for victory in all 8 cats on board or promoting all pieces on board
            void promote();

            // Restart the game from the beginning:
            void restart( );

            // Return a pointer to a copy of myself:
            game* clone( ) const;
            // Compute all the moves that the next player can make:
            void compute_moves(std::queue<std::string>& moves) const;
            // Display the status of the current game:
            void display_status( ) const;
            // Evaluate a board position:
            // NOTE: positive values are good for the computer.
            int evaluate( ) const;
            // Return true if the current game is finished:
            bool is_game_over( ) const;
            // Return true if the given move is legal for the next player:
            bool is_legal(const std::string& move) const;
        private:
            Space board[6][6]; // 6X6 board of Space objects found in space.h

            bool game_over;

            int player1_kittens;
            int player2_kittens;

            int player1_cats;
            int player2_cats;
    };
}

#endif