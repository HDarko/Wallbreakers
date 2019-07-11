/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. 
All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. 
Meanwhile, adjacent houses have security system connected and it will automatically contact the police
if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house,
determine the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
             because they are adjacent houses.

Example 2:

Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.
Notes:

Robber can either rob house i and not i-1 or i+1
Or not thus they cab rob i-1 and i+1
If we have 0 houses then the max we can rob is 0
if we have 1 house then the max is the amount from house 0
if we have 2 then max is between the culmulative loot stored in max 1 or
the loot in house 2 plus loot stored in max 0.
so maxloot[housenum]= max (maxloot[housenum -1]), loot[housenum]+ maxloot[housenumber-2])
we also need to compare between two scenarios:
one is the we pick first house so cant rob last. second is we pick last so we ignore first

*/

//Dynamic Programming Solution
/*
  Runtime: 0 ms, faster than 100.00% of C++ online submissions for House Robber II.
  Memory Usage: 8.7 MB, less than 22.36% of C++ online submissions for House Robber II.
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        //if we have 0 houses then return 0.
        if(nums.empty())
        {
            return 0;
        }
        //if only one house then return that house loot
        else if(nums.size()==1)
        {
            return nums[0];
        }
       // if only two houses then return best loot between them
        else if (nums.size()==2)
        {
            return max(nums[0], nums[1]);
        }
        else
            //We need records of the max loot so far for memoization
            vector<int> maxLootRecordFirstHouse(nums.size()-1);
        //record loot for house 0 
           // maxLootRecordFirstHouse[0]=nums[0];
        //record loot for house 1
           // maxLootRecordFirstHouse[1]=nums[1];
            vector<int> maxLootRecordLastHouse(nums.size()-1);
            //return max loot between scenario 1 with robbing first house and scenario 2
            //robbing last house
            return max(BestLootNoAdjacentHouses(nums, 0, nums.size()-2),
                       BestLootNoAdjacentHouses(nums, 1, nums.size()-1));
        
    }
    
    int BestLootNoAdjacentHouses(vector<int>&nums, int startHouseIndex, int lastHouseIndex)
    {
         //starting from second house we need a null house for the -2 calculation so
        // for example if we working with last house being index 4 then we have five houses in all
        //add a nul house with loot 0 then we have 6 so add two to the lastHouseIndex
        vector<int> maxLootRecord((lastHouseIndex+2)-startHouseIndex);
       //record loot for null house
         maxLootRecord[0]=0;
        //record loot for first house
        maxLootRecord[1]=nums[startHouseIndex];
        // now starting from next house or house index 1 (index 2 for our vector)
        //so we need to use (index-1) + startHouseIndex for nums 
        for (int index=2; ((index-1)+startHouseIndex)<=lastHouseIndex; index++)
        {
            maxLootRecord[index]=max(maxLootRecord[index-1], nums[(index-1)+(startHouseIndex)]+ maxLootRecord[index-2]);
            //cout<<"Index:"<<index<<"\n";
            //cout<<maxLootRecord[index]<<"\n";
        }
        //The max loot is contained in the last index so return the value stored there
        return maxLootRecord.back();
    }
};

//Solution 2 using Recusion and memoization
//According to LeetCode
/*
Runtime: 4 ms, faster than 72.78% of C++ online submissions for House Robber II.
Memory Usage: 8.5 MB, less than 66.53% of C++ online submissions for House Robber II.
*/
class Solution {

public:
    int rob(vector<int>& nums) {
        //if we have 0 houses then return 0.
        if(nums.empty())
        {
            return 0;
        }
        //if only one house then return that house loot
        else if(nums.size()==1)
        {
            return nums[0];
        }
       // if only two houses then return best loot between them
        else if (nums.size()==2)
        {
            return max(nums[0], nums[1]);
        }
        else
        {
            //We need records of the max loot so far for memoization
            vector<int> maxLootRecordFirstHouse(nums.size()+1);
            vector<int> maxLootRecordLastHouse(nums.size()+1);
        //record loot for house 0 
          maxLootRecordFirstHouse[0]=0;
          maxLootRecordLastHouse[0]=0;
        //record loot for house 1
           maxLootRecordFirstHouse[1]=nums[0];
           maxLootRecordLastHouse[1]=nums[1];
        //return max loot between scenario 1 with robbing first house and scenario 2
        //robbing last house
            //start with second house
            return max(BestLootNoAdjacentHouses(nums, 1, nums.size()-2, 2,maxLootRecordFirstHouse),
                       BestLootNoAdjacentHouses(nums, 2, nums.size()-1,2,maxLootRecordLastHouse));
        
    }
    }
    
    int BestLootNoAdjacentHouses(vector<int>&nums, int curHouseIndex, int lastHouseIndex, int curLootIndex,
                                vector<int> &maxLootRecord)
    {
        maxLootRecord[curLootIndex]=max(maxLootRecord[curLootIndex-1], nums[curHouseIndex]+ maxLootRecord[curLootIndex-2]);
        if (curHouseIndex==lastHouseIndex)
        {
            //cout<<maxLootRecord[curLootIndex]<<"\n";
            return maxLootRecord[curLootIndex];
        }
        else
        {
            return BestLootNoAdjacentHouses(nums,curHouseIndex+1, lastHouseIndex, curLootIndex+1,
                                 maxLootRecord);
        }
    }
};
