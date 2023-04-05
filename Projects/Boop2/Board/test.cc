#include <iostream>

using namespace std;

int main(){
    cout << "\n\n\n--------------------------------------------------------\n|                                                      |\n";
    for (int x = 0; x < 6; x++){ // Rows
    cout << "|";
                for (int y = 0; y < 6; y++){ // Colums
                    cout << "  xxxxx  ";
                }
                if (x != 5){
                    cout << "|\n|                                                      |\n|------------------------------------------------------|\n|                                                      |\n";
                }
                else{
                    cout << "|\n|                                                      |\n--------------------------------------------------------\n\n\n";
                }
            }
    return 0;
}