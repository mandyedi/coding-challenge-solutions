/* http://www.cstutoringcenter.com
 *
 * Problem 6 solution
 * Problem: Given the following function and it's results:
 *
 *          f(x,y) = x^y + y^x where x>0 and y>1
 *              f(1,2) = 1^2 + 2^1 = 3
 *              f(2,3) = 2^3 + 3^2 = 17
 *              f(3,4) = 3^4 + 4^3 = 145
 *                      .
 *                      .
 *                      .
 *
 *          Using the above function denoted by f(x,y),
 *          and given that the initial values of x = 1 and y = 2,
 *          which increase by 1 each time,
 *          what are the last 4 digits of the sum of the first 15 function calls.
 *
 * author:  mandyedi
 * contact: mandyedi@gmail.com
 */

#include <iostream>
#include <math.h>

using namespace std;

double func(int x, int y)
{
    if(x <= 0)
        x = 1;
    if(y <= 1)
        y = 2;

    return pow(x, y) + pow(y, x);
}

int main()
{
    double sum = 0;
    cout.precision(25);

    for(int i=1; i<=16; i++)
    {
        cout << "x: " << i << " y: " << i+1 << " ";
        sum += func(i, i+1);
        cout << sum << endl;
    }

    cout << sum;

    return 0;
}
