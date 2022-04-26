# 284. Peeking Iterator

###### Tag: Design, Iterator, Copy Constructor (Deep Copy)

For the `next()` and `hasNext()` methods, there is no need to override them in the `class PeekingIterator`. To implement the `peek()` method,
we can take the advatnage of copy constructor (deep copy) to create an object with type `Iterator` and a rvalue of `*this`. If the `peek()` 
method is called, the local `Iterator` object will return `next()` method. Even though, the iterator inside the local `Iterator` object will point
to the next element, the local object will be deleted when the `peek()` is removed from the call stack.It does not affect the overall feature of our main
`PeekingIterator` object.

```
Naive Approach to only handle integer type

class PeekingIterator : public Iterator {
    int value;
    bool isNextValid;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        
	    if (Iterator::hasNext()) {
            value = Iterator::next();
            isNextValid = true;
        } else {
            value = 0;
            isNextValid = false;
        }
	}
	
	int peek() {
        return value;
	}
	
	int next() {
        int temp = value;
        if (Iterator::hasNext()) {
            value = Iterator::next();
        } else {
            isNextValid = false;
            
        }
        return temp;
	}
	
	bool hasNext() const {
	    return isNextValid;
	}
};
```