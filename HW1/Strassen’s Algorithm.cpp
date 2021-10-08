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
	int A_11[n/2][n/2];
	int A_12[n/2][n/2];
	int A_21[n/2][n/2];
	int A_22[n/2][n/2];
	int B_11[n/2][n/2];
	int B_12[n/2][n/2];
	int B_21[n/2][n/2];
	int B_22[n/2][n/2];
	int C_11[n/2][n/2];
	int C_12[n/2][n/2];
	int C_21[n/2][n/2];
	int C_22[n/2][n/2];
	srand(time(NULL));
	clock_t start,finish;
	double duration;
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
	//set partial aarray
	for(int i=0;i<n/2;i++){
		for(int j=0;j<n/2;j++){
			A_11[i][j]=A[i][j];
			B_11[i][j]=B[i][j];	
		}		
	}
	for(int i=0;i<n/2;i++){
		for(int j=0;j<n/2;j++){
			A_12[i][j]=A[i][j+n/2];
			B_12[i][j]=B[i][j+n/2];	
		}	
	}
	for(int i=0;i<n/2;i++){
		for(int j=0;j<n/2;j++){
			A_21[i][j]=A[i+n/2][j];
			B_21[i][j]=B[i+n/2][j];		
		}	
	}
	for(int i=0;i<n/2;i++){
		for(int j=0;j<n/2;j++){
			A_22[i][j]=A[i+n/2][j+n/2];
			B_22[i][j]=B[i+n/2][j+n/2];	
		}	
	}
	//calculate partial array
	int M1[n/2][n/2],M2[n/2][n/2],M3[n/2][n/2],M4[n/2][n/2],M5[n/2][n/2],M6[n/2][n/2],M7[n/2][n/2];
	int temp1[n/2][n/2];
	int temp2[n/2][n/2];
	for(int i=0;i<n/2;i++){
		for(int j=0;j<n/2;j++){
			M1[i][j]=0;
			M2[i][j]=0;
			M3[i][j]=0;
			M4[i][j]=0;
			M5[i][j]=0;
			M6[i][j]=0;
			M7[i][j]=0;
			temp1[i][j]=0;
			temp2[i][j]=0;
		}
	}
	//calculate M1
	for(int i=0;i<n/2;i++){
		for(int j=0;j<n/2;j++){
			temp1[i][j]=A_11[i][j]+A_22[i][j];
			temp2[i][j]=B_11[i][j]+B_22[i][j];
		}
	}
	for(int i=0;i<n/2;i++){
		for (int j=0;j<n/2;j++){
			for(int k=0;k<n/2;k++){	
				M1[i][j]=M1[i][j]+temp1[i][k]*temp2[k][j];
			}	
		}
	}

	//calculate M2
	for(int i=0;i<n/2;i++){
		for(int j=0;j<n/2;j++){
			temp1[i][j]=A_21[i][j]+A_22[i][j];
		}
	}
	for(int i=0;i<n/2;i++){
		for (int j=0;j<n/2;j++){
			for(int k=0;k<n/2;k++){	
				M2[i][j]=M2[i][j]+temp1[i][k]*B_11[k][j];
			}
		}
	}

	//calculate M3
	for(int i=0;i<n/2;i++){
		for(int j=0;j<n/2;j++){
			temp1[i][j]=B_12[i][j]-B_22[i][j];
		}
	}
	for(int i=0;i<n/2;i++){
		for (int j=0;j<n/2;j++){
			for(int k=0;k<n/2;k++){	
				M3[i][j]=M3[i][j]+A_11[i][k]*temp1[k][j];
			}
		}
	}

	//calculate M4
	for(int i=0;i<n/2;i++){
		for(int j=0;j<n/2;j++){
			temp1[i][j]=B_21[i][j]-B_11[i][j];
		}
	}
	for(int i=0;i<n/2;i++){
		for (int j=0;j<n/2;j++){
			for(int k=0;k<n/2;k++){	
				M4[i][j]=M4[i][j]+A_22[i][k]*temp1[k][j];
			}
		}
	}

	//calculate M5
	for(int i=0;i<n/2;i++){
		for(int j=0;j<n/2;j++){
			temp1[i][j]=A_11[i][j]+A_12[i][j];;
		}
	}
	for(int i=0;i<n/2;i++){
		for (int j=0;j<n/2;j++){
			for(int k=0;k<n/2;k++){	
				M5[i][j]=M5[i][j]+temp1[i][k]*B_22[k][j];
			}
		}
	}

	//calculate M6
	for(int i=0;i<n/2;i++){
		for(int j=0;j<n/2;j++){
			temp1[i][j]=A_21[i][j]-A_11[i][j];
			temp2[i][j]=B_11[i][j]+B_12[i][j];
		}
	}
	for(int i=0;i<n/2;i++){
		for (int j=0;j<n/2;j++){
			for(int k=0;k<n/2;k++){	
				M6[i][j]=M6[i][j]+temp1[i][k]*temp2[k][j];
			}
		}
	}

	//calculate M7
	for(int i=0;i<n/2;i++){
		for(int j=0;j<n/2;j++){
			temp1[i][j]=A_12[i][j]-A_22[i][j];
			temp2[i][j]=B_21[i][j]+B_22[i][j];
		}
	}
	for(int i=0;i<n/2;i++){
		for (int j=0;j<n/2;j++){
			for(int k=0;k<n/2;k++){	
				M7[i][j]=M7[i][j]+temp1[i][k]*temp2[k][j];
			}	
		}
	}

	//calculate array C
	for(int i=0;i<n/2;i++){
		for(int j=0;j<n/2;j++){
			C_11[i][j]=M1[i][j]+M4[i][j]-M5[i][j]+M7[i][j];
			C_12[i][j]=M3[i][j]+M5[i][j];
			C_21[i][j]=M2[i][j]+M4[i][j];
			C_22[i][j]=M1[i][j]+M3[i][j]-M2[i][j]+M6[i][j];
		}
	}
	for(int i=0;i<n/2;i++){
		for(int j=0;j<n/2;j++){
			C[i][j]=C_11[i][j];
		}
	}
	for(int i=0;i<n/2;i++){
		for(int j=n/2;j<n;j++){
			C[i][j]=C_12[i][j-n/2];
		}
	}
	for(int i=n/2;i<n;i++){
		for(int j=0;j<n/2;j++){
			C[i][j]=C_21[i-n/2][j];
		}
	}
	for(int i=n/2;i<n;i++){
		for(int j=n/2;j<n;j++){
			C[i][j]=C_22[i-n/2][j-n/2];
		}
	}
	duration=(double)start/CLOCKS_PER_SEC;
	//print array C_Strassen��s Algorithm
	cout<<"array C_Strassen��s Algorithm"<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<C[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	cout<<"cost "<<(double)duration<<" s"<<endl; 
	
	
    return 0; 
} 

