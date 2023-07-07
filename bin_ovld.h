#ifndef BINARY_CODE
#define BINARY_CODE

#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>

using namespace std;

#define STATUS_SUCCESS    0
#define STATUS_ERROR     -1
#define BUFFER_SIZE      100
#define IS_SPACE(c)  ((c) == '\t' || \
             (c) == '\n' || \
     (c) == '\r' || \
     (c) == ' '  || \
                      (c) == '\v' || \
                      (c) == '\f')


class Byte
{
    private :        
        unsigned char byte;      
       
    public :
        Byte();
        Byte( unsigned char);
        Byte(unsigned int );
        Byte(int );
        Byte( long int);
        Byte( const char* );
        int setBit( unsigned int bit_pos, unsigned int value);
        int clearBit( unsigned int bit_pos);
        char* getBitStr( char* buffer);
        char* trim_string( char *);
        void displayBits(void);
        void displayAllform();
        friend Byte operator +( const Byte &, const Byte & );
       
        
};

#endif
