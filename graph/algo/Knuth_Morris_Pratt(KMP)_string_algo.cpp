#include<bits/stdc++.h>
using namespace std;
// longest Proper Prefix Suffix
vector<int> lpsArray(string &t){
    int m=t.size();
    vector<int> lps(m,0);
    int len=0;
    int i=1;
    lps[0]=0;
    while(i<m){
        if(t[i]==t[len]){
            len++;
            lps[i]=len;
            i++;
        }
        else{
            if(len!=0){
                len=lps[len-1];
            }
            else{
                lps[i]=0;
                i++;
            }
        }
    }
    return lps;
}
vector<int> KMPSearch(string &s, string &t){
    int n=s.size();
    int m=t.size();
    int i=0; int j=0;
    vector<int> lps=lpsArray(t);
    vector<int> ans;
    while((n-i)>=(m-j)){
        if(s[i]==t[j]){
            i++;
            j++;
        }
        if(j==m){
            ans.push_back(i-j+1);
            j=lps[j-1];
        }
        else if(i<n && s[i]!=t[j]){
            if(j!=0) j=lps[j-1];
            else i++;
        }
    }
    return ans;
}
int main(){
    string s,t;
    cin>>s>>t;
    vector<int> ans=KMPSearch(s,t);
    for(auto it:ans){
        cout<<it<<" ";
    }
}
