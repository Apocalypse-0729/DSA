struct Node{
    Node* links[2];
    bool containKey(int bit){
        return (links[bit]!=NULL);
    }
    void put(int bit, Node* node){
        links[bit]=node;
    }
    Node* get(int bit){
        return links[bit];
    }
};
class Trie{
    public:
    Node* root;
    Trie(){
        root=new Node();
    }
    void insert(int num){
        Node* node=root;
        for(int i=31; i>=0;i--){
            int bit=(num>>i)&1;
            if(!node->containKey(bit)){
                node->put(bit,new Node());
            }
            node=node->get(bit);
        }
    }
    int getMax(int num){
        Node* node=root;
        int maxval=0;
        for(int i=31; i>=0;i--){
            int bit=(num>>i)&1;
            if(node->containKey(1-bit)){
                maxval=maxval | (1<<i);
                node=node->get(1-bit);
            }
            else{
                node=node->get(bit);
            }
        }
        return maxval;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(auto it:nums){
            trie.insert(it);
        }
        int ans=0;
        for(auto it:nums){
            ans=max(ans,trie.getMax(it));
        }
        return ans;
    }
};
