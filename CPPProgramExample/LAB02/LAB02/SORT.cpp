/*
. ÇáÈÑäÇãÌ íŞæã ÈÇÓÊŞÈÇá ÚÏÏ 5 ÃÚÏÇÏ Ëã ÊÑÊíÈåã ÊÑÊíÈÇ ÊÕÇÚÏíÇ æÚÑÖåã Úáì ÇáÔÇÔÉ.
*/
#include <iostream>
using namespace std;
int main()
{
	double x[5];
	double temp;
	int  i,j;
	cout<<"\n Enter five numbers: ";
	for (i=0;i<5;i++)
		cin>>x[i];
	for(i = 0;i<5;i++)
		for (j= i+1;j<5;j++) 
			{
				if(x[i]>x[j]) 
				{
					temp = x[i];
					x[i] = x[j];
					x[j] = temp;
				}
			}
	cout<<"\n The sorted numbers  are :\n";
	for(i=0;i<5;i++)
		cout<<x[i]<<"\n";
	return 0;
}
