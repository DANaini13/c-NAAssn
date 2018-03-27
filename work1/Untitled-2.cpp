#include<iostream>
using namespace std;

void rec(int num,float b,int i){
    if(i>=num){
        cout<<"result = 1 - 1/2 + 1/3 - 1/4 + ... + 1/99 - 1/100 = "<<b<<endl;
        return;
    }
    float c,d;
    c = i + 1;
    d = 1/c;
    b = b + d;
    ++i;
    c = i + 1;
    d = 1/c;
    b = b - d;
    ++i;
    rec(num,b,i);
}
int main(){
    int num = 100;
    float b = 0;
    int i = 0;
    //============================================
    for(; i < num; ++i){
        float c,d;
        c = i + 1;
        d = 1/c;
        b = b + d;
        ++i;
        c = i + 1;
        d = 1/c;
        b = b - d;
    }
    cout<<"result = 1 - 1/2 + 1/3 - 1/4 + ... + 1/99 - 1/100 = "<<b<<endl;
    //==========================================
    b = 0;
    i = 0;
    rec(num,b,i);
}