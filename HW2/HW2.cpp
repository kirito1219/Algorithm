#include<iostream> 
#include<string> 
#include<vector>  
using namespace std; 
  

// define operator calculate 
int calculate(int a, char ch, int b){
	if (ch=='+'){
		return a+b; 
	}else if(ch=='-'){
		return a-b; 
	}else if(ch == '*'){
		return a*b; 
	}
} 
  
// evaluate all condition 
vector<int> MAX_value(string exp, int begin, int end) { 
  // to reserve ans
  vector<int> A; 
  
  // Only one char then return
  // Only have 3 char , then calcuate , middle must be operator
  if (begin == end) { 
    A.push_back(exp[begin] - '0');  
  }else if(begin == (end-2)){
  	int num = calculate(exp[begin]-'0', exp[begin+1], exp[begin+2]-'0'); 
  	A.push_back(num); 
	}
  
  int value;
  // every i is an operator 
  for (int i=begin+1; i<=end; i+=2) {  
    // left operator in exp 
    vector<int> front = MAX_value(exp, begin, i-1); 
    // right operator in exp
    vector<int> back = MAX_value(exp, i+1, end); 
    // Calculate value for every condition   
   	 for (int a=0; a<front.size(); a++) { 
        for (int b=0; b<back.size(); b++) { 
            value = calculate(front[a], exp[i], back[b]); 
            A.push_back(value); 
        } 
      } 
	}
    return A; 
} 
//print max value
int printMAX(vector<int> A,string B){
	int MAX;
  for (int i=0; i< A.size(); i++){
    if(i==0){
			MAX=A[i];
		}else if(i<A.size()-1){
			if(MAX<A[i+1]){
				MAX=A[i+1];
			}
		}
  }
  
	cout<<B<<" = "<<MAX<<endl;
  
}
 
int main() 
{ 
    string expression ;
		cout<<"input string"<<endl;
		cin>>expression; 
		cout<<endl;
    int len = expression.length(); 
    vector<int> ans = MAX_value(expression, 0, len-1); 
  	printMAX(ans,expression);
    return 0; 
} 



