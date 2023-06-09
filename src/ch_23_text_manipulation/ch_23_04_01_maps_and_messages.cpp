// program tests the Message class, which defines a message as a pair of
// iterators to the first and last lines in a vector of strings
//
// program also tests the Mail_file class that represents a a mail file as a
// file (name) that contains a vector of lines and a vector of Messages
//
// program then demonstrates how to use a multimap to process the contents
// of a Mail_file

#include <iostream> // for cout
#include <string> // for string, getline()
#include <utility> // for pair
#include <map> // for multimap
#include "message_utils.hpp" // for Message, Line_iter, find_from_addr(),
                             // find_subject()
#include "mail_file.hpp" // for Mail_file, Msg_iter

int main()
{
    using std::multimap;
    using std::string;
    using std::cout;
    using std::pair;

    Mail_file mfile("example-mail-file.txt");  // initialize mfile from a file

    // NOTE: a multimap is an associative container that stores elements
    // formed by a combination of a key value and a mapped value, following
    // a specific order, and where multiple elements can have equivalent keys
    
    // gather messages from each sender together in a multimap
    multimap<string, const Message*> sender;

    for (Msg_iter msg_it = mfile.begin(); msg_it != mfile.end(); msg_it++)
    {
        const Message& m = *msg_it;
        string s;
        if (find_from_addr(&m, s))
            sender.insert(make_pair(s, &m));
    }

    // iterate over multimap
    // typedef multimap<string, const Message*>::const_iterator mmap_const_it;
    using mmap_const_it = multimap<string, const Message*>::const_iterator;

    for (mmap_const_it it = sender.begin(); it != sender.end(); ++it)
    {
        cout << "key: " << it->first << '\n';
        cout << "value: ";
        for (Line_iter li = it->second->begin();
             li != it->second->end(); ++li)
            cout << *li << '\n';
        cout << "end\n";
    }
    cout << '\n';

    // find the bounds on the messages where the sender is John Doe..
    pair<mmap_const_it, mmap_const_it> pp =
        sender.equal_range("John Doe <jdoe@machine.example>");

    // find the subject(s) of the messages sent by John Doe
    for (mmap_const_it p = pp.first; p != pp.second; p++)
        cout << find_subject(*p->second) << '\n';

    return 0;
}
