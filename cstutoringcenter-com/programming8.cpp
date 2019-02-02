/* http://www.cstutoringcenter.com
 *
 * Problem 8 solution
 * Problem: What is the sum of the first 250 prime numbers?
 *
 *
 * author:  mandyedi
 * contact: mandyedi@gmail.com
 */

#include <iostream>

using namespace std;


int main()
{
    int sum = 5;

    for(int i=4; i<=250; i++)
    {
        bool prime = true;
        for(int j=2; j<i-1; j++)
        {
            if(i % j == 0)
            prime = false;
        }

        if(prime)
        {
            sum += i;
        }
    }

    cout << "sum of the first 250 prime numbers: " << sum;

    return 0;
}
