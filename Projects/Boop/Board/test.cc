#include <iostream>
#include "space.h"

using namespace std;
using namespace main_savitch_14;

int main(){
    Space a1;
    cout << "\n\n\n--------------------------------------------------------\n";
    cout << "|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|\n";
    for (int x = 0; x < 6; x++){ // Rows
        cout << "|";
        for (int y = 0; y < 6; y++){ // Colums
            cout << "xx";
            a1.print_k1();
            cout << "xx";
        }
        if (x != 5){
            cout << "|\n|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|\n";
            cout << "|------------------------------------------------------|\n";
            cout << "|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|\n";
        }
        else{
            cout << "|\n|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|\n";
            cout << "--------------------------------------------------------\n\n\n";
        }
    }
return 0;
}