#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
 
struct Cun{
	char name[20];
	char number[20];
	char address[100];
};
//������ʾ �Ƿ���� 
bool response(){
cout<<"�Ƿ������(Y/N)"<<endl;
char response;
cin>>response;
if (response == 'Y' || response == 'y')
return true;
return false;
}
//���ͨѶ¼����Ϣ 
void displayContract(Cun Alldate){
cout<<"name:"<< Alldate.name<<endl;
cout<<"number:"<< Alldate.number<<endl;
cout<<"address:"<< Alldate.address<<endl;
}
//������ϵ�� 
void search(Cun Alldate[],int Chang) {
	do {
	cout<<"������ϵ��������";
	char name[20];
	cin.ignore(20, '\n');
	cin.get(name, 20, '\n');
	cin.ignore(20, '\n');
	cout<<"���ҵ�������ϵ�ˣ�"<<endl<<endl;
	for(int i=0; i<Chang; ++i) {				 
	if (0 == strcmp(name,Alldate[i].name)) {			//�Ա�ÿһ���˵����� 
	displayContract(Alldate[i]);
	}
	}
}while(response());
}
//�鿴���е���ϵ����Ϣ 
void LookA(Cun Alldate[],int Chang){
	for(int i=0;i<Chang-1;++i){					//��������ϵ�˽��а���ĸ������ 
		for(int j=0;j<Chang-1;++j){
			if(Alldate[j].name>Alldate[j+1].name){
				strcpy(Alldate[i].name,Alldate[i+1].name);
			}
		}
	}
	int i;
	cout<<"�ҵĵ绰����\n"<<endl;
	for(i=0; i<Chang - 1; ++i) {				//���������ϵ����Ϣ 
	displayContract(Alldate[i]);
	cout<<"================================================="<<endl;
	}
	cout<<endl;
}
//�����ϵ�� 
void add_date(int &Chang,Cun Alldate[]){ 
	if(Chang<10000){
		char name[20];
		char number[20];
		char address[100];
		cout<<"����������:";
		cin.get(name,20,'\n');
		cin.ignore(20,'\n');
		cout<<"��������룺";
		cin.get(number,20,'\n');
		cin.ignore(20,'\n');
		cout<<"�������ַ��";
		cin.get(address,100,'\n');
		cin.ignore(20,'\n'); 
		strcpy(Alldate[Chang].name,name);				//������ϵ����Ϣ�������� 
		strcpy(Alldate[Chang].number,number);
		strcpy(Alldate[Chang].address,address);
		Chang=Chang+1;
	}
}
//����ϵ����Ϣ���ı������뵽������ 
void K(Cun Alldate[],int &Chang){
	ifstream TXL("tongxunlu!.txt");
	char a;
	int SC[5];
	int z;
//��ʵ�ʳ��ȴ��ı��������Chang�� 
	for(z=0;z<5;++z){			//���������������ȸ�ֵ0�� 
		SC[z]=0;
	}
	TXL.get(a);
	for(z=5;z>0;--z){ 			//��char��Ϊint 
	if(! (a=='|')){
		SC[z]=a -'0';
		TXL.get(a);
	}
}
	Chang=SC[1]+SC[2]*10+SC[3]*100+SC[4]*1000+SC[5]*10000;			//��ֵ��Chang�� 
	
	int i= 0;
	char b[10000];
	while(!TXL.eof()){			//�Ƚ��ı�������ϵ����Ϣ�浽һ����ʱ�����У� 
	TXL.get(a);
	b[i]=a;
	++i;
	}
	i=0;
	for(int j=0;j<=Chang;++j){					//����ʱ�������Ϣ�ֱ�浽Alldate��name��number��address�� 
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
		cout<<"������ѡ�"<<endl<<"1.�鿴������ϵ��"<<endl<<"2.�����ϵ��"<<endl<<"3.������ϵ��"<<endl<<"4.�˳�"<<endl;
		char Choose;
		cin>>Choose;
	switch(Choose){
		case '1':
		LookA(Alldate,Chang);//�鿴ͨѶ¼ 
		break;
		case '2':
		add_date(Chang,Alldate);//�����ϵ�� 
		break;
		case '3':
		search(Alldate, Chang);;//������ϵ�� 
		break;
		case '4':
		baocun(Alldate,Chang);//������ϵ�� 
		break;
		}
	}while(true);
	}
