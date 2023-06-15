/* This file checks wheather the bit at nth position is set or not. It also clears the bit at the nth position. The number is displayed in both Hexadecimal as well as
 Binary format*/
 
#include<stdio.h>

#define SET_BIT(no, pos) ((no) = (no) | (0x01<<(pos)))

#define CLEAR_BIT(no, pos) ((no) = (no) &(~ (0x01<<(pos))))

int s_bit(unsigned int number,int pos)
{
  number = (number | (0x01<<pos));
  return number;
}

int c_bit(unsigned int number, int pos)
{
  number = number & (~(0x01<<pos));
  return number;
}

void prin(unsigned int number)
{
  char binary_str[33] ={};
  for(int i=31;i>=0;i--)
  {
    if(number & 0x01)
      binary_str[i]='1';
    else
      binary_str[i]='0';
    number=number>>1;
  }
  binary_str[32] ='\0';
  printf(" Number is %s\n",binary_str);
}

int main()
{
  unsigned int number= 0x43AB;
  int pos,cpos;
  printf(" Number Before Set %x\n", number);
  prin(number);
  printf("\nEnter Position to change\n");
   scanf("%d",&pos);
  int result = SET_BIT(number,pos);
  printf(" \nNumber after set %x\n ",result);
  prin(result);
  printf("\n");
  printf("Enter Position to clear\n");
   scanf("%d",&cpos);
  int result1= CLEAR_BIT(number, cpos);
  printf(" \nNumber after clear %x\n ",result1);
  prin(result1);
  return 0;
}
 
