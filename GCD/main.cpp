#include <iostream>
using namespace std;
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
int main()

{
    int x, y;
    cout << "Greatest Common Divisor Calculator" << endl;
    cout << "\nPlease enter two positive integers" << endl;
    cin >> x >> y;
    if (x>0 && y>0)
        cout << "\nThe GCD of  " << x << "  and  " << y << " is:  " << GCD(x, y) << endl;
    else
        cout << "incorrect numbers" << endl;
    return 0;
}
