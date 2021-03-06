// Coder_and_decoder.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <fstream>

using namespace std;

int menu();
int smenu();
int smenu2();
int chmenu(char text[]);
int coder();
int decoder();
void input();
void inputc();
void inputf();
void inputfc();
void output();
void outputc();
void outputdc();
void outputf();
void outputfc();

char tocode[1000];
char todecode[1000];

int c = 0;

char alphabet[] = { 'a', 'b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };

int main()
{
	int ex = 0;
	do {
		switch (menu()) {

		case 0:
			switch (smenu())
			{
			case 0:
				input();
				coder();
				break;

			case 1:
				inputf();
				coder();
				break;
			}
			break;

		case 1:
			switch (smenu2())
			{
			case 0:
				if (c == 0) {
					cout << "Programm memory is empty !\n";
					char text[] = "Would you like to enter coded text form keyboard ?";

					switch (chmenu(text))
					{
					case 0: inputc();
						break;
					case 1: system("cls");
						break;
					}

					system("pause");
				}
				else {
					decoder();
				}
				break;
			case 1:
				inputfc();
				decoder();
				break;
			}
		break;
		
		case 2:
			output();
			system("pause");
		break;

		case 3:
			ex = 1;
			break;

		}
	} while (ex == 0);
    return 0;
}

void input() {
	cout << "Max text lenght 1000 symbols!!\n";
	string str;
	gets_s(tocode);
	str = tocode;
	c = str.length();
}

void inputc() {
	cout << "Max text lenght 1000 symbols!!\n";
	string str;
	gets_s(todecode);
	str = todecode;
	c = str.length();
}

void inputf() {
	char name[100];
	char buff;
	cout << "Enter file name (example.txt): ";
	cin >> name;
	ifstream fin(name);
	if (!fin.is_open()) {
		cout << "File is not found!";
		system("pause");
	}
	else {
		for (int i = 0; fin; i++) {
			fin.get(tocode[i]);
			if (fin.eof()) break;
		}

		string str;
		str = tocode;
		c = str.length();
		cout << "\nData readed !\n";
		fin.close();
	}
	cout << endl;
}

void inputfc() {
	char name[100];
	char buff;
	cout << "Enter file name (example.txt): ";
	cin >> name;
	ifstream fin(name);
	if (!fin.is_open()) {
		cout << "File is not found!";
		system("pause");
	}
	else {
		for (int i = 0; fin; i++) {
			fin.get(todecode[i]);
			if (fin.eof()) break;
		}

		string str;
		str = todecode;
		c = str.length();
		cout << "\nData readed !\n";
		fin.close();
	}
	cout << endl;
}


void output() {
	cout << "\nDecoded data: ";
	for (int i = 0; i < c; i++) {
		cout << tocode[i];
	}
	cout << "\nCoded data: ";
	for (int i = 0; i < c; i++) {
		cout << todecode[i];
	}
	cout << endl;
}

void outputdc() {
	cout << "\nCoded data: ";
	for (int i = 0; i < c; i++) {
		cout << todecode[i];
	}
	cout << "\n\nDecoded data: ";
	for (int i = 0; i < c; i++) {
		cout << tocode[i];
	}
	cout << endl;
}

void outputc() {
	cout << "\nCoded data: ";
	for (int i = 0; i < c; i++) {
		cout << todecode[i];
	}
	cout << endl;
}

void outputf() {
	char name[100];
	cout << "Enter file name (example.txt): ";
	cin >> name;
	ofstream fout(name, ios::trunc);
	for (int i = 0; i < c; i++) {
		fout << tocode[i] << " ";
	}
	fout.close();

	cout << "Data sucsessfully saved!\n";
	system("pause");
}

void outputfc() {
	char name[100];
	cout << "Enter file name (example.txt): ";
	cin >> name;
	ofstream fout(name, ios::trunc);
	for (int i = 0; i < c; i++) {
		fout << todecode[i] << " ";
	}
	fout.close();

	cout << "Data sucsessfully saved!\n";
	system("pause");
}

int coder() {
	for (int i = 0; i < c; i++)
		todecode[i] = tocode[i];

	for (int i = 0; i < c; i++) {
		if (todecode[i] == ' ')
			todecode[i] = '!';
	}

	for (int i = 0; i < c; i++) {
		if (todecode[i] == '!') {
			continue;
		}
		for (int j = 0; j < 26; j++) {
			if (todecode[i] == alphabet[j]) {
				if ((j + 11) >= 26) {
					todecode[i] = alphabet[(j + 11) - 26];
				}
				else {
					todecode[i] = alphabet[j + 11];
				}
				break;
			}
		}
	}
	outputc();
	cout << endl;
	system("pause");
	char text[] = "Would you like to save coded text ?";
	switch (chmenu(text))
	{
	case 0:
		outputfc();
		break;
	case 1:
		system("cls");
		break;
	}
	return 0;
}

int decoder() {
	for (int i = 0; i < c; i++)
		tocode[i] = todecode[i];

	for (int i = 0; i < c; i++) {
		if (tocode[i] == '!' && tocode[i + 1] != '!') {
			continue;
		}
		for (int j = 0; j <= 26; j++) {
			if (tocode[i] == alphabet[j]) {
				if ((j - 11) < 0) {
					tocode[i] = alphabet[26 - (11 - j)];
				}
				else {
					tocode[i] = alphabet[j - 11];
				}
				break;
			}
		}
	}
	
	for (int i = 0; i < c; i++) {
		if (tocode[i] == '!' && tocode[i + 1] != '!' || tocode[i + 1] != ' ')
			tocode[i] = ' ';
	}
	outputdc();
	cout << endl;
	system("pause");
	char text[] = "Would you like to save decoded text ?";
	switch (chmenu(text))
	{
	case 0:
		outputf();
		break;
	case 1:
		system("cls");
		break;
	}
	system("pause");
	return 0;
}

int menu() {
	int key = 0;
	int code;
	do
	{
		system("cls");
		key = (key + 4) % 4;
		if (key == 0)
			cout << "-> 1. Code text\n";
		else
			cout << "   1. Code text\n";

		if (key == 1)
			cout << "-> 2. Decode text\n";
		else
			cout << "   2. Decode text\n";
		if (key == 2)
			cout << "-> 3. Output data on screen\n";
		else
			cout << "   3. Output data on screen\n";
		if (key == 3)
			cout << "-> 4. Exit\n";
		else
			cout << "   4. Exit\n";
		code = _getch();
		if (code == 224)
		{
			code = _getch();
			if (code == 80) key++;
			if (code == 72) key--;
		}
	} while (code != 13);
	system("cls");
	return key;
}

int smenu() {
	int key = 0;
	int code;
	do
	{
		system("cls");
		key = (key + 2) % 2;
		cout << "Input text from :\n";
		if (key == 0)
			cout << "-> 1. Keyboard\n";
		else
			cout << "   1. Keyboard\n";

		if (key == 1)
			cout << "-> 2. File\n";
		else
			cout << "   2. File\n";
		code = _getch();
		if (code == 224)
		{
			code = _getch();
			if (code == 80) key++;
			if (code == 72) key--;
		}
	} while (code != 13);
	system("cls");
	return key;
}

int smenu2() {
	int key = 0;
	int code;
	do
	{
		system("cls");
		key = (key + 2) % 2;
		cout << "Input coded text from :\n";
		if (key == 0)
			cout << "-> 1. Programm memory\n";
		else
			cout << "   1. Programm memory\n";

		if (key == 1)
			cout << "-> 2. File\n";
		else
			cout << "   2. File\n";
		code = _getch();
		if (code == 224)
		{
			code = _getch();
			if (code == 80) key++;
			if (code == 72) key--;
		}
	} while (code != 13);
	system("cls");
	return key;
}

int chmenu(char text[]) {
	int key = 0;
	int code;
	do
	{
		system("cls");
		key = (key + 2) % 2;
		cout << text << endl;
		if (key == 0)
			cout << "-> 1. Yes\n";
		else
			cout << "   1. Yes\n";

		if (key == 1)
			cout << "-> 2. No\n";
		else
			cout << "   2. No\n";
		code = _getch();
		if (code == 224)
		{
			code = _getch();
			if (code == 80) key++;
			if (code == 72) key--;
		}
	} while (code != 13);
	system("cls");
	return key;
}