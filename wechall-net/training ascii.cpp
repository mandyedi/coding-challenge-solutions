#include <iostream>


using namespace std;

int main()
{
    int v[] = {84, 104, 101, 32, 115, 111, 108, 117, 116, 105, 111, 110, 32, 105, 115, 58, 32, 104, 110, 97, 112, 104, 111, 101, 109, 111, 111, 98, 114};

    int n = sizeof(v)/sizeof(v[0]);

    for(int i=0; i<n; i++)
    {
        cout << (char)v[i];
    }

    return 0;
}
