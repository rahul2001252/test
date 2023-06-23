main_test: utility_code_test.h character_input.h bit_manupulation.h state_transition_test.h va_list_test.h binary_search.h 
	gcc -g -DRELOCATABLE_OBJ -I. -c utility_code_test.c -o utility_code_test.o
	gcc -g -DRELOCATABLE_OBJ -I. -c character_input.c -o character_input.o
	gcc -g -DRELOCATABLE_OBJ -I. -c bit_manupulation.c -o bit_manupulation.o
	gcc -g -DRELOCATABLE_OBJ -I. -c state_transition_test.c -o state_transition.o
	gcc -g -DRELOCATABLE_OBJ -I. -c va_list_test.c -o va_list_test.o
	gcc -g -DRELOCATABLE_OBJ -I. -c binary_search.c -o binary_search.o

	gcc -I. -g utility_code_test.o character_input.o bit_manupulation.o state_transition.o va_list_test.o binary_search.o  main_test.c -o main_test

clean:
	rm maintest utility_code_test.o character_input.o bit_manupulation.o state_transition.o va_list_test.o binary_search.o
