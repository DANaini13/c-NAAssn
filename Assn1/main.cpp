#include<iostream>
#include<fstream>
#include<cstring>
#include<cmath>
using namespace std;
 
struct Person{
	char name[20];
	char number[20];
	char address[100];
};

bool response(){
	cout<<"�Ƿ������(Y/N)"<<endl;
	char response;
	cin>>response;
	if (response == 'Y' || response == 'y')
		return true;
	return false;
}

void displayContract(Person allData){
	cout<<"name:"<< allData.name<<endl;
	cout<<"number:"<< allData.number<<endl;
	cout<<"address:"<< allData.address<<endl;
}

void search(Person allData[],int length) {
	do {
		cout<<"������ϵ��������";
		char name[20];
		cin.ignore(20, '\n');
		cin.get(name, 20, '\n');
		cin.ignore(20, '\n');
		cout<<"���ҵ�������ϵ�ˣ�"<<endl<<endl;
		for(int i=0; i<length; ++i) {				 
			if (0 == strcmp(name,allData[i].name)) {
				displayContract(allData[i]);
			}
		}
	}while(response());
}

void LooloadDataA(Person allData[],int length){
	for(int i=0;i<length-1;++i){		
		for(int j=0;j<length-1;++j){
			if(allData[j].name>allData[j+1].name){
				strcpy(allData[i].name,allData[i+1].name);
			}
		}
	}
	int i;
	cout<<"�ҵĵ绰����\n"<<endl;
	for(i=0; i<length - 1; ++i) {		
	displayContract(allData[i]);
	cout<<"================================================="<<endl;
	}
	cout<<endl;
}

void add_date(int &length,Person allData[]){ 
	if(length<10000){
		char name[20];
		char number[20];
		char address[100];
		cout<<"����������:";
		cin.ignore(20,'\n');
		cin.get(name,20,'\n');
		cin.ignore(20,'\n');
		cout<<"��������룺";
		cin.get(number,20,'\n');
		cin.ignore(20,'\n');
		cout<<"�������ַ��";
		cin.get(address,100,'\n');
		cin.ignore(20,'\n'); 
		cout<<"length: "<<length<<endl;
		cout<<"name: "<< allData[length].name;
		strcpy(allData[length].name,name);
		cout<<"tag"<<endl;
		strcpy(allData[length].number,number);
		strcpy(allData[length].address,address);
		length=length+1;
	}
}

void loadData(Person allData[],int &length){
	ifstream dataFile("tongxunlu!.txt");
	char a;
	int lengthInts[100];
	for (int i=0; i<100; ++i)
		lengthInts[i] = -1;
	dataFile.get(a);
	for (int i=0; i<100 && a != '|'; ++i) {
		lengthInts[i] = a - '0';
		dataFile.get(a);
	}
	length = 0;
	int count = 0;
	for(int i=99; i>=0; --i) {
		if(lengthInts[i] != -1){
			length += pow(10, count) * lengthInts[i];
			++count;
		}
	}

	char buffer[200];
	dataFile.getline(buffer, 100);
	int index = 0;
	while(index < length) {
		dataFile.getline(buffer, 100);
		int i;
		for(i=0; buffer[i] != '|'; ++i) {
			allData[index].name[i] = buffer[i];
			allData[index].name[i + 1] = '\0';
		}
		++i;
		for(int j = 0; buffer[i] != '|'; ++i, ++j) {
			allData[index].number[j] = buffer[i];
			allData[index].number[j + 1] = '\0';
		}
		++i;
		for(int j = 0; buffer[i] != '|'; ++i, ++j) {
			allData[index].address[j] = buffer[i];
			allData[index].address[j + 1] = '\0';
		}
		++index;
	}

}


void saveToFile(Person allData[],int length){
	fstream dataFile("tongxunlu!.txt");
	dataFile<<length<<"|";
	int i;
	for(i=0;i<length;++i){
		dataFile<<'\n'<<allData[i].name<<'|'<<allData[i].number<<'|'<<allData[i].address<<'|';
	}
	dataFile.close();
}

int main(){
	ifstream dataFile("tongxunlu!.txt");
	if(!dataFile.is_open()){
		ofstream("tongxunlu!.txt");
	}
	int length;
	Person allData[10000];
	loadData(allData,length);
	cout<<length<<endl;
	do{
		cout<<"������ѡ�"<<endl<<"1.�鿴������ϵ��"<<endl<<"2.�����ϵ��"<<endl<<"3.������ϵ��"<<endl<<"4.�˳�"<<endl;
		char Choose;
		cin>>Choose;
		switch(Choose){
			case '1':
				LooloadDataA(allData,length);
				break;
			case '2':
				add_date(length,allData); 
				break;
			case '3':
				search(allData, length);;
				break;
			case '4':
				saveToFile(allData,length);
				return 0;
		}
	}while(true);
}
