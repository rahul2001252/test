main_test: utility_code_test.h character_input.h bit_manupulation.h state_transition_test.h
	gcc -g -DRELOCATABLE_OBJ -I. -c utility_code_test.c -o utility_code_test.o
	gcc -g -DRELOCATABLE_OBJ -I. -c character_input.c -o utility_code_test.o
	gcc -g -DRELOCATABLE_OBJ -I. -c bit_manupulation.c -o bit_manupulation.o
	gcc -g -DRELOCATABLE_OBJ -I. -c state_transition_test.c -o state_transition.o
	gcc -I. -g utility_code_test.o character_input.o bit_manupulation.o state_transition.o main_test.c -o main_test
	
clean:
	rm maintest utility_code_test.o utility_code_test.o bit_manupulation.o state_transition.o

