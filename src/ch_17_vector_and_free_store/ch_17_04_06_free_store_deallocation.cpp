// program implements a function that returns a pointer to a dynamically
// allocated result and leaves the responsibility of deallocating it to the
// caller

// function that returns a dynamically allocated result... user must remember to
// deallocate when done and be careful to avoid double frees and improper access
double *calc(int res_size, int max);

int main()
{
    double *r = calc(100, 1000);
    delete[] r; // return memory allocated for calc()'s return value

    return 0;
}

double *calc(int res_size, int max)
{
    double *p = new double[max]; // dynamically allocate an array of max doubles

    // dynamically allocate an array of res_size doubles
    double *res = new double[res_size];

    // use p to calcualte results to be stored in res...

    delete[] p; // release memory allocated for p
 
    return res; // return result... caller needs to deallocate
}
