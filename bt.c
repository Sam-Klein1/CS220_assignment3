#include <stdio.h>
#include <stdlib.h>

extern unsigned long* getRBP();

int main(); //function signature to be able to get address of main in our print_backtrace function

unsigned long* print_backtrace(unsigned int count){

  //allocate array to hold count number of pointers
  unsigned long *ret_arr = (unsigned long *) malloc(sizeof(unsigned long *) * count);
  /*find the bounds of main*/
  unsigned char *start = (unsigned char *)&main; //start
  unsigned char *end; //end
  //-start by reading bytes until you hit the return function (0xc3) 
  unsigned char *curr_byte = (unsigned char *)&main;
  while(*curr_byte != 0xc3){

    curr_byte++;
  }
  //-indentify the address of the return instruction, this will be after the current byte reads 0xc3
  end = curr_byte; 
  //-The start address of main and the address of the return instruction form the bounds of main*/

  /*Gather count number of return addresses in the preceding frames, or until you hit a return address that is inside main*/
  unsigned long *curr_rbp = getRBP(); //ASM helper function to obtain rbp pointer
  unsigned long *ret_addr;
  while (count > 0){

    ret_addr = (unsigned long *)*(curr_rbp + 8); //get current address 
    ret_arr = (unsigned long *)ret_addr; //accumulate ret_addr
    printf("%p\n", ret_arr);
    ret_arr++;

    // start <= ret_addr <= end (Checking if ret_addr is in bounds of main)
    if(((unsigned long *)start <= ret_addr) && (ret_addr <= (unsigned long *)end)){
      return ret_arr;
    }
    
    curr_rbp = (unsigned long *)*(curr_rbp);
    count--;
  }
  return ret_arr;

  //deallocate memory 
  free(ret_arr);
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