// program demonstrates how to decrypt a file that was previous encrypted
// with the Tiny Encryption Algorithm and a user provided key

#include <encryption_utils/tiny_encryption_algorithm.hpp> // for decrypt()
#include <exception> // for exception
#include <iostream> // for cin, cout, cerr
#include <string> // for string
#include <fstream> // for ifstream, ofstream
#include <ios> // for ios_base::hex, ios_base::basefield
#include <cpp_facilities/std_lib_facilities.hpp> // for error()

int main()
{
    using std::exception;
    using std::cerr;
    using std::string;
    using std::cout;
    using std::cin;
    using std::ifstream;
    using std::ofstream;
    using std::ios_base;

    try
    {
        const int nchar = 2 * sizeof(int); // 8 bytes (64 bits)
        const int kchar = 2 * nchar; // 16 bytes (128 bits)

        string op;
        string key;
        string infile;
        string outfile;

        cout << "Please enter:\n"
            << "1) file to decrypt\n"
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

        unsigned int inptr[2];
        char outbuf[nchar + 1];
        outbuf[nchar] = '\0';

        unsigned int *outptr = reinterpret_cast<unsigned int*>(outbuf);

        in_fs.setf(ios_base::hex, ios_base::basefield);

        // read encrypted file, decrypt contents, write decrypted contents to
        // output file
        while (in_fs >> inptr[0] >> inptr[1])
        {
            TEA::decrypt(inptr, outptr, k);
            out_fs << outbuf;
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
