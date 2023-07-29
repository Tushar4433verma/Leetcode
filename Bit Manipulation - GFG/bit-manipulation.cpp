//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void bitManipulation(int n, int i) {
        
        int mask=1<<i-1;
        
        int check=(n&mask);
        if(check)  cout<<1<<" ";
        else cout<<0<<" ";
        
        cout<<(n|mask)<<" ";
        
        int newm=1<<i-1;
        int temp=~(newm);
        
        cout<<(n&temp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n >> i;
        Solution ob;
        ob.bitManipulation(n, i);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends