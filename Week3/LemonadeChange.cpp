/*
Problem :
At a lemonade stand, each lemonade costs $5. 

Customers are standing in a queue to buy from you, and order one at a time (in the order specified by bills).

Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill.  You must provide the correct change to each customer, so that the net transaction is that the customer pays $5.

Note that you don't have any change in hand at first.

Return true if and only if you can provide every customer with correct change.

 

Example 1:

Input: [5,5,5,10,20]
Output: true
Explanation: 
From the first 3 customers, we collect three $5 bills in order.
From the fourth customer, we collect a $10 bill and give back a $5.
From the fifth customer, we give a $10 bill and a $5 bill.
Since all customers got correct change, we output true.

Example 2:

Input: [5,5,10]
Output: true

Example 3:

Input: [10,10]
Output: false

Example 4:

Input: [5,5,10,10,20]
Output: false
Explanation: 
From the first two customers in order, we collect two $5 bills.
For the next two customers in order, we collect a $10 bill and give back a $5 bill.
For the last customer, we can't give change of $15 back because we only have two $10 bills.
Since not every customer received correct change, the answer is false.


Notes:
    Since the customer can only pay in fives, 10s and 20s, this means that for every 5 with increase,
    every 10 we pay 5 and for every 20 we pay either 3 5s or a 10 and a 5.
    Thus the we need to keep track of how many 10s and 5s we have
    
    According to LeetCodef for my solution:
    Runtime: 12 ms, faster than 97.56% of C++ online submissions for Lemonade Change.
    Memory Usage: 9.8 MB, less than 17.11% of C++ online submissions for Lemonade Change.
*/
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fivesCounter{0};
        int tensCounter{0};
        for (int &bill: bills)
        {
            //If we get a five dollar bill
            if (bill==5)
            {
                fivesCounter+=1;
            }
            else if (bill==10)
            {
                if(fivesCounter!=0)
                {
                    fivesCounter-=1;
                    tensCounter+=1;
                }
                else
                {
                    return false;
                }
            }
            else if (bill==20)
            {
                //First check if we can do 5 and ten
                if(fivesCounter>0)
                {
                    //Lose one five first
                    fivesCounter-=1;
                    if( tensCounter>0)
                    {
                        tensCounter-=1;
                    }
                    //else lose the other 2 5s
                    else
                    {
                        fivesCounter-=2;
                    }
                    //FivesCounter is less than zero we did not have enough fives
                    if(fivesCounter<0)
                    {
                        return false;
                    }
                }
                else
                {
                    //We dont have enough fives
                    return false;
                }
            }
        }
        //If we reached end of loop with no Falses then every one got their change
        return true;
        
    }
};
