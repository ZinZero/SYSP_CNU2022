/*
 * CS:APP Data Lab
 *
 * <Please put your name and userid here>
 * Name : Jang Jin Young
 * Student Number : 202102695
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

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

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
/* Copyright (C) 1991-2020 Free Software Foundation, Inc.
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
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000,0x80000000) = 0,
 *            addOK(0x80000000,0x70000000) = 1,
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int addOK(int x, int y)
{
   int x_MSB = x >> 0x1F;                           // x 값을 31bit 만큼 right shift
   int y_MSB = y >> 0x1F;                           // y 값을 31bit 만큼 right shift
   int xy_MSB = (x + y) >> 0x1F;                    // x + y 한 값을 31bit 만큼 right shift
   return !((~(x_MSB ^ y_MSB) & (xy_MSB ^ x_MSB))); // x의 MSB와 y의 MSB nor한 값의 반대 값과 x + y의 MSB 값과 x의 MSB 값의 nor한 값의 &연산한 값의 반대 값을 출력한다.
}
/*
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x)
{
   int oddPositon = (0xAA << 8) + 0xAA;            // 변수 oddPositon에 0xAA를 8만큼 left shift하고 0xAA를 더한 값을 저장한다.
   oddPositon = (oddPositon << 0x10) + oddPositon; // oddPositon을 16만큼 left shift 하고 oddPositon을 더한 값을 다시 저장한다.

   return !((x & oddPositon) ^ oddPositon); // x와 oddPositon &연산한 값과 oddPositon을 ^한 값의 반대 값을 반환한다.
}
/*
 * bitNor - ~(x|y) using only ~ and &
 *   Example: bitNor(0x6, 0x5) = 0xFFFFFFF8
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitNor(int x, int y)
{
   return (~x & ~y); // x와 y값을 not 하고 그 값의 &연산 값을 반환한다.
}

/*
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf)
{
   int negativeValue = 0x80000000 ^ uf; // sign bit를 변경해준다.
   int exp = 0x7F800000 & uf;           // exp 필드의 값을 저장한다.
   int frac = 0x007FFFFF & uf;          // frac 필드의 값을 저장한다.
   if ((exp == 0x7F800000) && frac)
   { // exp의 값이 모두 1이고 frac의 값이 0이 아닐때 는 NaN
      return uf;
   }
   else
   {
      return negativeValue; // NaN이 아닌 경우에는 값을 반환한다.
   }
}
/*
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf)
{
   int exp = 0x7F800000 & uf; //  exp 필드의 값을 저장한다.
   int MSB = 0x80000000 & uf; // 부호 값을 저장한다.
   if (exp == 0x7F800000)
   {             // exp 필드의 값이 모두 1인지 판별 1이면 NaN
      return uf; // 값을 그대로 반환한다.
   }
   else if (exp == 0)
   {                          // exp 필드의 값이 모두 0이면  비정규화
      return MSB | (uf << 1); // uf값을 1만큼 left shift한 값과 MSB를 or 연산한 값을 반환한다.
   }
   else
   {                          // 나머지의 경우 정규화 인코딩
      return uf + 0x00800000; // exp의 +1해서 값을 반환해준다.
   }
}
/*
 * rempwr2 - Compute x%(2^n), for 0 <= n <= 30
 *   Negative arguments should yield negative remainders
 *   Examples: rempwr2(15,2) = 3, rempwr2(-35,3) = -3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int rempwr2(int x, int n)
{
   int denominator = (1 << n) + ~0; // left shift 연산으로 2의 n거듭제곱을 만들고 -1을 해준다.
   int remainder = x & denominator; // 나머지를 구해준다.

   // 음수 계산을 위한 과정
   int isDivisible = !!remainder;         // 나누어 떨어졌다면 0을, 나누어 떨어지지 않았다면 1을 저장하도록 한다.
   int twoPowerByN = isDivisible << n;    // 나머지가 0이면 0, 0이 아니면 2의 제곱을 가지도록 한다.
   int negTwoPowerByN = ~twoPowerByN + 1; // 2의 보수법을 이용해 음수 값을 구한다.
   int MSB = x >> 0x1F;                   // x의 MSB를 구해 음수인지 양수인지 판별한다.

   return remainder + (negTwoPowerByN & MSB);
   /*
   x가 양수이면 MSB 값이 0이라서 (negTwoPowerByN & MSB)값이 0이 된다. 따라서 더해도 값이 변하지 않는다.
   x가 음수이지만
   나머지가 0일 경우에는 negTwoPowerByN 값이 0이라서 (negTwoPowerByN & MSB)이 0이 된다. 따라서 더해도 값이 변하지 않는다.
   나머지가 0이 아닐 때는 양수로 나눈 나머지의 -2^n을 해서 나머지를 구한다.
   */
}
