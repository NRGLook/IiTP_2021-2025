#ifndef SMART_POINTERS_H
#define SMART_POINTERS_H

#include <type_traits>
#include <utility>
#include <ostream>

template<typename T>
struct ControlBlock
{
    T* sh_ptr;
    size_t shared_counter = 0;
    size_t weak_counter = 0;

    void increaseSharedCount()
    {
        shared_counter++;
    }

    void decreaseSharedCount()
    {
        shared_counter--;
    }

    void increaseWeakCount()
    {
        weak_counter++;
    }

    void decreaseWeakCount()
    {
        weak_counter--;
    }
};

template<typename  T>
class weak_ptr;

template <typename T>
class shared_ptr
{
private:
    ControlBlock<T>* c_ptr = nullptr;

    template<typename D> friend class shared_ptr;
    template<typename D> friend class weak_ptr;

public:
    using element_type = std::remove_extent_t<T>;

    shared_ptr()
    {

    }

    explicit shared_ptr(T* ptr) : c_ptr(new ControlBlock<T>)
    {
        c_ptr->sh_ptr = ptr;
        c_ptr->increaseSharedCount();
    }

    ~shared_ptr()
    {
        if (!c_ptr || !c_ptr->sh_ptr)
        {
            return;
        }
        c_ptr->decreaseSharedCount();
        if (c_ptr->shared_counter <= 0)
        {
            delete c_ptr->sh_ptr;
            c_ptr->sh_ptr = nullptr;
            if (c_ptr->weak_counter <= 0)
            {
                delete c_ptr;
                c_ptr = nullptr;
            }
        }
    }

    /*** Copy Semantics ***/
    shared_ptr(const shared_ptr& obj) // copy constructor
    {
        c_ptr = obj.c_ptr;
        if (c_ptr)
        {
            c_ptr->increaseSharedCount();
        }
    }

    shared_ptr<T>& operator=(shared_ptr<T>& obj) // copy assignment
    {
        if (c_ptr)
        {
            c_ptr->decreaseSharedCount();
        }
        c_ptr = obj.c_ptr;
        if (c_ptr)
        {
            c_ptr->increaseSharedCount();
        }
        return *this;
    }

    /*** Move Semantics ***/
    //guarantee that there will be no exceptions
    shared_ptr(shared_ptr&& dyingObj) noexcept // move constructor
    {
        c_ptr = dyingObj.c_ptr;
        if (c_ptr)
        {
            c_ptr->sh_ptr = dyingObj.c_ptr->sh_ptr;
        }
        dyingObj.c_ptr->sh_ptr = nullptr;
    }

    shared_ptr<T>& operator=(shared_ptr<T>&& dyingObj) noexcept // move assignment
    {
        if (this->c_ptr)
        {
            c_ptr->decreaseSharedCount();
        }
        c_ptr = dyingObj.c_ptr;
        if (c_ptr)
        {
            c_ptr->sh_ptr = dyingObj.c_ptr->sh_ptr;
        }
        dyingObj.c_ptr = nullptr;
        return *this;
    }

    T* get() const noexcept
    {
        if (c_ptr)
        {
            return c_ptr->sh_ptr;
        }
        else
        {
            return nullptr;
        }
    }

    T* operator->() const noexcept
    {
        return c_ptr->sh_ptr;
    }

    T& operator*() const noexcept
    {
        return *(c_ptr->sh_ptr);
    }

    size_t use_count() const noexcept
    {
        if (c_ptr)
        {
            return c_ptr->shared_counter;
        }
        return 0;
    }

    bool unique() const noexcept
    {
        if (this->use_count() == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    explicit operator bool() const noexcept
    {
        if (this->get() != nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool owner_before(const shared_ptr<T>& other) const noexcept
    {
        return c_ptr < other.c_ptr;
    }

    bool owner_before(const weak_ptr<T>& other) const noexcept
    {
        return c_ptr < other.c_ptr;
    }

    void reset(T* ptr)
    {
        delete c_ptr->sh_ptr;
        c_ptr->sh_ptr = ptr;
    }

    void swap(shared_ptr& r) noexcept
    {
        std::swap(c_ptr, r.c_ptr);
    }

    void swap(const shared_ptr<T>& obj)
    {
        std::swap(c_ptr, obj.c_ptr);
    }

    explicit shared_ptr(const weak_ptr<T>& ptr) : c_ptr(ptr.c_ptr)
    {
        if (c_ptr)
        {
            c_ptr->incSharedCount();
        }
    }
};

template<typename T>
class shared_ptr<T[]>
{
private:
    T* obj = nullptr;
    ControlBlock<T>* c_ptr = nullptr;

    template<typename D> friend class shared_ptr;
    template<typename D> friend class weak_ptr;

public:
    using element_type = std::remove_extent_t<T>;

    shared_ptr()
    {

    }

    explicit shared_ptr(T* ptr) : c_ptr(new ControlBlock<T>)
    {
        c_ptr->sh_ptr = ptr;
        c_ptr->increaseSharedCount();
    }

    ~shared_ptr()
    {
        if (!c_ptr || !c_ptr->sh_ptr)
        {
            return;
        }
        c_ptr->decreaseSharedCount();
        if (c_ptr->shared_counter <= 0)
        {
            delete[] c_ptr->sh_ptr;
            c_ptr->sh_ptr = nullptr;
            if (c_ptr->weak_counter <= 0)
            {
                delete c_ptr;
                c_ptr = nullptr;
            }
        }
    }

    /*** Copy Semantics ***/
    shared_ptr(const shared_ptr& obj) // copy constructor
    {
        c_ptr = obj.c_ptr;
        if (c_ptr)
        {
            c_ptr->increaseSharedCount();
        }
    }

    shared_ptr<T>& operator=(shared_ptr<T>& obj) // copy assignment
    {
        if (c_ptr)
        {
            c_ptr->decreaseSharedCount();
        }
        c_ptr = obj.c_ptr;
        if (c_ptr)
        {
            c_ptr->increaseSharedCount();
        }
        return *this;
    }

    /*** Move Semantics ***/
    shared_ptr(shared_ptr&& dyingObj) noexcept // move constructor
    {
        c_ptr = dyingObj.c_ptr;
        if (c_ptr)
        {
            c_ptr->sh_ptr = dyingObj.c_ptr->sh_ptr;
        }
        dyingObj.c_ptr->sh_ptr = nullptr;
    }

    shared_ptr<T>& operator=(shared_ptr<T>&& dyingObj) noexcept // move assignment
    {
        if (this->c_ptr)
        {
            c_ptr->decreaseSharedCount();
        }
        c_ptr = dyingObj.c_ptr;
        if (c_ptr)
        {
            c_ptr->sh_ptr = dyingObj.c_ptr->sh_ptr;
        }
        dyingObj.c_ptr = nullptr;
        return *this;
    }

    T* get() const noexcept
    {
        if (c_ptr)
        {
            return c_ptr->sh_ptr;
        }
        else
        {
            return nullptr;
        }
    }

    T* operator->() const noexcept
    {
        return c_ptr->sh_ptr;
    }

    T& operator*() const noexcept
    {
        return *(c_ptr->sh_ptr);
    }

    size_t use_count() const noexcept
    {
        if (c_ptr)
        {
            return c_ptr->shared_counter;
        }
        return 0;
    }

    bool unique() const noexcept
    {
        if (this->use_count() == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    explicit operator bool() const noexcept
    {
        if (this->get() != nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool owner_before(const shared_ptr<T>& other) const noexcept
    {
        return c_ptr < other.c_ptr;
    }

    bool owner_before(const weak_ptr<T>& other) const noexcept
    {
        return c_ptr < other.c_ptr;
    }

    void reset(T* ptr)
    {
        delete c_ptr->sh_ptr;
        c_ptr->sh_ptr = ptr;
    }

    void swap(shared_ptr& r) noexcept
    {
        std::swap(c_ptr, r.c_ptr);
    }

    void swap(const shared_ptr<T>& obj)
    {
        std::swap(c_ptr, obj.c_ptr);
    }

    explicit shared_ptr(const weak_ptr<T>& ptr) : c_ptr(ptr.c_ptr)
    {
        if (c_ptr)
        {
            c_ptr->incSharedCount();
        }
    }

    T& operator[](size_t index) noexcept
    {
        return c_ptr->sh_ptr[index];
    }
};

//only for non-array types
template<typename T, typename... Args>
std::enable_if_t<!std::is_array<T>::value, shared_ptr<T>>
make_shared(Args&&... args)
{
    return shared_ptr<T>(new T(std::forward<Args>(args)...));
}

//only for array types
template<typename U>
std::enable_if_t<std::is_array<U>::value, shared_ptr<U>>
make_shared(int n)
{
    return shared_ptr<U>(new std::remove_extent_t<U>[n]());
}

template<typename T, typename U>
bool operator==(const shared_ptr<T>& lhs, const shared_ptr<U>& rhs) noexcept
{
    return lhs.get() == rhs.get();
}

template<typename T, typename U>
bool operator!=(const shared_ptr<T>& lhs, const shared_ptr<U>& rhs) noexcept
{
    return lhs.get() != rhs.get();
}

template<typename T, typename U, typename V>
std::basic_ostream<U, V>& operator<<( std::basic_ostream<U, V>& os, const shared_ptr<T>& ptr )
{
    os << ptr.get();
    return os;
}

template<typename T>
class weak_ptr
{
private:
    ControlBlock<T>* c_ptr = nullptr;

    template<typename D> friend class shared_ptr;
    template<typename D> friend class weak_ptr;

public:
    weak_ptr() : c_ptr(nullptr)
    {

    }

    ~weak_ptr()
    {
        if (!c_ptr)
        {
            return;
        }
        c_ptr->decreaseWeakCount();
        if (c_ptr->shared_counter <= 0 && c_ptr->weak_counter <= 0)
        {
            delete c_ptr;
            c_ptr = nullptr;
        }
    }

    weak_ptr(const shared_ptr<T>& obj)
    {
        c_ptr = obj.c_ptr;
        if (c_ptr)
        {
            c_ptr->increaseWeakCount();
        }
    }

    weak_ptr<T>& operator=(const weak_ptr<T>& another)
    {
        if (c_ptr)
        {
            c_ptr->decWeakCount();
        }
        c_ptr = another.c_ptr;
        if (c_ptr)
        {
            c_ptr->incWeakCount();
        }
        return *this;
    }

    weak_ptr<T>& operator=(const shared_ptr<T>& ptr) noexcept
    {
        if (c_ptr)
        {
            c_ptr->decWeakCount();
        }
        c_ptr = ptr.c_ptr;
        if (c_ptr)
        {
            c_ptr->incWeakCount();
        }
        return *this;
    }

    weak_ptr<T>& operator=(weak_ptr<T>&& another) noexcept
    {
        if (this->c_ptr)
        {
            c_ptr->decWeakCount();
        }
        c_ptr = another.c_ptr;
        another.c_ptr = nullptr;
        return *this;
    }

    void reset() noexcept
    {
        if (c_ptr)
        {
            c_ptr->decreaseWeakCount();
        }
        c_ptr = nullptr;
    }

    void swap(weak_ptr& r) noexcept
    {
        std::swap(c_ptr, r.c_ptr);
    }

    size_t use_count() const noexcept
    {
        if (c_ptr)
        {
            return c_ptr->shared_counter;
        }
        return 0;
    }

    bool expired() const noexcept
    {
        return (!c_ptr || c_ptr->sharedCount <= 0);
        //return this->use_count() == 0;
    }

    shared_ptr<T> lock() const noexcept
    {
        return (expired() ? shared_ptr<T>() : shared_ptr<T>(*this));
    }

    bool owner_before(const weak_ptr<T>& other) const noexcept
    {
        return c_ptr < other.c_ptr;
    }

    bool owner_before(const shared_ptr<T>& other) const noexcept
    {
        return c_ptr < other.c_ptr;
    }
};


template <typename T>
class unique_ptr
{
private:
    T* u_ptr = nullptr;

public:
    explicit unique_ptr(T* ptr): u_ptr(ptr) {}

    ~unique_ptr()
    {
        delete u_ptr;
    }

    unique_ptr(const unique_ptr&) = delete;

    unique_ptr& operator=(const unique_ptr&) = delete;

    //moving constructor
    unique_ptr(unique_ptr&& another) noexcept
    {
        u_ptr = another.u_ptr;
        another.u_ptr = nullptr;
    }

    unique_ptr<T>& operator=(unique_ptr&& another) noexcept
    {
        if (&another == this)
        {
            return *this;
        }
        delete u_ptr;
        u_ptr = another.u_ptr;
        another.u_ptr = nullptr;
        return *this;
    }

    T& operator*() const
    {
        return *u_ptr;
    }

    T* operator->() const
    {
        return u_ptr;
    }

    //checks if there is an associated managed object
    explicit operator bool() const noexcept
    {
        return (u_ptr != nullptr);
    }

    //returns a pointer to the managed object
    T* get() const
    {
        return u_ptr;
    }

    //returns a pointer to the managed object and releases the ownership
    T* release()
    {
        T* temp = u_ptr;
        u_ptr = nullptr;
        return temp;
    }

    //replaces the managed object
    void reset(T* p)
    {
        delete u_ptr;
        u_ptr = p;
    }

    //swaps the managed objects
    void swap(unique_ptr& another) noexcept
    {
        std::swap(u_ptr, another.u_ptr);
    }

};

template <typename T>
class unique_ptr<T[]>
{
private:
    T* u_ptr = nullptr;

public:
    explicit unique_ptr(T* ptr): u_ptr(ptr) {}

    ~unique_ptr()
    {
        delete[] u_ptr;
        u_ptr = nullptr;
    }

    unique_ptr(const unique_ptr&) = delete;

    unique_ptr& operator=(const unique_ptr&) = delete;

    //moving constructor
    unique_ptr(unique_ptr&& another) noexcept
    {
        u_ptr = another.u_ptr;
        another.u_ptr = nullptr;
    }

    unique_ptr<T>& operator=(unique_ptr&& another) noexcept
    {
        if (&another == this)
        {
            return *this;
        }
        delete u_ptr;
        u_ptr = another.u_ptr;
        another.u_ptr = nullptr;
        return *this;
    }

    T& operator*() const
    {
        return *u_ptr;
    }

    T* operator->() const
    {
        return u_ptr;
    }

    //checks if there is an associated managed object
    explicit operator bool() const noexcept
    {
        return (u_ptr != nullptr);
    }

    //returns a pointer to the managed object
    T* get() const
    {
        return u_ptr;
    }

    T& operator[](int i) const
    {
        return u_ptr[i];
    }

    //returns a pointer to the managed object and releases the ownership
    T* release()
    {
        T* temp = u_ptr;
        u_ptr = nullptr;
        return temp;
    }

    //replaces the managed object
    void reset(T* p)
    {
        delete[] u_ptr;
        u_ptr = p;
    }

    //swaps the managed objects
    void swap(unique_ptr& another) noexcept
    {
        std::swap(u_ptr, another.u_ptr);
    }

};

//only for non-array types
template<class U, class... Args>
std::enable_if_t<!std::is_array<U>::value, unique_ptr<U>>
make_unique(Args&&... args)
{
    return unique_ptr<U>(new U(std::forward<Args>(args)...));
}

//only for array types
template<class U>
std::enable_if_t<std::is_array<U>::value, unique_ptr<U>>
make_unique(std::size_t n)
{
    return unique_ptr<U>(new std::remove_extent_t<U>[n]());
}

template<class T, class U>
bool operator==(const unique_ptr<T>& x, const unique_ptr<U>& y) { return x.get() == y.get(); }

template<class T, class U>
bool operator<(const unique_ptr<T>& x, const unique_ptr<U>& y) { return x.get() < y.get(); }

template<class T, class U>
bool operator>(const unique_ptr<T>& x, const unique_ptr<U>& y) { return x.get() > y.get(); }

template<class T, class U>
bool operator<=(const unique_ptr<T>& x, const unique_ptr<U>& y) { return x.get() <= y.get(); }

template<class T, class U>
bool operator>=(const unique_ptr<T>& x, const unique_ptr<U>& y) { return x.get() >= y.get(); }

template<class T, class U>
bool operator!=(const unique_ptr<T>& x, const unique_ptr<U>& y) { return x.get() != y.get(); }


#endif // SMART_POINTERS_H
