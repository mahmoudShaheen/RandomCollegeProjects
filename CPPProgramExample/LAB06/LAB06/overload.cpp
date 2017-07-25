#define PI 3.1415
#include<iostream>
using namespace std;
class coord{
	protected:
float x,y,z;
	public:
void param(float d1=0, float d2=0, float d3=0)
		{
			x=d1; y=d2; z=d3;
		}
		float get_x(){return x;}
		float get_y(){return y;};
		float get_z(){return z;}
};
class circle: public coord{
	public:
		float area(){return PI*x*x;}
};

class parallel: public coord{
	public:
		float area(){return (2*(x*y+y*z+z*x));}
};










int main()
{
	circle c;
	parallel p;
	c.param(2);
	cout<<"\n The area of a circle with radius ";
cout<<c.get_x()<<" = "<<c.area();
	p.param(2,4,3);
	cout<<"\n\n The area of a parallelepiped with sides ";
	cout<<p.get_x()<<p.get_y()<<p.get_z();
	cout<<" = "<<p.area() <<endl;
	return 0;
}
