#include<iostream>
#include<string>
#include "MyThread.h"
#include<thread>
#include<fstream>
#include<Windows.h>
#include<vector>



int main() {
	//std::thread t1(funcion_1);//t1 bat dau chay

	MyThread thread;
	thread.wirte_file("note.txt");
	ofstream myfile("note.txt");
	vector<string> v;


	string path = "D:\\1LINK\\Week3\\Thread_Final\\content\\";
	string searchPatter = "*.txt";
	string fullFile = path + searchPatter;

	WIN32_FIND_DATA FindData;
	HANDLE hFind;
	hFind = FindFirstFile(fullFile.c_str(), &FindData);
	if (hFind == INVALID_HANDLE_VALUE) {
		cout << "Khong tim thay" << endl;
		return -1;
	}
	cout << "Doc duong dan toi file .txt: " << endl;
	do {
		string filePath = path + FindData.cFileName;
		cout << filePath << endl;//in ra duong dan toi file .txt oke
		v.push_back(filePath);
		string s;
		//Chua doc duoc du lieu cua file

	} while (FindNextFile(hFind, &FindData) > 0);
	system("pause");
}