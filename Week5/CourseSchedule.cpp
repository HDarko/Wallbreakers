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
Internet slow so not sure how this solution faires
We have to test it another time
*/

        class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //Using topology sort
        vector<vector<int>> graph(numCourses, vector<int>{});
        vector<int> preCourses(numCourses,0);
        
        //Build an graph-list of edges
        for(auto classPair: prerequisities)
        {
            //graph[neededclass]=class after
            graph[classPair[1]].push_back(classPair[0]);
        }
        //Record the preCourses
        for(auto course: graph)
        {
            for(auto prereq: course)
            {
                preCourses[course]++;
            }
        }
        
        for(int index=0; index<numCourses; index++)
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
            for(auto course: graph[start])
            {
                preCourses[course]-=1;
            }
        }
        return true;
        
    }
};
        
