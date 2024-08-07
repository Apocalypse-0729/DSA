#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node*links[26];
    bool flag=false;

    bool containKey(char ch){
        return (links[ch-'a']!=NULL);
    }
    void put(char ch, Node* node){
        links[ch-'a']=node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void setEnd(){
        flag=true;
    }
    bool isEnd(){
        return flag;
    }
};
class Trie{
    private:
        Node* root;
    public:
        Trie(){
            root=new Node();
        }
        void insert(string word){
            Node* node=root;
            for(int i=0; i<word.size(); i++){
                if(!node->containKey(word[i])){
                    node->put(word[i],new Node());
                }
                node=node->get(word[i]);
            }
            node->setEnd();
        }
        bool search(string word){
            Node *node=root;
            for(int i=0; i<word.size(); i++){
                if(!node->containKey(word[i])){
                    return false;
                }
                node=node->get(word[i]);
            }
            return node->isEnd();
        }
        bool startWith(string word){
            Node *node=root;
            for(int i=0; i<word.size(); i++){
                if(!node->containKey(word[i])){
                    return false;
                }
                node=node->get(word[i]);
            }
            return true;
        }
};
int countDistinctSubstrings(string &word)
{
    //    Write your code here.
    int cnt=0;
    Node *root=new Node();
    for(int i=0; i<word.size();i++){
        Node *node=root;
        for(int j=i;j<word.size(); j++){
            if(!node->containKey(word[j])){
                cnt++;
                node->put(word[j],new Node());
            }
            node=node->get(word[j]);
        }
    }
    return cnt+1;
}
