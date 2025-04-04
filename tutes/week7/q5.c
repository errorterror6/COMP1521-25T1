Convert the following decimal numbers
 into IEEE 754-encoded bit-strings:

- divide by the largest power of 2.

 2.5 = 
 2.5 / 2 = 1.25
 2.5 = +      1.25   * 2^(128 - 127)
float= sign * 1.frac * 2^(exp - 127)
 sign: +
 frac: 0.25
 exp: 128

1.frac * 2^exp = 2.5
1.frac = 2.5 / 2^exp
1 <= 1.frac < 2
//we can satisfy when 2^exp is the largest
//that fits into our number.

 0.375
 0.375 / 0.25 = 1.5
 0.375 = +    1.5    * 2^(125 - 127)
 num   = sign 1.frac * 2^(exp - 127)
 sign: 0 +
 exp: 125, 0b01111101
 frac: 0.5 = 2^-1
bin: 1.1000000000000000000000
idx: 0.123456789

0 01111101 10000000000000000000000




 27.0
 27 / 16 = 1.6875
 27 =  1.6875 * 2^(131-127)
 num = 1.frac * 2^(exp - 127)
 sign: 0
 exp: 131 = 10000011
 frac: 0.6875 = 0.5 + 0.125 + 0.0625
      = 2^-1 + 2^-3 + 2^4
1011000000000000000000000
123456789

0 10000011 10110000000000000000000
