# File System Simulator

[![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)](https://isocpp.org/)
[![Makefile](https://img.shields.io/badge/Makefile-000000?style=for-the-badge&logo=gnu&logoColor=white)](https://www.gnu.org/software/make/)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

A command-line **File System Simulator** built in C++ that demonstrates tree data structures, object-oriented design, recursion, and memory management. It mimics core Linux file system commands (`ls`, `cd`, `mkdir`, `touch`, `rm`, `mv`, `pwd`) using a custom tree-based structure.

## ✨ Features

- **Tree-based File System**: Nodes represent files (`f`) and directories (`d`) with parent-child relationships
- **Supported Commands**:
  - `ls` - List contents of current directory
  - `mkdir <name>` - Create new directory
  - `touch <name>` - Create new file
  - `cd <dirname>` / `cd ..` - Navigate directories
  - `pwd` - Print working directory
  - `rm <name>` - Remove file or directory (recursive)
  - `mv <old> <new>` - Rename file or directory
  - `exit` - Quit the simulator
- **Robust Error Handling**: Duplicate names, invalid paths, non-directory `cd`, etc.
- **Recursive Deletion**: Proper cleanup of entire directory subtrees
- **Memory Safe**: No leaks (verified via project tests)

## 🛠️ Tech Stack

- **Language**: C++14
- **Data Structure**: Tree (vector of child pointers + parent links)
- **Build System**: GNU Make
- **Testing**: Catch2 framework

## 🚀 Quick Start

### Prerequisites
- g++ (GCC) with C++14 support
- Make

### Build & Run

```Bash
# Clone the repo
git clone <your-repo-url>
cd filesystem-simulator

# Build the main executable
make main

# Run the simulator
./main
```

## Example Session
```Bash
$ mkdir projects
$ cd projects
/root/projects
$ touch main.cpp
$ ls
f main.cpp
$ mkdir tests
$ pwd
/root/projects
$ cd ..
/root
$ rm projects
projects removed successfully
$ exit
```

## 🧪 Testing
```Bash
# Run all tests
make test-all

# Build and run sample execution
make test-run
```

## 🎯 What This Demonstrates

- **Advanced Data Structures:** Custom tree implementation with dynamic children
- **OOP Principles:** Encapsulation, inheritance-ready design, RAII
- **Memory Management:** Manual allocation/deallocation with destructors and recursive cleanup
- **Recursion:** Deep deletion of directory trees
- **Command Parsing:** Input handling and argument validation
- **Modular Design:** Clean separation of concerns (Node, FileSystem, Terminal)

## 📚 Learning Outcomes
This project strengthened my understanding of:

- Tree traversals and hierarchical data
- Pointer management in C++
- Recursive algorithms
- Building maintainable command-line tools

##🔧 Future Improvements (Ideas)

- Add file content storage
- Support for absolute paths
- Wildcard operations (rm *)
- Persistent storage (serialize tree to disk)

Feel free to explore the code and run the simulator!

## 📄 License
This project is open-sourced under the MIT License.
