#ifndef _UTILITY_CODE_TEST_H_
#define _UTILITY_CODE_TEST_H_
        #include<stdio.h>
	#define MAX_STR_SIZE 100

	#define MINUS '-'

	#define PLUS '+'

	#define NUMBER(s) ('0' <= (s) <= '9')

	#define TO_LOWER(c) (((c)>='A' && (c)<='Z')?(c)=(c)+'a'-'A':(c))

	#define TO_UPPER(c) (((c)>='a' && (c)<='z')?(c)=(c)+'A'-'a':(c))

	extern int ascii_to_int(char *s);
	extern int to_lower(int c);
	extern int to_upper(int c);
	extern void string_to_lower(char s[]);
	extern void string_to_upper(char s[]);
	extern void str_copy(char *dest, char *src);
	extern void mem_copy(char *dest, char *src, int size);
	extern void print_memory(char *dest, int size);
	extern void string_reverse(char dest[]);
	extern char *str_cat(char *str1,char *str2);
	void mem_set(char *ptr, char c, int size);
	extern int get_length( char *temp_ptr);
	extern char *trim_string( char *str);
	extern int utilities_main();
#endif
