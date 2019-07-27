/*
Given an undirected graph, return true if and only if it is bipartite.

Recall that a graph is bipartite if we can split it's set of nodes into 
two independent subsets A and B such that every edge in the graph has one node in A and another node in B.

The graph is given in the following form: graph[i] is a list of indexes j for 
which the edge between nodes i and j exists.  Each node is an integer between 0 and graph.length - 1. 
There are no self edges or parallel edges: graph[i] does not contain i, and it doesn't contain any element twice.

Example 1:
Input: [[1,3], [0,2], [1,3], [0,2]]
Output: true
Explanation: 
The graph looks like this:
0----1
|    |
|    |
3----2
We can divide the vertices into two groups: {0, 2} and {1, 3}.

Example 2:
Input: [[1,2,3], [0,2], [0,1,3], [0,2]]
Output: false
Explanation: 
The graph looks like this:
0----1
| \  |
|  \ |
3----2
We cannot find a way to divide the set of nodes into two independent subsets.

 

Note:

    graph will have length in range [1, 100].
    graph[i] will contain integers in range [0, graph.length - 1].
    graph[i] will not contain i or duplicate values.
    The graph is undirected: if any element j is in graph[i], then i will be in graph[j].

According to LeetCode:
Runtime: 20 ms, faster than 96.74% of C++ online submissions for Is Graph Bipartite?.
Memory Usage: 11.2 MB, less than 58.09% of C++ online submissions for Is Graph Bipartite?.

*/

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        //O - not in set, 1= Set A, 2= Set B
        vector<int> subset(graph.size(),0);
        vector<bool> visited(graph.size(), false);
        for(int edgeNum=0; edgeNum<graph.size(); edgeNum++)
        {
            if(!DFS(edgeNum, graph,subset,visited ))
            {
                return false;
            }
        }
        return true;
        
    }
    //Going for a node 1 =A, node 2 =b approach
    bool DFS(int edgeNum,vector<vector<int>>& graph, vector<int>& subset, vector<bool> &visited)
             {
                 if(visited[edgeNum]!=0) 
                 {
                     return true;
                }
                 visited[edgeNum]=true;
                 subset[edgeNum]=(subset[edgeNum]==0)? 1:subset[edgeNum];
                 for (auto node: graph[edgeNum] )
                  {
                      if(subset[node]==0)
                      {
                          if(subset[edgeNum]==1)
                          {
                              subset[node]=2;
                          }
                          else
                          {
                             subset[node]=1; 
                          }
                          if (!DFS(node, graph, subset, visited))
                          {
                              return false;
                          }
                         
                      }
                      if((subset[node]) == subset[edgeNum])
                          {
                              return false;
                          }
                  }
                  return true;
             }
};
