#include <iostream>

using namespace std;

bool is_prime(int n)
{
    if (n <= 1)
        return false;
    else if (n <= 3)
        return true;
    else if (n % 2 == 0 || n % 3 == 0)
        return false;
    int i = 5;
    while (i*i <= n)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
        i = i + 6;
    }
    return true;
}


unsigned long int pow_int(unsigned long int x,unsigned long int n)
{
    unsigned long int res = 1;
    for (unsigned long int i = 0; i != n; ++i)
        res *= x;
    return res;
}

int GCD(int m , int n )
{
    unsigned g;
    g = m % n;
    m = n;
    n = g;
    if (n!=0)
        GCD ( m , n );
    else
        return m ;

}

unsigned long int calce(unsigned long int xn)
{
    unsigned long int e;
    unsigned long int temp;
    for (unsigned long int i=4 ; i < xn ; i++)
        {
            e=i;
            temp=GCD(e,xn);
            if(temp==1)
                return e;
        }
    return -1;
}

unsigned long int calcd(unsigned long int e, unsigned long int xn)
{
    unsigned long int d;
    unsigned long int temp;
    for(unsigned long int i=0 ; i<xn ; i++)
    {
        d=i;
        temp=d*e;
        temp=temp%xn;
        if(temp==1)
            return d;
    }
    return -1;
}

unsigned long int encrypt (unsigned long int M, unsigned long int n, unsigned long int e)
{
    if(M<n)
    {
        M=pow_int(M,e);
        M=M%n;
        return M;
    }
    return -1;
}
unsigned long int decrypt (unsigned long int M, unsigned long int n, unsigned long int d)
{
    M=pow_int(M,d);
    M=M%n;
    return M;
}



int main()
{
    unsigned long int n,xn;
    int p,q;
    unsigned long int e, d;
    unsigned long int M;
    while(!(is_prime(p))||!(is_prime(q)))
    {
        cout << "Enter Prime number for p:" << endl;
        cin >> p;
        cout << "Enter Prime number for q:" << endl;
        cin >> q;
    }
    n=p*q;
    cout << "n=" <<n << endl;
    xn=(p-1)*(q-1);
    cout << "xn=" << xn << endl;
    e=calce(xn);
    cout << "e=" <<e << endl;
    d=calcd(e,xn);
    cout << "d=" <<d << endl;
    while (true){
    M=n+1;
    while (M>n)
    {
        cout << "enter a msg." << endl;
        cin >> M;
    }
    cout << "m=" <<M << endl;
    M= encrypt(M,n,e);
    cout << "Encrypted: "<< M << endl;
    M= decrypt(M,n,d);
    cout << "Decrypted: "<< M << endl;
    p=0;
    q=0;
    }
    return 0;
}
