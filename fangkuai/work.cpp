#include "work.h"
#include <iostream>
using namespace std;

void Savenumber :: display(int a) {
    for(int b = 0; b < 3; ++b){
    cout<<space[a];
    }
}

void Output::display(int a){
    switch (a){;
    case 1:
        for(int b = 0; b < 2; ++b){
            Savenumber::display(1);
            Savenumber::display(2);
            cout<<endl;
        }
        for(int b = 0; b < 2; ++b){
            Savenumber::display(3);
            Savenumber::display(4);
            cout<<endl;
        }
    case 2:
            for(int b = 0; b < 2; ++b){
            Savenumber::display(1);
            Savenumber::display(2);
            cout<<endl;
        }
        for(int b = 0; b < 2; ++b){
            Savenumber::display(0);
            Savenumber::display(3);
            Savenumber::display(4);
            cout<<endl;
        }
    case 3:
            for(int b = 0; b < 2; ++b){
            Savenumber::display(0);
            Savenumber::display(1);
            Savenumber::display(2);
            cout<<endl;
        }
        for(int b = 0; b < 2; ++b){
            Savenumber::display(3);
            Savenumber::display(4);
            cout<<endl;
        }
    }
}