
#include <iostream>
#include <windows.h>
#include <process.h>
#include <conio.h>
using namespace std;
class point{
int x,y;
	public:
		point (int u, int v){x=u; y=v;}
// function definition -- requires windows.h
		void gotoxy()
		{
			HANDLE hConsoleOutput;
			COORD dwCursorPosition;
			cout.flush();
			dwCursorPosition.X= x;
			dwCursorPosition.Y= y;
			hConsoleOutput= GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);
		}



		int operator <=(point p)
			{return (x<=p.x && y<=p.y);}
		int operator >=(point p)
			{return (x>=p.x && y>=p.y);}
		point operator +=(point p)
			{return point(x+=p.x, y+=p.y);}
};
int main()
{
	system("cls"); // function definition -- requires process.h
	for (point p1(20,5);p1<=point(60,5);p1+=point(1,0))
	{p1.gotoxy(); _putch('*');}
	for (point p4(60,5);p4<=point(60,20);p4+=point(0,1))
	{p4.gotoxy(); _putch('*');}
	for (point p2(60,20);p2>=point(20,20);p2+=point(-1,0))
	{p2.gotoxy (); _putch('*');}
	for (point p3(20,5);p3<=point(20,20);p3+=point(0,1))
	{p3.gotoxy(); _putch('*');}
	cout<<"\n";
	return 0;
}



