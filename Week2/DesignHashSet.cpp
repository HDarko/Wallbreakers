/*
Problem:
Design a HashSet without using any built-in hash table libraries.

To be specific, your design should include these functions:

    add(value): Insert a value into the HashSet. 
    contains(value) : Return whether the value exists in the HashSet or not.
    remove(value): Remove a value in the HashSet. If the value does not exist in the HashSet, do nothing.


Example:

MyHashSet hashSet = new MyHashSet();
hashSet.add(1);         
hashSet.add(2);         
hashSet.contains(1);    // returns true
hashSet.contains(3);    // returns false (not found)
hashSet.add(2);          
hashSet.contains(2);    // returns true
hashSet.remove(2);          
hashSet.contains(2);    // returns false (already removed)

    All values will be in the range of [0, 1000000].
    The number of operations will be in the range of [1, 10000].
    Please do not use the built-in HashSet library.

Notes: I find myself curious about this.
For this question I could either see a linked list implementation, a vector implementation
or even a bitset implementation though that one feels like cheating to me?
I went for vector in both this and the hastbale cos I pioritised simplicity and memory.
This has resulted in a sacrifice to my speed but I think it suffices.

According to LeetCode on 7/1/2019
Runtime: 388 ms, faster than 5.04% of C++ online submissions for Design HashSet.
Memory Usage: 35.8 MB, less than 98.31% of C++ online submissions for Design HashSet.
*/
class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        
    }
    
    void add(int key) {
        if(!contains(key))
        {
            set.push_back(key);
        }
        
    }
    
    void remove(int key) {
        auto result=find(set.begin(),set.end(),key);
        if(result!=set.end())
        {
            set.erase(result);
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        if(set.empty())
        {
            return false;
        }
        return (find(set.begin(),set.end(),key)!=set.end());
        
    }
    vector<int> set;
};
