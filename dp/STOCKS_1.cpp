class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=prices[0];
        int profit=INT_MIN;
        for(int i=1; i<prices.size(); i++){
            int cost=prices[i]-mini;
            profit=max(profit,cost);
            mini=min(prices[i],mini);
        }
        if(profit<0) return 0;
        return profit;
    }
};
