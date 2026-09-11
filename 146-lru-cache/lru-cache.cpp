class Node {
public:
    int key ;
    int val ;
    Node* prev ;
    Node* next ;

    // Constructor to initialize a node with key and value
    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    int cap ;
    unordered_map<int, Node*> cache ;

    Node* left ;
    Node* right ;

    // Removes a node from its current position in the doubly linked list
    void remove(Node* node) {

        Node* prev = node->prev ;

        Node* nxt = node->next ;

        prev->next = nxt ;

        nxt->prev = prev ;

    }

    // Inserts a node just before the right dummy node
    // This position represents the most recently used node
    void insert(Node* node) {

        Node* prev = right->prev ;

        prev->next = node ;

        node->prev = prev ;

        node->next = right ;

        right->prev = node ;
    }

public:
    // Initializes the cache with the given capacity
    // left and right are dummy nodes used as boundaries
    LRUCache(int capacity) {
        cap = capacity ;

        cache.clear() ;

        left = new Node(0, 0) ;
        right = new Node(0, 0) ;

        left->next = right ;
        right->prev = left ;

    }

    // Returns the value if the key exists
    // Also moves the accessed node to the most recently used position
    int get(int key) {
        if (cache.find(key) != cache.end()) {

            Node* node = cache[key] ;

            // Move the accessed node to the MRU position
            remove(node) ;
            insert(node) ;

            return node->val ;

        }

        return -1 ;
    }

    // Inserts a new key-value pair or updates an existing key
    void put(int key, int value) {

        // If key already exists, remove its old node
        if (cache.find(key) != cache.end()) {

            remove(cache[key]) ;

        }

        // Create a new node and store it in the hash map
        Node* newNode = new Node(key, value) ;

        cache[key] = newNode ;

        // New node becomes the most recently used node
        insert(newNode) ;

        // If capacity is exceeded, remove the least recently used node
        if (cache.size() > cap) {

            // left->next is the least recently used node
            Node* lru = left->next ;

            remove(lru) ;

            cache.erase(lru->key) ;

            delete lru ;
            
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

