/* http://www.cstutoringcenter.com
 *
 * Problem 5 solution
 * Problem: a = 26, b = 25, c = 24, d = 23 ..... x = 3, y = 2, z = 1
 *          What is the sum of each letter of this sentence: "The quick brown fox jumped over the cow"?
 *          (Note, a white space has no value).
 *
 * author:  mandyedi
 * contact: mandyedi@gmail.com
 */

#include <iostream>

using namespace std;

int main()
{
    string s = "thequickbrownfoxjumpedoverthecow";
    int sum = 0;

    for(int i=0; i<s.size(); i++)
    {
        sum += ((int)s[i] - 123) * (-1);
    }

    cout << sum;

    return 0;
}
