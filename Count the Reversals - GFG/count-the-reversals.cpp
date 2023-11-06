//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int countRev (string s)
{
   int n=s.size();
   stack<char>st;
   
   if(n&1)
     return -1;
     
   for(int i=0;i<n;i++)
   {
       char ch=s[i];
       //open brace
       if(ch=='{')
         st.push(ch);
       else
       {
           //close brace
           if(!st.empty() && st.top()=='{')
             st.pop();
           else
             st.push(ch);
       }
   }
   
   int a=0,b=0;
   
   while(!st.empty())
   {
       int top=st.top();
       if(top=='{') 
         a++;
       else
         b++;
       st.pop();
   }
   
   return ceil(a/2.0)+ceil(b/2.0);
   
}