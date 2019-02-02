#include <iostream>
#include <fstream>

using namespace std;

/*
turn off 660,55 through 986,197
turn off 341,304 through 638,850
turn off 199,133 through 461,193
toggle 322,558 through 977,958
toggle 537,781 through 687,941
turn on 226,196 through 599,390
*/

int main(int argc, char **argv)
{
    std::ifstream infile("006.txt");
    std::string line;

    int **lights = new int*[1000];
    for(int i = 0; i < 1000; i++)
        lights[i] = new int[1000];

    for( int i = 0; i < 1000; i++ )
    {
        for( int j = 0; j < 1000; j++ )
        {
            lights[i][j] = 0;
        }
    }

    for (int i = 0; i < 1000; ++i)
    {
        for (int j = 0; j < 1000; ++j)
        {   
            lights[i][j] = 0;
        }
    }

    while (std::getline(infile, line))
    {
        int startX, startY, endX, endY;
        if ( line.find("on") != string::npos)
        {
            std::sscanf(line.c_str(), "turn on %d,%d through %d,%d", &startX, &startY, &endX, &endY);
            for (int i = startX; i <= endX; ++i)
            {
                for (int j = startY; j <= endY; ++j)
                {   
                    lights[i][j] += 1;
                }
            }
        }
        else if ( line.find("off") != string::npos)
        {
            std::sscanf(line.c_str(), "turn off %d,%d through %d,%d", &startX, &startY, &endX, &endY);
            for (int i = startX; i <= endX; ++i)
            {
                for (int j = startY; j <= endY; ++j)
                {   
                    lights[i][j] -= 1;
                    if ( lights[i][j] < 0)
                    {
                        lights[i][j] = 0;
                    }
                }
            }
        }
        else if ( line.find("toggle") != string::npos)
        {
            std::sscanf(line.c_str(), "toggle %d,%d through %d,%d", &startX, &startY, &endX, &endY);
            for (int i = startX; i <= endX; ++i)
            {
                for (int j = startY; j <= endY; ++j)
                {   
                    lights[i][j] += 2;
                }
            }
        }  
    }

    int on = 0;
    for (int i = 0; i < 1000; ++i)
    {
        for (int j = 0; j < 1000; ++j)
        {   
            on += lights[i][j];
        }
    }

    cout << on << endl;

    infile.close();

    for(int i = 0; i < 1000; i++)
    {
        delete [] lights[i];
    }
    delete [] lights;

    return 0;
}