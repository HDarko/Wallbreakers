/*
Design and implement a data structure for Least Recently Used (LRU) cache.
It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

The cache is initialized with a positive capacity.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache( 2 /* capacity */ );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
*/

//This had me used a linked list as a queue but it worked out in the end.
/*According to LeetCode:
Runtime: 92 ms, faster than 99.08% of C++ online submissions for LRU Cache.
Memory Usage: 37.9 MB, less than 84.44% of C++ online submissions for LRU Cache.
*/
class LRUCache {
public:
    LRUCache(int capacity) {
        maxCapacity=capacity;
        
    }
    
    int get(int key) {
        //if value doesnt exist in map then return -1
        auto keyFound= keyToValue.find(key);

        if(keyFound==keyToValue.end())
        {
            return -1;
        }
        //if found in map then put the node in back of our queue
        //and then return the value
        else
        {
            cache.splice(cache.end(),cache, keyFound->second);
            return (keyFound->second)->second;
        }
        
    }
    
    void put(int key, int value) {
        //Check if the key exists in map
        auto keyFound= keyToValue.find(key);
        if(keyFound!=keyToValue.end())
        {
            //If it exist then just update the value and push to back of queue
             cache.splice(cache.end(), cache, keyFound->second);
            (keyFound->second)->second= value;                  
        }
        else
        {
            //if not in map then first check if we are at capacity
            if(keyToValue.size()==maxCapacity)
            {
                //remove the least used or the value at the from of the queue/linked list
               
                int leastUsedKey= cache.front().first;
                keyToValue.erase(leastUsedKey);
                cache.pop_front();
            }
            //add the new value to the back of list 
            cache.push_back(pair<int,int>(key,value));
            //update the map
            list<pair<int,int>>:: iterator lastValue= cache.end();
            lastValue--;
            keyToValue[key]=lastValue;
        }
        
    }
    unordered_map<int, list<pair<int,int>>:: iterator> keyToValue;
    int maxCapacity;
    list<pair<int,int>> cache;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

