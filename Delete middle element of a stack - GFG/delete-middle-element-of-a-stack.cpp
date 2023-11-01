//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
    
    public:
    //Function to delete middle element of a stack.
    void solve(stack<int>&st,int cnt,int s)
    {
        if(cnt==s/2)
        {
            st.pop();
            return;
        }
        
        int num=st.top();
        st.pop();
        solve(st,cnt+1,s);
        st.push(num);
    }
    void deleteMid(stack<int>&s, int size)
    {
        
        int cnt=0;
        solve(s,cnt,size);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}

// } Driver Code Ends