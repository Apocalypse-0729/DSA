#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001];
int n,m;

int func(int ind, int prev, vector<int> &v){
    if(ind==v.size()) return 0;
    if(dp[ind][prev]!=-1) return dp[ind][prev];
    int prevRobot=(ind-prev)*v[ind]+func(ind+1,prev,v);
    int newRobot=m+func(ind+1,ind,v);
    return dp[ind][prev]=min(prevRobot,newRobot);
    
}
int main(){
    cin>>n>>m;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    memset(dp,-1,sizeof(dp));
    int firstNonZero=-1;
    for(int i=0; i<n; i++){
        if(v[i]!=0){
            firstNonZero=i;
            break;
        }
    }
    int ans=0;
    if(firstNonZero!=-1) ans=m+func(firstNonZero+1,firstNonZero,v);
    cout<<ans<<endl;
    return 0;
}
