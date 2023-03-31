#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "product.h"

using namespace std;

void main_menu(list<product*> product_list);
void product_menu(list<product*> product_list);
void showlist(list<product*> l);

int main(){
    list<product*> product_list;
    //ifstream fin;
    //fin.open("backup.txt");
    //fin.close();
    main_menu(product_list);
    return 0;
}

void main_menu(list<product*> product_list){
    int choice = 0;
    cout << "Please select from the following options\n";
    cout << "1: Place an order\n";
    cout << "2: View orders\n";
    cout << "3: Quit\n";
    cin >> choice;
    
    if (choice == 1){ // Place an order
        product_menu(product_list);
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
        main_menu(product_list);
        return;
    }
}

void product_menu(list<product*> product_list){
    int choice = 0;
    cout << "Please Select from our list of products\n";
    cout << "1: Shirt\n";
    cout << "2: Skirt\n";
    cout << "3: Heel\n";
    cout << "4: Ears\n";
    cout << "5: Knife\n";
    cout << "6: Cancel\n";
    cin >> choice;
    product* p;
    switch (choice){
        case 1: // shirt
            p = new shirt;
            p -> input(p);
            product_list.push_back(p);
            break;
        case 2: // skirt
            p = new skirt;
            p -> input(p);
            product_list.push_back(p);
            break;
        case 3: // heel
            p = new heel;
            p -> input(p);
            product_list.push_back(p);
            break;
        case 4: // ears
            p = new ears;
            p -> input(p);
            product_list.push_back(p);
            break;
        case 5: // knife
            p = new knife;
            p -> input(p);
            product_list.push_back(p);
            break;
        case 6: // cancel
            break;
        default: // invalid input (still an integer because I don't feel like using try and except)
            cout << "Not a valid choice\n";
            product_menu(product_list);
            break;
    }
}

void showlist(list<product*> l)
{
    list<product*>::iterator it;
    for (it = l.begin(); it != l.end(); ++it)
        (*it) -> output(cout);
}