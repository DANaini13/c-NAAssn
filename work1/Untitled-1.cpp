#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;

void oput(float a,float b){
    float c = (a+b)/2;
    cout<<"The first die comes up:"<<a<<endl<<"The second die comes up:"<<b<<endl<<"Your total roll is:"<<c<<endl;
}

    void rec(int times, int i,int a[]){
        if(i>=times){
           oput(a[0],a[1]);
            return;
        }
        a[i]=(rand() %6)+1;
        ++i;
        rec(times,i,a);
    }

int main(){
    int times = 2;
    int a[times];
    srand((unsigned)time(NULL)); 
    for(int i = 0; i < 2; ++i){
        a[i]=(rand() %6)+1;
    }
    oput(a[0],a[1]);

//=====================================
    int i = 0;
    rec(times,i,a);
}

