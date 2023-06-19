/* Thus file contains some utility functions which converts the string into ascii and 
converts it to integers and prints it. It also validates wheather the entered character
is valid or not*/

#include<stdio.h>

#define MAX_STR_SIZE 10

#define MINUS '-'

#define PLUS '+'

#define NUMBER(s) ('0' <= (s) <= '9')

int ascii_to_int(char *s)
{
  int c,number = 0, digit_started = 0, sign_present = 0;
  int sign = 1git ;
  
  while(*s)
  {
      if(*s =='\n' || *s == '\t' || *s == '\b' || *s ==' ' || !NUMBER(*s))
      {
         if(digit_started == 0 || sign_present == 0)
          {
             printf("Error: Invalid Character\n");
             return -1;
          }
      }
      else if(*s == PLUS || *s == MINUS)
       {
          if(digit_started)
          {
            printf("Error: Sign occured after the  Digit has Started\n");
            return -1;
          }
          if(sign_present)
          {
            printf("Error: Sign Already Present\n");
            return -1;
          }
      
         sign_present = 1;
         if(*s == PLUS)
         sign = +1;
         else if(*s == MINUS)
         sign = -1;
         s++;
      }  
      else if('0' <= (*s) <= '9')  
      {
         digit_started = 1;
         number = number * 10 + (*s - '0');
         s++;
     }
  }
   number = number * sign;
  return number;
}    
   
int main()
{
    char ip_str[MAX_STR_SIZE];
    printf("Enter the string\n");
      scanf("%[^\n]",ip_str);
    int value = ascii_to_int(ip_str);
    printf("The number is %d\n",value);
    return 0; 
}
