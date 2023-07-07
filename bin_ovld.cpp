#include "bin_ovld.h"

Byte::Byte():byte(0){};

Byte::Byte( unsigned char value )
{
    byte = value ;
};

Byte::Byte( const unsigned int value )
{
    byte = (unsigned char) 0xff & value ;
};

Byte::Byte( const int value )
{
    byte = (unsigned char) 0xff & value ;
};

Byte::Byte( const long int value )
{
    byte = (unsigned char) 0xff & value ;
};

int Byte :: setBit( unsigned int bit_pos, unsigned int value = 1 )
{
    if(bit_pos > 7)
    {
        return STATUS_ERROR;
    }
    if( value)
    {
        byte = byte | (0x01 << bit_pos);
    }
    else
    {
        byte = byte & (~(0x01 << bit_pos));
    }
   
    return STATUS_SUCCESS;    
}

Byte::Byte( const char* value )
{
    char trim_str[BUFFER_SIZE + 1];
    char *trim_ptr;
    int trim_len = 0;
    int bit_pos;
    int i;
    this->byte = 0;
   
    strncpy(trim_str, value, BUFFER_SIZE);  
    trim_ptr = trim_string( trim_str);
    for( int i = 0;  trim_ptr[i] != '\0' ; i++)
    {
        if(trim_ptr[i] != '0' && trim_ptr[i] != '1')
        {
            //assert(0);
        }
        trim_len++;
    }
   
    for( i = trim_len -1, bit_pos = 0; i >= 0; i--)
    {
        if(trim_ptr[i] == '1')
        {
            setBit(bit_pos);
        }
        bit_pos++;
    }        
};

char* Byte ::trim_string(char *in_str)
{
    int f_index = -1;
    int l_index = -1;
    int idx;
   
    if( !in_str)
    {      
        printf("Error :Empty string\n");
        return NULL;
    }
   
    for(idx = 0; in_str[idx] != '\0'; idx++ )
    {    
        if(!(IS_SPACE(in_str[idx])) )
        {
            if( f_index == -1)
            {
                f_index = idx;
            }
            l_index = idx;
        }
     }
           
    if( f_index != -1 )
    {
        return in_str;
    }
       
    in_str[l_index+1] = '\0';

    for(idx = 0; f_index <= l_index && f_index >= 0; f_index++,idx++)
    {
        in_str[idx] = in_str[f_index];
    }
    in_str[idx] = '\0';
    //cout<<in_str;
    return in_str;
}


int Byte :: clearBit( unsigned int bit_pos)
{
    if(bit_pos > 7)
    {
        return STATUS_ERROR;
    }

    byte = byte & (~(0x01 << bit_pos));
       
    return STATUS_SUCCESS;

}

char* Byte :: getBitStr(char* buffer)
{
    if(!buffer)
    {
        cout << "NULL pointer in getBitString" << endl;
        return NULL;
    }
    char* temp_buff = buffer;
   
    for( int i = 7; i >= 0; i--)
    {
        if( (this->byte) & (0x01 << i))
        {
            *buffer = '1';
        }
        else
        {
            *buffer = '0';
        }
        buffer++;
    }
    *buffer = '\0';
    return temp_buff;
}
   
void Byte :: displayBits()
{
    char bit_str[10];    
    printf(" %s\n", getBitStr( bit_str));  
}

void Byte :: displayAllform()
{
  cout<<"Hexadecimal:"<<hex<<(unsigned int)byte;
}

Byte operator + ( const Byte &obja, const Byte &objb)
{
    unsigned int carry,c ;
    Byte objc;
    c = (unsigned int) obja.byte + (unsigned int)objb.byte;
    carry = (0x0100) & c;
    objc.byte = (unsigned char)c;
   
    return objc;
}
   
   

int main()
{
    char byteStr[10]=" 10011001";
    
    Byte b1(1), b2(4),b3;
    
    Byte long_b(10L);
    
    Byte obj_str = "10110011";
    
    obj_str.displayAllform();
    obj_str.displayBits();
    Byte long1 = 20L;
    //Byte c_b(byteStr);
    
    long_b.displayBits();
    //c_b.displayBits();
   
   long1.displayBits();
   
   
   /* a.setBit(5, 1);
    a.setBit(1);
    a.setBit(2);
    a.clearBit(2); */
    
    b3 = b1 + b2;

    b3.displayBits();
}
