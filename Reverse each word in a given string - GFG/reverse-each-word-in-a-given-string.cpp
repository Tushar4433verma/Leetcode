//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseWords (string s)
    {
        stack<char>st;
        string ans="";
        
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='.')
            {
                while(!st.empty())
                {
                    ans.push_back(st.top());
                    st.pop();
                }
                ans.push_back('.');
            }
            else
              st.push(s[i]);
        }
         while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
       
       
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.reverseWords (s) << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends