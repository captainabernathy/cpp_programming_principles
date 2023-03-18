#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iterator>
#include <fstream>

using std::vector;
using std::string;
using std::ifstream;
using std::cout;
using std::cerr;
using std::endl;
using std::multimap;
using std::pair;

// define a Message as a pair of iterators into a vector<string>
// A Message object points to the first and last line of a message
using Line_iter = vector<string>::const_iterator;
class Message {
    Line_iter first;
    Line_iter last;

    public:
        Message(Line_iter first_line, Line_iter last_line)
            : first {first_line}, last{last_line}
        {  }

        Line_iter begin() const
        {
            return first;
        }

        Line_iter end() const
        {
            return last;
        }
};

using Msg_iter = vector<Message>::const_iterator;

// Mail_file is a struct that holds lines of text and messages, specifically...
// it holds all the lines of a file, and simplifies access to messages
struct Mail_file {

    string name; // file name
    vector<string> lines; // lines in order
    vector<Message> messages; // messages in order

    Mail_file(const string& file); // read file into lines

    Msg_iter begin() const
    {
        return messages.begin();
    }

    Msg_iter end() const
    {
        return messages.end();
    }
};

Mail_file::Mail_file(const string& file)
{
    ifstream ifs(file.c_str()); // open file
    if (!ifs)
    {
        cerr << "failed to open " << file << endl;
        exit(EXIT_FAILURE);
    }

    string s;
    while (getline(ifs, s))
        lines.push_back(s); // build vector of lines

    Line_iter first = lines.begin(); // build vector of Messages
    for (Line_iter li = lines.begin(); li != lines.end(); li++)
        if (*li == "----") // end of message
        {
            messages.push_back(Message(first, li));
            first = li + 1; // ---- not part of message
        }
}

// is *p the first part of s?
size_t is_prefix(const string& s, const string& p);

bool find_from_addr(const Message *m, string& s);

string find_subject(const Message& m);

int main()
{
    Mail_file mfile("my-mail-file.txt");  // initialize mfile from a file

    // gather messages from each sender together in a multimap
    multimap<string, const Message *> sender;

    for (Msg_iter msg_it = mfile.begin(); msg_it != mfile.end(); msg_it++)
    {
        const Message& m = *msg_it;
        string s;
        if (find_from_addr(&m, s))
            sender.insert(make_pair(s, &m));
    }

    // iterate over multimap and extract the subjects
    using mmap_const_it = multimap<string, const Message*>::const_iterator;
    pair<mmap_const_it, mmap_const_it> pp =
        sender.equal_range("John Doe <jdoe@machine.example>");

    for (mmap_const_it p = pp.first; p != pp.second; p++)
        cout << find_subject(*p->second) << endl;

    return 0;
}

size_t is_prefix(const string& s, const string& li)
{
    size_t sz = li.size();
    return (string(s, 0, sz) == li) ? sz : 0;
}

bool find_from_addr(const Message *msg, string& s)
{
    for (Line_iter li = msg->begin(); li != msg->end(); li++)
        if (size_t sz = is_prefix(*li, "From: "))
        {
            s = string(*li, sz);
            return true;
        }

    return false;
}

string find_subject(const Message& msg)
{
    for (Line_iter li = msg.begin(); li != msg.end(); li++)
        if (size_t sz = is_prefix(*li, "Subject: "))
            return string(*li, sz);
    return "";
}
