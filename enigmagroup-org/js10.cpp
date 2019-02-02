#include <iostream>

using namespace std;

void Check(string entry)
{
    string charlist = "abcdefghijklmnopqrstuvwxyz";
    int n = 4;
    double total = 0;

    for(int i=0; i<n; i++)
    {
        string countone[0] = entry[i];
        int counttwo = charlist.find(countone[0]);
        counttwo++;
        total *= 17;
        total += counttwo;
    }
    //if(total == 248410397744610)
        cout << total << endl;

}

int main()
{

    string str = "abcdefghijklmnopqrstuvwxyz";
    int ln = str.size();
    string c0 ="";
    string c1 ="";
    string c2 ="";
    string c3 ="";
    string c4 ="";

    for(int a=0; a<ln; a++){
    for(int b=0; b<ln; b++){
    for(int c=0; c<ln; c++){
    for(int d=0; d<ln; d++){
    for(int e=0; e<ln; e++){
    c0.assign(str.substr(a,1));
    c1.assign(str.substr(b,1));
    c2.assign(str.substr(c,1));
    c3.assign(str.substr(d,1));
    c4.assign(str.substr(e,1));
    Check(c0+c1+c2+c3+c4);
    //cout << c0 + c1 + c2 + c3 + c4 << endl;
    }}}}}
    return 0;
}
