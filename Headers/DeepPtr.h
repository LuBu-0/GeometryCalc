#ifndef DEEPPTR_H
#define DEEPPTR_H
#include <iostream>

template <class T>
class DeepPtr {
private:
    T* ptr;
public:
    DeepPtr() : ptr(nullptr) {}
    DeepPtr(T* p) : ptr(p) {}
    DeepPtr(const DeepPtr& d) : ptr(d->clone()){}
    ~DeepPtr() {if(ptr) delete ptr;}
    DeepPtr& operator=(T* d) {return ptr(d);}
    DeepPtr& operator=(const DeepPtr& d) {this->ptr = (d.ptr->clone()); return *this;}
    T* operator->() const {return ptr;}
    T& operator*()  const {return *ptr;}
    explicit operator bool() const {return ptr == nullptr ? false : true;}

};
#endif // DEEPPTR_H
