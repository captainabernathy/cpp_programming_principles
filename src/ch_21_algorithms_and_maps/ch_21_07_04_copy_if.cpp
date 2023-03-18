#include <vector>
#include <iostream>
using namespace std;

template<typename In, typename Out, typename Pred>
Out copy_if(In first, In last, Out res, Pred p)
{
    while (first != last)
    {
        if (p(*first))
        {
            *res = *first;
            ++res;
        }
        ++first;
    }

    return res;
}

template<typename T>
class Larger_than {
    T v;
public:
    Larger_than(T val)
        : v {val}
    {  }
    bool operator()(T x)
    {
        return x > v;
    }
};

int main()
{
    vector<int> v1{10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    vector<int> v2(v1.size());
    copy_if(v1.begin(), v1.end(), v2.begin(), Larger_than<int>(6));

    for (auto i : v2)
        cout << i << endl;
}
