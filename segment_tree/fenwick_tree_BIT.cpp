#include<bits/stdc++.h>
using namespace std;

class FNWKTree{
  public:
    vector<int> bit;
    FNWKTree(int n){
        bit.resize(n+1,0);
    }
    void update(int ind, int val){
        ind++;
        int n=bit.size();
        while(ind<n){
            bit[ind]+=val;
            ind+=(ind & -ind);
        }
        return;
    }
    int query(int ind){
        int sum=0;
        ind++;
        while(ind>0){
            sum+=(bit[ind]);
            ind-=(ind & -ind);
        }
        return sum;
    }
    void build(vector<int> &arr){
        int n=arr.size();
        for(int i=0; i<n; i++){
            update(i, arr[i]);
        }
        return;
    }
};
int main(){
    // Fenwick Tree/ Binary Inmdexed Tree
    // Only for sum Query
    int n; cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    FNWKTree ft(n);
    ft.build(arr);
    int q; cin>>q;
    while(q--){
        int type; cin>>type;
        if(type==1){
            int l,r; cin>>l>>r;
            cout<<ft.query(r)-ft.query(l-1)<<endl;
        }
        else{
            int ind,val; cin>>ind>>val;
            arr[ind]+=val;
            ft.update(ind,val);
        }
    }
}
