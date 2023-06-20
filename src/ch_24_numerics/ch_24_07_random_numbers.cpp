// program demonstrates how to use a random number engine with a distribution
// object to generate random numbers

#include <functional> // for bind<>
#include <random> // for normal_distribution<>, default_random_engine
#include <vector> // for vector
#include <iostream> // for cout

// returns a random int b/t 0 and max
int rand_int(int max);

// returns a random int b/t min and max
int rand_int(int min, int max);

int main()
{
    using std::bind;
    using std::normal_distribution;
    using std::default_random_engine;
    using std::vector;
    using std::cout;

    // bind a normal distribution of doubles with mean 15 and standard
    // deviation for to a random number generator
    // NOTE: bind<> returns a function object that calls the function passed to
    // its first argument with the subsequent arguments
    auto gen = bind(normal_distribution<double> {15, 4.0},
                    default_random_engine { });

    // consruct a histogram using gen()
    vector<int> hist(2 * 15);
    for (size_t i = 0; i < 500; i++) // 500 samples
        ++hist[size_t(round(gen()))]; // increase count at corresponding index

    // output histogram
    for (size_t i = 0; i < hist.size(); i++)
    {
        cout << i << '\t';
        for (int j = 0; j < hist[i]; j++)
            cout << '*';
        cout << '\n';
    }
    cout << '\n';

    // construct a histogram using rand_int()
    vector<int> hist2(2 * 15);
    for (size_t i = 0; i < 500; i++)
        ++hist2[size_t(rand_int(0, 30))];

    // output histogram
    for (size_t i = 0; i < hist2.size(); i++)
    {
        cout << i << '\t';
        for (int j = 0; j < hist2[i]; j++)
            cout << '*';
        cout << '\n';
    }

    return 0;
}

// returns a random int b/t min and max
int rand_int(int min, int max)
{
    static std::default_random_engine ran; // maintains state
    return std::uniform_int_distribution<> {min, max}(ran);
}

// returns a random int b/t 0 and max
int rand_int(int max)
{
    return rand_int(0, max);
}
