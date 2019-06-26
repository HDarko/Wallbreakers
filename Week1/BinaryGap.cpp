/*
Problem:
Given a positive integer N, 
find and return the longest distance between two consecutive 1's 
in the binary representation of N.
Notes:

If there aren't two consecutive 1's, return 0.
  This solution worked on first try so happy about that;
  
  At the time this was done
  Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Gap.
Memory Usage: 8.4 MB, less than 35.34% of C++ online submissions for Binary Gap.
*/

class Solution {
public:
    int binaryGap(int N) {
  
      //All 1s have been been tested
        bool all=false;
        size_t distance=0;
        string binary=bitset<32>(N).to_string();
        size_t firstLoc=binary.find('1');
        if(firstLoc!=string::npos)
        {
            size_t curOne=firstLoc;
             while(all!=true)
            {
                size_t loc=binary.find('1',curOne+1);
                 if(loc!=string::npos)
                 {
                     if((loc-curOne)>distance)
                     {
                         distance=loc-curOne;
                     }
                     curOne=loc;                 
                 }
                 else{
                     all=true;
                 }
            }
             return distance;
            
        }
        else
        {
            return 0;
        }
       
        
        
    }
};
