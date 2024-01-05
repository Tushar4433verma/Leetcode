class Solution {
public:
    vector<int> majorityElement(vector<int>& a) {
          map<int,int>mp;
        vector<int>ans;
        int size=a.size();
        
        for(int i=0;i<size;i++) mp[a[i]]++;
        
        for(auto it:mp)
        {
            if(it.second>ceil(size/3))  ans.push_back( it.first);
        }
        return ans;
        
    }
};