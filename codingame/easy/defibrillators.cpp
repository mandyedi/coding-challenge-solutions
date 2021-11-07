/*
Title: Defibrillators
Tags: easy, loops, distances, trigonometry
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>

using namespace std;

float getDegreeFromString( string &s ) {
    size_t pos = s.find_first_of( "," );
    s = s.replace( pos, 1, "." );
    return stof( s );
}

float getDistance( float latA, float lonA, float latB, float lonB ) {
    float x = ( lonB - lonA ) * cos( ( latA + latB ) / 2.0f );
    float y = latB - latA;
    return sqrtf( x * x + y * y ) * 6371.0f;
}

struct Def {
    int identifier;
    string name;
    string address;
    string phone;
    float lon;
    float lat;
};

int main()
{
    string LON;
    cin >> LON; cin.ignore();
    float userLon = getDegreeFromString( LON );
    cerr << "User lon " << userLon << endl;

    string LAT;
    cin >> LAT; cin.ignore();
    float userLat = getDegreeFromString( LAT );
    cerr << "User lat " << userLat << endl;

    int N;
    cin >> N; cin.ignore();
    vector<Def> defibrillators;
    defibrillators.reserve( N );
    for (int i = 0; i < N; i++) {
        string DEFIB;
        getline(cin, DEFIB);
        std::istringstream ss(DEFIB);
        vector<string> tokens;
        string token;
        while(std::getline(ss, token, ';')) {
            tokens.push_back( token );
        }
        Def d;
        d.identifier = atoi( tokens[0].c_str() );
        d.name = tokens[1];
        d.address = tokens[2];
        d.phone = tokens[3];
        d.lon = getDegreeFromString( tokens[4] );
        d.lat = getDegreeFromString( tokens[5] );
        defibrillators.push_back( d );
    }

    float minDistance = getDistance( userLat, userLon, defibrillators[0].lat, defibrillators[0].lon );
    int minIndex = 0;

    for ( int i = 1; i < N; i++ ) {
        float distance = getDistance( userLat, userLon, defibrillators[i].lat, defibrillators[i].lon );
        if ( minDistance > distance ) {
            minDistance = distance;
            minIndex = i;
        }
    }

    cout << defibrillators[minIndex].name << endl;
}
