#include "terminal.hpp"
#include <sstream>
#include <string>

Terminal::Terminal(){
    done = false;
}

void Terminal::run(){
    string terminalInput;

    string word1, word2, word3;
  
    while (!done){
      cout << "$ "; 
      getline(cin, terminalInput);
  
      istringstream iss(terminalInput);
      int wordCount = 0;
  
      if (iss >> word1) wordCount++;
      if (iss >> word2) wordCount++;
      if (iss >> word3) wordCount++;
  
      string extra;
      if (iss >> extra){
        cout << word1 << ": " << "too many arguments" << endl;
      }
  
      // one word commands
      if (wordCount >= 1){
        if (word1 == "exit"){
          done = true;
        }
        else if (word1 == "ls"){
          cout << fs.ls();
        }
        else if (word1 == "pwd"){
          cout << fs.pwd() << endl;
        }
      }
  
      // two word commands 
      if (wordCount >= 2){
        string result;
        if (word1 == "mkdir"){
          result = fs.mkdir(word2);
        }
        else if (word1 == "cd"){
          result = fs.cd(word2);
        }
        else if (word1 == "touch"){
          result = fs.touch(word2);
        }
        else if (word1 == "rm"){
          result = fs.rm(word2);
        }
        if (!result.empty()){
          cout << result << endl;
        }
      }
  
      // three word command
      if (wordCount >= 3){
        string result;
        if (word1 == "mv"){
          result = fs.mv(word2, word3);
        }
        if (!result.empty()){
          cout << result << endl;
        }
        }
      }
    }