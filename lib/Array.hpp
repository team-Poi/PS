#include <vector>
#include <algorithm>

template <typename T>
class Array {
public:
    std::vector<T> v;
    
    Array(std::vector<T> arr) {
        this->v = arr;
    }
    
    Array(unsigned long size, T value) {
        this->v.resize(size, value);
    }
    
    Array(unsigned long size) {
        this->v.reserve(size);
    }

    Array() {}
    
    T& last() {
        return &v[v.size() - 1];
    }
    
    T& font() {
        return &v[v.size() - 1];
    }
    
    T &at(unsigned long index) {
        if(index < 0) index = v.size() - index;
        return v[index];
    }
    
    T &operator[](unsigned long index) {
        return this->at(index);
    }
    
    void push_back(T val) {
        this->v.push_back(val);
    }
    
    void push(T val) {
        this->push_back(val);
    }
    
    T pop_back() {
        T data = this->last();
        this->v.pop_back();
        return data;
    }
    
    T pop() {
        return this->pop_back();
    }
    
    unsigned long size() {
        return this->v.size();
    }
    
    void append(Array<T> arr) {
        unsigned long initIdx = this->v.size();
        this->v.reserve(this->v.size() + arr.v.size());
        
        for(unsigned long i = 0;i < arr.v.size(); i++)
            this->v[i + initIdx] = arr[i];
    }

    auto begin() {
        return this->v.begin();
    }
    
    auto end() {
        return this->v.end();
    }

    template <class _Comp>
    void sort(_Comp __comp) {
        std::sort(this->v.begin(), this->v.end(), __comp);
    }

    void sort() {
        std::sort(this->v.begin(), this->v.end());
    }
    
    unsigned long capacity() {
        return this->v.capacity();
    }
};
