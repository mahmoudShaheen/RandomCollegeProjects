/*
���� ������� ����� �� ����� ���� ������ ������ �� ��� �� ����� ������ �� ��� ������ 
author � ����� ������ title ������ status �� ���� ����� "in" �� ��� ���� "out".
��� �������� ���� ��� ��� �������� �� ���� ���� ���� �� ������� ��� ��� ��������
�������� ��� ��� ���� ����� ����� ������
. ��� �������� ���� ��� ���� ����� ������. 
*/
#include<iostream>
#include<string>
using namespace std;
class book{
		char author [30]; 		
		char title [40];
		char status [10];
	public:
		book (char *n,char *t,char *s);
		~book(){cout<<"\n\n\tDestruction\n";}
		void show();
};	
book::book(char *n,char *t,char *s)
{
	strcpy_s(author,n);
	strcpy_s(title,t);
	strcpy_s(status,s);
}
void book::show()
{
	cout<<"\n\n\t"<<title<<"\t\t"<<author;
	cout<<"\t"<<status;
}
int main()
{
	book b1 ("A.m.Elakkad","Omar's Genious","IN");
	book b2 ("A.Mahfouz","Miramar     ","OUT");
	cout<<"\n\n\tTitle\t\t\tAuthor\t\tStatus";
	b1.show();
   	b2.show();
return 0;
}
