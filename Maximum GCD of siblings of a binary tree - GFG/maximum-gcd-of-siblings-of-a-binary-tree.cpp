//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int gcd(int a, int b){
        if(b==0) return a;
        return gcd(b,a%b);
    }
    int maxBinTreeGCD(vector<vector<int>> arr, int N) {
        // code here
        sort(arr.begin(), arr.end());
        int max_gcd = 0;
        for(int i=0; i<arr.size(); i++){
            int gnum = arr[i][0];
            int j=i+1;
            while(j<arr.size() && arr[j][0]==gnum) j++;
            if((j-i)%2==0){
                max_gcd = max(max_gcd,gcd(arr[i][1],arr[j-1][1]));
                i=j-1;
            }else{
                max_gcd = max(max_gcd,0);
            }
        }
        return max_gcd;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,u,v;
        cin>>N;
        
        vector<vector<int>> arr;
        
        for(int i=0; i<N-1; i++)
        {
            cin>>u>>v;
            vector<int> edge;
            edge.push_back(u);
            edge.push_back(v);
            arr.push_back(edge);
        }

        Solution ob;
        cout << ob.maxBinTreeGCD(arr,N) << endl;
    }
    return 0;
}
// } Driver Code Ends