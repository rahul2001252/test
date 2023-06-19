/* This file accepts a line from user and stores it in a buffer. We also
count number of characters, words and spaces present in the input string
*/
#include<stdio.h>

#define IP_BUFFER_SIZE 512

#define IN 1

#define OUT 0 
 
#define IS_WHITE_SPACE(c)  ((c) == ' ' || \
                            (c) == '\n' || \
                            (c) == '\r' || \
                            (c) == '\v' || \
                            (c) == '\f' || \
                            (c) == '\t')

char *ptr = " Some String";
char aptr[] = "Something";


int word_count(char * buff)
{
  int inword=OUT, c, words=0;
  while(c=*buff)
  {
    if(!IS_WHITE_SPACE(c))
     {
      if(inword == OUT)
      {
       words++;
       inword=IN;
      }
     }
    if(IS_WHITE_SPACE(c))
    {
     if(inword == IN)
     {
      inword=OUT;
      buff++;
     }
   }
   if(inword=IN)
    words++;
  return words;
}
}
int get_line(char *buff, int max)
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
    
  }
  *buff = '\0'; 
  printf("\nSpaces= %d\n", spaces);
  return ch_count;
}


int main()
{
  char ip_buffer[IP_BUFFER_SIZE+1];
  int c = get_line(ip_buffer, IP_BUFFER_SIZE);
  
  printf("Characters %d\n",c);
  int w_count = word_count(ip_buffer);
  printf("Words=%d\n", w_count);
  printf("Size of one input buffer is %lu\n", sizeof(ip_buffer));
  printf("Size of one input buffer is %lu\n", sizeof(ip_buffer[0]));
  return 0;
}
 
