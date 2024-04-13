#ifndef UNORDERED_MAP_H
#define UNORDERED_MAP_H

#include <iostream>
#include <vector>
#include <forward_list>

template <class Key, class Value, class Hash = std::hash<Key>, class EqualTo = std::equal_to<Key>>
class unordered_map
{
    struct ListNode;
public:
    using key_type = Key;
    using mapped_type = Value;
    using value_type = std::pair<const Key, Value>;
    using iterator = typename std::forward_list<ListNode>::iterator;
    constexpr static const float _max_load_factor = 0.8;
    constexpr static const int start_buckets_count = 16;

private:
    struct ListNode
    {
    public:
        value_type* keyValue;
        size_t cached_hash;
        ListNode(const Key key, Value value, size_t cached_h)
        {
            keyValue = new value_type(key, value);
            //keyValue.first = key;
            //keyValue.second = value;
            cached_hash = cached_h;
        }

        ListNode(const ListNode& other)
        {
            keyValue = new value_type(other.keyValue->first, other.keyValue->second);
            cached_hash = other.cached_hash;
        }

        ~ListNode()
        {
            delete keyValue;
        }
    };
    std::forward_list<ListNode> elements;
    std::vector<iterator> buckets;
    size_t _size;
    size_t _buckets_count;
    Hash hash_func;

public:
    unordered_map()
    {
        _buckets_count = start_buckets_count;
        buckets.resize(_buckets_count, elements.begin());
        _size = 0;
    }

    float max_load_factor() { return _max_load_factor; }

    float load_factor() { return static_cast<float>(size()) / static_cast<float>(_buckets_count); }

    size_t size() const { return _size; }

    bool empty() const { return elements.empty(); }

    std::pair<iterator, bool> insert(const value_type& value)
    {
        size_t index = hash_func(value.first) % _buckets_count;

        iterator iter = buckets[index];

        if (iter == elements.end())     // nothing at this index
        {
            float k = static_cast<float>(size()) / static_cast<float>(_buckets_count); //formula load_factor(n/N)
            if (_max_load_factor < k)
                rehash(_buckets_count * 2);
            elements.push_front(*(new ListNode(value.first, value.second, index)));
            buckets[index] = elements.begin();
            _size++;
            return std::make_pair(buckets[index], true);
        }
        else    // smth was at this index
        {
            int countOfDuplicate = 0;
            for (; iter != elements.end() && (*iter).cached_hash == index; iter++)
            {
                if ((*iter).keyValue->first == value.first)   // check if duplicates
                {
                    return std::make_pair(iter, false);
                }
                countOfDuplicate++;
                iterator tmp = iter;
                tmp++;
                if (tmp == elements.end() || (*tmp).cached_hash != index)
                    break;
            }

            float k = static_cast<float>(size()) / static_cast<float>(_buckets_count);
            if (_max_load_factor < k)
                rehash(_buckets_count * 2);

            iter = buckets[index];  // against invalidation. And next lines untill insert_after
            int countOfDuplicate1 = 0;
            for (; iter != elements.end() && (*iter).cached_hash == index; iter++)
            {
                if ((*iter).keyValue->first == value.first)   // check if duplicates
                {
                    return std::make_pair(iter, false);
                }
                countOfDuplicate1++;
                iterator tmp = iter;
                tmp++;
                if (tmp == elements.end() || (*tmp).cached_hash != index)
                    break;
            }

            elements.insert_after(iter, *(new ListNode(value.first, value.second, index)));
            _size++;
            return std::make_pair(++iter, true);
        }
    }

    size_t erase(const Key& key)
    {
        size_t index = hash_func(key) % _buckets_count;

        iterator iter = buckets[index];

        if (iter == elements.end())
            return 0;

        for (; iter != elements.end() && (*iter).cached_hash == index; iter++)
        {
            if (EqualTo().operator()((*iter).keyValue->first, key))   // if it's first with such index
            {
                // so as curr element can't be deleted(because it's forward_list) need to find curr from begin. (if first elements with such index)
                iterator tmp = elements.begin();
                if (tmp == iter)    // it's first element in the list
                {
                    elements.pop_front();
                    iterator beginElements = elements.begin();
                    if (index == (*beginElements).cached_hash)
                        buckets[index] = elements.begin();
                    else
                        buckets[index] = elements.end();
                    _size--;
                    return 1;
                }

                iterator buf;
                while (tmp != iter)
                {
                    buf = tmp;
                    ++tmp;
                    if (tmp == iter)
                        break;
                }
                elements.erase_after(buf);
                buf++;
                if (buf != elements.end() && (*buf).cached_hash == index)    // if there are still with such index
                    buckets[index] = buf;
                else
                    buckets[index] = elements.end();
                _size--;
                return 1;
            }
            iterator tmp = iter;
            tmp++;
            if (EqualTo().operator()((*tmp).keyValue->first, key))
                break;
            else
                return 0;
        }
        _size--;
        elements.erase_after(iter);
        return 1;
    }

//method close adress(zepochka)

    void rehash(size_t count)
    {
        if (count <= _buckets_count) return;

        buckets.clear();
        _buckets_count = count;
        buckets.resize(_buckets_count, elements.end());
        _size = 0;

        std::forward_list<ListNode> tmp_elements;
        tmp_elements = elements;
        iterator iter = tmp_elements.begin();
        while (!elements.empty())
            elements.pop_front();
        while (iter != tmp_elements.end())
        {
            insert(std::make_pair((*iter).keyValue->first, (*iter).keyValue->second));
            iter++;
        };
        tmp_elements.clear();
    }

    bool contains(const key_type& key)
    {
        size_t index = hash_func(key) % _buckets_count;

        iterator iter = buckets[index];

        if (iter == elements.end())
            return 0;

        for (; iter != elements.end() && (*iter).cached_hash == index; iter++)
        {
            if (EqualTo().operator()((*iter).keyValue->first, key))
                return true;

        }
        return false;
    }

    iterator begin() { return elements.begin(); }

    iterator end() { return elements.end(); }

    void clear()
    {
        elements.clear();
        buckets.clear();
        buckets.resize(_buckets_count, elements.begin());
        _size = 0;
    }

    mapped_type& at(const Key& key)
    {
        size_t index = hash_func(key) % _buckets_count;

        iterator iter = buckets[index];

        if (iter == elements.end())
            throw std::out_of_range("No such key");

        for (; iter != elements.end() && (*iter).cached_hash == index; iter++)
        {
            if (EqualTo().operator()((*iter).keyValue->first, key))
            {
                return (*iter).keyValue->second;
            }

        }
        throw std::out_of_range("No such key");
    }

    Value& operator[](const Key& key)
    {
        size_t index = hash_func(key) % _buckets_count;

        iterator iter = buckets[index];

        if (iter == elements.end())
        {
            std::pair<iterator, bool> b = insert(std::make_pair(key, ""));
            iterator t = b.first;
            return t->keyValue->second;
        }

        for (; iter != elements.end() && (*iter).cached_hash == index; iter++)
        {
            if (EqualTo().operator()((*iter).keyValue->first, key))
            {
                return (*iter).keyValue->second;
            }

        }
        std::pair<iterator, bool> b = insert(std::make_pair(key, ""));
        iterator t = b.first;
        return t->keyValue->second;
    }
};

#endif // UNORDERED_MAP_H
