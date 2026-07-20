# File System Simulator

[![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)](https://isocpp.org/)
[![Makefile](https://img.shields.io/badge/Makefile-000000?style=for-the-badge&logo=gnu&logoColor=white)](https://www.gnu.org/software/make/)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

A command-line **File System Simulator** built in C++ that demonstrates tree data structures, object-oriented design, recursion, and memory management. It mimics core Linux file system commands (`ls`, `cd`, `mkdir`, `touch`, `rm`, `mv`, `pwd`) using a custom tree-based structure.

**Perfect for showcasing data structures and systems programming skills to recruiters.**

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

```bash
# Clone the repo
git clone <your-repo-url>
cd filesystem-simulator

# Build the main executable
make main

# Run the simulator
./main
