#include <iostream>

void gen_serial(const char *username) {
  char next_char = 0;
  int second = 4, magic1, first = 1, magic2;

  while (*username) {
    magic1 = 4 * next_char + second;
    magic2 = (4 * next_char + ((magic1 + *username) ^ 0x33) - *username) ^ 0x22;
    second = magic1 - 245;
    first = magic2 + 444;
    next_char = *username++;
  }
  std::cout << first << '-' << second;
}

int main() {
  std::string username;
  std::cin >> username;
  gen_serial(username.c_str());
  return 0;
}