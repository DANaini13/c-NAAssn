#include "words.h"
#include <cstring>
#include <iostream>
using namespace std;

Word::Word(const char* content) {
	// 深拷贝
	this -> content = new char[strlen(content) + 1];
	strcpy(this -> content, content);
	cout<<"1"<<endl;
}

Word::~Word() {
	delete this -> content;
	this -> content = NULL;
	cout<<"2"<<endl;
}

void Word::display() {
	cout<<this -> content;
	cout<<"3"<<endl;
}

ChineseWord::ChineseWord(const char* content): Word(content) {
	cout<<"4"<<endl;
}

ChineseWord::~ChineseWord() {
	cout<<"5"<<endl;
}

void ChineseWord::display() {
	cout<<"Chinese: ";
	Word::display();
	cout<<"6"<<endl;
}