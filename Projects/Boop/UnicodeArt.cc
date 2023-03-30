/**
 * @file UnicodeArt.cc
 * @author Olivia Radecki (gr982220@ohio.edu)
 * @brief This program is simply meant to take a value in unicode and output the characters so I can see the character for Unicode Art
 * @date 2023-03-24 
 */

#include <iostream>
#include "colors.h"

using namespace std;

int main(){
    //Little Lesbian
    cout << LESBIAN_ORANGE << "@@" << RESET << "@" << LESBIAN_MAGENTA << "@@" << RESET << endl << endl;

    // Big Lesbian
    cout << LESBIAN_ORANGE << "@@@@@" << RESET << endl;
    cout << "@@@@@" << endl;
    cout << LESBIAN_MAGENTA << "@@@@@" << RESET << endl << endl;

    // Little Demi
    cout << BLACK << "@@" << PURPLE << "@@@" << RESET << endl << endl;

    //Big Demi
    cout << BLACK << "@" << RESET << "@@@@" << endl;
    cout << BLACK << "@@" << PURPLE << "@@@" << RESET << endl;
    cout << BLACK << "@" << RESET << "@@@@" << endl << endl;
    return 0;
}