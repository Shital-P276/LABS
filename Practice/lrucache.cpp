#include <iostream>
#include <list>

class LRUCache {
private:
    int capacity;               // Maximum size of the cache
    std::list<int> cacheList;   // List to store keys in LRU order

public:
    LRUCache(int cap) : capacity(cap) {}

    void refer(int key) {
        // Check if the key exists in the cache
        auto it = std::find(cacheList.begin(), cacheList.end(), key);

        if (it == cacheList.end()) {
            // If the cache is full, remove the least recently used element
            if (cacheList.size() == capacity) {
                cacheList.pop_back(); // Remove the last element (LRU)
            }
        } else {
            // If the key exists, remove it from its current position
            cacheList.erase(it);
        }

        // Add the key to the front of the list (most recently used)
        cacheList.push_front(key);
    }

    void display() {
        std::cout << "Cache content: ";
        for (int key : cacheList) {
            std::cout << key << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    LRUCache cache(3); // Create an LRU Cache with capacity 3

    cache.refer(1);
    cache.refer(2);
    cache.refer(3);
    cache.display(); // Output: 3 2 1

    cache.refer(4); // 1 is removed (least recently used)
    cache.display(); // Output: 4 3 2

    cache.refer(2); // 2 becomes the most recently used
    cache.display(); // Output: 2 4 3

    cache.refer(5); // 3 is removed
    cache.display(); // Output: 5 2 4

    return 0;
}
