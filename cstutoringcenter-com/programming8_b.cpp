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
    int array[53] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241};
    int sum = 0;

    for(int i=0; i<53; i++)
    {
        sum += array[i];
    }

    cout << sum;

    return 0;
}
