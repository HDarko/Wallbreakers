/*
 You are given two arrays (without duplicates) nums1 and nums2 where nums1’s elements are subset of nums2. 
 Find all the next greater numbers for nums1's elements in the corresponding places of nums2.

The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2.
If it does not exist, output -1 for this number.

Example 1:

Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
Output: [-1,3,-1]
Explanation:
    For number 4 in the first array, you cannot find the next greater number for it in the second array, so output -1.
    For number 1 in the first array, the next greater number for it in the second array is 3.
    For number 2 in the first array, there is no next greater number for it in the second array, so output -1.

Example 2:

Input: nums1 = [2,4], nums2 = [1,2,3,4].
Output: [3,-1]
Explanation:
    For number 2 in the first array, the next greater number for it in the second array is 3.
    For number 4 in the first array, there is no next greater number for it in the second array, so output -1.

Note:

    All elements in nums1 and nums2 are unique.
    The length of both nums1 and nums2 would not exceed 1000.
    */
    
    class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        //if either argument is empty then return an empty vector;
        if(nums1.empty() || nums2.empty()) {return {};}
          //A map to store the next greater number. map[element]= next greater number
        unordered_map <int, int> greaterNumMap;
        vector<int> result;
      
        //Since nums1 is a subset of nums2 we can use a stack to solve this
        stack<int> curElement;
        curElement.push(nums2[0]);
       
        for (int index =1; index<nums2.size(); index++ )
        {
          
            if(curElement.empty()){ curElement.push(nums2[index]);}
            
            //if we iterate and find smaller values tha current stack top 
            //we put then on top of stack;
            //the moment we find a value larger than current top to we update our map and remove
            //then update for the newest top which till the stack is empty
            while((!curElement.empty()) && ((curElement.top() <= nums2[index])))
            { 
                    greaterNumMap[curElement.top()]= nums2[index];
                    curElement.pop();
            }
            curElement.push(nums2[index]);
     
        }
         //Now we check each element in nums1 and create the vector
            for(int &value: nums1)
            {
                if(greaterNumMap.find(value)!=greaterNumMap.end())
                {
                    result.push_back(greaterNumMap[value]);
                }
                else
                {
                    result.push_back((-1));
                }
            }
        return result;
        
    }
};
