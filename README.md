# Assignment 3
## Provided Files
### main.c
Driver code for questions 1 and 2. No changes should be made to this file. You can compile and run this code with the command `make`. Note: The Makfile will be used to test your code on LDAP machines. Points will be deducted if any compiler warnings or errors are produced.

### reverse_in_place_asm.S
This is where you will write your x86 code for question 1. 

### add_arrays_asm.S
This is where you will write your x86 code for question 2.

### bt.c
This is where you'll be writing your code for question 3. Be sure to add any .S files to the repo you create if you are using helper functions in x86. You will need to provide instructions below on how to compile and run your code for this problem.

### Makefile
We have provided a makefile with the following explicit rules:

- `test`: has dependency on the main executable file, and runs main.
- `test1`-`test2`: have dependency on the main executable file, and runs main with command line arguments that will allow only test cases from the corresponding question on the assignment, i.e. typing `make test1` will run only the test cases for question 1, and typing `make test2` will run only the test cases for question 2. These will be helpful for working on individual problems in the assignment.
- `clean`: removes all executable and object files created by the Makefile.

## Completing the Assignment

1. Clone the repository on a UNIX machine using the command `git clone URL` for the URL of your repository.
2. For each question on the handout on Brightspace, write the corresponding function in the provided files provided in this repository. You may use helper functions to write any of these functions. Do not edit the main function in either C file; this is already set up to run some test cases that will be used to test your code. Make sure that your code compiles and runs properly on the LDAP machines without any errors or warnings; points will be duducted for errors or warnings.
3. Regularly push edits you make in your local repository using the commands `git commit -a -m "commit comment"` to commit the changes you made, and `git push` to update the master repository.
4. Edit this README below to provide instructions for compiling and running bt.c, and to specify the number of grace days used for this assignment. Additionally, give any references you used in completing this assignment (you can simply write "None." if you didn't use any) or provide miscellaneous comments about your code (any known issues should be documented here -- if you have no comments to make, you can simply write "None.").
5. Once you are finished, post the 40-hex-character hash code of your final commit in the assignment link on Brightspace. You can obtain this code using the command `git rev-parse HEAD`.

## Instructions
Provide instructions here for compiling and running bt.c

$ gcc -c getRBP.S -o getRBP.o

$ gcc bt.c getRBP.o -o bt -g

$ gdb ./bt

(gdb) b print_backtrace

(gdb) r

(gdb) bt

(gdb) c


## Grace days

Grace days used for this assignment: 1/2

Grace days remaining: -/8

## References

## Miscellaneous comments
