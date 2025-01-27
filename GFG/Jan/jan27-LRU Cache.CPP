int capacity;  // Maximum capacity of the cache
    std::unordered_map<int, std::pair<int, std::list<int>::iterator>> cache;  // Maps key to value and its position in the list
    std::list<int> order;  // List to track the order of access

public:
    // Constructor to initialize cache with capacity
    LRUCache(int cap) {
        capacity = cap;
    }

    // Function to return value corresponding to the key
    int get(int key) {
        // If key is not present in cache
        if (cache.find(key) == cache.end()) {
            return -1;  // return -1 for key not found
        }

        // Move the accessed key to the front of the list (most recently used)
        order.splice(order.begin(), order, cache[key].second);
        
        // Return the value of the key
        return cache[key].first;
    }

    // Function for storing key-value pair
    void put(int key, int value) {
        // If the key is already in the cache, update the value and move it to the front
        if (cache.find(key) != cache.end()) {
            cache[key].first = value;  // Update the value
            order.splice(order.begin(), order, cache[key].second);  // Move to the front
            return;
        }

        // If cache is full, remove the least recently used (LRU) item
        if (cache.size() == capacity) {
            int lru = order.back();
            order.pop_back();  // Remove the LRU item
            cache.erase(lru);  // Erase it from the cache
        }

        // Add the new key-value pair to the cache and the order list
        order.push_front(key);
        cache[key] = {value, order.begin()};
    }