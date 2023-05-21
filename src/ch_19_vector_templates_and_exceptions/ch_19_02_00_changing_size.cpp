// program performs various operations on a vector to illustrate the
// relationship between size and capacity

#include <iostream> // for cout
#include <vector> // for vector()
#include <string> // for string

// function outputs vector v's size and capacity, prepended by string s
void print_info(std::vector<double> const& v, std::string const& s);

int main()
{
    using std::vector;
    using std::cout;
    
    int n = 100;
    std::vector<double> v(n); // v's size and capacity are 100

    print_info(v, "v"); // 100, 100
    cout << '\n';

    v.resize(10); // v's size is 10 and capacity is 100

    cout << "after v.resize(10)..." << '\n';
    print_info(v, "v"); // 10, 100
    cout << '\n';

    v.push_back(7); // increases size by 1... v's size is 11 and capacity is 100

    cout << "after v.push_back(7)..." << '\n';
    print_info(v, "v"); // 11, 100
    cout << '\n';

    vector<double> v2(7); // v2's size and capacity are 7

    print_info(v2, "v2"); // 7, 7
    cout << '\n';

    v = v2; // v's size is now 7 but it's capacity is still 100

    cout << "after v = v2..." << '\n';
    print_info(v, "v"); // 7, 100

    return 0;
}

void print_info(std::vector<double> const& v, std::string const& s)
{
    std::cout << s << ".size(): " << v.size() << '\n';
    std::cout << s << ".capacity(): " << v.capacity() << '\n';
}
