#include<iostream>
#include<string>
using namespace std;

 int main(){
     int a = 100;
     int b,c,d;
     for(int i = 0; i < 900; ++i){
        string e = to_string(a);
        b = e[0] - '0';
        c = e[1] - '0';
        d = e[2] - '0';
        if(a == b*b*b + c*c*c + d*d*d){
            cout<<a<<' ';
        }
        ++a;
     }
     cout<<endl;
 }