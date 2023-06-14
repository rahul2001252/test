#include<stdio.h>

int g_myglobal_scope;
static int gs_myglobal_static_var;
char g_mychar;

double red(int *i, char *cstr, int *array)
{
    double red_var = 9.89900; 
    printf("this is red function\n");
    char *ptr= (char *)0x123;
    printf("fn: %s\n",ptr); 
    return red_var;
}

int orange(char *str, int b, float c)
{
    int a;
    int array[3] = { 1, 2, 3 };
    char str2[] = "hello";   
    printf("this is orange function\n");
    double ret = red( &a, str2, array );
    return 0;
} 

float yellow(char array[], char *c)
{
    char str[] = "yellow";
    int yel_var;
    float float_var;
    printf("this is yellow function\n");
    int ret = orange( str, yel_var, float_var );
    return 0;
}

char *green(int array[], char a)
{
    char array2[] = "hello";
    char b = 'E';
    printf("this is green function\n");
    float x = yellow( array2, &b );
    return &g_mychar;
}

int *blue(char *c, short int d)
{
    int array[] = { 1, 2 };
    char z = 'a';
    printf("this is blue function\n");
    char *x = green(array, z);
    return 0; 
}

char indigo(char a, int b)
{
    char x = 'a';
    short int d = 1;
    printf("this is indigo function\n");
    int *z = blue (&x, d);
    return x;
}

int violet(int a, int b)
{
    char x = 'a';
    int z = 5;
    printf("this is violet function");
    char y = indigo(x, z);
    return 1;
}

int main( int argc, char *argv[] )
{
    int a = 1;
    int b = 2;
    int z = violet( a, b );
    return 0;
} 
   
