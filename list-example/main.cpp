#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "list.h"
using namespace std;

int main(){
    srand((unsigned)time(NULL));
    LinkList list;
    list.build();
    list.display();
    //====================================
    list.removeFirst();
    //====================================
    list.display();
    list.removeAll();
    return 0;
}