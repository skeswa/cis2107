#include <stdio.h>


unsigned int add(unsigned int, unsigned int);
unsigned int sub(unsigned int, unsigned int);
unsigned int mul(unsigned int, unsigned int);
unsigned int lt(unsigned int, unsigned int);
unsigned int gt(unsigned int, unsigned int);
unsigned int getByte(unsigned int, unsigned int);
unsigned int reverse(unsigned int);

int main(int argc, char **argv)
{
    unsigned int i, j;
    printf("Enter an integer ");
    scanf("%u", &i);
    printf("\nEnter another integer ");
    scanf("%u", &j);
    printf("\ni + j = %u\n", add(i,j));
    printf("\ni - j = %u\n", sub(i,j));
    printf("\ni * j = %u\n", mul(i,j));
    printf("i > j = %s\n", (gt(i,j) ? "TRUE" : "FALSE"));
    printf("i < j = %s\n", (lt(i,j) ? "TRUE" : "FALSE"));
    printf("jth byte of i = %x\n", getByte(i,j));
    printf("%x in reverse is %x\n", i, reverse(i));
    return 0;
}

unsigned int add(unsigned int i, unsigned int j)
{
	unsigned int carry = 0, mask = 1, r = 0;
	while (mask != 0) {
		if (mask & i) {
			if (mask & j) {
				if (carry) {
					r = r | mask;
				} else {
					carry = 1;
				}
			} else {
				if (!carry) {
					r = r | mask;
				}
			}
		} else if (mask & j) {
			if (!carry) {
				r = r | mask;
			}
		} else {
			if (carry) {
				r = r | mask;
				carry = 0;
			}
		}
		mask = mask << 1;
	}
	return r;
}

unsigned int sub(unsigned int i, unsigned int j)
{
	return add(i, (~j + 1));
}

unsigned int mul(unsigned int i, unsigned int j)
{
	unsigned int total = 0;
	for (; j != 0; j = sub(j, 1)) {
	    	total = add(total, i);
	}
	return total;
}

/* returns non-zero if i is less than j or zero otherwise */
unsigned int lt(unsigned int i, unsigned int j)
{
	while (i != 0 && j != 0) {
		i = i >> 1;
		j = j >> 1;
	}
	return (i == 0) ? 1 : 0;
}

/* returns non-zero if i is greater than j or zero otherwise */
unsigned int gt(unsigned int i, unsigned int j)
{
	while (i != 0 && j != 0) {
		i = i >> 1;
		j = j >> 1;
	}
	return i;
}

/* returns the jth byte of i */
unsigned int getByte(unsigned int i, unsigned int j)
{
	unsigned int mask = 255;
	for (; j != 1 && j != 0; j = sub(j, 1)) {
		mask = mask << 8;
	}
	return i & mask;
}

/* returns the integer whose binary representation is the
   same as that of i in reverse. */
unsigned int reverse(unsigned int i)
{
	unsigned int mask = 1, r = 0, cursor = 31;
	while (cursor != 0) {
		r = r | ((mask & i) << cursor);
		i = i >> 1;
		cursor = sub(cursor, 1);	
	}
	return r;	
}
