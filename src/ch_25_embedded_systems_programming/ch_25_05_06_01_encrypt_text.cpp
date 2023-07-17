// program demonstrates how to use the Tiny Encryption Algorithm to encrypt a
// file (such as message.txt) with a user provided key

#include <encryption_utils/tiny_encryption_algorithm.hpp> // for encrypt()
#include <exception> // for exception
#include <iostream> // for cin, cout, cerr
#include <string> // for string
#include <fstream> // for ifstream, ofstream
#include <ios> // for hex
#include <iomanip> // for setw(), setfill()
#include <cpp_facilities/std_lib_facilities.hpp> // for error()

int main()
{
    using std::exception;
    using std::cerr;

    try
    {
        using std::string;
        using std::cout;
        using std::cin;
        using std::ifstream;
        using std::ofstream;
        using std::hex;
        using std::setw;
        using std::setfill;

        const int nchar = 2 * sizeof(int); // 8 bytes (64 bits)
        const int kchar = 2 * nchar; // 16 bytes (128 bits)

        string op;
        string key;
        string infile;
        string outfile;

        cout << "Please enter:\n"
            << "1) file to encrypt\n"
            << "2) output file name\n"
            << "3) encryption key\n";

        cin >> infile >> outfile >> key;

        while (key.size() < kchar)
            key += '0'; // pad key

        // initialize input and output file streams
        ifstream in_fs {infile.c_str()};
        ofstream out_fs {outfile.c_str()};

        if (!(in_fs && out_fs))
            error("bad file name");

        unsigned int const* k =
            reinterpret_cast<unsigned int const*>(key.data());

        unsigned int outptr[2];
        char inbuf[nchar];

        unsigned int *inptr = reinterpret_cast<unsigned int*>(inbuf);

        // read file, encrypt contents, write encrypted contents to output file
        size_t count = 0;
        while (in_fs.get(inbuf[count]))
        {
            out_fs << hex;
            if (++count == nchar)
            {
                TEA::encrypt(inptr, outptr, k);
                // pad with leading zeros
                out_fs << setw(8) << setfill('0') << outptr[0] << ' '
                    << setw(8) << setfill('0') << outptr[1] << ' ';
                count = 0;
            }
        }

        if (count) // pad
        {
            while (count != nchar)
                inbuf[count++] = '0';
            TEA::encrypt(inptr, outptr, k);
            out_fs << outptr[0] << ' ' << outptr[1] << ' ';
        }
    }
    catch (exception& ex)
    {
        cerr << "error: " << ex.what() << '\n';
        return 1;
    }
    catch (...)
    {
        cerr << "Unknown exception!\n";
        return 2;
    }

    return 0;
}
