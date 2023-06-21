#include <stdio.h>

unsigned int get_bit1(unsigned int no, int pos_start, int pos_end)
{
    unsigned int result, mask;
    mask = (~0u >> (31 - (pos_end - pos_start))) << pos_start;
    result = no & mask;
    return result;
}

unsigned int get_bit2(unsigned int no, int pos_start, int pos_end)
{
    unsigned int result, mask;
    mask = (~0u >> (31 - (pos_end - pos_start))) << pos_start;
    result = no & mask;
    result = result >> pos_start;
    return result;
}

unsigned int get_bit3(unsigned int no, int pos_start, int pos_end)
{
    unsigned int result, mask;
    mask = (~0u >> (31 - pos_end)) << pos_start;
    result = no & mask;
    result = result >> pos_start;
    return result;
}

void print_binary(unsigned int number)
{
    char binary_str[33] = {};
    for (int i = 31; i >= 0; i--)
    {
        if (number & 0x01)
            binary_str[i] = '1';
        else
            binary_str[i] = '0';
        number = number >> 1;
    }
    binary_str[32] = '\0';
    printf("Number after operation is %s\n", binary_str);
}

int main()
{
    unsigned int number = 0x0003f123;
    int pos_start, pos_end;

    printf("Enter Starting position: ");
    scanf("%d", &pos_start);
    
    printf("Enter Ending position: ");
    scanf("%d", &pos_end);
    
    printf("Number before operation is\n");
    print_binary(number);

    number = get_bit2(number, pos_start, pos_end);
    print_binary(number);

    return 0;
}

