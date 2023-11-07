class Solution {
public:
    
    vector<int>nextSmaller(vector<int>&arr,int n)
    {
        stack<int>st;
        vector<int>bc;
        st.push(-1);
        
        for(int i=n-1;i>=0;i--)
        {
            int curr=arr[i];
            while(st.top()!=-1 && arr[st.top()]>=curr)
              st.pop();
            bc.push_back(st.top());
            st.push(i);
        }
        reverse(bc.begin(),bc.end());
        return bc;
    }
    
    vector<int>prevSmaller(vector<int>&arr,int n)
    {
        stack<int>st;
        vector<int>bc;
        st.push(-1);
        
        for(int i=0;i<n;i++)
        {
            int curr=arr[i];
            while(st.top()!=-1 && arr[st.top()]>=curr)
              st.pop();
            bc.push_back(st.top());
            st.push(i);
        }
       // reverse(bc.begin(),bc.end());
        return bc;
        
    }
    int largestRectangleArea(vector<int>& heights) {
        
        int n=heights.size();
        vector<int>next;
        vector<int>prev;
        int area=INT_MIN;
 
        next=nextSmaller(heights,n);
        prev=prevSmaller(heights,n);
        
        for(int i=0;i<n;i++)
        {
            int l=heights[i];
            if(next[i]==-1)
                next[i]=n;
            int b=next[i]-prev[i]-1;
            int ans=l*b;
            area=max(area,ans);
        }
        return area;
    }
};