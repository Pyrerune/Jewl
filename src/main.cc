#include <iostream>
#include <fstream>
#include <cstring>
#include "Interpreter.h"
int main(int argc, char *argv[]) {
  Interpreter interpreter;
  double version = 1.1;
  if(argv[1] == NULL) {
    std::cout << "NullFileException: No Filename Given" << std::endl << "Required At line 9" << std::endl;
    return 1;
  }
  if(strcmp(argv[1], "-v") == false || strcmp(argv[1], "--version") == false) {
    std::cout << "====================" << std::endl;
    std::cout << "========JEWL========" << std::endl;
    std::cout << "====================" << std::endl;
    std::cout << "Version: " << version << std::endl;
    return 0;
  }
  std::string file = argv[1];
  std::string line;
  std::ifstream t(file);

  //std::cout << count;
  std::string contents { std::istreambuf_iterator<char>(t), std::istreambuf_iterator<char>() };
  contents.append("<EOF>");
  char arr[contents.length() + 1];
  strcpy(arr, contents.c_str());

  int end = interpreter.run(arr, contents.length());
  switch(end) {
    case 1:
      std::cout << std::endl << "GENERAL ERROR" << std::endl;
      break;
    case 2:
      std::cout << std::endl << "DuplicateVarNameError" << std::endl;
      break;
    case 3:
      std::cout << std::endl << "UnTerminatedPrintFunction" << std::endl;

  }
  return 0;
}
