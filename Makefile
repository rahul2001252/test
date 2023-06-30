C_COMPILER = gcc
CPP_COMPILER = g++
CPM_FLAGS = -g -Wall -fPIC -c -I.


all: create_rel_obj regular_elf_exec static_lib shared_lib elf_exec_using_static_lib elf_exec_using_shared_lib

create_rel_obj: utility_code_test.h character_input.h bit_manupulation.h state_transition_test.h va_list_test.h binary_search.h opp_concept_test.h
	$(C_COMPILER) $(CPM_FLAGS) -DRELOCATABLE_OBJ utility_code_test.c -o utility_code_test.o
	$(C_COMPILER) $(CPM_FLAGS) -DRELOCATABLE_OBJ character_input.c -o character_input.o
	$(C_COMPILER) $(CPM_FLAGS) -DRELOCATABLE_OBJ bit_manupulation.c -o bit_manupulation.o
	$(C_COMPILER) $(CPM_FLAGS) -DRELOCATABLE_OBJ state_transition_test.c -o state_transition.o
	$(C_COMPILER) $(CPM_FLAGS) -DRELOCATABLE_OBJ va_list_test.c -o va_list_test.o
	$(C_COMPILER) $(CPM_FLAGS) -DRELOCATABLE_OBJ binary_search.c -o binary_search.o
	$(CPP_COMPILER) $(CPM_FLAGS) -DRELOCATABLE_OBJ opp_concept_test_main.cpp -o opp_concept_test_main.o
	$(CPP_COMPILER) $(CPM_FLAGS) main_test.c -o main_test.o

regular_elf_exec: 
	$(CPP_COMPILER) -I. -g utility_code_test.o character_input.o bit_manupulation.o state_transition.o va_list_test.o binary_search.o opp_concept_test_main.o  main_test.o -o regular_elf_exec

clean:
	rm *.o main_test *.a

static_lib: create_rel_obj
	ar -rc libmy_test_static_lib.a utility_code_test.o character_input.o bit_manupulation.o state_transition.o va_list_test.o binary_search.o opp_concept_test_main.o main_test.o

shared_lib: create_rel_obj
	gcc -shared -o libmyTestDynamicLib.so utility_code_test.o character_input.o bit_manupulation.o state_transition.o va_list_test.o binary_search.o opp_concept_test_main.o main_test.o 

elf_exec_using_static_lib: static_lib
	$(CPP_COMPILER) main_test.o libmy_test_static_lib.a -o maintestwstaticlib.o 

elf_exec_using_shared_lib: shared_lib
	$(CPP_COMPILER) main_test.o -L. libmyTestDynamicLib.so -o maintestwSharedLib	
