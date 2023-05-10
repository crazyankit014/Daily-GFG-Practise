//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int totalCuts(int N,int K,vector<int> &A){
         vector<int>lmax(N,0);
        vector<int>rmin(N,0);
        int lm=0;
        int rm=INT_MAX;
        
        if(N==1){
            return 0;
        }
        
        for(int i=0;i<N;i++){
            lm=max(lm,A[i]);
            lmax[i]=lm;
        }
        
        for(int i=N-1;i>=0;i--){
            rm=min(rm,A[i]);
            rmin[i]=rm;
        }
        
        int ans=0;
        for(int i=1;i<N;i++){
            if(lmax[i-1]+rmin[i]>=K){
                ans++;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,K;
        cin>>N>>K;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution ob;
        cout<<ob.totalCuts(N,K,A)<<endl;
    }
    return 0;
}
// } Driver Code Ends