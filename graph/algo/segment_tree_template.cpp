#include<bits/stdc++.h>
using namespace std;

class SEGTree{
  public:
    vector<int> seg;
    SEGTree(int n){
        seg.resize(4*n+1);
    }
    void build(int ind,int low, int high,vector<int> &arr){
        if(low==high){
            seg[ind]=arr[low];
            return;
        }
        int mid=(low+high)/2;
        build(2*ind+1,low,mid,arr);
        build(2*ind+2,mid+1,high,arr);
        seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);
    }
    int query(int ind,int low,int high, int l, int r){
        if(low>r && high<l) return INT_MAX;
        if(low>=l && high<=r) return seg[ind];
        int mid=(low+high)/2;
        int min1=query(2*ind+1,low,mid,l,r);
        int min2=query(2*ind+2,mid+1,high,l,r);
        return min(min2,min1);
    }
    void update(int ind,int low,int high,int i,int val){
        if(low==high){
            seg[ind]=val;
            return;
        }
        int mid=(low+high)/2;
        if(i<=mid) update(2*ind+1,low,mid,i,val);
        else update(2*ind+2,mid+1,high,i,val);
        seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);
    }
};
int main(){
    int n; cin>>n;
    SEGTree stree(n);
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    stree.build(0,0,n-1,arr);
    for(int i=0; i<4*n+1; i++) cout<<stree.seg[i]<<" ";
    cout<<endl;
    int q; cin>>q;
    while(q--){
        int type; cin>>type;
        if(type==1){
            int low,high; cin>>low>>high;
            cout<<stree.query(0,0,n-1,low,high)<<endl;
        }
        else{
            int i,val; cin>>i>>val;
            stree.update(0,0,n-1,i,val);
            for(int i=0; i<4*n+1; i++) cout<<stree.seg[i]<<" ";
            cout<<endl;
            arr[i]=val;
        }
    }
}
