#include "Interpreter.h"
#include <iostream>
#include <bits/stdc++.h>

char replaceChar(char ch1, char ch2) {
	  ch1 = ch2;
	  return ch1;
}
std::vector<int> getIndex(std::vector <std::string> input, std::string searched) {
    std::vector<int> result;

    for (int i = 0; i < input.size(); i++) {
        if (input[i] == searched) {
            result.push_back(i);
        }
    }

    return result;
}
int convertInt(int ch1) {
	  if(ch1 == 48) {
	    return 0;
	  } else if(ch1 == 49) {
	    return 1;
	  } else if(ch1 == 50) {
	    return 2;
	  } else if(ch1 == 51) {
	    return 3;
	  } else if(ch1 == 52) {
	    return 4;
	  } else if(ch1 == 53) {
	    return 5;
	  } else if(ch1 == 54) {
	    return 6;
	  } else if(ch1 == 55) {
	    return 7;
	  } else if(ch1 == 56) {
	    return 8;
	  } else if(ch1 == 57) {
	    return 9;
	  } else {
	    return ch1;
	  }
}

int Interpreter::run(char token[], int size) {
	int lines = 0;
	int end = 0;
	size = size - 1;
	bool lined = false;
	bool print = false;
	bool var = false;
	bool integer = false;
	bool ifBool = false;
	int digit_first = 0;
	int digit_second = 0;
	std::vector <std::string> varFullName;
	std::vector <std::string> varFullContent;
	std::vector <int> varFullContentInt;
	std::vector <std::string> varType;
	std::string strVar = "";

	int intVar = 0;
	char expr = ' ';
	for (int i = 0; i <= size; i++) {
		char tok = token[i];
		//formatting
		if(tok == '\n') {
			tok = ' ';
			lines++;
		} else if(tok == '<') {
			if(token[i+1] == 'E') {
				if(token[i+2] == 'O') {
					if(token[i+3] == 'F') {
						if(token[i+4] == '>') {

							return 0;
						}
					}
				}
			}
		}
		//check for newline
		//setup for printing
		if(token[i] == 'p' && token[i+1] == 'r' && token[i+2] == 'i' && token[i+3] == 'n' && token[i+4] == 't' && token[i+5] == 'l' && token[i+6] == 'n') {
			lined = true;
			var = false;
			print = true;
		} else if(token[i] == 'p' && token[i+1] == 'r' && token[i+2] == 'i' && token[i+3] == 'n' && token[i+4] == 't' && token[i+5] != 'l') {
			lined = false;
			var = false;
			print = true;
		} else if(token[i] == 'S' && token[i+1] == 't' && token[i+2] == 'r') {
			lined = false;
			print = false;
			var = true;
			integer = false;
			std::string var;
			std::string varContent;
			for(int x = 1; token[i+3+x] != '='; x++) {

				std::string chstr(1, token[i+3+x]);
				char* ch = const_cast<char*>(chstr.c_str());
				var.append(ch);
			}
			//std::cout << var.length();
			if(token[i+3+var.length()+1] == '=' && token[i+3+var.length()+2] == '"') {
				for(int x = 2; token[i+3+var.length()+x] != ';'; x++) {
					int y = 3+var.length();
					if(token[i+y+x] == '~' || token[i+y+x] == '"') {

					} else {
						std::string chstr(1, token[i+y+x]);
						char* ch = const_cast<char*>(chstr.c_str());
						varContent.append(ch);
					}
				}
			}
			varFullName.push_back(var);
			varFullContent.push_back(varContent);
			varFullContentInt.push_back(0);
			varType.push_back("String");
		} else if(token[i] == 'I' && token[i+1] == 'n' && token[i+2] == 't') {
			std::string var;
			int varContent;
			lined = false;
			print = false;
			integer = true;
			for(int x = 0; token[i+3+x] != '='; x++) {
				if(token[i+3+x] == ' ') {

				} else {
					std::string chstr(1, token[i+x+3]);
					char* ch = const_cast<char*>(chstr.c_str());
					var.append(ch);
				}
			}
			if(token[i+3+var.length()+1] == '=') {
				//std::cout << token[i+3+var.length()+2];
				for(int x = var.length() + 5; token[i+x] != ';'; x++) {
					if(token[i+x] == '1' || token[i+x] == '2' || token[i+x] == '3' || token[i+x] == '4' || token[i+x] == '5' || token[i+x] == '6' || token[i+x] == '7' || token[i+x] == '8' || token[i+x] == '9' || token[i+x] == '0') {
						if(token[i+x+1] == '1' || token[i+x+1] == '2' || token[i+x+1] == '3' || token[i+x+1] == '4' || token[i+x+1] == '5' || token[i+x+1] == '6' || token[i+x+1] == '7' || token[i+x+1] == '8' || token[i+x+1] == '9' || token[i+x+1] == '0') {
							int num = token[i+x];
							int num1 = token[i+x+1];
							num = convertInt(num);
							num1 = convertInt(num1);
							num = num * 10;
							num = num + num1;
							varContent = num;
							x++;
							x++;
						} else {
							int num = token[i+x];
							num = convertInt(num);

							//std::cout << i+x << std::endl;
							varContent = num;
						}
					}
				}
		}
			varFullName.push_back(var);
			varFullContentInt.push_back(varContent);
			varFullContent.push_back(" ");
			varType.push_back("Integer");
			//std::cout << varContent;

		} else if(token[i] == 'i' && token[i+1] == 'f' && token[i+3] == '[') {
			std::string condition;
			
			for(int x = 0; token[i+5+x] != ']'; x++) {
				int intResult;
				int cmpInt;
				std::string strResult;
				std::string cmpStr;
				if(token[i+5+x] == '+') {
					if(token[i+5+x-2] == '1' || token[i+5+x-2] == '2' || token[i+5+x-2] == '3' || token[i+5+x-2] == '4' || token[i+5+x-2] == '5' || token[i+5+x-2] == '6' || token[i+5+x-2] == '7' || token[i+5+x-2] == '8' || token[i+5+x-2] == '9' || token[i+5+x-2] == '0') {
						
						if(token[i+5+x-1] == '1' || token[i+5+x-1] == '2' || token[i+5+x-1] == '3' || token[i+5+x-1] == '4' || token[i+5+x-1] == '5' || token[i+5+x-1] == '6' || token[i+5+x-1] == '7' || token[i+5+x-1] == '8' || token[i+5+x-1] == '9' || token[i+5+x-1] == '0') {
							if(token[i+5+x+1] == '1' || token[i+5+x+1] == '2' || token[i+5+x+1] == '3' || token[i+5+x+1] == '4' || token[i+5+x+1] == '5' || token[i+5+x+1] == '6' || token[i+5+x+1] == '7' || token[i+5+x+1] == '8' || token[i+5+x+1] == '9' || token[i+5+x+1] == '0') {
								if(token[i+5+x+2] == '1' || token[i+5+x+2] == '2' || token[i+5+x+2] == '3' || token[i+5+x+2] == '4' || token[i+5+x+2] == '5' || token[i+5+x+2] == '6' || token[i+5+x+2] == '7' || token[i+5+x+2] == '8' || token[i+5+x+2] == '9' || token[i+5+x+2] == '0') {
									int num = token[i+5+x-2];
									int num1 = token[i+5+x-1];
									int num2 = token[i+5+x+1];
									int num3 = token[i+5+x+2];
									num = convertInt(num);
									num1 = convertInt(num1);
									num2 = convertInt(num2);
									num3 = convertInt(num3);
									num = num * 10;
									num2 = num2 * 10;
									num = num + num1;
									num2 = num2 + num3;
									num = num + num2;
									intResult = num;
								} else {
									int num = token[i+x+5-2];
									int num1 = token[i+x+5-1];
									int num2 = token[i+x+5+1];
									num = convertInt(num);
									num1 = convertInt(num1);
									num2 = convertInt(num2);
									num = num * 10;
									num = num + num1;
									num = num + num2;
									intResult = num;
								}
							}
						}
					
					} else if(token[i+x+5-1] == '1' || token[i+x+5-1] == '2' || token[i+x+5-1] == '3' || token[i+x+5-1] == '4' || token[i+x+5-1] == '5' || token[i+x+5-1] == '6' || token[i+x+5-1] == '7' || token[i+x+5-1] == '8' || token[i+x+5-1] == '9' || token[i+x+5-1] == '0') {
							if(token[i+x+5+1] == '1' || token[i+x+5-1] == '2' || token[i+x+5+1] == '3' || token[i+x+5+1] == '4' || token[i+x+5+1] == '5' || token[i+x+5+1] == '6' || token[i+x+5+1] == '7' || token[i+x+5+1] == '8' || token[i+x+5+1] == '9' || token[i+x+5+1] == '0') {
								if(token[i+x+5+2] == '1' || token[i+x+5+2] == '2' || token[i+x+5+2] == '3' || token[i+x+5+2] == '4' || token[i+x+5+2] == '5' || token[i+x+5+2] == '6' || token[i+x+5+2] == '7' || token[i+x+5+2] == '8' || token[i+x+5+2] == '9' || token[i+x+5+2] == '0') {
									int num = token[i+x+5-1];
									int num1 = token[i+x+5+1];
									int num2 = token[i+x+5+2];
									num = convertInt(num);
									num1 = convertInt(num1);
									num2 = convertInt(num2);
									num1 = num1 * 10;
									num1 = num1 + num2;
									num = num + num1;
									intResult = num;
								} else {
									int num = token[i+x+5-1];
									int num1 = token[i+x+5+1];
									num = convertInt(num);
									num1 = convertInt(num1);
									num = num + num1;
									intResult = num;
								}
							}
						}
				} else if(token[i+x+5] == '==') {
					if(intResult != NULL) {
						if(token[i+x+5+2] == '1' || token[i+x+5+2] == '2' || token[i+x+5+2] == '3' || token[i+x+5+2] == '4' || token[i+x+5+2] == '5' || token[i+x+5+2] == '6' || token[i+x+5+2] == '7' || token[i+x+5+2] == '8' || token[i+x+5+2] == '9' || token[i+x+5+2] == '0') {
							if(token[i+x+5+1] == '1' || token[i+x+5+1] == '2' || token[i+x+5+1] == '3' || token[i+x+5+1] == '4' || token[i+x+5+1] == '5' || token[i+x+5+1] == '6' || token[i+x+5+1] == '7' || token[i+x+5+1] == '8' || token[i+x+5+1] == '9' || token[i+x+5+1] == '0') {
								int num = token[i+x+5+2];
								int num1 = token[i+x+5+1];
								num = convertInt(num);
								num1 = convertInt(num1);
								num = num * 10;
								num = num + num1;
								cmpInt = num;
							}
						} else if(token[i+x+5+1] == '1' || token[i+x+5+1] == '2' || token[i+x+5+1] == '3' || token[i+x+5+1] == '4' || token[i+x+5+1] == '5' || token[i+x+5+1] == '6' || token[i+x+5+1] == '7' || token[i+x+5+1] == '8' || token[i+x+5+1] == '9' || token[i+x+5+1] == '0') {
								int num = token[i+x+5+2];
								num = convertInt(num);
								cmpInt = num;
						}
						if(intResult == cmpInt) {
							ifBool = true;
						} else {
							ifBool = false;
						}
					}
				}
				
			}
		}

	//	print = false;


	//print = false;
		//format and print strings
		if(token[i] == '"') {
			std::string word;
			for(int x = 0; token[i+x] != ';'; x++) {
				if(token[i+x] == '~' || token[i+x] == '"') {

				} else {
					std::string chstr(1, token[i+x]);
					char* ch = const_cast<char*>(chstr.c_str());
					word.append(ch);
				}
			}
			if(print == true) {
				if(lined == false) {
					std::cout << word;
				} else if(lined == true) {
					std::cout << word << std::endl;
				}
			}
		}
			else if(token[i] == '1' || token[i] == '2' || token[i] == '3' || token[i] == '4' || token[i] == '5' || token[i] == '6' || token[i] == '7' || token[i] == '8' || token[i] == '9' || token[i] == '0') {
			if(token[i+1] == '1' || token[i+1] == '2' || token[i+1] == '3' || token[i+1] == '4' || token[i+1] == '5' || token[i+1] == '6' || token[i+1] == '7' || token[i+1] == '8' || token[i+1] == '9' || token[i+1] == '0') {
				if(token[i+3] == '1' || token[i+3] == '2' || token[i+3] == '3' || token[i+3] == '4' || token[i+3] == '5' || token[i+3] == '6' || token[i+3] == '7' || token[i+3] == '8' || token[i+3] == '9' || token[i+3] == '0') {
					if(token[i+4] == '1' || token[i+4] == '2' || token[i+4] == '3' || token[i+4] == '4' || token[i+4] == '5' || token[i+4] == '6' || token[i+4] == '7' || token[i+4] == '8' || token[i+4] == '9' || token[i+4] == '0') {
						//2 Double Digit Numbers
						int num = token[i];
						int num1 = token[i+1];
						int num2 = token[i+3];
						int num3 = token[i+4];
						num = convertInt(num);
						num1 = convertInt(num1);
						num2 = convertInt(num2);
						num3 = convertInt(num3);
						num = num * 10;
						num = num + num1;
						num2 = num2 * 10;
						num2 = num2 + num3;
						if(token[i+2] == '+') {
							num = num + num2;
						} else if(token[i+2] == '-') {
							num = num - num2;
						} else if(token[i+2] == '*') {
							num = num * num2;
						} else if(token[i+2] == '/') {
							num = num / num2;
						}
						if(print == true) {
							if(lined == true) {
								std::cout << num << std::endl;
							} else {
								std::cout << num;
							}
						}
						i++;
						i++;
						i++;
						i++;
					} else {
						//1 Double Digit 1 Single Digit
						int num = token[i];
						int num1 = token[i+1];
						int num2 = token[i+3];
						num = convertInt(num);
						num1 = convertInt(num1);
						num2 = convertInt(num2);
						num = num * 10;
						num = num + num1;
						if(token[i+2] == '+') {
							num = num + num2;
						} else if(token[i+2] == '-') {
							num = num - num2;
						} else if(token[i+2] == '*') {
							num = num * num2;
						} else if(token[i+2] == '/') {
							num = num / num2;

						}
						if(print == true) {
							if(lined == true) {
								std::cout << num << std::endl;
							} else {
								std::cout << num;
							}
						}
						i++;
						i++;
						i++;
					}
				} else {
					//1 Double Digit
					int num = token[i];
					int num1 = token[i+1];
					num = convertInt(num);
					num1 = convertInt(num1);
					num = num * 10;
					num = num + num1;
					if(print == true) {
						if(lined == true) {
							std::cout << num << std::endl;
						} else {
							std::cout << num;
						}
					}
				}
				i++;
				i++;
			} else if(token[i+2] == '1' || token[i+2] == '2' || token[i+2] == '3' || token[i+2] == '4' || token[i+2] == '5' || token[i+2] == '6' || token[i+2] == '7' || token[i+2] == '8' || token[i+2] == '9' || token[i+2] == '0'){
				//2 single digits;
				if(token[i+3] == '1' || token[i+3] == '2' || token[i+3] == '3' || token[i+3] == '4' || token[i+3] == '5' || token[i+3] == '6' || token[i+3] == '7' || token[i+3] == '8' || token[i+3] == '9' || token[i+3] == '0') {
					//1 single digit 1 double digit
					int num = token[i];
					int num1 = token[i+2];
					int num2 = token[i+3];
					num = convertInt(num);
					num1 = convertInt(num1);
					num2 = convertInt(num2);
					num1 = num1 * 10;
					num1 = num1 + num2;
					if(token[i+1] == '+') {
						num = num + num1;
					} else if(token[i+1] == '-') {
						num = num - num1;
					} else if(token[i+1] == '*') {
						num = num * num1;
					} else if(token[i+1] == '/') {
						num = num / num1;

					}
					if(print == true) {
						if(lined == true) {
							std::cout << num << std::endl;
						} else {
							std::cout << num;
						}
					}
					i++;
					i++;
					i++;
				} else {
				int num = token[i];
				int num1 = token[i+2];
				num = convertInt(num);
				num1 = convertInt(num1);
				if(token[i+1] == '+') {
					num = num + num1;
				} else if(token[i+1] == '-') {
					num = num - num1;
				} else if(token[i+1] == '*') {
					num = num * num1;
				} else if(token[i+1] == '/') {
					num = num / num1;

				}
				if(print == true) {
					if(lined == true) {
						std::cout << num << std::endl;
					} else {
						std::cout << num;
					}
				}
			}
			i++;
			i++;
			} else {
				//1 single digit
				int num = token[i];
				num = convertInt(num);
				if(print == true) {
					if(lined == true) {
						std::cout << num << std::endl;
					} else {
						std::cout << num;
					}
				}

				i++;
			}
		}

		else if(token[i] == '$') {
			std::string varName;
			std::string varNameInt;
			std::string varContent;
			std::string varNamecmp;

			for(int x = 0; token[i+x] != ';'; x++) {
				if(token[i+x] == '$') {

				} else {
					std::string chstr(1, token[i+x]);
					char* ch = const_cast<char*>(chstr.c_str());


						varName.append(ch);

			}
			}
			std::vector<int> index;

			index = getIndex(varFullName, varName);

			if(index.size() < 1) {
				continue;
			}
			if(index.size() > 1) {
				int errLine = lines;
				std::cout << "=========================" << std::endl;
				std::cout << "==========ERROR==========" << std::endl;
				std::cout << "=========================" << std::endl;
				std::cout << "At Line: " << errLine << std::endl;

				return 2;
			} else {
				if(print == true) {
					if(lined == true) {
						if(varType[index[0]] == "String") {
							std::cout << varFullContent[index[0]] << std::endl;
						} else if(varType[index[0]] == "Integer") {
							std::cout << varFullContentInt[index[0]] << std::endl;
						}
					} else {
						if(varType[index[0]] == "String") {
							std::cout << varFullContent[index[0]];
						} else if(varType[index[0]] == "Integer") {
							std::cout << varFullContentInt[index[0]];
						}
					}
				}
			}

		}

		if(token[i+1] == ';') {
			continue;
		}


		}

		return 0;
}
