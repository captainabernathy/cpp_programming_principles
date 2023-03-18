#include <iostream>
#include <list>
#include <string>
#include <stdexcept>
#include <vector>

using std::list;
using std::vector;
using std::string;
using std::exception;
using std::runtime_error;
using std::cout;
using std::cerr;
using std::endl;

namespace our {
    template<typename In, typename Out>
    Out copy(In first, In last, Out res)
    {
        while (first != last)
        {
            *res = *first;
            ++res;
            ++first;
        }

        return res;
    }

    template<typename Iter>
    void print(Iter start, Iter stop)
    {
        while (start != stop)
        {
            cout << *start << endl;
            start++;
        }
    }
}

inline void error(const string& msg)
{
    throw runtime_error(msg);
}

void f(list<int>& dest, vector<int>& src)
{
    if (dest.size() < src.size())
        error("target container too small");
    our::copy(src.begin(), src.end(), dest.begin());
}

int main()
{
    try
    {
        vector<int> v{1, 2, 3, 4};
        list<int> l(4);
        f(l, v);
        our::print(v.begin(), v.end());
        cout << endl;
        our::print(l.begin(), l.end());
    }
    catch(exception& ex)
    {
        cerr << "error: " << ex.what() << endl;
        return 1;
    }
    catch (...)
    {
        cerr << "unknown exception" << endl;
        return 2;
    }

    return 0;
}
