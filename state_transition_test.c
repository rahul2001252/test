#include<stdio.h>

#define STATE_A ('A')
#define STATE_B ('B')
#define STATE_C ('C')
#define STATE_D ('D')
#define STATE_E ('K')
#define STATE_J ('J')

char transition_state(char cur_state, int input)
{
  char next_state;
  next_state=cur_state;
  switch(cur_state)
   {
    case (STATE_A): if(input ==0)
                   {
                     next_state= STATE_C;
                   }
                   break;
    case (STATE_B): if(input ==2)
                   {
                    next_state = STATE_A;
                   }
                   break;
    case (STATE_C): if(input ==4)
                   {
                     next_state= STATE_D;
                   }
                   else if(input ==3)
                   {
                    next_state= STATE_B;
                   }
                   break;
    case (STATE_D): if(input ==5)
                   {
                     next_state= STATE_E;
                   }
                   else if(input== 8)
                   {
                    next_state=STATE_J;
                   }
                   break;
    case (STATE_E):  if(input ==6)
                     {
                      next_state= STATE_B;
                     }
                     else if(input ==4)
                     {
                       next_state= STATE_C;
                     }
                     break;
    case (STATE_J): if(input == 8)
                    {
                      next_state = STATE_E;
                    }
                    break;              
                   
    default : next_state = cur_state;
   }
  return next_state;
 }
 
 int main()
 {
   char state;
   int input;
   state = STATE_A;
   while(1)
   {
     printf("Enter Input :");
     scanf("%d",&input);
     if(input ==8888)
     {
       break;  
     }
       state=transition_state(state,input);
       
       printf("Current %c\n",state);
     }
   return 0;
 }
