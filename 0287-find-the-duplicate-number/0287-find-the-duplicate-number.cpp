class Solution {
public:
    int findDuplicate(vector<int>& nums) {
      
        map<int,int>mp;
        
        for(int i=0;i<nums.size();i++) mp[nums[i]]++;
        
        for(auto n:mp)
        {
            if(n.second>1) return n.first;
        }
        return 1;
    }
};