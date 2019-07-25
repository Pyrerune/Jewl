#include "Interpreter.h"
#include <iostream>

char replaceChar(char ch1, char ch2) {
	  ch1 = ch2;
	  return ch1;
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
	size = size - 1;
	bool lined = false;
	bool print = false;
	int digit_first = 0;
	int digit_second = 0;
	char expr = ' ';
	for (int i = 0; i <= size; i++) {
		char tok = token[i];
		//formatting
		if(tok == '\n') {
			tok = ' ';
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
			print = true;
		} else if(token[i] == 'p' && token[i+1] == 'r' && token[i+2] == 'i' && token[i+3] == 'n' && token[i+4] == 't' && token[i+5] != 'l') {
			lined = false;
			print = true;
		}
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
		} else if(token[i] == '1' || token[i] == '2' || token[i] == '3' || token[i] == '4' || token[i] == '5' || token[i] == '6' || token[i] == '7' || token[i] == '8' || token[i] == '9' || token[i] == '0') {
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


		if(token[i+1] == ';') {
			continue;
		}



		}

		return 0;
}