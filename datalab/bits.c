/*
 * SWE2001 Data Lab
 *
 * <SooHyun Moon 2021315224>
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

// You will provide your solution to the Data Lab by
// editing the collection of functions in this source file.

// INTEGER CODING RULES:
//  
//   Replace the "return" statement in each function with one
//   or more lines of C code that implements the function. Your code 
//   must conform to the following style:
//  
//   int Funct(arg1, arg2, ...) {
//       /* brief description of how your implementation works */
//       int var1 = Expr1;
//       ...
//       int varM = ExprM;

//       varJ = ExprJ;
//       ...
//       varN = ExprN;
//       return ExprR;
//   }

//   Each "Expr" is an expression using ONLY the following:
//   1. Integer constants 0 through 255 (0xFF), inclusive. You are
//       not allowed to use big constants such as 0xffffffff.
//   2. Function arguments and local variables (no global variables).
//   3. Unary integer operations ! ~
//   4. Binary integer operations & ^ | + << >>
//     
//   Some of the problems restrict the set of allowed operators even further.
//   Each "Expr" may consist of multiple operators. You are not restricted to
//   one operator per line.

//   You are expressly forbidden to:
//   1. Use any control constructs such as if, do, while, for, switch, etc.
//   2. Define or use any macros.
//   3. Define any additional functions in this file.
//   4. Call any functions.
//   5. Use any other operations, such as &&, ||, -, or ?:
//   6. Use any form of casting.
//   7. Use any data type other than int.  This implies that you
//      cannot use arrays, structs, or unions.

//  
//   You may assume that your machine:
//   1. Uses 2s complement, 32-bit representations of integers.
//   2. Performs right shifts arithmetically.
//   3. Has unpredictable behavior when shifting if the shift amount
//      is less than 0 or greater than 31.


// EXAMPLES OF ACCEPTABLE CODING STYLE:
//   /*
//    * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
//    */
//   int pow2plus1(int x) {
//      /* exploit ability of shifts to compute powers of 2 */
//      return (1 << x) + 1;
//   }

//   /*
//    * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
//    */
//   int pow2plus4(int x) {
//      /* exploit ability of shifts to compute powers of 2 */
//      int result = (1 << x);
//      result += 4;
//      return result;
//   }

// FLOATING POINT CODING RULES

// For the problems that require you to implement floating-point operations,
// the coding rules are less strict.  You are allowed to use looping and
// conditional control.  You are allowed to use both ints and unsigneds.
// You can use arbitrary integer and unsigned constants. You can use any arithmetic,
// logical, or comparison operations on int or unsigned data.

// You are expressly forbidden to:
//   1. Define or use any macros.
//   2. Define any additional functions in this file.
//   3. Call any functions.
//   4. Use any form of casting.
//   5. Use any data type other than int or unsigned.  This means that you
//      cannot use arrays, structs, or unions.
//   6. Use any floating point data types, operations, or constants.


// NOTES:
//   1. Use the dlc (data lab checker) compiler (described in the handout) to 
//      check the legality of your solutions.
//   2. Each function has a maximum number of operations (integer, logical,
//      or comparison) that you are allowed to use for your implementation
//      of the function.  The max operator count is checked by dlc.
//      Note that assignment ('=') is not counted; you may use as many of
//      these as you want without penalty.
//   3. Use the btest test harness to check your functions for correctness.
//   4. Use the BDD checker to formally verify your functions
//   5. The maximum number of ops for each function is given in the
//      header comment for each function. If there are any inconsistencies 
//      between the maximum ops in the writeup and in this file, consider
//      this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */

#endif
/* Copyright (C) 1991-2021 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
/* 
 * allEvenBits - return 1 if all even-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allEvenBits(0xFFFFFFFE) = 0, allEvenBits(0x55555555) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allEvenBits(int x) { // uses 9 ops to get even bits 
 x &= x>> 16;
 x &= x>> 8;
 x &= x>> 4;
 x &= x >>2;
 x &= 0x1;
 return x;
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) { // gets odd bits on reverse of even 
 int a = 0xaa+(0xaa<<8)+(0xaa<<16)+(0xaa<<24);  
 return !((x&a)^a);
}
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) { // uses 4 bits to get argument of x and y
 return ~(~x| ~y);
}
/* 
 * bitOr - x|y using only ~ and & 
 *   Example: bitOr(6, 5) = 7
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitOr(int x, int y) { //uses for 4 ops using De Morgan's law
 return ~((~x) & (~y));// De Morgan's law 
}
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) { // uses application of De Morgan's law for x and y relation with or 
 return (~(~x & ~y) & ~(x & y));
}
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) { 
 int a = x+1;
 x = x+a; //x plus one is equal to x and uses de morgan's law to see if max 
 x = ~x;
 a = !a;
 x = x+a;
 return !x;
}
/*
 * isTmin - returns 1 if x is the minimum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmin(int x) { //does if opposite of tmax 
 return !((x^(~x+1)) + !x);
}
/* 
 * TMax - return maximum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmax(int x) {  //returns maximum of complement integers with 1 and 31 
 return ~(1<<31);
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(int x) { //returns minimum of complement integers
 return 1<<31;
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 
 *   Rating: 2
 */
int negate(int x) { //gets x returned when negative
 return ~x+1;
}
/* 
 * rotateLeft - Rotate x to the left by n
 *   Can assume that 0 <= n <= 31
 *   Examples: rotateLeft(0x87654321,4) = 0x76543218
 *   Legal ops: ~ & ^ | + << >> !
 *   Max ops: 25
 *   Rating: 3 
 */
int rotateLeft(int x, int n) { //ratates left by getting head and tail differentiated 
 int hm, lm;
 int high;
 int shift;
 shift = 33+ ~n;
 hm = ~0 << shift;
 lm = ~(~0<<n);
 high = ((x & hm) >> shift) &lm;
 return (x << n) | high;
}
/* 
 * rotateRight - Rotate x to the right by n
 *   Can assume that 0 <= n <= 31
 *   Examples: rotateRight(0x87654321,4) = 0x187654321
 *   Legal ops: ~ & ^ | + << >> !
 *   Max ops: 25
 *   Rating: 3 
 */
int rotateRight(int x, int n) { //rates right by differentiating head and tail into rotating to right
 int s = (32 +~n+1);
 int head = (1<< n) + ~1 + 1;
 int tail = ~(head << s);
 int t = (x >> n) & tail;
 int h = (x & head) << s;
 return t|h;
}

/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
 int s = 1<<31;
 int upperB = ~(s | 0x39);
 int lowB = ~0x30;
 upperB = s &(upperB+x) >> 31;
 lowB = s &(lowB+1+x)>>31;
 return !(upperB | lowB);
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) { 
 unsigned sign = ( uf >> 31) & 0x1;
 unsigned exp = (uf >> 23) & 0xFF;
 unsigned fraction = uf & 0x007FFFFF;
 int B = exp -127;
 if (B < 0)
   return 0;
 if (exp == 0xFF || B >= 31)
    return 0x80000000u;
 else{ 
  fraction = fraction | (1<<23);
  if ( B <= 23)
   fraction >>= (23 - B);
  else
   fraction <<= (B -23);
 }
  if(sign)
   return -fraction;
  else
   return fraction;
} 
 
