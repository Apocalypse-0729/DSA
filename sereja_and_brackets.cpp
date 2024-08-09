#include<bits/stdc++.h>
using namespace std;
 
struct info{
    public:
        int open,close,full;
        info(){
            open=0;
            close=0;
            full=0;
        }
        info(int _close,int _open,int _full){
            close=_close;
            full=_full;
            open=_open;
        }
};
info merge(info &left, info &right){
    info ans=info(0,0,0);
    ans.full=left.full+right.full+min(left.open,right.close);
    ans.open=left.open+right.open-min(left.open,right.close);
    ans.close=left.close+right.close-min(left.open,right.close);
    return ans;
}
void build(int ind, int low, int high,vector<info> &seg,string &s){
    if(high==low){
        seg[ind].open=(s[low]=='(');
        seg[ind].close=(s[low]==')');
        seg[ind].full=0;
        return;
    }
    int mid=(high+low)/2;
    build(2*ind+1,low,mid,seg,s);
    build(2*ind+2,mid+1,high,seg,s);
    seg[ind]=merge(seg[2*ind+1],seg[2*ind+2]);
}
info query(int ind, int low, int high, int l, int r, vector<info> &seg){
    if(low>r || high<l){
        return info();
    }
    if(low>=l && high<=r){
        return seg[ind];
    }
    int mid=(low+high)/2;
    info left=query(2*ind+1,low,mid,l,r,seg);
    info right=query(2*ind+2,mid+1,high,l,r,seg);
    return merge(left,right);
}
int main(){
    string s; cin>>s;
    int size=s.size();
    vector<info> seg(4*size+1);
    build(0,0,size-1,seg,s);
    int n; cin>>n;
    while(n--){
        int l,r; cin>>l>>r;
        info ans=query(0,0,size-1,l-1,r-1,seg);
        cout<<2*(ans.full)<<endl;
    }
}
