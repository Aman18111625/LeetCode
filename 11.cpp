//Question : - Best Time to Buy and Sell Stock -II (https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/)
//Difficulty : Medium
//Pre-requisites: Buy and Sell Stock -I 


//when you solve this question on paper you will easily get we need simply highest-lowest for all 
//Best Source For Understanding this problem:- PepCoding
int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int profit=0;
        for(int i=1;i<n;i++)
        {
         if(prices[i]>prices[i-1]) profit+=(prices[i]-prices[i-1]);
        }
       return profit;
    }