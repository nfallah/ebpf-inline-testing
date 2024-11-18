// set status of r0 and then exit.

void my_func()
{
    asm volatile(".byte 0xb7, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00" :::); // dst(r0) = 1
    //asm volatile(".byte 0x95, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00" :::); // EXIT
    // return; with or without an explicit return, the end of this function will call exit as the last insn.
}