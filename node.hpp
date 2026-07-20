#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Node{
    private:
        char type; 
        string name;
        vector<Node*> children; // a node will contain an arbitrary number of children
        Node* parent;

        void removeHelper(Node* node);

    public:
        Node() = default;
        Node(string name, char type);
        ~Node();

        void addChild(Node* child); // [3]
        void addChild(string name, char type);
        bool removeChild(string name);

        void setParent(Node* parent);
        void setType(char type);
        void setName(string name);

        Node* getChild(string name);
        const vector<Node*>& getChildren() const; // read-only access
        vector<Node*>& getChildren(); // for modification
        Node* getParent();
        char getType();
        string getName();
};

#endif

/*
[3] Unique Pointer Tutorials (for future use)
    https://www.learncpp.com/cpp-tutorial/stdunique_ptr/
    https://www.geeksforgeeks.org/smart-pointers-cpp/
*/