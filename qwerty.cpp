#include <iostream>
#include <vector>
#include <list>
#include <string>

template <typename T>
class RangeIterator {
private:
    typename T::iterator current;
    typename T::iterator end;
public:
    RangeIterator(typename T::iterator begin, typename T::iterator end)
            : current(begin), end(end) {}

    RangeIterator<T>& operator++() {
        ++current;
        return *this;
    }

    RangeIterator<T>& operator--() {
        --current;
        return *this;
    }

    typename T::value_type& operator*() {
// Where it gets complicated is generic programming. For example, if I wanted to write a generic sum() function, I would
// need it to know what kind of container to iterate and what type its elements are, so I would need to have something like this
        return *current;
    }

    bool operator!=(const RangeIterator<T>& other) const {
        return current != other.current;
    }

    void print()
    {
        for (auto it = current; it != end; ++it)
        {
            std::cout << *it << " ";
        }
    }
};

int main() {
    std::vector<std::string> first = {"one", "two", "three", "four", "five"};
    RangeIterator<std::vector<std::string>> first_one(first.begin(), first.end());
    first_one.print();
    std::cout << '\n';

    std::list<float> second = {2.9, -10.1, 7.9, 2, 0.1, -8};
    RangeIterator<std::list<float>> second_start(second.begin(), second.end());
    RangeIterator<std::list<float>> second_finish(second.end(), second.end());
    second_start.print();

    return 0;
}
