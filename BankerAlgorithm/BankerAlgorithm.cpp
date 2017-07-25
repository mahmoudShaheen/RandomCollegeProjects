#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {
	int p,r;
	cout	<< "\nEnter Number Of Processes\n";
	cin >> p;
	cout	<< "\nEnter Number Of Resources\n";
	cin >> r;
	int all[p][r];
	int max[p][r];
	int av[r];
	int need[p][r];
	int temp;
	bool done[p];
	for (int i=0 ; i<p;i++)
		done[p]= false;
	cout	<< "\nEnter Allocation Matrix\n";
	for( int i=0 ; i<p ; i++ ){
		for( int j=0 ; j<r ; j++) {
			cin >> all[i][j]; 
		}
	}
	cout	<< "\nEnter Max Matrix\n";
	for( int i=0 ; i<p ; i++ ){
		for( int j=0 ; j<r ; j++){
			cin >> max[i][j];
		}
	}
	cout	<< "\nEnter initial Available Resources\n";
	for( int i=0 ; i<r ; i++ )
		cin >> av[i];
	cout	<< "\n\n\nNeed Matrix";
	for( int i=0 ; i<p ; i++ ){
		cout	<< endl;
		for( int j=0 ; j<r ; j++) {
			need[i][j]=max[i][j]-all[i][j];
			cout	<< " " << need[i][j] << " ";
			if(need[i][j] < 0){
				cout	<< "\nERR: Process has resources more than its Max \n";
				exit (EXIT_FAILURE);
			}
		}
	}
	cout << "\n\n\nExecution Sequence\t\t	Available\n";
	for(int x =0 ; x<p ; x++){
		for(int i=0 ; i <p ; i++){
			temp =0;
			if(!done[i]){
				for(int j=0 ; j<r ; j++){
					if(need[i][j] <= av[j] )
						temp++;
				}
				if(temp == r ){
					done[i]=true;
					for(int j=0 ; j<r ; j++){
						av[j]+=all[i][j];
					}
				cout << "\tP" << i <<"\t\t\t\t";
				for(int j=0 ; j<r ; j++)
				cout << av[j] << " ";
				cout<<endl;
				}
			}
		}
	}
	temp =0;
	for (int i=0 ; i<p ; i++){
		if (done[i])
		temp++;
	}
	if (temp ==p)
		cout << "\nThe System is in a safe state!\n";
	else
		cout << "\nThe System is not in a safe state!\n";
	//request
	int preq,req[r];
	cout << "\nEnter the process number\n";
	cin >> preq ;
	cout << "\nEnter the request\n";
	for (int i=0 ; i<r ; i++)
		cin >> req[i];
	for (int i =0 ; i<r ; i++){
		if( req[i] <= need[preq][i] )
			temp++;
	}
	if(temp == r && done[preq] )
		cout<<"\nRequest Can Be Granted\n";
	else
		cout <<"\nRequest Can not Be Granted\n";
	return 0;
} 

