class MyHashMap {
private:
    int size;
    int capacity = 2;
    double load_factor = 0.75; // use in Java
    vector<list<pair<int,int>>>bucket;
    
public:    
    MyHashMap() 
    {
        this->size = 0;
        this->capacity = 2;
        this->bucket = vector<list<pair<int,int>>>(capacity);
    }
    
    void put(int key, int value) 
    {
        
        int h = hash(key);
        list<pair<int,int>>::iterator it = searchKey(key);
        if(it != bucket[h].end())
        {
            it->second = value;
            return;
        }

        size++;
        bucket[h].push_back(make_pair(key,value));
        
        if(size >= (load_factor * capacity))
        {
            // Double the capacity
            capacity = capacity << 1; 
            rehashbucket();
        }
    }
    
    int get(int key) 
    {
        
        int h = hash(key);
        list<pair<int,int>>::iterator it = searchKey(key);
        if(it != bucket[h].end()) 
        {
            return it->second;
        }
        return -1;
    }
    
    void remove(int key) 
    {
        int h = hash(key);
        list<pair<int,int>>::iterator it = searchKey(key);
        if(it == bucket[h].end()) 
        {
            return;
        }
        
        size--;
        bucket[h].erase(it);
        if(size <= (0.5 * load_factor * capacity))
        {
            // Shrink the size to half of what the bucket had before
            capacity = capacity >> 1;
            rehashbucket();
        }
    }
    
private:
    // Return the hash value inside the bucket
    int hash(int key) 
    {
        return key % capacity;
    }
    
    // Resize the bucket
    void rehashbucket() 
    {
        size = 0;
        capacity = max(2, capacity);    
        vector<list<pair<int,int>>> prev_bucket(std::move(bucket));
        bucket = vector<list<pair<int,int>>>(capacity);
        
        for (const auto &chain: prev_bucket) 
        {
            for (const auto& item : chain) 
            {
                put(item.first, item.second);
            }
        }
    }
    
    // Search the key in bucket[hash_value] chain of linked list
    list<pair<int,int>>::iterator searchKey(int key) 
    {
        int h = hash(key);
        list<pair<int,int>>::iterator it;
        for(it = bucket[h].begin(); it!=bucket[h].end();it++)
            if(it->first == key) {
                return it;
        }
        return it;
    }    
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */