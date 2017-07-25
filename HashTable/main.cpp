//author: Mahmoud Shaheen
// الاسم: محمود محمد محمود عبد المقصود
//الفرقة: الثالثة حاسبات
//Hash Table With Linear Probing
//Compiled using GNU GCC Compiler
//Algorithm & Data Structure Course "Prof: Haitham Abo Bakr"

#include <iostream>
#include <math.h>
using namespace std;

int hashsizefun;

bool is_prime(int n) // i get pseudo Code for this function from the Internet from "https://en.wikipedia.org/wiki/Primality_test"
{
    if (n <= 1)
        return false;
    else if (n <= 3)
        return true;
    else if (n % 2 == 0 || n % 3 == 0)
        return false;
    int i = 5;
    while ((i*i) <= n)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
        i = i + 6;
    }
    return true;
}

int hashfun(int x)
{
    int y = x % hashsizefun;
    return y;
}

int main()
{
    int no,key,cont=1;
    int hashsize;
    int f=0;
    int x=0;
    char op;
    cout << "\n\t\t Welcome To HashTable With Linear Probing" << endl;
    while (!(is_prime(hashsize)))
    {
        cout << "\n Please Enter a prime number for HashTable Size\n";
        cin >> hashsize;
    }
    hashsizefun= hashsize ;
    hashsize = hashsize-1;
    int hashtable[hashsize] ;

    for (int i=0 ; i<= hashsize ; i++)
        hashtable[i]=NULL;

    while (cont==1)
    {
        cout << "\n\n please enter \n i for insertion \n s for search \n followed by the number you want to make the operation on\n or press p to print \n\n\n";
        cin >> op ;

        switch (op)
        {
        case 'i':
            {
                cin >> no;
                key = hashfun(no);
                    for (int i = key ; i<= hashsize ; i++)
                    {
                        if (!hashtable[i])
                        {
                            hashtable[i] = no;
                            cout << "\n Index:" << i << endl ;
                            break;
                        }
                        if( i == hashsize && hashtable[hashsize] )
                        {
                            if (x==1)
                            {
                                cout << "\n The HashTable is Full \n";
                                break;
                            }
                            else
                            {
                                i= -1;
                                x=1;
                            }
                        }

                    }
                break;
            }
        case 's':
            {
                cin >> no;
                key = hashfun(no);
                for (int i =key ; i<= hashsize+1 ; i++)
                {
                    if( i == hashsize+1 && hashtable[hashsize-1] )
                        {
                            if (x==1)
                            {
                                break;
                            }
                            else
                            {
                                i= -1;
                                x=1;
                                continue;
                            }
                        }
                    if (hashtable[i]== no)
                    {
                        cout <<"\n Found in Index:  " << i << endl;
                        f=1;
                        break;
                    }
                }
                if (f==0)
                {
                    cout << "\n This number is not in the table \n";
                    f=0;
                }
                break;
            }
        case 'p':
            {
                cout << "\n\n The HashTable:-\n\n";
                for (int i=0 ; i<= hashsize ; i++)
                    cout << i << "  :\t" << hashtable[i] << endl;
                break;
            }
        default:
            {
                cout << "\n Error: Unknown operation \n";
            }
        }
        cout << "\n if you want to continue press 1 \n";
        cin >> cont;
        x=0;
    }

    return 0;
}
