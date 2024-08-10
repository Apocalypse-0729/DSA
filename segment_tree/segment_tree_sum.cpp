#include<bits/stdc++.h>
using namespace std;

class SEGTree{
  public:
    vector<int> seg;
    SEGTree(int n){
        seg.resize(4*n+1);
    }
    void build(int ind, int low, int high, vector<int> &arr){
        if(low==high){
            seg[ind]=arr[low];
            return;
        }
        int mid=(high+low)>>1;
        build(2*ind+1,low,mid,arr);
        build(2*ind+2,mid+1,high,arr);
        seg[ind]=seg[2*ind+1]+seg[2*ind+2]; // Calculate sum of left and right subtrees
    }
    int query(int ind,int low, int high, int l, int r){
        if(low>r || high<l){
            return 0; // Out of range, return 0
        }
        if(low>=l && high<=r){
            return seg[ind]; // Completely within range, return sum
        }
        int mid=(high+low)>>1;
        int left=query(2*ind+1,low,mid,l,r);
        int right=query(2*ind+2,mid+1,high,l,r);
        return left+right; // Calculate sum of left and right subtrees
    }
    void update(int ind,int low, int high,int i, int val){
        if(low==high){
            seg[ind]=val;
            return;
        }
        int mid=(high+low)>>1;
        if(i<=mid){
            update(2*ind+1,low,mid,i,val);
        }
        else{
            update(2*ind+2,mid+1,high,i,val);
        }
        seg[ind]=seg[2*ind+1]+seg[2*ind+2]; // Update sum after updating a node
    }
};
int main(){
    int n; cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    SEGTree seg(n);
    seg.build(0,0,n-1,arr);
    int q; cin>>q;
    while(q--){
        int l,r; cin>>l>>r;
        cout<<seg.query(0,0,n-1,l,r)<<endl;
    }
    
}
