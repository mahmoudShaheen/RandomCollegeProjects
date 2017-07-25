#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;
int add;
char name[20];
class inventory{
		char item[20];
		int onhand;
		float cost;
	public:
		void input();
		void output(ofstream &fout);
		friend void check_in(inventory &ob);

};
void check_in(inventory &ob)
{
	if(strcmp(name,ob.item)==0)
		ob.onhand +=add;
}
void inventory::input()
{
	cout<<" item: ";cin>>item;
	cout<<" onhand: ";cin>>onhand;
	cout<<" cost: ";cin>>cost;

}
void inventory::output(ofstream &fout){
	fout<<setiosflags(ios::left);
	fout<<"\n "<<setw(15)<<item;
	fout<<setw(10)<<onhand;
	fout<<setw(10)<<cost;
	fout<<setw(10)<<onhand*cost;
}
int main()
{
	int i,j,no;
	inventory ob[5];
	for (i=0;i<5;i++)
	{
		cout<<" \n Enter data of item #"<<i+1<<"\n";
		ob[i].input();
	}

	cout<<"\n Enter no. of updates: ";
	cin>>no;
	for(j=0;j<no;j++)
	{
		cout<<" name: "; cin>>name;
		cout<<" +addition/-deletion: ";cin>>add;
		for(i=0;i<5;i++)
			check_in(ob[i]);
	}
	ofstream fout("InvFile.txt",ios::app);
	fout<<setiosflags(ios::left);
	fout<<"\n "<<setw(15)<<"Item name";
	fout<<setw(10)<<"onhand";
	fout<<setw(10)<<"cost";
	fout<<setw(10)<<"Total cost";
	for (i=0;i<5;i++)
		ob[i].output(fout);
	fout.close();
	return 0;
}



