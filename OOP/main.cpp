#include "words.h"
#include <iostream>
using namespace std;

//

int main() {
    ChineseWord one = ChineseWord("yi");
    one.display();

    EnglishWord two = EnglishWord ("two");
    two.display();
    return 0;
}