#ifndef PAIR_H
#define PAIR_H
#include <iostream>
template<class A, class B>
struct pair
{
    A first;
    B second;

    pair() : first(), second() { }

    pair(const A& a, const B& b) : first(a), second(b) { }

    template<class AA, class BB>
    pair(const pair<AA, BB>& p) : first(p.first), second(p.second) { }

    pair& operator =(const pair& p)
    {
        first = std::move(p.first);
        second = std::move(p.second);
        return *this;
    }

    template<class AA, class BB>
    pair& operator =(const pair<AA, BB>& p)
    {
        first = std::move(p.first);
        second = std::move(p.second);
        return *this;
    }

    void swap(pair& p)
    {
        std::swap(first, p.first);
        std::swap(second, p.second);
    }

    template<class AA, class BB>
    void swap(pair<AA, BB>& p)
    {
        first = std::move(p.first);
        second = std::move(p.second);
    }

    void make_pair(A x, B y)
    {
        first = x;
        second = y;
    }
};
#endif // PAIR_H
