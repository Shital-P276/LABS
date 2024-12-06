#include <iostream>
#include <map>
using namespace std;

struct Node {
    Node* next;
    Node* prev;
    int key;
    int value;
    
    Node(int k, int val) : key(k), value(val), next(NULL), prev(NULL) {}
};

class Cache {
protected:
    map<int, Node*> mp; // map to store key -> node
    int cp;              // capacity
    Node* head;          // head of the doubly linked list (most recently used)
    Node* tail;          // tail of the doubly linked list (least recently used)

    virtual void set(int, int) = 0;
    virtual int get(int) = 0;

public:
    Cache(int capacity) : cp(capacity), head(NULL), tail(NULL) {}
};

class LRUCache : public Cache {
public:
    LRUCache(int capacity) : Cache(capacity) {
        head = new Node(0, 0);  // dummy node for head
        tail = new Node(0, 0);  // dummy node for tail
        head->next = tail;
        tail->prev = head;
    }

    void set(int key, int value) {
        if (mp.find(key) != mp.end()) {
            // Update the value and move to the front
            Node* node = mp[key];
            node->value = value;
            moveToHead(node);
        } else {
            // Create a new node and add to the front
            Node* newNode = new Node(key, value);
            mp[key] = newNode;
            addToHead(newNode);

            // If the cache exceeds capacity, remove the least recently used item
            if (mp.size() > cp) {
                Node* tailPrev = removeTail();
                mp.erase(tailPrev->key);
                delete tailPrev;
            }
        }
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;  // Key not found
        } else {
            Node* node = mp[key];
            moveToHead(node);  // Move the accessed node to the front
            return node->value;
        }
    }

private:
    void addToHead(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToHead(Node* node) {
        removeNode(node);
        addToHead(node);
    }

    Node* removeTail() {
        Node* res = tail->prev;
        removeNode(res);
        return res;
    }
};

int main() {
    int n, capacity;
    cin >> n >> capacity;
    LRUCache cache(capacity);
    
    for (int i = 0; i < n; ++i) {
        string command;
        cin >> command;
        
        if (command == "set") {
            int key, value;
            cin >> key >> value;
            cache.set(key, value);
        } else if (command == "get") {
            int key;
            cin >> key;
            cout << cache.get(key) << endl;
        }
    }

    return 0;
}
