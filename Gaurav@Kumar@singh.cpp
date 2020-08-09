#include<bits/stdc++.h>
#include<iostream>
#include<sstream>
#include<fstream> // file ke liye hai
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<time.h>
#include<windows.h> // output screen buffer size ke liye hai
#include<stdlib.h> // jump function ke liye use krte hai 
//#include<ctime>
//#include<graphics.h>
//#include<dos.h>
using namespace std;
void delay(int number_of_seconds) 
{ 
    // Converting time into milli_seconds 
    int milli_seconds = 1000 * number_of_seconds; 
  
    // Storing start time 
    clock_t start_time = clock(); 
  
    // looping till required time is not achieved 
    while (clock() < start_time + milli_seconds);
} 
void sizebufferconsole(short x,short y) // buffer size ke liye short use krte hai 
{
	// typedef class of SMALL_RECT{WHICH CONSIST OF data members like top,left,right and bottom};
	SMALL_RECT rect;
	COORD coord;
	//COORDINATE consists of two variable x-axis and y-axis
	coord.X= x;
	coord.Y=y;
	//declaration of SMALL_RECT data members
	rect.Top=0;
	rect.Left=0;
	rect.Bottom=coord.Y-1;
	rect.Right=coord.X-1;
	//console and window function
	
	//HANDLE hwnd=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE),coord);
	SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE),TRUE,&rect);
}
void gotoxy(short x,short y)
{
	COORD pos={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
void calChk(int n)
{
	system("CLS");
	sizebufferconsole(1000,1000);
	cout<<"Your Selected N value: "<<n<<"\n\n";
	string str1;
	ifstream fs("chk.txt",ios::app);
	map<string,int> mp;
	while(!fs.eof())
	{
		fs>>str1;
		//cout<<str1<<"\n";
		mp[str1]++;
	}
	vector<string> vect;
	vector<int> vect1;
	for(auto x:mp)
	{
	   stringstream gaurav(x.first);
		int num=0;
		gaurav>>num;
		//cout<<num<<"\n";
		if(x.first!="."&&x.first!=" "&&x.first!="/"&&x.first!=","&&num==0)
		{
		//cout<<x.first<<" "<<x.second<<"\n";
		vect.push_back(x.first);
		vect1.push_back(x.second);
	    }
	}
	int si=vect.size();
	int num=0;
	string str;
	for(int i=0;i<si-1;i++)
	{
		for(int j=i+1;j<si;j++)
		{
			if(vect1[i]<vect1[j])
			{
				num=vect1[i];
				vect1[i]=vect1[j];
				vect1[j]=num;
				
				str=vect[i];
				vect[i]=vect[j];
				vect[j]=str;
			}
		}
	}
	cout<<"Your output is loading in few seconds..........."<<"\n\n";
	delay(10);
	for(int i=0;i<n;i++)
	{
		cout<<i+1<<".  "<<vect[i]<<" "<<vect1[i]<<"\n";
	}
	cout<<"                                                    Thank you very much for using this Software                        "<<"\n";
}
int main()
{
	//SetConsoleTitle("Gaurav");
	system("title Gaurav Kumar Singh");
	sizebufferconsole(130,30);
	system("COLOR FC");
	
	////
	gotoxy(45,2);
	cout<<"LOVELY PROFESSIONAL UNIVERSITY"<<"\n";
	gotoxy(73,3);
	cout<<"PHAGWARA(JALANDHAR), PUNJAB"<<"\n";
	gotoxy(50,4);
	cout<<"WELCOME TO TERRIBLY TINY TALES PROJECT"<<"\n";
	gotoxy(50,6);
	cout<<"PROJECT NAME         : FREQUENCY OF WORDS"<<"\n";
	gotoxy(50,7);
	cout<<"NAME                 : GAURAV KUMAR SINGH"<<"\n";
	gotoxy(50,8);
	cout<<"REGISTRATION  NO     : 11704683"<<"\n";
	
	int n=0;
	gotoxy(55,12);
	cout<<"Enter the value of N: "<<"\n";
	gotoxy(77,12);
	cin>>n;
	calChk(n);
}
