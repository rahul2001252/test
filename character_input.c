/* This file accepts a line from user and stores it in a buffer. We also
count number of characters, words and spaces present in the input string
*/
#include<stdio.h>

#define IP_BUFFER_SIZE 512

char *ptr = " Some String";
char aptr[] = "Something";


int get_line(char *buff,int max)
{
  int c, ch_count = 0;
  int spaces = 0, words = 0, inword = 0;
  
  while(( c = getchar()) != EOF && --max )
  {
    *buff = c;
    buff++;
    ch_count++;
    if(c == ' ' || c == '\n' || c == '\t')
     spaces++;
    if(c != ' ' && c != '\n' && c != '\t' && !inword)
    {
      words++;
      inword=1;
    }
    if((c == ' ' || c == '\n' || c == '\t') && inword)
     inword=0;
  }
  *buff = '\0'; 
  printf("\nSpaces= %d\nWords = %d\n", spaces,words);
  return ch_count;
}


int main()
{
  char ip_buffer[IP_BUFFER_SIZE+1];
  int c = get_line(ip_buffer, IP_BUFFER_SIZE);
  
  printf("Characters %d\n",c);
  printf("Size of one input buffer is %lu\n", sizeof(ip_buffer));
  printf("Size of one input buffer is %lu\n", sizeof(ip_buffer[0]));
}
 
