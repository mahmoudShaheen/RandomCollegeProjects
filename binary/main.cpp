#include <iostream>
#include<bitset>

using namespace std ;

int main()
{
    int x;
    cin >> x;
    bitset<32> t;
    t=x;
    t.to_string();
    t=(t>>1);
    cout << t;

    return 0;
}
