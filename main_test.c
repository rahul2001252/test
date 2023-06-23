#include<stdio.h>
#include<stdlib.h>
#include "utility_code_test.h"
#include "state_transition_test.h"
#include "character_input.h"
#include "bit_manupulation.h"
#include "va_list_test.h"
#include "binary_search.h"

int main()
{
  int choice;
  do
  {
   printf("Enter your choice (0 to exit)\n1. Utilities\n2. Character Input\n3. Bit Manupulation\n4. State Transition\n5. Variable Length arguements\n6. Binary Search\n");
   scanf("%d",&choice);
   switch(choice)
   {
    case 1 : utilities_main();
              break;
    case 2 : character_input_main();
             break;
    case 3 : bit_manupulation_main();
             break;
    case 4 : state_transition_main();
             break;
    case 5 : va_main();
             break;
    case 6:  binary_search_main();
             break;
   }
  }while(choice !=0);
}
