#include <iostream>
#include <cstring>
using namespace std;

#define MAX 10000

bool response(){
	cout<<"是否继续？(Y/N)"<<endl;
	char response;
	cin>>response;
	if (response == 'Y' || response == 'y')
		return true;
	return false;
}

struct Contract{
	char name[20];
	char phoneNo[20];
	char address[100];
};

void displayContract(Contract contract) {
	cout<<"姓名: "<<contract.name<<endl;
	cout<<"电话："<<contract.phoneNo<<endl;
	cout<<"地址："<<contract.address<<endl;
}

void displayAllContracts(Contract contracts[], int length) {
	cout<<"我的电话本：\n"<<endl;
	int i;
	for(i=0; i<length - 1; ++i) {
		displayContract(contracts[i]);
		cout<<"=========================华丽分割线========================"<<endl;
	}
	displayContract(contracts[i]);
	cout<<endl;
}

void searchAndDisplayContracts(Contract contracts[], int length) {
	do {
		cout<<"请输入联系人姓名"<<endl;
		char name[20];
		cin.ignore(20, '\n');
		cin.get(name, 20, '\n');
		cin.ignore(20, '\n');
		cout<<"找到了如下联系人："<<endl<<endl;
		for(int i=0; i<length; ++i) {
			if (0 == strcmp(name, contracts[i].name)) {
				displayContract(contracts[i]);	
			}
		}
	}while(response());
}

void addContract(Contract contracts[], int &length) {
	do {
		if(length >= MAX) {
			cout<<"电话本容量已满，添加失败"<<endl;
			return;
		}
		char name[20];
		char phoneNo[20];
		char address[100];
		cout<<"请输入联系人姓名：\n";
		cin.ignore(20, '\n');
		cin.get(name, 20, '\n');
		cin.ignore(20, '\n');
		cout<<"请输入电话：\n";
		cin.get(phoneNo, 20, '\n');
		cin.ignore(20, '\n');
		cout<<"请输入地址：\n";
		cin.get(address, 100, '\n');
		cin.ignore(100, '\n');
		strcpy(contracts[length].name, name);
		strcpy(contracts[length].phoneNo, phoneNo);
		strcpy(contracts[length].address, address);
		++length;
	}while(response());
}

int main(){
	int length = 0;
	Contract contracts[MAX];

	do {
		cout<<"请输入菜单选项：\n1. 查看所有联系人\n2. 查看指定联系人\n3. 添加联系人\n4. 退出系统\n";
		char response;
		cin >> response;
		switch(response) {
			case '1': displayAllContracts(contracts, length); break;
			case '2': searchAndDisplayContracts(contracts, length); break;
			case '3': addContract(contracts, length); break;
			case '4': return 0;
		}
	}while(true);
	return 0;
}
