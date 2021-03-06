/*
*There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

Example 1:

Input: 2, [[1,0]] 
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.

Example 2:

Input: 2, [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.

Note:

    The input prerequisites is a graph represented by a list of edges, not adjacency matrices. 
    Read more about how a graph is represented.
    You may assume that there are no duplicate edges in the input prerequisites.


*

/*
According to LeetCode:
Runtime: 24 ms, faster than 66.05% of C++ online submissions for Course Schedule.
Memory Usage: 14.1 MB, less than 42.33% of C++ online submissions for Course Schedule.
*/

    class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //Using topology sort
        vector<vector<int>> graph(numCourses, vector<int>{});
        //How many courses is they key a prereq for
        vector<int> preCourses(numCourses,0);
        
        //Build an graph-list of edges
        for(auto classPair: prerequisites)
        {
            //graph[neededclass]=class after
            graph[classPair[1]].push_back(classPair[0]);
        }
        //Record the preCourses
        for(auto course: graph)
        {
            for(auto prereq: course)
            {
                preCourses[prereq]++;
            }
        }
        
        for(int count=0; count<numCourses; count++)
        {
            int start{0};
            while(start<numCourses)
            {
                //Can we find a start course that requires no requiristes
                if(preCourses[start]==0)
                {
                    break;
                }
                else                    
                {
                   start+=1; 
                }
            }
            if(start==numCourses)
            {
                return false;
            }
            //need to make the current start
            preCourses[start]=(-1);
            for(auto course: graph[start])
            {
                preCourses[course]-=1;
            }
        }
        return true;
        
    }
};
        
