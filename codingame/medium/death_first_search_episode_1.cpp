/*
Title: Death First Search - Episode 1
Tags: medium, bfs, graphs
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    struct Node  {
        int index;
        bool isExit;
        Node *next;
    };
    Node *nodes = nullptr;

    int N; // the total number of nodes in the level, including the gateways
    int L; // the number of links
    int E; // the number of exit gateways
    cin >> N >> L >> E; cin.ignore();
    cerr << "N: " << N << endl;
    cerr << "L: " << L << endl;
    nodes = new Node[N];
    for ( int i = 0; i < N; i++ ) {
        nodes[i].index = i;
        nodes[i].next  = nullptr;
    }
    for (int i = 0; i < L; i++) {
        int N1; // N1 and N2 defines a link between these nodes
        int N2;
        cin >> N1 >> N2; cin.ignore();

        // Edge N1 -> N2
        Node *node1 = &nodes[N1];
        while( node1->next ) {
            node1 = node1->next;
        }
        Node *node2new = new Node;
        node2new->index = N2;
        node2new->next = nullptr;
        node1->next = node2new;

        // Edge N2 -> N1
        Node *node2 = &nodes[N2];
        while( node2->next ) {
            node2 = node2->next;
        }
        Node *node1new = new Node;
        node1new->index = N1;
        node1new->next = nullptr;
        node2->next = node1new;
    }
    for (int i = 0; i < E; i++) {
        int EI; // the index of a gateway node
        cin >> EI; cin.ignore();
        nodes[EI].isExit = true;
    }

    // Print graph
    // cerr << "Graph:" << endl;
    // for (int i = 0; i < N; i++) {
    //     cerr << nodes[i].index << ". node - exit: " << nodes[i].isExit << endl;
    //     cerr << "  next nodes: ";
    //     Node *next = nodes[i].next;
    //     while ( next ) {
    //         cerr <<  next->index << " ";
    //         next = next->next;
    //     }
    //     cerr << endl;
    // }

    // game loop
    cerr << "\nGame loop:\n\n";
    while (1) {
        int SI; // The index of the node on which the Skynet agent is positioned this turn
        cin >> SI; cin.ignore();
        cerr << "Agent node: " << SI << endl;
        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;

        // Block edge if it is between the agent and an exit
        Node *next = nodes[SI].next;
        cerr << "SI index " << nodes[SI].index << endl;
        bool isNextExit = false;
        while ( next ) {
            cerr << "SI next index " << next->index;
            cerr << " is exit " << nodes[next->index].isExit << endl;
            if ( nodes[next->index].isExit ) {
                isNextExit = true;
                cout << SI << " " << next->index << endl;
                break;
            }
            next = next->next;
        }

        if ( !isNextExit ) {
            cout << SI << " " << nodes[SI].next->index << endl; // Example: 0 1 are the indices of the nodes you wish to sever the link between
        }
    }
}
