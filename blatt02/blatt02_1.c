
#include <stdio.h>
#include <stdint.h>

int main() {
  int16_t a_16, b_16, c_16;
  int32_t a_32, b_32, c_32;
  uint16_t a_u16, b_u16, c_u16;

  b_16 = a_16 = 22222;
  b_32 = a_32 = 22222;

  c_32 = a_32 + b_32;
  c_16 = a_16 + b_16;
  printf("a_32 + b_32 = %d + %d = %d \n\n", a_32, b_32, c_32);
  printf("a_16 + b_16 = %hd + %hd = %hd\n\n", a_16, b_16, c_16);

  a_u16 = a_16 + c_32;
  printf("a_16 + c_32 = %hd + %d = %hu\n\n", a_16, c_32, a_u16);

  a_u16 = 2222;
  b_u16 = -222;
  c_u16 = a_u16 + b_u16;
  printf("a_u16 + b_u16 = %hu(=%hd) + %hu(=%hd) = %hu(=%hd)\n\n", a_u16,
         a_u16, b_u16, b_u16, c_u16, c_u16);

  a_32 = 555;
  b_32 = 1001;
  c_16 = c_32 = a_32 * b_32;
  printf("c_16 = c_32 = a_32 * b_32\n");
  printf("%hd = %d = %d * %d\n\n", c_16, c_32, a_32, b_32);
  c_32 = c_16 = a_32 * b_32;
  printf("c_32 = c_16 = a_32 * b_32\n");
  printf("%d = %hd = %d * %d\n\n", c_32, c_16, a_32, b_32);

  return 0;
}
