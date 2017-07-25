#include <iostream>
#include<tgmath.h>

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

unsigned long int calcd2(unsigned long int e, unsigned long int xn)
{
    unsigned long int d;
    unsigned long int x;
    float c1;
    float c2;
    int c3;
    for(unsigned long int i=0 ; i<xn ; i++)
    {
        x=i;
        c1=x*xn+1;
        c2=c1/e;
        c3=(int)c2;
        if(fmod(c2,c3)==0)
            return c2;
    }
    return -1;
}

unsigned long int encrypt (unsigned long int M, unsigned long int n, unsigned long int e)
{
    if (e> 64||M>n)
        return -1;
    int arr[8];
    for (int i=0;i<8;i++)
        arr[i]=0;
    int temp;
    for (int i=7 ; i<=0 ; i++)
    {
        temp=pow_int(2,i);
        if(e/temp>=1)
        {
            arr[i]=1;
            e=e-temp;
        }
    }
    temp=1;
    int temp2;
    for (int i=0 ; i<8 ; i++)
    {
        if (arr[i]==1)
        {
            temp2=pow_int(2,i);
            temp*=pow_int(M,temp2)%n;
        }
    }
    temp=temp%n;
    return temp;
    /*if(M<n)
    {
        M=pow_int(M,e);
        M=M%n;
        return M;
    }
    return -1;*/
}
unsigned long int decrypt (unsigned long int M, unsigned long int n, unsigned long int d)
{
    if (d> 1048576)
        return -1;
    int arr[21];
    for (int i=0;i<21;i++)
        arr[i]=0;
    int temp;
    for (int i=20 ; i<=0 ; i++)
    {
        temp=pow_int(2,i);
        if(d/temp>=1)
        {
            arr[i]=1;
            d=d-temp;
        }
    }
    temp=1;
    for (int i=0 ; i<20 ; i++)
    {
        if (arr[i]==1)
            temp*=pow_int(M,pow_int(2,i))%n;
    }
    temp=temp%n;
    return temp;

    /*unsigned long int temp;
    M=pow_int(M,d);
    M=M%n;
    return M;*/
}



int main()
{
    while (true){
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
    M=n+1;
    cout << "n=" <<n << endl;
    xn=(p-1)*(q-1);
    cout << "xn=" << xn << endl;
    e=calce(xn);
    cout << "e=" <<e << endl;
    d=calcd(e,xn);
    cout << "d=" <<d << endl;
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
