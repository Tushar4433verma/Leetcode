class Solution {
public:
    
    void solve(vector<string>&ans,string temp,int in,int j,string mp[],string digits)
    {
        if(in>=j)
        {
            ans.push_back(temp);
            return;
        }
        int num=digits[in]-'0';
        string patt=mp[num];
        
        for(int i=0;i<patt.size();i++)
        {
            temp.push_back(patt[i]);
            solve(ans,temp,in+1,j,mp,digits);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        
        vector<string>ans;
        if(digits.length()==0) return ans;
        string temp="";
        int i=0;
        int j=digits.size();
        string map[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
        solve(ans,temp,i,j,map,digits);
        return ans;
        
    }
};