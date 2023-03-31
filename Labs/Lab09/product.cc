#include <iostream>
#include "product.h"

using namespace std;

void shirt::input(product* p){
    cout << "Provide a size: ";
    cin >> size;
    cout << "\nProvide a color: ";
    cin >> color;
    cout << endl;
    //product_list.push_back(p);
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

void skirt::input(product* p){
    cout << "Provide a size: ";
    cin >> size;
    cout << "\n Provide a length: ";
    cin >> length;
    cout << "\nProvide a color: ";
    cin >> color;
    cout << endl;
    //product_list.push_back(p);
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

void heel::input(product* p){
    cout << "Provide a size: ";
    cin >> size;
    cout << "\n Provide a heel height: ";
    cin >> height;
    cout << "\nProvide a color: ";
    cin >> color;
    cout << endl;
    //product_list.push_back(p);
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

void ears::input(product* p){
    cout << "provide an animal: ";
    cin >> animal;
    cout << "\nProvide a color: ";
    cin >> color;
    cout << endl;
    //product_list.push_back(p);
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

void knife::input(product* p){
    cout << "Provide a blade length: ";
    cin >> length;
    cout << "\nProvide a handle material\n";
    cin >> handle;
    cout << endl;
    //product_list.push_back(p);
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