#include <iostream>
using namespace std;
bool isPrime (int number)
{
	for (int i=2;i<number;i++) 
	{	
		if(number % i ==0)   
			return false;             
    }
	return true;                             
}
int main( ) 
{
int y ;  
	bool z;
    	cout<<" Enter an integer number: " ;
    	cin>> y;
    	z = isPrime (y);
	if (z == true)
		cout <<" the number is prime \n";
    else
		cout << " the number is not prime \n";

	return 0;
}
