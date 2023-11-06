//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

#include<math.h>
class Solution
{
    
    public:
    //Function to delete middle element of a stack.
    void solve(stack<int>&st,int mid)
    {
        if(st.size()==mid)
        {
            st.pop();
            return;
        }
        int num=st.top();
        st.pop();
        solve(st,mid);
        st.push(num);
    }
    void deleteMid(stack<int>&s, int size)
    {
        if(size&1)
          solve(s,ceil(size/2.0));
        else
          solve(s,size/2);
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