#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include "node.hpp"

class FileSystem {
    private:
        Node* root;
        Node* currentDirectory;
        void addNode(Node*);
        Node* findNode(string name);

    public:
        FileSystem();
        ~FileSystem();
        string mkdir(string name);
        string touch(string name);
        string pwd();
        string ls();
        string rm(string name);
        string mv(string from, string to);
        string cd(string dirname);
};


#endif

/*
[1] Binary tree array implementation
    https://www.geeksforgeeks.org/binary-tree-array-implementation/

[2] Binary tree c++
    https://www.geeksforgeeks.org/binary-tree-in-cpp/

[3] Tree Data Structure
    https://www.geeksforgeeks.org/introduction-to-tree-data-structure/
*/