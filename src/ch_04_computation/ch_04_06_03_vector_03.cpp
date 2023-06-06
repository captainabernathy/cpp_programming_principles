// program demonstrates various common vector operations as well as the usage of
// C++'s standard sorting algorithm as it determines the uniqe strings
// contained in a vector of strings

#include <vector> // for vector
#include <string> // for string
#include <iostream> // for cin, cout
#include <algorithm> // for sort()

int main()
{
    using std::vector;
    using std::string;
    using std::cout;
    using std::cin;
    using std::sort;

    vector<string> words; // empty vector of strings
    string temp; // placeholder variable to fill vector

    cout << "Enter strings values (or CTRL-D when done): "; // prompt user
    while (cin >> temp) // read string into temp
        words.push_back(temp); // write temp to vector
   
    // NOTE: the size() method returns the number of elements in a container
    cout << "Number of words: " << words.size() << '\n';

    // default sort... provied by algorithm library
    // requires iterator to first and last elements in the range of the
    // container to be sorted
    sort(words.begin(), words.end()); // sort from beginning to end

    for (unsigned int i = 0; i < words.size(); i++)
        if (i == 0 || words[i - 1] != words[i]) // is this a new word?
            cout << words[i] << '\n';

    return 0;
}
