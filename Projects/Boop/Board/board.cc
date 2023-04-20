#include <iostream>
#include "space.h"

using namespace std;
using namespace main_savitch_14;

void display_status(Space board[6][6]);

int main(){
    string move = "c2";
    Space board[6][6]; // Creates an empty 6x6 board
    display_status(board);
    board[0][0].Space_mutator(move);
    display_status(board);
    return 0;
}

void display_status(Space board[6][6]){
    int sub_row = 0;
    cout << "\n\n\n      1        2        3        4        5        6        \n";
    cout << " --------------------------------------------------------\n";
    for (int row = 0; row < 6; row++){
        for (int sub_column = 0; sub_column < 3; sub_column++){
            switch (sub_row){
                case 1:
                    cout << "F|";
                    break;
                case 4:
                    cout << "E|";
                    break;
                case 7:
                    cout << "D|";
                    break;
                case 10:
                    cout << "C|";
                    break;
                case 13:
                    cout << "B|";
                    break;
                case 16:
                    cout << "A|";
                    break;
                default:
                    cout << " |";
                    break;
            }
            sub_row++;
            for (int column = 0; column < 6; column++){
                cout << "  ";
                switch (board[row][column].Access_State()){ 
                    case 0: // Empty
                        cout << "     ";
                        break;
                    case 1: // Little Lesbian
                        switch (sub_column){
                            case 1:
                                cout << "\e[38;5;208m@@\e[0m@\e[38;5;90m@@\e[0m";
                                break;
                            default:
                                cout << "     ";
                                break;
                        }
                        break;
                    case 2: // Little Trans
                        switch (sub_column){
                            case 1:
                                cout << "\e[34m@\e[35m@\e[0m@\e[35m@\e[34m@\e[0m";
                                break;
                            default:
                                cout << "     ";
                                break;
                        }
                        break;
                    case 3: // Big Lesbian
                        switch (sub_column){
                            case 0:
                                cout << "\e[38;5;208m@@@@@\e[0m";
                                break;
                            case 1:
                                cout << "@@@@@";
                                break;
                            case 2:
                                cout << "\e[38;5;90m@@@@@\e[0m";
                                break;
                        }
                        break;
                    case 4: // Big Trans
                        cout << "\e[34m@\e[35m@\e[0m@\e[35m@\e[34m@\e[0m";
                        break;
                }
                cout << "  ";
            }
            cout << "|\n";
        }
        if (row != 5){
            cout << " |------------------------------------------------------|\n";

        }
    }
    cout << " --------------------------------------------------------\n\n\n";
}