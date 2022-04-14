//
// Created by Ioana Ursu on 05/04/2022.
//

#include "iostream"
#include "console.h"

using namespace std;

void menu() {
    cout << "1." << endl;
}

void Console() {
    int ok = 0;
    char option;
    while (ok != 1) {
        menu();
        cout << "Give option: ";
        cin >> option;
        switch (option) {
            case '1': {
                cout << "1";
                break;

            }
            case 'x':{
                ok=1;break;
            }
            default:
                cout<<"Wrong option! Try Again!"<<endl;

        }
    }
}