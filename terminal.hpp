#ifndef TERMINAL_H
#define TERMINAL_H

#include "filesystem.hpp"

class Terminal{
    private:
        FileSystem fs;
        bool done;

    public:
        Terminal();
        void run();
};

#endif