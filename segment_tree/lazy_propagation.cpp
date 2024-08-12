#include<bits/stdc++.h>
using namespace std;

class SEGTree{
  public:
    vector<int> seg;
    vector<int> lazy;
    SEGTree(int n){
        seg.resize(4*n+1);
        lazy.resize(4*n+1,0);
    }
    void build(int ind, int low, int high, vector<int> &arr){
        if(low==high){
            seg[ind]=arr[low];
            return;
        }
        int mid=(high+low)/2;
        build(2*ind+1,low, mid,arr);
        build(2*ind+2,mid+1,high,arr);
        seg[ind]=seg[2*ind+1]+seg[2*ind+2];
    }
    void update(int ind, int low, int high, int l, int r,int val){
        if(lazy[ind]!=0){
            seg[ind]+=(high-low+1)*lazy[ind];
            if(low!=high){
                lazy[2*ind+1]+=lazy[ind];
                lazy[2*ind+2]+=lazy[ind];
            }
            lazy[ind]=0;
        }
        // no overLap CAse
        if(high<l || r<low){
            return;
        }
        if(high<=r && l<=low){
            seg[ind]+=(high-low+1)*val;
            if(low!=high){
                lazy[2*ind+1]+=val;
                lazy[2*ind+2]+=val;
            }
            return;
        }
        int mid=(high+low)/2;
        update(2*ind+1,low,mid,l,r,val);
        update(2*ind+2,mid+1,high,l,r,val);
        seg[ind]=seg[2*ind+1]+seg[2*ind+2];
    }
    int query(int ind, int low, int high, int l, int r){
        if(lazy[ind]!=0){
            seg[ind]+=(high-low+1)*lazy[ind];
            if(low!=high){
                lazy[2*ind+1]+=lazy[ind];
                lazy[2*ind+2]+=lazy[ind];
            }
            lazy[ind]=0;
        }
        // no overLap CAse
        if(high<l || r<low){
            return 0;
        }
        if(high<=r && l<=low){
            return seg[ind];
        }
        int mid=(high+low)/2;
        int left=query(2*ind+1,low,mid,l,r);
        int right=query(2*ind+2,mid+1,high,l,r);
        return (left+right);
    }
};
int main(){
    int n; cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    SEGTree sg(n);
    sg.build(0,0,n-1,arr);
    int q; cin>>q;
    while(q--){
        int type; cin>>type;
        if(type==1){
            int l,r; cin>>l>>r;
            cout<<sg.query(0,0,n-1,l,r)<<endl;
        }
        else{
            int l,r,val; cin>>l>>r>>val;
            sg.update(0,0,n-1,l,r,val);
        }
    }
}
