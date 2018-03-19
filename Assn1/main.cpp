#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
 
struct Cun{
	char name[20];
	char number[20];
	char address[100];
};
//文字提示 是否继续 
bool response(){
cout<<"是否继续？(Y/N)"<<endl;
char response;
cin>>response;
if (response == 'Y' || response == 'y')
return true;
return false;
}
//输出通讯录的信息 
void displayContract(Cun Alldate){
cout<<"name:"<< Alldate.name<<endl;
cout<<"number:"<< Alldate.number<<endl;
cout<<"address:"<< Alldate.address<<endl;
}
//查找联系人 
void search(Cun Alldate[],int Chang) {
	do {
	cout<<"输入联系人姓名：";
	char name[20];
	cin.ignore(20, '\n');
	cin.get(name, 20, '\n');
	cin.ignore(20, '\n');
	cout<<"查找到以下联系人："<<endl<<endl;
	for(int i=0; i<Chang; ++i) {				 
	if (0 == strcmp(name,Alldate[i].name)) {			//对比每一个人的姓名 
	displayContract(Alldate[i]);
	}
	}
}while(response());
}
//查看所有的联系人信息 
void LookA(Cun Alldate[],int Chang){
	for(int i=0;i<Chang-1;++i){					//对所有联系人进行按字母的排序 
		for(int j=0;j<Chang-1;++j){
			if(Alldate[j].name>Alldate[j+1].name){
				strcpy(Alldate[i].name,Alldate[i+1].name);
			}
		}
	}
	int i;
	cout<<"我的电话本：\n"<<endl;
	for(i=0; i<Chang - 1; ++i) {				//输出所有联系人信息 
	displayContract(Alldate[i]);
	cout<<"================================================="<<endl;
	}
	cout<<endl;
}
//添加联系人 
void add_date(int &Chang,Cun Alldate[]){ 
	if(Chang<10000){
		char name[20];
		char number[20];
		char address[100];
		cout<<"请输入姓名:";
		cin.get(name,20,'\n');
		cin.ignore(20,'\n');
		cout<<"请输入号码：";
		cin.get(number,20,'\n');
		cin.ignore(20,'\n');
		cout<<"请输入地址：";
		cin.get(address,100,'\n');
		cin.ignore(20,'\n'); 
		strcpy(Alldate[Chang].name,name);				//复制联系人信息到数组内 
		strcpy(Alldate[Chang].number,number);
		strcpy(Alldate[Chang].address,address);
		Chang=Chang+1;
	}
}
//将联系人信息从文本中输入到数组内 
void K(Cun Alldate[],int &Chang){
	ifstream TXL("tongxunlu!.txt");
	char a;
	int SC[5];
	int z;
//将实际长度从文本中提出到Chang中 
	for(z=0;z<5;++z){			//数组内所有数字先赋值0； 
		SC[z]=0;
	}
	TXL.get(a);
	for(z=5;z>0;--z){ 			//将char改为int 
	if(! (a=='|')){
		SC[z]=a -'0';
		TXL.get(a);
	}
}
	Chang=SC[1]+SC[2]*10+SC[3]*100+SC[4]*1000+SC[5]*10000;			//赋值到Chang中 
	
	int i= 0;
	char b[10000];
	while(!TXL.eof()){			//先将文本所有联系人信息存到一个临时数组中； 
	TXL.get(a);
	b[i]=a;
	++i;
	}
	i=0;
	for(int j=0;j<=Chang;++j){					//将临时数组的信息分别存到Alldate的name，number，address中 
		char c[100];
		int d;
		for(d=0;!(b[i]=='|');++i,++d){
			c[d]=b[i];
		}
		strcpy(Alldate[j].name,c);
		for(d=0;(b[i]=='|');++i,++d){
			c[d]=b[i];
		}
		strcpy(Alldate[j].number,c);
		for(d=0;!(b[i]=='|');++i,++d){
			c[d]=b[i];
		}
		strcpy(Alldate[j].address,c);
}
}


void baocun(Cun Alldate[],int Chang){
	fstream TXL("tongxunlu!.txt");
	int i;
	for(i=0;i<Chang;++i){
	TXL<<Alldate[i].name<<'|'<<Alldate[i].number<<'|'<<Alldate[i].address<<'|'<<endl;
}
	TXL.close();
}

int main(){
	ifstream TXL("tongxunlu!.txt");
	if(!TXL.is_open()){
		ofstream("tongxunlu!.txt");
	}
	int Chang;
	Cun Alldate[10000];
	K(Alldate,Chang);
	do{
		cout<<"请输入选项："<<endl<<"1.查看所有联系人"<<endl<<"2.添加联系人"<<endl<<"3.查找联系人"<<endl<<"4.退出"<<endl;
		char Choose;
		cin>>Choose;
	switch(Choose){
		case '1':
		LookA(Alldate,Chang);//查看通讯录 
		break;
		case '2':
		add_date(Chang,Alldate);//添加联系人 
		break;
		case '3':
		search(Alldate, Chang);;//查找联系人 
		break;
		case '4':
		baocun(Alldate,Chang);//保存联系人 
		break;
		}
	}while(true);
	}
