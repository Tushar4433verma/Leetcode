//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++

void solve(int i,int j,string &str)
{
    
  if(i>j) return;
    
  
  swap(str[i],str[j]);
  i++;
  j--;
  solve(i,j,str);
    
}
string reverseWord(string str){
    
  
  int i=0;
  int j=str.length()-1;
  
  solve(i,j,str);
  return str;
  
  
  
  
  
}



//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	string s;
	cin >> s;
	
	cout << reverseWord(s) << endl;
	}
	return 0;
	
}


// } Driver Code Ends