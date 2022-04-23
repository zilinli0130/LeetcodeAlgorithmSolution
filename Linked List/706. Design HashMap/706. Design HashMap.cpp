class MyHashMap {
    struct Node {
      int key;
      int value;
      Node* next;
      Node(int key = -1, int value = -1): next(nullptr), key(key), value(value) {}
    };
    Node* myMap;
    Node* curPtr;
    Node* prevPtr = nullptr;
public:
    MyHashMap():myMap(new Node()) {
    }
    
    void put(int key, int value) {
        
        curPtr = myMap;
        prevPtr = myMap;
        while (curPtr) {
            if (curPtr->key == key) {
                curPtr->value = value;
                return;
            }
            prevPtr = curPtr;
            curPtr = curPtr->next;
        }
        prevPtr->next = new Node(key, value);
        return;
    }
    
    int get(int key) {
        
        curPtr = myMap;
        while (curPtr) {
            if (curPtr->key == key) {
                return curPtr->value;
            }
            curPtr = curPtr->next;
        }
        return -1;
    }
    
    void remove(int key) {
        
        curPtr = myMap;
        prevPtr = myMap;
        while (curPtr) {
            if (curPtr->key == key) {
                prevPtr->next = curPtr->next;
                return;
            }
            prevPtr = curPtr;
            curPtr = curPtr->next;
        }
        return;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */