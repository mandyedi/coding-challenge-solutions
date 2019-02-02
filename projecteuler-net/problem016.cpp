/**
 * Project Euler Problem 21
 */

#include <iostream>

using namespace std;

// Sum of proper divisers of n
void d(unsigned int &n, unsigned int &sum)
{
    if(sum != 0)
    {
        sum = 0;
    }
    for(int i=1; i<n; i++)
    {
        if(n%i == 0)
        {
            sum += i;
        }
    }
}

int main()
{
    unsigned int aSum = 0;
    unsigned int bSum = 0;
    unsigned int sum  = 0;
    for(unsigned int a=2; a<10000; a++)
    {
        d(a, aSum);
        d(aSum, bSum);
        if(a == bSum && a != aSum)
        {
            cout << a << endl;
            sum += a;
        }
    }
    cout << sum;
    return 0;
}
