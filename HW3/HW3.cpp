#include <iostream>
#include <string>
#include <vector>
using namespace std;
void swap(int &p, int &q){ 
    int temp ;
    temp= p;
    p = q; 
    q = temp; 
} 
// sort by deadline
void Sort(int n,int A[], int B[]){ 
  int i, j, min; 
  for(i=0;i<n-1;i++){ 
    min=i; 
    for(j=i+1;j<n;j++){
      if(B[j] < B[min]){
				min=j; 
			} 
    }
    swap(B[min], B[i]); 
    swap(A[min], A[i]);
  } 
} 

void max_profit(int n,int A[],int B[]){
	vector <int> foo;
	int value;
	int t=0;
	Sort(n,A,B);
	for(int i=0;i<n;i++){
		foo.push_back(1);
		t=t+A[i];	 
		if(t>B[i]){
			foo.pop_back();
			t=t-B[i];
		}
	}
	
	value=foo.size();
	cout<<endl<<"Output:"<<endl<<"Maximum profit = "<<value;
	
}
int main(){
	int n;
	cout<<"Input data"<<endl;
	cin>>n;
	int a,b;
	int t[n];
	int d[n];
	for(int i=0;i<n;i++){
		cin >> a >> b;
   	t[i]=a;
		d[i]=b;	
  }
  max_profit(n,t,d);

}


