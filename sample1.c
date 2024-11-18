// Jump forward with offset of 0 -- unconditional jump.

int my_func()
{
    asm volatile(".byte 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00" :::);
    return 0;
}