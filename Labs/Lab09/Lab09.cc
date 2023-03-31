#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "product.h"

using namespace std;

void main_menu();
void product_menu();

int main(){
    list<product*> product_list;
    //ifstream fin;
    //fin.open("backup.txt");
    //fin.close();
    main_menu();
    return 0;
}

void main_menu(){
    int choice = 0;
    cout << "Please select from the following options\n";
    cout << "1: Place an order\n";
    cout << "2: View orders\n";
    cout << "3: Quit\n";
    cin >> choice;
    
    if (choice == 1){ // Place an order
        product_menu();
        return;
    }
    else if (choice == 2){ // View orders
        return;
    }
    else if (choice == 3){ // Quit
        return;
    }
    else{ // Invalid number
        cout << "Not a valid selction\n";
        cin >> choice;
        main_menu();
        return;
    }
}

void product_menu(){
    int choice = 0;
    cout << "Please Select from our list of products\n";
    cout << "1: Shirt\n";
    cout << "2: Skirt\n";
    cout << "3: Heel\n";
    cout << "4: Ears\n";
    cout << "5: Knife\n";
    cout << "6: Cancel\n";
    cin >> choice;
    product* p = new shirt;
}

