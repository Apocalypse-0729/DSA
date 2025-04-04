#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll func(ll maxi){
    ll low=0,high=2*maxi;
    ll sum=0;
    ll ans=0;
    while(high>=low){
        ll mid=(high+low)/2;
        sum=(mid*(mid+1))/2;
        if(sum>=maxi && sum%2==maxi%2){
            high=mid-1;
            ans=mid;
        }
        else low=mid+1;
    }
    return ans;
}
int main(){
    ll n,p,q; cin>>n>>p>>q;
    vector<pair<ll,ll>> v(n);
    for(int i=0; i<n; i++) cin>>v[i].first>>v[i].second;
    vector<ll> dist(n);
    for(int i=0; i<n; i++){
        dist[i]=abs(p-v[i].first)+abs(q-v[i].second);
    }
    bool isEven=(dist[0]%2==0);
    for(auto it:dist){
        if((it%2==0)!=isEven){
            cout<<-1<<endl;
            return 0;
        }
    }
    ll maxi=*max_element(dist.begin(),dist.end());
    cout<<func(maxi)<<endl;
    return 0;
}
