#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern unsigned long reverse_in_place(char *str); 
extern long add_arrays(long *arr1, long *arr2, unsigned long num, long *result);

int main(int argc, char ** argv)
{
  int t = 0;
  if (argc > 1) t = atoi(argv[1]);

  if (2 - t){
	char *s = (char *) malloc (100); 
	memset(s, 0, 100); 
	strcpy(s, "Hello World!"); 
	puts(s); 
	unsigned long l = reverse_in_place(s); 
	printf("Size of rev str: %lu\n", l); 
	puts(s); 
  }
  if (1 - t){
	long l1[] = {3, 23, 32, 121, 0, 43, 95, 4};
	long l2[] = {-823,12,-1222,84834, -328, 0, 9, -1387};
	long res[] = {0, 0, 0, 0, 0, 0, 0, 0}; 
	long sum = add_arrays(l1, l2, 8, res); 
	int i = 0;
	printf("l1 = {");
	for(i = 0; i < 7; i++) {
		printf("%ld,", l1[i]); 
	}
	printf("%ld}\n", l1[7]);
	printf("l2 = {");
	for(i = 0; i < 7; i++) {
		printf("%ld,", l2[i]); 
	}
	printf("%ld}\n", l2[7]);
	for(i = 0; i < 8; i++) {
		printf("%ld + %ld = %ld\n", l1[i], l2[i], res[i]); 
	}
	printf("Sum = %ld\n", sum); 	
    }
    return 0; 
}


