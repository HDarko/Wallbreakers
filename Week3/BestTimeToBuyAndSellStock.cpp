/*

Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.

Example 1:

Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
             Not 7-1 = 6, as selling price needs to be larger than buying price.

Example 2:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.

*/

/*
   /*The first question we want to ask is what is the minimum cost to buy
        a stock(from day 1 to current day), then second is with the minPrice we know so far what is 
        the max profit between selling our stock today - our know min Price and any profit in the past.
        to get this we need an vector of prices+1 so that day zero is a null day and has an INT_Max so that
        the formula we divised upwards will work
        
        According to LeetCode for the dynamic solution:
        Runtime: 8 ms, faster than 78.99% of C++ online submissions for Best Time to Buy and Sell Stock.
        Memory Usage: 9.6 MB, less than 16.15% of C++ online submissions for Best Time to Buy and Sell Stock.
        
        */
        
        class Solution {
public:
    int maxProfit(vector<int>& prices) {
      
        if(prices.size()==0)
        {
            return 0;
        }
        vector<int> minPriceFromStartToToday(prices.size()+1,INT_MAX);
        int maxProfit{0};
        for(int nextDay=1;nextDay<=prices.size();nextDay++)
        {
            //cout<<nextDay;
            //minPrice for currntDay is found by comparing the previous min price found
            //and the price of today. To accomplish this we need a null or day 0 with max int
            //in our minPrice vector
            //thus we need to use today -1 to get correct index
            minPriceFromStartToToday[nextDay]=min(prices[nextDay-1],
                                                       minPriceFromStartToToday[nextDay-1]);
         
            //we compare the current maxProfit vs the todays price - for minPrice we found before 
            maxProfit=max(maxProfit,  prices[nextDay-1] - minPriceFromStartToToday[nextDay]);
        }
        
        return maxProfit;
    }
};

/*
Recursion is trying to do esential the same thing but done in the functions arguments.
According to LeetCode:
For the recusrion solution:
Runtime: 4 ms, faster than 98.97% of C++ online submissions for Best Time to Buy and Sell Stock.
Memory Usage: 19.8 MB, less than 5.00% of C++ online submissions for Best Time to Buy and Sell Stock.
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0)
        {
            return 0;
        }
        //The first question we want to ask is what is the minimum cost to buy
        //a stock(from day 1 to now), then second is with a specific stock we want to sell starting from a 
        //specific day, what is the max profit we can get from that stock
        
       return (FindMaxProfit(prices,0,0,prices[0]));
       
    }
    
     int FindMaxProfit(vector<int>&  prices,int curIndex,int maxProfit, int minPrice)
     {
         // cout<<"maxP"<<maxProfit<<"\n";
         if(curIndex<prices.size())
         {
             
             maxProfit=max(maxProfit,FindMaxProfit( prices, curIndex+1,
                                                    max(maxProfit, prices[curIndex]-minPrice),
                           min( minPrice,prices[curIndex])));
         }  
          
        return maxProfit;
     }
       
};

