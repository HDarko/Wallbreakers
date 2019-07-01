/*
Problem:
Design a HashMap without using any built-in hash table libraries.

To be specific, your design should include these functions:

    put(key, value) : Insert a (key, value) pair into the HashMap. If the value already exists in the HashMap, update the value.
    get(key): Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
    remove(key) : Remove the mapping for the value key if this map contains the mapping for the key.


Example:

MyHashMap hashMap = new MyHashMap();
hashMap.put(1, 1);          
hashMap.put(2, 2);         
hashMap.get(1);            // returns 1
hashMap.get(3);            // returns -1 (not found)
hashMap.put(2, 1);          // update the existing value
hashMap.get(2);            // returns 1 
hashMap.remove(2);          // remove the mapping for 2
hashMap.get(2);            // returns -1 (not found) 


    All keys and values will be in the range of [0, 1000000].
    The number of operations will be in the range of [1, 10000].
    Please do not use the built-in HashMap library.

Notes:
After some though I decided the best way to go about this would be a vector of pairs.
I can easily check, add to , remove update such a data structure.

According to LeetCode:
Runtime: 220 ms, faster than 14.14% of C++ online submissions for Design HashMap.
Memory Usage: 41.1 MB, less than 98.15% of C++ online submissions for Design HashMap.
*/

class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        auto result= find_if(map.begin(), map.end(),[&key](const pair<int,int>& pairing){return 
           pairing.first==key;});
        if(result!=map.end())
        {
            (*result).second=value;
        }
        else{
            map.push_back(make_pair(key,value));
        }
        
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
       auto result= find_if(map.begin(), map.end(),[&key] (const pair<int,int>& pairing){return 
           pairing.first==key;});
        if(result!=map.end())
        {
            return ((*result).second);
        }
        else{
            return (-1);
        }
                    
        
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
         auto result= find_if(map.begin(), map.end(),[&key] (const pair<int,int>& pairing){return 
           pairing.first==key;});
        if(result!=map.end())
        {
            map.erase(result);
        }
        
    }
    
    vector<pair<int,int>> map;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
//I found this solution interesting since it shows another method of going through this question.

class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap(): container(32, nullptr), len(32)  {
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int key_ = getKey(key);
        ListNode* cur = container[key_];
        if(!cur)
            container[key_] = new ListNode(key, value);
        else {
            for(; cur; cur = cur->next) {
                if(cur->key == key) {
                    cur->val = value;
                    return;
                }
            }
            ListNode* tmp = new ListNode(key, value);
            tmp->next = container[key_];
            container[key_] = tmp;
        }
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int key_ = getKey(key);
        if(!container[key_]) return -1;
        ListNode* cur = container[key_];
        while(cur && cur->key!= key) cur = cur->next;
        if(!cur) return -1;
        return cur->val;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int key_ = getKey(key);
        ListNode** pp = &container[key_];
        while(*pp) {
            if((*pp)->key != key)
                pp = &(*pp)->next;
            else {
                ListNode* tmp = *pp;
                *pp = (*pp)->next;
                delete tmp;
            }
        }
    }
private:
    struct ListNode {
        int key;
        int val;
        ListNode* next;
        ListNode(int _key, int _val): key(_key), val(_val), next(nullptr) {
        }
    };
    int len;
    vector<ListNode* > container;
    int getKey(int key)  {
        return key & (len - 1);
    }
};
