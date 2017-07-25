#include <iostream>
#include<cmath>

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


int main()
{
    int num;
    bool stat;
    while (true)
    {
        cout << "\nEnter a number" << endl;
        cin >> num;
        stat = is_prime(num);
        if (stat)
            cout << "The number is prime" << endl;
        else
            cout << "The number isn't prime" << endl;
    }
    return 0;
}
