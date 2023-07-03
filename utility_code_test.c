/* Thus file contains some utility functions which converts the string into ascii and 
converts it to integers and prints it. It also validates wheather the entered character
is valid or not. Also convert the characters and strings to upper and lower characters. Concatenation of two strings using pointers is also performed.*/
#include<stdio.h>
#include "utility_code_test.h"

#define MAX_STR_SIZE 100

#define MINUS '-'

#define PLUS '+'

#define NUMBER(s) ('0' <= (s) <= '9')

#define TO_LOWER(c) (((c)>='A' && (c)<='Z')?(c)=(c)+'a'-'A':(c))

#define TO_UPPER(c) (((c)>='a' && (c)<='z')?(c)=(c)+'A'-'a':(c))

#define IS_WHITE_SPACE(c)  ((c) == ' ' || \
                            (c) == '\n' || \
                            (c) == '\r' || \
                            (c) == '\v' || \
                            (c) == '\f' || \
                            (c) == '\t')
#define BIG_INDIAN 0X01
#define LITTLE_INDIAN 0X02
                            
#define IS_BIG_INDIAN (get_indian() == BIG_INDIAN)

#define IS_LITTLE_INDIAN (get indian() == LITTLE_INDIAN)

char str1[MAX_STR_SIZE] = "Hello world";
char str2[MAX_STR_SIZE] = "Again";
char tr_str[MAX_STR_SIZE]= "  AB CD  ";
char search[10] = "world";
char *result;
int int_val =0x1A2B3C4D;
int ascii_to_int(char *s)
{
  int c,number = 0, digit_started = 0, sign_present = 0;
  int sign = 1;
  
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
  
int to_lower(int c)
{
  if(c>='A' && c<='Z')
   return c = c + 'a' - 'A';
  else
   return c;
}

int to_upper(int c)
{
   if(c>='a' && c<='a')
    return c = c + 'A' - 'a';
   else
    return c;
}

void string_to_lower(char s[])
{
  int c,i=0;
  while(c=s[i])
  {
   TO_LOWER(c);
    s[i]=c;
   i++;
  }
}

void string_to_upper(char s[])
{
 int c,i=0;
 while(c=s[i])
 {
   TO_UPPER(c);
    s[i]=c;
   i++;
 }
}

void str_copy(char *dest, char *src)
{
  while((*dest = *src)!= '\0')
  {
    dest++;
    src++;
  }
}

void mem_copy(char *dest, char *src, int size)
{
 while(size>0)
 { 
  *dest=*src;
  dest++;
  src++;
  size--;
 }
}

void print_memory(char *dest, int size)
{
 char c;
 for(int i=0;i<size;i++)
 {
   c=*(dest+i);
   printf("0x%x\n", (c&0xff));
   if(i & 07 == 0x6)
    printf("\n");
 }
 printf("\n");
}
  
void string_reverse(char dest[])
{
  if(dest == NULL)
  {
   printf("Error: NULL Pointer occured\n");
  }
  else
  {
    int length=0,index=0,temp,j;
    for(index=0; dest[index]!='\0'; index++)
    {
     length++;
    }
    printf("Length of string %d\n", length);
    for(int i=0, j=length-1; i<j; i++,j--)
    {
      temp = dest[i];
      dest[i] = dest[j];
      dest[j] = temp;
    }
  }
}

    
  
  
char *str_cat(char *str1,char *str2)
{
   char *s=str1;
   if(!str1)
   {
     printf(" Error\n");
     str1++;
   }
   else
   {
    while(*str1!='\0')
     str1++;
    while((*str1 = *str2)!='\0')
     {
      str2++;
      str1++;
     }
     return s;
   }
}

int get_length( char *temp_ptr)
{
    int length;
    length = 0;
    while(*temp_ptr != '\0')
    {
        length++;
        temp_ptr++;
      }
    return length;
}

char *trim_string( char *str)
{
    /*int length;
    char *temp_ptr;
    int i=0;
    int j;*/
    int f_index=-1;
    int l_index=-1;
    int idx;
    if(!str)
    {
     printf("Empty String\n");
    }
    for(idx=0;str[idx]!='\0';idx++)
    {
     if(!IS_WHITE_SPACE(str[idx]))
     {
       if(f_index == -1)
       {
         f_index =idx;
       }
        l_index=idx;
     }
    }
    str[l_index+1]='\0';
    for(idx=0;f_index<=l_index;f_index++,idx++)
     str[idx] = str[f_index];
     str[idx]='\0';
    /*//length = get_length( str );
    while(IS_WHITE_SPACE(str[i]))
    {
      i++;
    }
    for(j=0,i;str[i]!='\0';j++,i++)
    {
      str[j]=str[i];
    }
    
    /*while( IS_WHITE_SPACE(str[0]))
    {
        i = 0;
        while(str[i] != '\0')
        {
            str[i] = str[i + 1];
            i++;
        }
        str[i] = '\0';
    }
     
    j = get_length(str) - 1;
    while( IS_WHITE_SPACE(str[j]))
    {
        j--;
    }
    str[j+1]='\0';*/
    return str;
}   

void mem_set(char *ptr, char c, int size)
{
  while(size>0)
  {
    *ptr = c;
    ptr++;
    size--;
  }
}
int get_indian()
{
  char *char_ptr=(char *)&int_val;
  int val =*char_ptr;
  if(val== 0x1A)
   return BIG_INDIAN;
  else
   return LITTLE_INDIAN;
}

int str_cmp(char *s, char *t)
{
 for(int i=0; s[i]==t[i];i++)
  if(s[i]=='\0')
   return 0;
  else
   return s[i]-t[i];
}

char *strstr(char *s, char *search_str)
{
  int i,j;
  if(*search_str =='\0')
   return s;
  for(i=0;s[i] != '\0'; i++)
  {
    if(s[i] == search_str[0])
    {
      for( j=1; search_str[j] != '\0'; j++)
      {
        if(s[i+j]!=search_str[j])
        {
         break;
        }
      }
      if(search_str[j] == '\0')
      {
       return &s[i];
      }
    }
  }
  return NULL;  
 }

int utilities_main()
{
    char ip_str[MAX_STR_SIZE],cp_str[MAX_STR_SIZE],m_str[MAX_STR_SIZE],me_str[MAX_STR_SIZE],c='Z',*cptr,*str,*tstr;
    
    printf("Enter the string\n");
      scanf("%[^\n]",ip_str);
    
    int value = ascii_to_int(ip_str);
    printf("The number is %d\n",value);
    
    cptr=&c;
    
    printf("Lower Case (from macro) of Z is %c\n",TO_LOWER(*cptr));
    printf("Upper case of a is %c\n",to_upper('a'));
    
    string_to_lower(ip_str);
    printf(" String Lower case is %s\n",ip_str);
    
    string_to_upper(ip_str);
    printf("String Upper case is %s\n", ip_str);
    
    str_copy(cp_str,ip_str);
    printf("Copied String is %s\n",cp_str);
    
    mem_copy(m_str, ip_str,3);
    printf("Copied Memory is %s\n",m_str);
    print_memory(ip_str,8);
    
    str = str_cat(str1, str2);
    printf(" String is %s\n", str);
    
    mem_set(me_str,'a',sizeof(me_str));
    printf("After Mem Set %s\n", me_str);
    
    printf("String before reversing %s\n", str2);
    string_reverse(str2);
    printf("String after reverse %s\n", str2);
    
    printf("The trimming string %s\n",tr_str);
    tstr = trim_string(tr_str);
    printf("String after trimming:%s",tstr);
    
    int ind = get_indian();
    if(IS_BIG_INDIAN)
     printf("\nBig Indian\n");
    else
     printf("\nLittle Indian\n");
     
    int cmp = str_cmp(str1,str2);
    if(!cmp)
     printf("\nStrings are same\n");
    else
     printf("\nStrings are not equal\n");
    printf("String is %s\n",str1);
    printf("Search String is %s\n",search);
    char *st = strstr(str1,search);
    if(st != NULL)
     printf("String found at index %ld\n",st-str1);
    else
     printf("String not found"); 
    
    return 0; 
}
#ifndef RELOCATABLE_OBJ
int main()
{
 utilities_main();
}
#endif 
