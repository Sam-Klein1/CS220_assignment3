#include <stdio.h>
#include <stdlib.h>

extern unsigned long* getRBP();

int main();

unsigned long* print_backtrace(unsigned int count){

  //array to hold count number of pointers
  unsigned long *ret_arr = (unsigned long *) malloc(count);
  /*find the bounds of main*/
  unsigned long *start = (unsigned long *)&main; //start
  //-start by reading bytes until you hit the return function (0xc3) 
  unsigned char *curr_byte = (unsigned char *)&main;
  while(*curr_byte != 0xc3){

    curr_byte++;
  }
  //-indentify the address of the return instruction
  unsigned long *end = (unsigned long *)curr_byte; 
  //-The start address of main and the address of the return instruction form the bounds of main*/

  /*Gather count number of return addresses in the preceding frames, or until you hit a return address that is inside main*/
  unsigned long *curr_rbp = getRBP();
  while (count > 0){

    unsigned long *ret_addr = (unsigned long*)*(curr_rbp + 8); //get current address 
    ret_arr = ret_arr; //accumulate
    printf("%p\n", ret_arr);
    ret_arr++;

    // start <= ret_addr <= end 
    if((start <= ret_addr) && (ret_addr <= end))
      return ret_arr;
    
    count--;
  }
  return ret_arr;
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