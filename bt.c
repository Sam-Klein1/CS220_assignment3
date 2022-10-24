#include <stdio.h>
#include <stdlib.h>

unsigned long* print_backtrace(unsigned int count)
{

}

/* Do not change anything below this point */
void j() { print_backtrace(10); }
void i() { j(); }
void h() { i(); }
void g() { h(); }
void f() { g(); }

int main(int argc, char *argv[])
{
  f();
  return 0;
}
