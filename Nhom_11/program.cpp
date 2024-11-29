#include<iostream>
#include<conio.h>
#include<iomanip>
#include<string.h>
#include<fstream>
#include<stdio.h>
using namespace std;

#include"Header.h"
#include"Thuvien.h"
#include"Menu.h"

void ChayChuongTrinh();

int main()
{
	ChayChuongTrinh();
	return 1;
}

void ChayChuongTrinh()
{
	BSTDungCu root = NULL;
	BSTCustomer root2 = NULL;
	int menu, soMenu = 8;
	do
	{
		menu = ChonMenu(soMenu);
		XuLyMenu(menu,root,root2);
		system("PAUSE");
	} while (menu > 0);
}
