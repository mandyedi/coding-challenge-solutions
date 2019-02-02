/* http://www.cstutoringcenter.com
 *
 * Problem 2 solution
 * Problem: As an example, the sum of the digits of 2 to the 10th power is:
 *          2^10 = 1024  => 1+0+2+4 => 7
 *          What is the sum of the digits of 2^50?
 *
 * author:  mandyedi
 * contact: mandyedi@gmail.com
 */

#include <iostream>
#include <math.h>

using namespace std;

/* Calculate number of digits of double
 */
int doubleLength(double number)
{
    int length = 0;

    while(1)
    {
        if(number > pow(10,length))
            length++;
        else
            return length;
    }

    return 0;
}

/* Convert digits of double to array of integer
 *
 * parameter number: The double number we want to convert to array of ints
 * parameter length: Number of digits of number
 * parameter array:  Pointer to an int array. Digits will put into this.
 */
void doubleToIntArray(double number, int length, int *array)
{
    for(int i=0; i<length; i++)
    {
        if(i == 0)
        {
            array[i] = (int)(number/ pow(10, length-1));
        }
        else
        {
            // shift not the perfect name, but if you understand the algorithm, the use of shift will be clear
            double shift = pow(10, (length-i));

            array[i] = (number - (floor(number/shift) * shift)) / (shift/10);
        }
    }

/*
    First I wrote the algorithm of getting the number's digits line by line.
    The test number is 8352.
    The algorithm above was wrote based on this:

    cout << "0. num: " <<         floor(8352/1000)                 << endl;
    cout << "1. num: " << (8352 - floor(8352/1000) * 1000) / 100   << endl;
    cout << "2. num: " << (8352 - floor(8352/100 ) * 100)  / 10    << endl;
    cout << "3. num: " << (8352 - floor(8352/10  ) * 10)   / 1     << endl;
*/
}

int main()
{
    double x = 1;       // variable for result of 2^50
    int length;         // length of x
    int *array;         // digits of x
    int sum = 0;        // sum of digits
    cout.precision(20); // set the precision of printing double

    // calculate 2^50
    for(int i=1; i<=50; i++)
    {
        x *= 2;
    }

    length = doubleLength(x);
    array = new int[length];

    doubleToIntArray(x, length, array);

    cout << "2^50 = " << x << endl;

    for(int i=0; i<length; i++)
    {
        sum += array[i];
    }

    cout << "sum of the digits of 2^50 = " << sum;

    delete[] array;

    return 0;
}
