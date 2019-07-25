#include <iostream>
#include <fstream>
#include <cstring>
#include "Interpreter.h"
int main(int argc, char *argv[]) {
  Interpreter interpreter;
  if(argv[1] == NULL) {
    std::cout << "NullFileException: No Filename Given" << std::endl << "Required At line 9" << std::endl;
    return 1;
  }
  std::string file = argv[1];
  std::string line;
  std::ifstream t(file);
  std::string contents { std::istreambuf_iterator<char>(t), std::istreambuf_iterator<char>() };
  contents.append("<EOF>");
  char arr[contents.length() + 1];
  strcpy(arr, contents.c_str());
  
  int end = interpreter.run(arr, contents.length());
  
  return end;
}
