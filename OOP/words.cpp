#include "words.h"
#include <cstring>
#include <iostream>
using namespace std;

Word::Word(const char* content) {
	// 深拷贝
	this -> content = new char[strlen(content) + 1];
	strcpy(this -> content, content);
}

Word::~Word() {
	delete this -> content;
	this -> content = NULL;
}

void Word::display() {
	cout<<this -> content;
}

ChineseWord::ChineseWord(const char* content): Word(content) {
}

void ChineseWord::display() {

}