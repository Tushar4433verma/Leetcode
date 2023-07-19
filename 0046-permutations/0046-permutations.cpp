class Solution {
public:

  void solve(vector<int>s,vector<vector<int>>&ans,int index)
	    {
	        //base case
	        if(index>=s.size())
	        {
	            ans.push_back(s);
	            return;
	        }
	        
	        for(int i=index;i<s.size();i++)
	        {
	            //ek case khud smbhal lo
	            swap(s[index],s[i]);
	            //baki recursion chacha dakh langa
	            solve(s,ans,index+1);
	            
	            //backtrack
	            //we are doing changes in original string to get back original one we bactrack
	             swap(s[index],s[i]);
	        }
	    }
    vector<vector<int>> permute(vector<int>& nums) {
         
         vector<vector<int>>ans;

         solve(nums,ans,0);
         return ans;
        
    }
};