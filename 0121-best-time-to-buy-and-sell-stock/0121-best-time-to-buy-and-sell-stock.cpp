class Solution {
public:
    int maxProfit(vector<int>& arr) {
      
        int n=arr.size();
        int aux[100000];
        
        aux[n-1]=arr[n-1];
        
        for(int i=n-2;i>=0;i--)
        {
            aux[i]=max(aux[i+1],arr[i]);
        }
        
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            ans=max(aux[i]-arr[i],ans);
         }
        
        return ans;
    }
};