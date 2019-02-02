#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

struct Attribute{
    string Name;
    string Value;
};

struct Tag{
    string Name;
    vector<Attribute> Attributes;
    vector<Tag*> Children;
};

bool isOpenTag(const string &line){
    return line[1] != '/';
}

//0  3   7    12   17 20 23   28
//<b value = "BadVal" size = "10">
void getTagData(const string &line, string &name, vector<Attribute> &attributes){
    size_t emptyPos = line.find_first_of(" ");
    name = line.substr(1, emptyPos - 1);

    size_t equalPos = line.find_first_of("=");
    size_t lastPos = emptyPos;
    while ( equalPos != string::npos){
        Attribute attribute;
        size_t nameStartPos = line.find_first_of(" ", lastPos) + 1;
        size_t nameEndPos = line.find_first_of(" ", nameStartPos );
        attribute.Name = line.substr(nameStartPos, nameEndPos - nameStartPos);
        size_t valueStartPos = line.find_first_of("\"", nameEndPos) + 1;
        size_t valueEndPos = line.find_first_of("\"", valueStartPos);
        attribute.Value = line.substr(valueStartPos, valueEndPos - valueStartPos);
        attributes.push_back(attribute);

        lastPos = valueEndPos - 1;
        equalPos = line.find_first_of("=", equalPos + 1);
    }
}

stack<Tag*> lastTags;
Tag *rootTag;
void createTagTree(vector<string> &lines){
    for(unsigned int i = 0; i < lines.size(); i++){
        string &line = lines[i];
        if(isOpenTag(line)){
            string name;
            vector<Attribute> attributes;
            getTagData(line, name, attributes);

            if (!lastTags.empty()){
                Tag *tag = new Tag;
                tag->Name = name;
                tag->Attributes = attributes;
                Tag *lastTag = lastTags.top();
                lastTag->Children.push_back(tag);
                lastTags.push(tag);
            } else {
                rootTag = new Tag;
                rootTag->Name = name;
                rootTag->Attributes = attributes;
                lastTags.push(rootTag);
            }
        } else {
            lastTags.pop();
        }
    }
}

int main()
{
    vector<string> lines;
    lines.push_back("<a value = \"GoodVal\">");
    lines.push_back("<b value = \"BadVal\" size = \"10\">");
    lines.push_back("</b>");
    lines.push_back("<c height = \"auto\">");
    lines.push_back("<d size = \"3\">");
    lines.push_back("<e strength = \"2\">");
    lines.push_back("</e>");
    lines.push_back("</d>");
    lines.push_back("</c>");
    lines.push_back("</a>");

    createTagTree(lines);

/*
<a value = "GoodVal">
  <b value = "BadVal" size = "10">
  </b>
  <c height = "auto">
    <d size = "3">
      <e strength = "2">
      </e>
    </d>
  </c>
</a>
*/
    std::cout << "\n";
    return 0;
}