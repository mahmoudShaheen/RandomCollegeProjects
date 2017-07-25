#include <iostream>
#include <math.h>
using namespace std;
class quadeq{
		double a,b,c;
		double M,x1,x2;
		double R,I;
	public:
		void comp();
		void show();
};
void quadeq::comp()
{
	cout<<" Enter a value of a: ";
	cin>>a;
	if (a==0)
	{
		cout<<" Invalid value for a? Enter a corect value: ";
        cin>>a;
		if(a==0)
			exit(1);
	}
	cout<<" Enter a value of b: ";
	cin>>b;
	cout<<" Enter a value of c: ";
	cin>>c;
M=b*b-4*a*c;
	


if(M==0)
	{
		x1=-b/(2*a);
		x2=-b/(2*a);
	}
	else if(M>0)
	{
		x1=(-b + sqrt(M))/(2*a);
		x2=(-b - sqrt(M))/(2*a);
	}
	else
	{
		R=-b/(2*a);
		I=sqrt(-M)/(2*a);
	}
}
void quadeq::show()
{
	if(M==0)
		cout<<"\n"<<" Two identical roots: x1= x2= "<< x1<<endl;
	else if (M>0)
	{
		cout<<"\n"<<" Two real roots: \n";
		cout<<" x1= "<<x1<<"\t x2= "<<x2<<endl;
	}
	else
	{
		cout<<"\n"<<" Two imaginary roots: \n";
		cout<<" x1= "<<R<<"+ i "<<I<<"\n";
		cout<<" x2= "<<R<<"- i "<<I<<"\n";
	}
}
int main ()
{
	quadeq e1;
	cout<<"\n\t Solving equation: a*x^2 + b*x + c = 0\n\n";
	e1.comp();
	e1.show();
	return 0;
}
