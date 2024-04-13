#ifndef MYSHARED_H
#define MYSHARED_H

#include<algorithm>
#include<utility>


template<class T>
class MyShared
{  
public:
    MyShared() : ptr(nullptr) , RefCount(new int(0)){};

    MyShared(T* ptr) : ptr(ptr) , RefCount(new int(1)){};

    MyShared(T* ptr, int* x) : ptr(ptr) , RefCount(x){
        (*RefCount)++;
    };


    MyShared(MyShared<T> const& OtherShared_ptr) : ptr(OtherShared_ptr.ptr) , RefCount(OtherShared_ptr.RefCount){//cs copy
//        if(ptr == nullptr) return;
        if(nullptr != OtherShared_ptr.ptr){
            (*this->RefCount)++;
        }
    }
    //конструктор перемещения + функция мув
    MyShared(MyShared<T> const&& OtherShared_ptr) : ptr(std::move(OtherShared_ptr.ptr)) , RefCount(std::move(OtherShared_ptr.RefCount)){//cs move
        if(ptr == nullptr) return;

        OtherShared_ptr.ptr = nullptr;
        OtherShared_ptr.RefCount = nullptr;

         ++(*RefCount);
    }
    MyShared<T>& operator=(MyShared<T>& OtherShared_ptr){
        if(this == &OtherShared_ptr) return *this;

        (*RefCount)--;
        if(*RefCount == 0){
            delete ptr;
            delete RefCount;
        }

        ptr = OtherShared_ptr.ptr;
        RefCount = OtherShared_ptr.RefCount;

        if(nullptr != OtherShared_ptr.ptr){
            (*this->RefCount)++;
        }

        return *this;
    };
    //конструктор перемещения при разных шеридах
    MyShared<T>& operator=(MyShared<T>&& OtherShared_ptr){

        if(this == &OtherShared_ptr) return *this;


        (*RefCount)--;
        if(*RefCount == 0){
            delete ptr;
            delete RefCount;
        }


        ptr = (OtherShared_ptr.ptr);
        RefCount = (OtherShared_ptr.RefCount);

        OtherShared_ptr.ptr = nullptr;
        OtherShared_ptr.RefCount = nullptr;

        return *this;
    };

    ~MyShared()
    {
        if(!RefCount) return;
        --*RefCount;
        if(!*RefCount){
            delete ptr;
            delete RefCount;
        }
    }

    //получаем указатель на указанное значение
    T* operator->()
    {
        return ptr;
    };
    //позволяет воспроизвести данные(перегрузка оператора разыменования)
    T& operator*() const noexcept{
        return *ptr;
    };

    void IncrementCountForWeak(){
        RefCount++;
    }
    void reset(T* newptr)
    {
//        delete ptr;
//        ptr = newptr;
    };

    //свапаем
    void swap (MyShared<T>& OtherShared_ptr) noexcept{
        std::swap(ptr, OtherShared_ptr.ptr);
        std::swap(RefCount, OtherShared_ptr.RefCount);

    };

    //returns a pointer or nullptr
    T* get() const noexcept
    {
        return ptr;
    };

    int* get_ReFCount() const noexcept
    {
        return RefCount;
    };

    bool Unique()
    {
       return *RefCount == 1 ? true : false;
    }

    int Use_Count()
    {
        return *RefCount;
    }

private:   
     T* ptr;
     int* RefCount;//ReferenceCount
};
#endif // MYSHARED_H
