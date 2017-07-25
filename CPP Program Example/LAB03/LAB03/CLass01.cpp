/*
ÇßÊÈ ÈÑäÇãÌÇ íÊÔßá ãä İÕíáÉ ÊŞæã ÈÊÎÒíä ÈíÇäÇÊ Úä ßÊÈ İí ãßÊÈÉ ãÊãËáÉ İí ÇÓã ÇáãÄáİ 
author æ ÚäæÇä ÇáßÊÇÈ title æÍÇáÊå status Ãí ßæäå ãÊÇÍÇ "in" Ãæ ÛíÑ ãÊÇÍ "out".
ÑÊÈ ÇáÈÑäÇãÌ ÈÍíË íÊã ÖÈØ ÇáÈíÇäÇÊ ãä ÎáÇá ÏÇáÉ ÈäÇÁ ãÚ ÇãßÇäíÉ ÚÑÖ Êáß ÇáÈíÇäÇÊ
æÇÎÑÇÌåÇ Úáì Ôßá ÌÏæá ÈÑÄæÓ ŞæÇÆã ãäÇÓÈÉ
. Öãä ÇáÈÑäÇãÌ ÏÇáÉ åÏã ÊÚÑÖ ÑÓÇáÉ ÈÇáåÏã. 
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
