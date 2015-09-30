/**
*Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.
*Example*
*
*/

#include<list>
class LRUCache{
public:
    // @param capacity, an integer
    LRUCache(int capacity) {
        // write your code here
        this->capacity = capacity; 
    }
    
    // @return an integer
    int get(int key) {
        // write your code here
        if (cacheMap.find(key) == cacheMap.end()) return -1;
        // 把当前访问的节点移到链表头部，并且更新map 中该节点的地址
        cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
        cacheMap[key] = cacheList.begin();
        return cacheMap[key]->value;
    }

    // @param key, an integer
    // @param value, an integer
    // @return nothing
    void set(int key, int value) {
        // write your code here
        if (cacheMap.find(key) == cacheMap.end()) {
            if (cacheList.size() == capacity) { //删除链表尾部节点（最少访问的节点）
                cacheMap.erase(cacheList.back().key);
                cacheList.pop_back();
            }
            // 插入新节点到链表头部, 并且在map 中增加该节点
            cacheList.push_front(CacheNode(key, value));
            cacheMap[key] = cacheList.begin();
        } else {
            //更新节点的值，把当前访问的节点移到链表头部, 并且更新map 中该节点的地址
            cacheMap[key]->value = value;
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
            cacheMap[key] = cacheList.begin();
        }
    }
private:
    struct CacheNode {
        int key;
        int value;
        CacheNode(int k, int v) : key(k), value(v) {}
    };
    list<CacheNode> cacheList;
    unordered_map<int, list<CacheNode>::iterator> cacheMap;
    int capacity;
};
