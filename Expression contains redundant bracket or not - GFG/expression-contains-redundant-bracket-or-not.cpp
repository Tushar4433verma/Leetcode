//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int checkRedundancy(string s) {
        stack<char>st;
        int ans;
        
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(' || s[i]=='+' || s[i]=='-'|| s[i]=='*' || s[i]=='/')
                st.push(s[i]);
            else
            {
                //closing
                if(s[i]==')'){
                if(st.top()=='+' || st.top()=='-'|| st.top()=='*' || st.top()=='/')
                { 
                    ans=1;
                    while(st.top()!='(')
                    {
                        st.pop();
                        ans=0;
                    }
                }
                else
                  return 1;
                  
                if(ans==1)
                  return 1;
                st.pop();
            }
            }
        }
        return 0;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        
    
        string s; 
        cin>>s;
        
        Solution obj;
        int res = obj.checkRedundancy(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends