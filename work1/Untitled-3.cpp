#include<iostream>
#include<string.h>
using namespace std;
int main(){
    string str;
    cout<<"input string:";
    cin>>str;
    int m=0,n=0;
    for(int i = 0; i < strlen(str.c_str()); ++i){
      if(str[i]>64 && str[i]<91){
            m +=1;
        }
        if(str[i]>96 && str[i]<123){
            n +=1;
        }
    }
    cout<<"Lowercase have: "<<n<<endl;
    cout<<"Capital have: "<<m<<endl;
}   