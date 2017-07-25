#include <iostream>

using namespace std;

int main()
{
    float x , y , z;
	bool check = true;
    char op;
    while(check)
    {
        cout << "\nPlease Enter the Mathematical formula..." << endl;
        cin >> x >> op >> y ;
        switch (op)
        {
        case '+' :
                z=x+y;
                cout << x <<" + " << y << " = " << z << endl ;
                break ;
        case '-' :
                z=x-y;
                cout << x <<" - " << y << " = " << z << endl ;
                break;
        case '*' :
            z=x*y;
            cout << x <<" * " << y << " = " << z << endl ;
            break ;
        case '/' :
            z=x/y;
            cout << x <<" / " << y << " = " << z << endl ;
            break;
        case '\\':
            z=y/x;
            cout << x <<" \\ " << y << " = " << z << endl ;
            break ;
        default:
            cout << "Err...Please try again !" <<endl ;
            break;
        }
    }
    return 0;
}
