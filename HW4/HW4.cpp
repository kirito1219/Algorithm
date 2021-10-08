#include <iostream> 
#include <vector>
#include <time.h>
using namespace std;

// original way

void  Bellman(int E,int V,int a[],int b[],int c[],int s,int e){
	int parent[V];
	int value[V];
	
	// Initialize
	for(int i=0;i<V;i++){
		value[i]=INT_MAX;
		parent[i]=-1;
	}
	value[s]=0;
	
	// run (V-1) times
	for(int i=0;i<V-1;i++){
		// for each vertex check its edge
		for(int j=0;j<E;j++){
				// do relax
				if(value[b[j]]>value[a[j]]+c[j]){
					value[b[j]]=value[a[j]]+c[j];
					parent[b[j]]=a[j];	
			}
			
		}
	}
	// check if it has negative weight cycle
	int aa=0;
	for(int j=0;j<E;j++){
		if(value[b[j]]>value[a[j]]+c[j]){
			cout<<"There is a negative weight cycle."<<endl<<endl;
			vector <int> gg;
			gg.push_back(b[j]);	
			int p=b[j];
			while(parent[p] !=b[j]){
				gg.push_back(parent[p]);
				p=parent[p];
			}
			for(int k=gg.size()-1;k>=0;k--){
				cout<<gg[k]<<" ";
			}
			cout<<endl;
			aa=1;
		}
	}
	// print shortest path
	if(aa==0){
		int d=e;
		vector <int> ans;

		while(parent[d]!=s){
			ans.push_back(parent[d]);
			d=parent[d];
		}
		cout<<s<<" ";
		for(int i=ans.size()-1;i>=0;i--){
			cout<<ans[i]<<" ";
		}
		cout<<e<<endl;
		cout<<value[e]<<endl;
	}
}
// modified way 

void  new_Bellman(int E,int V,int a[],int b[],int c[],int s,int e){
	int parent[V];
	int value[V];
	
	for(int i=0;i<V;i++){
		value[i]=INT_MAX;
		parent[i]=-1;
	}
	value[s]=0;
	int count;
	for(int i=0;i<V-1;i++){
		count=0;
		for(int j=0;j<E;j++){
				if(value[b[j]]>value[a[j]]+c[j]){
					value[b[j]]=value[a[j]]+c[j];
					parent[b[j]]=a[j];	
					count=1;
				}
		}
		if(count==0){
			break;
		}
	}

	int aa=0;
	for(int j=0;j<E;j++){
		if(value[b[j]]>value[a[j]]+c[j]){
		//	cout<<"There is a negative weight cycle."<<endl;
			vector <int> gg;
			gg.push_back(b[j]);	
			int p=b[j];
			while(parent[p] !=b[j]){
				gg.push_back(parent[p]);
				p=parent[p];
			}
			for(int k=gg.size()-1;k>=0;k--){
		//		cout<<gg[k]<<" ";
			}
	//		cout<<endl;
			aa=1;
		}
	}
	if(aa==0){
		int d=e;
		vector <int> ans;

		while(parent[d]!=s){
			ans.push_back(parent[d]);
			d=parent[d];
		}
	//	cout<<s<<" ";
		for(int i=ans.size()-1;i>=0;i--){
	//		cout<<ans[i]<<" ";
		}
	//	cout<<e<<endl;
	//	cout<<value[e];
	}
}
int main(){
	int V, E;
	cin>>V>>E;
	int source,end;
	cin>>source>>end;
	int a[E],b[E],c[E];
	for(int i=0;i<E;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	cout<<"-------------"<<endl;
	clock_t t1, t2,t3,t4;
	t1 = clock();
	Bellman(E,V,a,b,c,source,end);
	t2 = clock();
	cout<<endl<<"original time: "<<t2-t1/(double)(CLOCKS_PER_SEC)<<"ms"<<endl;
	
	t3=clock();
	new_Bellman(E,V,a,b,c,source,end);
	t4=clock();
	cout<<endl<<"modified time: "<<t4-t3/(double)(CLOCKS_PER_SEC)<<"ms"<<endl;
	
	return 0;
}
