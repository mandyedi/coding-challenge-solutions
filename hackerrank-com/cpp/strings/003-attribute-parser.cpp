#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

struct Attribute {
    string Name;
    string Value;
};

struct Tag {
    string Name;
    int Level;
    vector<Attribute> Attributes;
    vector<Tag *> Children;
};

bool isOpenTag( const string &line ) {
    return line[1] != '/';
}

void getTagData( const string &line, string &name, vector<Attribute> &attributes ) {
    size_t closePos = line.find_first_of( " " );
    if ( closePos == string::npos ) {
        closePos = line.find_first_of( ">" );
    }
    name = line.substr( 1, closePos - 1 );

    size_t equalPos = line.find_first_of( "=" );
    size_t lastPos = closePos;
    while ( equalPos != string::npos ) {
        Attribute attribute;
        size_t nameStartPos = line.find_first_of( " ", lastPos ) + 1;
        size_t nameEndPos = line.find_first_of( " ", nameStartPos );
        attribute.Name = line.substr( nameStartPos, nameEndPos - nameStartPos );
        size_t valueStartPos = line.find_first_of( "\"", nameEndPos ) + 1;
        size_t valueEndPos = line.find_first_of( "\"", valueStartPos );
        attribute.Value = line.substr( valueStartPos, valueEndPos - valueStartPos );
        attributes.push_back( attribute );

        lastPos = valueEndPos - 1;
        equalPos = line.find_first_of( "=", equalPos + 1 );
    }
}

void createTagTree( Tag *&rootTag, vector<string> &lines ) {
    stack<Tag *> lastTags;
    rootTag = new Tag;
    rootTag->Name = "Root";
    rootTag->Level = 0;
    for ( unsigned int i = 0; i < lines.size(); i++ ) {
        string &line = lines[i];
        if ( isOpenTag( line ) ) {
            string name;
            vector<Attribute> attributes;
            getTagData( line, name, attributes );

            if ( !lastTags.empty() ) {
                Tag *lastTag = lastTags.top();
                Tag *tag = new Tag;
                tag->Name = name;
                tag->Level = lastTag->Level + 1;
                tag->Attributes = attributes;
                lastTag->Children.push_back( tag );
                lastTags.push( tag );
            }
            else {
                Tag *tag = new Tag;
                tag->Name = name;
                tag->Level = 0;
                tag->Attributes = attributes;
                rootTag->Children.push_back( tag );
                lastTags.push( rootTag );
            }
        }
        else {
            lastTags.pop();
        }
    }
}

void checkQuery( Tag *rootTag, vector<string> &tagNames, string &attributeName, string &query ) {
    queue<Tag *> q;
    q.push( rootTag );

    vector<bool> valid( tagNames.size(), false );

    Tag *lastValidTag = nullptr;
    while ( !q.empty() ) {
        Tag *tag = q.front();
        q.pop();
        //cerr << tag->Name << " " << tag->Level << endl;

        int level = tag->Level;
        //bool valid = false;
        if ( level < tagNames.size() ) {
            if ( tagNames[level].compare( tag->Name ) == 0 ) {
                valid[level] = true;
                lastValidTag = tag;
            }
        }

        if ( tag->Children.size() > 0 ) {
            for ( unsigned int i = 0; i < tag->Children.size(); i++ ) {
                q.push( tag->Children[i] );
            }
        }
    }

    bool allValid = true;
    for ( int i = 0; i < tagNames.size(); i++ ) {
        //cerr << valid[i] << " ";
        if ( valid[i] == false ) {
            allValid = false;
            break;
        }
    }

    if ( allValid ) {
        vector<Attribute> &attributes = lastValidTag->Attributes;
        bool validAttribute = false;
        for ( int i = 0; i < attributes.size(); i++ ) {
            if ( attributes[i].Name.compare( attributeName ) == 0 ) {
                validAttribute = true;
                cout << attributes[i].Value << endl;
            }
        }
        if ( validAttribute == false ) {
            cout << "Not Found!\n";
        }

        //cerr << query << " last tag: " << lastValidTag->Name << endl;
    }
    else {
        cout << "Not Found!\n";
    }
}

void printTagTree( Tag *rootTag )
{
    queue<Tag*> q;
    q.push( rootTag );

    while ( !q.empty() )
    {
        Tag *tag = q.front();
        q.pop();

        for ( int i = 0; i < tag->Level; i++ )
        {
            cout << " ";
        }
        cout << tag->Name << " ";
        for ( auto &atr : tag->Attributes )
        {
            cout << atr.Name << "=" << atr.Value << " ";
        }
        cout << "\n";

        for ( auto child : tag->Children )
        {
            q.push( child );
        }
    }
}

void releaseMemory( Tag *rootTag )
{
    queue<Tag *> q;
    q.push( rootTag );

    while ( !q.empty() )
    {
        Tag *tag = q.front();
        q.pop();

        for ( auto child : tag->Children )
        {
            q.push( child );
        }

        delete tag;
    }
}

int main()
{
    int n, q;
    cin >> n; cin >> q;
    cin.ignore( 256, '\n' );

    vector<string> lines( n );
    for ( int i = 0; i < n; i++ ) {
        getline( cin, lines[i] );
    }

    Tag *rootTag = nullptr;

    createTagTree( rootTag, lines );

    //printTagTree();

    string qr;
    for ( int i = 0; i < q; i++ ) {
        getline( cin, qr );

        vector<string> tagNames;
        size_t pos = 0, prevPos = 0;
        while ( (pos = qr.find_first_of( ".", pos )) != string::npos ) {
            tagNames.push_back( qr.substr( prevPos, pos - prevPos ) );
            prevPos = ++pos;
        }
        size_t posAttr = qr.find( "~" );
        tagNames.push_back( qr.substr( prevPos, posAttr - prevPos ) );

        string attributeName = qr.substr( posAttr + 1, qr.size() - posAttr - 1 );

        checkQuery( rootTag, tagNames, attributeName, qr );
    }

    releaseMemory( rootTag );

    return 0;
}
