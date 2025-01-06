#include <iostream>
using namespace std;

inline void write(unsigned x) {
  if (x > 9)
    write(x / 10);
  putchar(x % 10 + '0');
}
int main() {
  unsigned x = 0, a = 0;
  char w;
  while (w = getchar(), w != EOF) {
    a += (w == '0' || w == '6' || w == '9') ? 1 : (w == '8') ? 2 : 0;
  }
  write(a);
}
