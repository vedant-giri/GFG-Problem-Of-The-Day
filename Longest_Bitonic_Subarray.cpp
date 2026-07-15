#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int bitonic(vector<int> &arr) {
        // code here
        int n=arr.size();
        int ans=1;
        vector<int> inc(n,1);
        vector<int> dec(n,1);
        for(int i=1;i<n;i++){
            if(arr[i]>=arr[i-1]) inc[i]=inc[i-1]+1;
        }
        for(int i=n-2;i>=0;i--){
            if(arr[i]>=arr[i+1]) dec[i]=dec[i+1]+1;
        }
        for(int i=0;i<n;i++){
            ans=max(inc[i]+dec[i]-1,ans);
        }
        return ans;
    }
};
int main(){
    Solution sol;
    int n;
    cout<<"Enter the size of array:"<<endl;
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the values of array"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Longest Bitonic array is of length "<<sol.bitonic(arr)<<endl;
    return 0;
}