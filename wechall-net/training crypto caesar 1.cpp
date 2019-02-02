#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    bool toFile = false;
    string s2 = "BPM YCQKS JZWEV NWF RCUXA WDMZ BPM TIHG LWO WN KIMAIZ IVL GWCZ CVQYCM AWTCBQWV QA TMLXOMLTIZLA";
    string s = "BPMYCQKSJZWEVNWFRCUXAWDMZBPMTIHGLWOWNKIMAIZIVLGWCZCVQYCMAWTCBQWVQATMLXOMLTIZLA";

    char c[s.size()];
    int minShift = -1;
    int maxShift = 58;

    if(toFile)
    {
        ofstream file ("solution.txt");

        for(int i=minShift; i<maxShift; i++)
        {
            file << i << ". shift: ";
            for(int j=0; j<s.size(); j++)
            {
                file << (char)(s[j]+i);
            }
            file << endl;
        }

        file.close();
    }

    else
    {
        for(int i=minShift; i<maxShift; i++)
        {
            cout << i << ". shift: ";
            for(int j=0; j<s.size(); j++)
            {
                cout << (char)(s[j]+i);
            }
            cout << endl;
        }
    }

    cout << "done";

    return 0;
}
