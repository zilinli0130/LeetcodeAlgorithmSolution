class MyHashSet {
private:
    int size;
    int capacity;
    vector<list<int>>bucket;
    double load_factor = 0.75; // use in Java
    
public:
    MyHashSet() 
    {
        this->size = 0;
        this->capacity = 2;
        bucket = vector<list<int>>(capacity);
    }
    
    void add(int key) 
    {
        int h = hash(key);
        if(contains(key)) 
        {
            return;
            
        }   
        
        size++;
        bucket[h].push_back(key);
        
        if(size >= (load_factor * capacity))
        {
            capacity = capacity << 1;
            rehashbucket();
        }
    }
    
    void remove(int key) 
    {
        int h = hash(key);
        list<int>::iterator it = searchKey(key);
        if(it == bucket[h].end())
        {
            return;
        }
        
        size--;
        bucket[h].remove(key);
        
        if(size <= (0.5 * load_factor * capacity))
        {
            capacity = capacity >> 1;
            rehashbucket();
        }
        
    }
    
    bool contains(int key) 
    {
        int h = hash(key);
        return searchKey(key)!= bucket[h].end();
    }
    
private:
    
    int hash(int key) 
    {
        return key % capacity;
    }
    
    // Search the key in bucket[hash_value]
    list<int>::iterator searchKey(int key) 
    {
        int h = hash(key);
        list<int>::iterator it;
        for (it = bucket[h].begin(); it != bucket[h].end(); it++)
        {
            if (*it == key)
            {
                return it;
            }
        }
        return it;
    }  
    
    // Resize the bucket
    void rehashbucket() 
    {
        size = 0;
        capacity = max(2,capacity);    
        vector<list<int>> prev_bucket(std::move(bucket));
        bucket = vector<list<int>>(capacity);
        
        for (const auto &container : prev_bucket)
        {
            for (const auto& item : container)
            {
                add(item);
            }
        }
    }
    
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */