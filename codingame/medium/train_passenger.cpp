/*
Title: Train Passenger
Tags: medium, pathfinding, bfs, graphs
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <list>

using namespace std;

class Node {
public:
    Node(const string &name) : Name(name), Visited(false), Previous(nullptr) {}

    string Name;
    bool Visited;
    vector<Node*> Neighbours;
    Node *Previous;
};

void printPath(Node *end) {
    list<Node*> path;
    Node *node = end;
    while (node != nullptr) {
        path.push_front(node);
        node = node->Previous;
    }

    for (Node *node : path) {
        cout << node->Name;
        if (node == end) {
            cout << endl;
        }
        else {
            cout << " > ";
        }
    }
}

void shortestPath(Node *start, Node *end) {
    queue<Node*> q;
    bool foundEnd = false;
    start->Visited = true;
    q.push(start);

    while (!q.empty() && !foundEnd) {
        Node *currentNode = q.front();
        q.pop();

        for (Node *node : currentNode->Neighbours) {
            if (!node->Visited) {
                node->Visited = true;
                q.push(node);
                node->Previous = currentNode;
                if (node == end) {
                    foundEnd = true;
                    break;
                }
            }
        }
    }
}

int main()
{
    unordered_map<string, Node*> nodes;

    string start;
    getline(cin, start);
    string end;
    getline(cin, end);
    int n;
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        string station_1;
        string station_2;
        cin >> station_1 >> station_2; cin.ignore();

        Node *node_1 = nullptr;
        Node *node_2 = nullptr;

        unordered_map<string, Node*>::iterator it = nodes.find(station_1);
        if (it == nodes.end()) {
            node_1 = new Node(station_1);
            nodes[station_1] = node_1;
        }
        else {
            node_1 = it->second;
        }

        it = nodes.find(station_2);
        if (it == nodes.end()) {
            node_2 = new Node(station_2);
            nodes[station_2] = node_2;
        }
        else {
            node_2 = it->second;
        }

        node_1->Neighbours.push_back(node_2);
        node_2->Neighbours.push_back(node_1);
    }

    for (auto item : nodes) {
        cerr << item.first << ": ";
        for (Node *neighbour : item.second->Neighbours) {
            cerr << neighbour->Name << " ";
        }
        cerr << endl;
    }

    shortestPath(nodes[start], nodes[end]);

    printPath(nodes[end]);

    auto item = nodes.begin();
    while (item != nodes.end()) {
        delete item->second;
        item = nodes.erase(item);
    }
}
