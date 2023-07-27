class Solution {
public:
    int compress(vector<char>& chars) {
        
        int n=chars.size();
        int k=0;
        int j,i=0;
        while(i<n)
        {
            j=i+1;
            
            while(j<n && chars[i]==chars[j])
                j++;
            
            chars[k]=chars[i];
            k++;
            
            int cnt=j-i;
            if(cnt>1)
            {
                string count=to_string(cnt);
                
                for(auto num:count)
                    chars[k++]=num;       
            }
            i=j;
        }
        return k;
        
    }
};