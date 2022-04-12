#include <iostream>

int gen_serial(const char *username) {
  char temp;
  char current;
  int magic;

  magic = 11243;
  while (*username) {
    current = *username;
    if (*username <= 110)
      temp = (current ^ 0xA2) + 14;
    else
      temp = (current ^ 0xF4) - 20;
    magic += temp;
    ++username;
  }

  return magic ^ 0xC0144;
}

int main() {
  std::string username;
  std::cin >> username;
  std::cout << gen_serial(username.c_str());
  return 0;
}
