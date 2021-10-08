#include <iostream> 
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std; 
int main(){
	int n;
	cin>>n;
	int A[n][n];
	int B[n][n];
	int C[n][n];
	clock_t start;
	double duration;
	srand(time(NULL));
	//give initial value
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			A[i][j]=rand()%101+1;
			B[i][j]=rand()%101+1;
			C[i][j]=0;
		}
	}	
	//print array A
	cout<<"array A"<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
		
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	//print array B
	cout<<"array B"<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){	
			cout<<B[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	
	start=clock();
	//print array C
	cout<<"array C"<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				C[i][j]=C[i][j]+A[i][k]*B[k][j];
			}
			cout<<C[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	duration=(double)start/CLOCKS_PER_SEC;
	cout<<"cost "<<duration<<" s"<<endl; 

    return 0; 
} 

