/*
146. LRU Cache
https://leetcode.com/problems/lru-cache/

Design and implement a data structure for Least Recently Used (LRU) cache. 
It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key 
exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. 
When the cache reached its capacity, it should invalidate the least recently 
used item before inserting a new item.

what is LRUCache:
see http://mcicpc.cs.atu.edu/archives/2012/mcpc2012/lru/lru.html
*/






/* notes

NOTE: in this problem, we do not need to consider the remove() operation , LOL
So, we can use a HashMap to record the position of a list
HashMap<Integer, Integer> key2valMap; // a map from key to value, 
ArrayList<Cache> cacheList;// record the time line of the position , when we
                                // just get/set a node, we add it back to tail,  and if it exist previously, we change its
                                //  value to Integer.Min_VALUE to mark it un-used.
HashMap<Integer, Integer> key2ListPos; // remember the most recent position in cacheList
                                            // that the key is saved
when the size of  cacheList  grows to big, we shrink it.


public class LRUCache {
    HashMap<Integer, Integer> key2valMap; // a map from key to value
    HashMap<Integer, Integer> key2ListPos; // remember the most recent position
                                            // that the key is saved
    ArrayList<Cache> cacheList;// record the time line of the position , when we
                                // just visit a node, we add it back to tail
    static int capacity;
 
    public LRUCache(int capacity) {
        assert (capacity > 0);
        key2valMap = new HashMap<Integer, Integer>();
        key2ListPos = new HashMap<Integer, Integer>(); // remember the position
        LRUCache.capacity = capacity;
        cacheList = new ArrayList<Cache>();
    }
 
    public int get(int key) {
        Integer val = key2valMap.get(key);
        if (val == null)
            return -1;
        else {
            // update the timeLine of cacheList,
            Cache c = new Cache(key, val);
            int prePos = key2ListPos.get(key);
            cacheList.get(prePos).val = Integer.MIN_VALUE; // no longer used
 
            key2ListPos.put(key, cacheList.size());
            cacheList.add(c);
            updateList();
            return val;
        }
    }
 
    public void set(int key, int value) {
        Integer findKey = key2valMap.get(key);
        // Step 1:  mark the oldest ones ( or the old set with key ) as un-used 
        if (findKey == null) { // if not find key
            if (key2valMap.size() >= capacity) // cache is full
                // delete the oldest one, searching from head of cacheList,
                for (int i = 0; i < cacheList.size(); i++)
                    if (cacheList.get(i).val != Integer.MIN_VALUE) {
                        int key2beDeleted = cacheList.get(i).key;
                        key2valMap.remove(key2beDeleted);    // remove this key in  key2valMap
                        key2ListPos.remove(key2beDeleted); // delete this key in key2ListPos --- make sure its size <= capacity
                        cacheList.get(i).val = Integer.MIN_VALUE; // mark the oldest key in cache as un-used
                        break;
                    }
        } else { // key is found
            int keyPrePos = key2ListPos.get(key); // previous position of key
            cacheList.get(keyPrePos).val = Integer.MIN_VALUE;
        }
        // add new value at tail
        key2valMap.put(key, value);
        key2ListPos.put(key, cacheList.size());
        Cache c = new Cache(key, value);
        cacheList.add(c);
        updateList();
    }
 
    private void updateList() { // shrink the
        // shrink the cacheList if needed ( in case it grows toooo big )
        if (cacheList.size() < 2 * capacity) // here 20 is randomly chosen
            return;
        // now, cacheList is too big, we need delete those cache<list> whose val
        // ( as position) < 0
        // copy and rest all the position of the reset
        for (int i = 0; i < cacheList.size(); i++) {
            if (cacheList.get(i).val == Integer.MIN_VALUE ) { // if current position < 0
                cacheList.remove(i);
                i--;
            } else {
                key2ListPos.put(cacheList.get(i).key, i);
            }
        }
    }
 
    class Cache {
        int key;
        int val;
 
        Cache(int k, int v) {
            key = k;
            val = v;
        }
    }
}



*/