#include "filesystem.hpp"

FileSystem::FileSystem(){
    this -> root = new Node("root", 'd');
    this -> currentDirectory = root;
}

FileSystem::~FileSystem(){
    delete root;
}

// void FileSystem::addNode(Node* ){
//     // BST insert zybooks
// }

// Node* FileSystem::findNode(string name){
//     // BST search algorithm from zybooks

// }

string FileSystem::mkdir(string name) {
    for (int i = 0; i < currentDirectory->getChildren().size(); i++) {
        if (currentDirectory->getChildren()[i]->getName() == name) {
            return "Error: " + name + " exists";
        }
    }
    Node* child = new Node(name, 'd');
    currentDirectory->addChild(child);
    return "directory " + name + " created successfully";
}

string FileSystem::touch(string name){
    // Inserts a child node of type 'f' into the current directory's children vector 
    
    for (int i = 0; i < currentDirectory -> getChildren().size(); i++){
        if (currentDirectory -> getChildren()[i] -> getName() == name){
            return "Error: " + name + " exists";
        }
    }
    Node* child = new Node(name, 'f');
    currentDirectory -> addChild(child);
    return "file " + name + " created successfully";
}

string FileSystem::pwd() {
    string presentWorkingDirectory;
    vector<string> pathComponents;
    Node* temp = currentDirectory;

    while (temp != nullptr) {
        pathComponents.push_back(temp->getName());
        temp = temp->getParent();
    }

    // Construct the path from root to current
    for (int i = pathComponents.size() - 1; i >= 0; i--) {
        presentWorkingDirectory += "/" + pathComponents[i];
    }

    return presentWorkingDirectory.empty() ? "/" : presentWorkingDirectory; // [5]
}

string FileSystem::ls() {
    string lsOutput;
    if (currentDirectory->getChildren().empty()) {
        return "";  // No children
    } 
    else {
        for (int i = 0; i < currentDirectory->getChildren().size(); i++) {
            string t(1,currentDirectory->getChildren()[i]->getType()); // [7]
            string n = currentDirectory->getChildren()[i]->getName();
            lsOutput += t + " " + n + "\n";
        }
    }
    return lsOutput;
}

string FileSystem::rm(string name){
    if (currentDirectory -> removeChild(name)){
        return name + " removed successfully";
    }
    return "No such file or directory";
}

string FileSystem::mv(string from, string to){
    for (Node* child : currentDirectory -> getChildren()){
        if (child -> getName() == from){
            child -> setName(to);
            return "file/dir renamed successfully";
        }
    }
    return "file not found";
}

string FileSystem::cd(string dirname){
    if (dirname == ".."){
        if (currentDirectory -> getParent() != nullptr){
            currentDirectory = currentDirectory -> getParent();
            return pwd();
        }
        else{
            return "can't change to directory " + dirname;
        }
    }

    for (Node* child : currentDirectory -> getChildren()){
        if (child -> getName() == dirname && child -> getType() == 'd'){
            currentDirectory = child;
            return pwd();
        }
        else if (child -> getName() == dirname && child -> getType() == 'f'){
            return dirname + ": is not a directory";
        }
    }
    return dirname + ": no such directory";
}

/*
[6] Character to string conversion
    https://www.geeksforgeeks.org/how-to-convert-a-single-character-to-string-in-cpp/

[7] Ternary operator
    https://www.w3schools.com/cpp/cpp_conditions_shorthand.asp
*/