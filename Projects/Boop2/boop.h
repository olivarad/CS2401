#ifndef BOOP_H
#define BOOP_H

#include "game.h"

namespace main_savitch_14
{
    class Boop:public game{
        public:
            // Default Constructor
            Boop();

            // Have the next player make a specified move:
            void make_move(const std::string& move);

            // Restart the game from the beginning:
            virtual void restart( );
        private:
            int move_number;

            int player1_kittens;
            int player2_kittens;

            int player1_cats;
            int player2_cats;

    };
}

#endif