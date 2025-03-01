// SWEN-250
// Larry Kiser December 5, 2023 version 1.0


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "bits.h"
#include "unit_tests.h"

// update the passed value:
// if shift is > 0 shift left by that number of positions (multiply)
// if shift is < 0 shift right by that number of positions (divide)
// if shift is 0 then do nothing.
void shift_value(unsigned int *p_value, int shift) {
    if (shift > 0) {
        *p_value <<= shift;  // Shift left (multiply by 2^shift)
    } else if (shift < 0) {
        *p_value >>= -shift; // Shift right (divide by 2^(-shift))
    }
    // If shift == 0, do nothing (no action required)
}



// update the passed value:
// position will be a number from 0 through 31.
// Set the bit in the passed value corresponding to the passed position.
// ONLY set the one bit in the passed value!
// e.g. if position is 1 you need to set the 2nd bit which is 0x02.
// Hint -- you can calculate the value by doing a left shift of 0x01
//         by that number of positions.
void set_bit(unsigned int *p_value, unsigned int position) {
    *p_value |= (1 << position); // Set the bit at the specified position
}


// update the passed value:
// all of the bits are switched to their opposite value.
// e.g. 0x000000ff becomes 0xffffff00
void flip_all(unsigned int *p_value) {
    *p_value = ~(*p_value); // Flip all bits using the bitwise NOT operator (~)
}


// update the passed value:
// ONLY clear the bit at the passed position. position is 0 through 31.
// all other bits must not be changed.
// e.g 0x0000008f is the passed value. position is 7 so updated value is
//     0x0000000f -- 1 << 7 is 0x80. 
// Create a mask -- this is where all of the bits are set to a 1 except
// for the one or few bits that are to be cleared (set to 0),.
// Steps to use:
//		value = 1 << bit_position // get the bit value from the position
//		mask = ~value ;
//		unsigned int *p_register &= mask ;
// Example:
//		goal is to clear bit 3 in the passed register.
//		unsigned int value = 1 << 3 ;	// convert the bit position into the corresponding value (8)
//		unsigned int mask = ~value ;	// flip very bit so the ONLY bit that is cleared is bit 3
//										// 0b0000 0000 0000 1000 -- value before flipping
//										// mask gets this: 0b1111 1111 1111 0111
//		unsigned int *p_register &= mask ;	// clear only bit 3!

void clear_bit(unsigned int *p_value, unsigned int position) {
    unsigned int mask = ~(1 << position); // Create a mask with all bits set to 1 except the target position
    *p_value &= mask; // Use the AND operation to clear the bit at the specified position
}


