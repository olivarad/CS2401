#include "chore.h"
#include <iostream>

using namespace std;

void chore::input(){
    cout << "Please provide a chore name: ";
    cin >> choreName;
    cout << "\nPlease provide a chore priority: ";
    cin >> priorityNumber;
    cout << endl;
}

void chore::output() const{
    cout << "Chore name: " << choreName << endl;
    cout << "Chore Priority: " << priorityNumber << endl;
}

bool operator < (const chore& c1, const chore& c2){
    if (c2.priorityNumber > c1.priorityNumber){
        return 1;
    }
    else{
        return 0;
    }
}