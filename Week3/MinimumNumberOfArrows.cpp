/*
  Problem:
 
*There are a number of spherical balloons spread in two-dimensional space. 
For each balloon, provided input is the start and end coordinates of the horizontal diameter. 
Since it's horizontal, y-coordinates don't matter and hence the x-coordinates of start and end of the diameter suffice.
Start is always smaller than end. There will be at most 104 balloons.

An arrow can be shot up exactly vertically from different points along the x-axis. 
A balloon with xstart and xend bursts by an arrow shot at x if xstart ≤ x ≤ xend. 
There is no limit to the number of arrows that can be shot. An arrow once shot keeps travelling up infinitely. 
The problem is to find the minimum number of arrows that must be shot to burst all balloons.

Example:

Input:
[[10,16], [2,8], [1,6], [7,12]]

Output:
2

Explanation:
One way is to shoot one arrow for example at x = 6 (bursting the balloons [2,8] and [1,6]) 
and another arrow at x = 11 (bursting the other two balloons).

Notes:
So we have a range start to end per balloon and and arrow destroys a ballon if the arrow is shot at any where between their range. 
Ideally we want to shoot arrows that fall in the range of multiple ballons and
the best way to go through that is to organize the ballons in some order.
The best way to sort the balloons is by their end points. 
then we since we know the suceeding ballons have an equal or
high end point we can just check the start pos of the succeding balloons
against the end of the last ballon we pierced.

According to LeetCode:
Runtime: 124 ms, faster than 71.67% of C++ online submissions for Minimum Number of Arrows to Burst Balloons.
Memory Usage: 27 MB, less than 9.70% of C++ online submissions for Minimum Number of Arrows to Burst Balloons.

*/

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty()){return 0;}
        //Sort by the endpoints in ascending order
        sort(points.begin(), points.end(), [](auto & left, auto& right){ return left[1]< right[1];});
        //Start with the lowest end point
        int arrowLoc=points[0][1];
        int numArrows=1;
        for(int index=1; index<points.size(); index++)
        {
            //If the arrow pieces the ballon cos the ballons start less than or equal arrow's range
            //since we know the end point should be greater or equal to arrows position thus the arrow
            //is hitting the balloon somewhere
            if(points[index][0]<=arrowLoc)
            {
                //move to next balloon
                continue;
            }
            else
            {
               // arrow is spent so increase the number and reset arrow pos to new end point
                numArrows+=1;
                arrowLoc=points[index][1];
            }
        }
        return numArrows;
    }
};
