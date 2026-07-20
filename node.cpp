#include "node.hpp"

Node::Node(string name, char type){
    this -> name = name;
    this -> type = type;
    this -> parent = nullptr;
}

Node::~Node(){
    for (Node* child : children){
        delete child;
    }
    children.clear();
}

void Node::addChild(Node* child){
    child -> setParent(this); // sets the node itself as the parent node
    children.push_back(child);
}

void Node::addChild(string name, char type){
    Node* child = new Node(name, type);
    child -> setParent(this);
    children.push_back(child);
}


// helper function (recursive)
void Node::removeHelper(Node* node){ 
    // iterates over the children vector and recurisvely delets any child nodes found

    for (Node* child : node -> getChildren()){
        removeHelper(child); // recursively delete the node's children
        delete child; // delete each child node
    }
    node -> getChildren().clear();
}


bool Node::removeChild(string name){
    for (int i = 0; i < children.size(); i++){
        if (children[i] -> getName() == name){
            removeHelper(children[i]); // delete all the node's descendants
            delete children[i]; // delete the node itself
            children.erase(children.begin() + i); // [5]
            return true;
        }
    }
    return false;
}

void Node::setParent(Node* parent){
    this -> parent = parent;
}

void Node::setType(char type){
    this -> type = type;
}

void Node::setName(string name){
    this -> name = name;
}

Node* Node::getChild(string name){
    for (int i =0; i < children.size(); i++){
        if (children[i] -> getName() == name){
            return children[i];
        }
    }
    return nullptr;
}

const vector<Node*>& Node::getChildren() const {
    return this -> children;
}

vector<Node*>& Node::getChildren(){
    return this -> children;
}

Node* Node::getParent(){
    return this -> parent;
}

char Node::getType(){
    return this -> type;
}
    

string Node::getName() {
    return this -> name;
}

/*
[4] Deleting a pointer element from a pointer vector
    https://cplusplus.com/forum/general/54905/

[5] Erase method
    https://www.geeksforgeeks.org/vector-erase-in-cpp-stl/
*/