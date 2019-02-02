/* http://www.cstutoringcenter.com
 * Problem 1 solution
 * Problem: What is the sum of the first 15 factorials, NOT INCLUDING 0!?
 * @author: mandyedi
 */

#include <iostream>

using namespace std;

double factorial(double n)
{
    if(n == 0)
        return 1;
    else
        return n * factorial(n-1);
}

int main()
{
    double sum = 0;
    for(int i=1; i<=15; i++)
    {
        cout << i << ". factorial: " << factorial(i) << endl;
        sum += factorial(i);
    }

    cout.precision(20);
    cout << endl << endl << sum;

    return 0;
}
