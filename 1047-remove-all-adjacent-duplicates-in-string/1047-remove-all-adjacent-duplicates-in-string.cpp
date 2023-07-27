class Solution {
public:
    string removeDuplicates(string s) {
        
        stack<char>st;
        string ans="";
        st.push('@');
        
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==st.top())
                st.pop();
            
            else{
                st.push(s[i]);
            }
        }
        while(st.top()!='@')
        {
            ans.push_back(st.top());
            st.pop();
        }
        int i=0;
        int j=ans.size()-1;
        
        while(i<j)
        {
            swap(ans[i],ans[j]);
                i++;
            j--;
        }
        
        return ans;
        
        
    }
};