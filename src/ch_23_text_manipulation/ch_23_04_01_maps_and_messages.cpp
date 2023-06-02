// program implements a class that defines a message as a pair of iterators
// to the first and last lines in a vector of strings
//
// program also implements a class that represents a mail file as a file name
// that contains a vector of lines and a vector of messages
//
// program then demonstrates how to use a multimap to process the contents
// of a mail file

#include <iostream> // for cout, cerr
#include <string> // for string, getline()
#include <vector> // for vector
#include <utility> // for pair
#include <map> // for multimap
#include <fstream> // for ifstream
#include <cstdlib> // for exit(), EXIT_FAILURE

using Line_iter = std::vector<std::string>::const_iterator;

// define a Message as a pair of iterators into a vector<string>
// A Message object points to the first and last line of a message
class Message {
    // private members
    Line_iter first;
    Line_iter last;

public:
    // constructor initializes first to first_line and last to last_line
    Message(Line_iter first_line, Line_iter last_line)
        : first {first_line}, last{last_line}
    {  }

    // returns an iterator to the first line in this Message
    Line_iter begin() const
    {
        return first;
    }

    // returns an iterator to the last line in this Message
    Line_iter end() const
    {
        return last;
    }
};

using Msg_iter = std::vector<Message>::const_iterator;

// Mail_file is a class that holds lines of text and messages, specifically...
// it holds all the lines of a file, and simplifies access to messages
struct Mail_file {

    std::string name; // file name
    std::vector<std::string> lines; // lines in order
    std::vector<Message> messages; // messages in order

    // conversion constructor... builds a mail file from a file
    explicit Mail_file(std::string const& file); // read file into lines

    // returns an iterator to the first message in this Mail_file
    Msg_iter begin() const
    {
        return messages.begin();
    }

    // returns an iterator to the last message in this Mail_file
    Msg_iter end() const
    {
        return messages.end();
    }
};

// conversion constructor... builds a mail file from a file
Mail_file::Mail_file(std::string const& file)
{
    std::ifstream ifs {file.c_str()}; // open file
    if (!ifs)
    {
        std::cerr << "failed to open " << file << std::endl;
        std::exit(EXIT_FAILURE);
    }

    name = file; // set name attribute

    // build up lines attribute
    std::string s;
    while (getline(ifs, s)) // read lines from the input stream to s
        lines.push_back(s); // build vector of lines

    // build up messages attributes
    Line_iter first = lines.begin(); // build vector of Messages
    for (Line_iter li = lines.begin(); li != lines.end(); ++li)
        if (*li == "----") // end of message
        {
            messages.push_back(Message(first, li));
            first = li + 1; // not part of message
        }
}

// is *li the first part of s?
// returns the size of the string passed to li if the beginning of the string
// passed to s is equal to li
size_t is_prefix(std::string const& s, std::string const& li);

// returns true and sets the string passed to s the rest of the characters in
// a line of the message passed to msg if the line begins with "From: "...
// returns false otherwise
bool find_from_addr(const Message *m, std::string& s);

// returns a string that contains the rest of the characters in a line of the
// message passed to msg if the line begins with "Subject: "...
// otherwise, returns an empty string
std::string find_subject(Message const& m);

int main()
{
    using std::multimap;
    using std::string;
    using std::cout;
    using std::pair;

    Mail_file mfile("my-mail-file.txt");  // initialize mfile from a file

    // NOTE: a multimap is an associative container that stores elements
    // formed by a combination of a key value and a mapped value, following
    // a specific order, and where multiple elements can have equivalent keys
    
    // gather messages from each sender together in a multimap
    multimap<string, const Message *> sender;

    for (Msg_iter msg_it = mfile.begin(); msg_it != mfile.end(); msg_it++)
    {
        const Message& m = *msg_it;
        string s;
        if (find_from_addr(&m, s))
            sender.insert(make_pair(s, &m));
    }

    // iterate over multimap
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

// returns the size of the string passed to li if the beginning of the string
// passed to s is equal to li
size_t is_prefix(std::string const& s, std::string const& li)
{
    size_t sz = li.size();
    // string(str,pos,len)... initializes a string of length len starting at
    // position pos of str
    return (std::string(s, 0, sz) == li) ? sz : 0;
}

// returns true and sets the string passed to s the rest of the characters in
// a line of the message passed to msg if the line begins with "From: "...
// returns false otherwise
bool find_from_addr(const Message *msg, std::string& s)
{
    // loop over lines
    for (Line_iter li = msg->begin(); li != msg->end(); ++li)
        // test if "From: " is a prefix of the current line
        if (size_t sz = is_prefix(*li, "From: "))
        {
            // NOTE: s = string(str,pos) returns the rest of the sting in str
            // begnning at the character pos...
            // so, s = string(*li, sz) is the same as string(*li, sz, -1)
            // s = string(*li, sz, -1); // write the "From: " string to s if so
            s = std::string(*li, sz); // write the "From: " string to s if so
            return true;
        }
    
    return false;
}

// returns a string that contains the rest of the characters in a line of the
// message passed to msg if the line begins with "Subject: "...
// otherwise, returns an empty string
std::string find_subject(Message const& msg)
{
    // loop over lines
    for (Line_iter li = msg.begin(); li != msg.end(); li++)
        // test if "Subject: " is the prefix of the current line
        if (size_t sz = is_prefix(*li, "Subject: "))
            // NOTE: string(str,pos) returns the rest of the string in str
            // beginning at the character pos
            return std::string(*li, sz); // if so return the rest of it
    return ""; // otherwise return an empty string
}
