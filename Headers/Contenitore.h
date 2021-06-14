#ifndef CONTENITORE_H
#define CONTENITORE_H
#include <iostream>

template <class T>
class Contenitore
{
private:

    unsigned int Size;
    unsigned int Capacity;
    T* Array;

public:

    class Iteratore{
        friend class Contenitore<T>;
    private:
        T* it;
        bool past_the_end;
        Iteratore(T* t, bool pte = false) : it(t), past_the_end(pte) {}
    public:
        Iteratore() : it(nullptr), past_the_end(false) {}
        T& operator*() const {return *it;}
        T* operator->() const {return &(*it);}
        Iteratore& operator++() {
                    if(it != nullptr) {
                        if(!past_the_end) {
                            if(it + 1 != nullptr) {it = it + 1;}
                            else { it = it + 1; past_the_end = true; }
                        }
                    }
                    return *this;
                }

        Iteratore& operator++(int){
                    const_Iteratore aux(*this);
                    if(it!= nullptr) {
                        if(!past_the_end) {
                            if(it + 1 != nullptr) it = it + 1;
                            else {it = it + 1; past_the_end = true;}
                        }
                    }
                    return aux;
                }

        Iteratore& operator--() {
                    if(it != nullptr) {
                        if(it - 1 == nullptr) it = nullptr;
                        else if(!past_the_end) it = it - 1;
                        else {it = it - 1; past_the_end = false;}
                    }
                    return *this;
                  }

        Iteratore& operator--(int) {
            const_Iteratore aux(*this);
            if(it != nullptr) {
                if(it - 1 == nullptr) it = nullptr;
                 else if(!past_the_end) it = it - 1;
                 else {it = it - 1; past_the_end = false;}
             }
             return aux;
         }

        Iteratore& operator=(Iteratore i) {it = i.it; return *this;}
        bool operator==(Iteratore i) const {return it == i.it;}
        bool operator!=(const Iteratore& i) const {return it != i.it;}
    };

    class const_Iteratore{
        friend class Contenitore<T>;
    private:
        const T* it;
        bool past_the_end;
        const_Iteratore(T* t, bool pte = false) : it(t), past_the_end(pte) {}
    public:
        const_Iteratore() : it(nullptr), past_the_end(false) {}
        const T& operator*() const {return *it;}
        const T* operator->() const {return &(*it);}

        const_Iteratore& operator++() {
            if(it != nullptr) {
                if(!past_the_end) {
                    if(it + 1 != nullptr) {it = it + 1;}
                    else { it = it + 1; past_the_end = true; }
                }
            }
            return *this;
        }

        const_Iteratore& operator++(int){
            const_Iteratore aux(*this);
            if(it!= nullptr) {
                if(!past_the_end) {
                    if(it + 1 != nullptr) it = it + 1;
                    else {it = it + 1; past_the_end = true;}
                }
            }
            return aux;
        }

        const_Iteratore& operator--() {
            if(it != nullptr) {
                if(it - 1 == nullptr) it = nullptr;
                else if(!past_the_end) it = it - 1;
                else {it = it - 1; past_the_end = false;}
            }
            return *this;
          }

        const_Iteratore& operator--(int) {
            const_Iteratore aux(*this);
            if(it != nullptr) {
                if(it - 1 == nullptr) it = nullptr;
                else if(!past_the_end) it = it - 1;
                else {it = it - 1; past_the_end = false;}
            }
            return aux;
          }

        const_Iteratore& operator= (const_Iteratore i) {it = i.it; return *this;}
        bool operator==(const_Iteratore i) const {return it == i.it;}
        bool operator!=(const const_Iteratore& i) const {return it != i.it;}
    };


    //costruttori
    Contenitore(unsigned int n = 0);
    Contenitore(const Contenitore& c);
    ~Contenitore();

    //metodi
    Iteratore begin() {return Iteratore(Array);}
    Iteratore end() {return Iteratore(Array+Size+1, true);}
    const_Iteratore begin() const {return const_Iteratore(Array);}
    const_Iteratore end() const {return const_Iteratore(Array+Size+1, true);}
    bool empty() const;
    unsigned int size() const;
    unsigned int capacity() const;
    void pushBack(const T& val);
    void popBack();
    T& front();
    T& back();
    void insert(const unsigned int& pos, const T& val);
    void erase(const unsigned int& pos);
    void clear();
    void resize(const unsigned int& n);
    void resize(const unsigned int& n, const T& x);
    void shrinkToFit();

    //operatori
    bool operator==(const Contenitore& c) const;
    bool operator!=(const Contenitore& c) const;
    Contenitore<T>& operator=(const Contenitore& c);
    T& operator[](unsigned int pos) const;
    bool operator>(const Contenitore& c) const;
    bool operator>=(const Contenitore & c) const;
    bool operator<(const Contenitore& c) const;
    bool operator<=(const Contenitore & c) const;
};

//costruttori
template <class T>
Contenitore<T>::Contenitore(unsigned int n) : Size(0), Capacity(n), Array(new T[Capacity]) {}

template <class T>
Contenitore<T>::Contenitore(const Contenitore& c) : Size(c.size()), Capacity(c.capacity()), Array(new T[c.capacity()])
{
    for(int i = 0; i < c.size(); ++i)
        Array[i] = c.Array[i];
}

template <class T>
Contenitore<T>::~Contenitore()
{
    if(Array) delete [] Array;
}

//metodi
template<class T>
bool Contenitore<T>::empty() const
{
    return Size == 0;
}

template <class T>
unsigned int Contenitore<T>::size() const
{
    return Size;
}

template <class T>
unsigned int Contenitore<T>::capacity() const
{
    return Capacity;
}

template<class T>
void Contenitore<T>::pushBack(const T& val)
{
    if(Size < Capacity)
    {
        Array[Size] = val;
        ++Size;
    }
    else
    {
        if(Capacity == 0)
            Capacity++;
        else
            Capacity = Capacity * 2;

        T * nuovo = new T[Capacity];

        for(unsigned int i = 0; i < Size; ++i)
            nuovo[i] = Array[i];

        nuovo[Size] = val;
        ++Size;
        delete [] Array;
        Array = nuovo;
    }
}

template <class T>
void Contenitore<T>::popBack()
{
    if(Size == 0)
    {
        std::cout<<"Contenitore vuoto, rimozione impossibile"<<std::endl;
    }
    else
        Size--;
}

template<class T>
T& Contenitore<T>::front()
{
    return Array[0];
}

template<class T>
T& Contenitore<T>::back()
{
    return Array[Size-1];
}

template <class T>
void Contenitore<T>::insert(const unsigned int& pos, const T& val)
{
    if(pos >= 0 && pos <= Size)
    {
        if (Size != Capacity)
        {
            for(int i = Size - 1; i >= pos; --i)
                Array[i+1] = Array[i];

            Array[pos] = val;
            ++Size;
        }
        else
        {
            if(Capacity == 0)
                Capacity++;

            else
                Capacity = Capacity * 2;

            T* nuovo = new T[Capacity];
            for(int i = 0; i < Size; ++i)
                nuovo[i] = Array[i];

            delete [] Array;
            Array = nuovo;
            insert(pos,val);
        }
    }
}

template <class T>
void Contenitore<T>::erase(const unsigned int& pos)
{
    if (pos < Size)
    {
        --Size;
        for(unsigned int i = pos; i < Size; ++i)
            Array[i] = Array[i+1];
    }
}

template <class T>
void Contenitore<T>::clear()
{
    Size = 0;
}

template<class T>
void Contenitore<T>::resize(const unsigned int &n)
{
    if(n < Size)
    {
        Size = n;
        T* nuovo = new T[Capacity];
        for(int i = 0; i < Size; ++i)
            nuovo[i] = Array[i];
        delete [] Array;
        Array = nuovo;
    }
    else if(n > Size)
    {
        if(n > Capacity)
            Capacity=n;

        for(int i = Size; i < n; ++i)
            Array[i] = T();

        Size = n;

    }
}

template<class T>
void Contenitore<T>::resize(const unsigned int& n, const T& x)
{
    if(n < Size)
    {
        Size = n;
        T* nuovo = new T[Capacity];
        for(int i = 0; i < Size; ++i)
            nuovo[i] = Array[i];
        delete [] Array;
        Array = nuovo;
    }
    else if(n > Size)
    {
        if(n > Capacity)
            Capacity = n;

       for(int i = Size; i < n; ++i)
           pushBack(x);
    }

}

template<class T>
void Contenitore<T>::shrinkToFit()
{
    Capacity = Size;
}

//operatori
template <class T>
bool Contenitore<T>::operator==(const Contenitore& c) const
{
    if(this == &c) return true;
    if(size() != c.size()) return false;

    for(int i=0; i<size(); ++i)
        if(Array[i] != c.Array[i]) return false;
    return true;
}

template <class T>
bool Contenitore<T>::operator!=(const Contenitore& c) const
{
    return !(*this == c);
}

template<class T>
Contenitore<T>& Contenitore<T>::operator=(const Contenitore<T>& c)
{
    if (this != &c)
    {
        delete [] Array;
        Capacity = c.Capacity;
        Array = Capacity == 0 ? nullptr : new T [Capacity];
    }

    for(int i = 0; i<c.Size; ++i)
        Array[i] = c.Array[i];

    Size = c.Size;

    return *this;
}


template <class T>
T& Contenitore<T>::operator[](unsigned int pos) const
{
    return Array[pos];
}

template<class T>
bool Contenitore<T>::operator>(const Contenitore &c) const
{
    if(this == &c) return false;
    for(int i = 0; i < Size; ++i)
    {
        if(Array[i] > c.Array[i])
            return true;
        else if(Array[i] < c.Array[i])
            return false;
    }
    if(Size < c.Size) return false;
    return false;
}

template<class T>
bool Contenitore<T>::operator>=(const Contenitore &c) const
{
    if(this == &c) return true;

    for(int i = 0; i < Size; ++i)
    {
        if(Array[i] > c.Array[i])
            return true;
        else if(Array[i] < c.Array[i])
            return false;
    }
    //tutti gli elementi visionati sono uguali
    if(Size < c.Size) return false;
    return true;
}

template<class T>
bool Contenitore<T>::operator<(const Contenitore &c) const
{
    if(this == &c) return false;

    for(int i = 0; i < Size; ++i)
    {
        if(Array[i] > c.Array[i])
            return false;
        else if(Array[i] < c.Array[i])
            return true;
    }
    if(Size < c.Size) return true;
    return false;
}

template<class T>
bool Contenitore<T>::operator<=(const Contenitore &c) const
{
    if(this == &c) return true;

    for(int i = 0; i < Size; ++i)
    {
        if(Array[i] > c.Array[i])
            return false;
        else if(Array[i] < c.Array[i])
            return true;
    }
    if(Size < c.Size) return true;
    return true;
}

#endif // CONTENITORE_H
