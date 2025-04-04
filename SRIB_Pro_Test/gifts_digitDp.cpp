#include<bits/stdc++.h>
using namespace std;

int dp[101][1001];
const int MOD=1e9+7;
int func(string A, int pos, bool tight, int sum){
    if(sum<0) return 0;
    if(pos==A.size()) return sum==0;
    if(!tight && dp[pos][sum]!=-1) return dp[pos][sum];
    
    int limit=tight ? (A[pos]-'0') : 9, result=0;
    for(int d=0; d<=limit; d++){
        result=(result+func(A,pos+1, tight && (d==limit), sum-d))%MOD;
    }
    return tight ? result : dp[pos][sum]=result;
}
int main(){
    string A; cin>>A;
    long long s; cin>>s;
    if(s>A.size()*9){
        cout<<0<<endl;
        return 0;
    }
    memset(dp, -1, sizeof(dp));
    cout<<func(A,0,true,s);
    return 0;
}
