class Solution {
public:
    
    void solve(vector<vector<int>>&ans,vector<int>temp,vector<int>num,int i,int j)
    {
        if(i>=j)
        {
            ans.push_back(temp);
            return;
        }
        
        //ecxlude
        solve(ans,temp,num,i+1,j);
        
        //inlcude
        int el=num[i];
        temp.push_back(el);
        solve(ans,temp,num,i+1,j);
        
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>>ans;
        vector<int>temp;
        int i=0;
        int j=nums.size();
        solve(ans,temp,nums,i,j);
        return ans;
        
    }
};