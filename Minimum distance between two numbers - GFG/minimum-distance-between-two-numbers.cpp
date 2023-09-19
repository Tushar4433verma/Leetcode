//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
  public:
    int minDist(int a[], int n, int x, int y) {
        
        int ix=-1,iy=-1;
        int ans=1e9;
        
        for(int i=0;i<n;i++)
        {
            if(a[i]==x) ix=i;
            else if(a[i]==y) iy=i;
              
            if(ix!=-1 && iy!=-1) ans=min(ans,abs(ix-iy));
        }
        
        if(ans==1e9) ans=-1;
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        int x, y;
        cin >> x >> y;
        Solution obj;
        cout << obj.minDist(a, n, x, y) << endl;
    }
    return 0;
}

// } Driver Code Ends