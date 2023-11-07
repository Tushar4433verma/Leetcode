//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    
    vector<long long > nextSmaller(vector<long long >&arr,int n)
    {
        stack<long long >st;
        vector<long long >bc;
        st.push(-1);
        
        for(int i=n-1;i>=0;i--)
        {
            long long  curr=arr[i];
            while(st.top()!=-1 && arr[st.top()]>=curr)
              st.pop();
            bc.push_back(st.top());
            st.push(i);
        }
        reverse(bc.begin(),bc.end());
        return bc;
    }
    
    vector<long long > prevSmaller(vector<long long >&arr,int n)
    {
        stack<long long >st;
        vector<long long >bc;
        st.push(-1);
        
        for(int i=0;i<n;i++)
        {
            long long int curr=arr[i];
            while(st.top()!=-1 && arr[st.top()]>=curr)
              st.pop();
            bc.push_back(st.top());
            st.push(i);
        }
       // reverse(bc.begin(),bc.end());
        return bc;
        
    }
    long long getMaxArea(long long h[], int n)
    {
        vector<long long >heights;
        for(int i=0;i<n;i++)  heights.push_back(h[i]);
        
        vector<long long>next;
        vector<long long>prev;
        long long area=INT_MIN;
 
        next=nextSmaller(heights,n);
        prev=prevSmaller(heights,n);
        
        for(int i=0;i<n;i++)
        {
            long long  l=heights[i];
            if(next[i]==-1)
                next[i]=n;
            long long  b=next[i]-prev[i]-1;
            long long ans=l*b;
            area=max(area,ans);
        }
        return area;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends