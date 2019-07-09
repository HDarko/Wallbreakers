/*
 A string S of lowercase letters is given. We want to partition this
 string into as many parts as possible so that each letter appears in at most one part,
 and return a list of integers representing the size of these parts.

Example 1:

Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.

    S will have length in range [1, 500].
    S will consist of lowercase letters ('a' to 'z') only.
    
    Notes:
    This took a lot of thinking . The main thing here is that all occurences of a leeter must be in a single partion. 
    This means the first up to the last time that number appears sow e can use that citing "ababcbaca" as an example.
First we start with a and we lock down the last occurence of a as the end of current partition. 
If while trying to get our index to reach the end of partition we reach a letter 
whose last of occurence is farther than our current partiion end then we update to our partition end to that point. 
when we reach the end then wetake the size of current partition and add it to a vector of results. 
which we return after we get all partitions.

According to LeetCode:
Runtime: 4 ms, faster than 95.01% of C++ online submissions for Partition Labels.
Memory Usage: 8.8 MB, less than 55.71% of C++ online submissions for Partition Labels.

*/

class Solution {
public:
    vector<int> partitionLabels(string S) {
        if (S.length()==1)
        {
            return {1};
        }
        vector<int> partitions;
        int partitionStart{0};
        int partitionEnd{0};
        unordered_map<char,int> lastPos;
        //Store a map of indexes of last locations of each letter
        for (char letter: S)
        {
            if(lastPos.find(letter)==lastPos.end())
            {
                lastPos[letter]= S.rfind(letter);
            }
        }
        
        for(int index=0; index<S.size();index++)
        {
            //if  last occurence any letter in current partition is larger than partition end
            //then update partition end
            partitionEnd=max(partitionEnd, lastPos[S[index]]);
            //If we reachwd end of current partition
            if(index==partitionEnd)
            {
                //add one cos arrays and starting at 0
                partitions.push_back((partitionEnd-partitionStart)+1);
                partitionStart=partitionEnd+1;
            }
        }
        return partitions;
        
    }
};
