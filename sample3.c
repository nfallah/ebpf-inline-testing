// Some register-based operations.

int my_func()
{
    int a = 7; // temporarily register 1
    asm volatile(".byte 0x07, 0x01, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00" :::); // dst(r1) += 17 (0x11)
    asm volatile(".byte 0x07, 0x02, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00" :::); // dst(r2) += 3 (0x03)
    asm volatile(".byte 0x1f, 0x21, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00" :::); // dst(r1) -= src(r2)
    asm volatile(".byte 0xbf, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00" :::); // dst(r0) = src(r1)
    return a; // return stack frame val pointing to literal 7

    // question -- how to actually return a r0 value we want this way? since r0 will always be overwritten by the high-level C var 'a'.
}