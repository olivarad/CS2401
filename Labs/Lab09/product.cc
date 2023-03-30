#include <iostream>
#include "product.h"

using namespace std;

void shirt::input(list<product*> product_list){
    cout << "Provide a size: ";
    cin >> size;
    cout << "\nProvide a color: ";
    cin >> color;
    cout << endl;
}

void shirt::output(std::ostream outs){
    if (&outs == &cout){ // outs is cout
        outs << "shirt\n";
        outs << "Size: " << size << endl;
        outs << "Color: " << color << endl;
    }
    else{ // file stream
        outs << "shirt\n";
        outs << size << endl;
        outs << color << endl;
    }
}

void skirt::input(list<product*> product_list){
    cout << "Provide a size: ";
    cin >> size;
    cout << "\n Provide a length: ";
    cin >> length;
    cout << "\nProvide a color: ";
    cin >> color;
    cout << endl;
}

void skirt::output(std::ostream outs){
    if (&outs == &cout){ // outs is cout
        outs << "skirt\n";
        outs << "Size: " << size << endl;
        outs << "Length: " << length << endl;
        outs << "Color: " << color << endl;
    }
    else{ // file stream
        outs << "skirt\n";
        outs << size << endl;
        outs << length << endl;
        outs << color << endl;
    }    
}

void heel::input(list<product*> product_list){
    cout << "Provide a size: ";
    cin >> size;
    cout << "\n Provide a heel height: ";
    cin >> height;
    cout << "\nProvide a color: ";
    cin >> color;
    cout << endl;
}

void heel::output(std::ostream outs){
    if (&outs == &cout){ // outs is cout
        outs << "heel\n";
        outs << "Size: " << size << endl;
        outs << "Heel height: " << height << endl;
        outs << "Color: " << color << endl;
    }
    else{ // file stream
        outs << "heel\n";
        outs << size << endl;
        outs << height << endl;
        outs << color << endl;
    }    
}

void ears::input(list<product*> product_list){
    cout << "provide an animal: ";
    cin >> animal;
    cout << "\nProvide a color: ";
    cin >> color;
    cout << endl;
}

void ears::output(std::ostream outs){
    if (&outs == &cout){ // outs is cout
        outs << "ears\n";
        outs << "Animal: " << animal << endl;
        outs << "Color: " << color << endl;
    }
    else{ // file stream
        outs << "ears\n";
        outs << animal << endl;
        outs << color << endl;
    }    
}

void knife::input(list<product*> product_list){
    cout << "Provide a blade length: ";
    cin >> length;
    cout << "\nProvide a handle material\n";
    cin >> handle;
    cout << endl;
}

void knife::output(std::ostream outs){
    if (&outs == &cout){ // outs is cout
        outs << "knife\n";
        outs << "Length: " << length << endl;
        outs << "Handle material: " << handle << endl;
    }
    else{ // file stream
        outs << "knife\n";
        outs << length << endl;
        outs << handle << endl;
    }    
}