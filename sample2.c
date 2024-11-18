// Jump BACKWARD with offset of -1 -- infinite loop jump?

// validates rule that JMP(offset) = goto insn(offset+1); JMP(-1) == goto insn(-1+1) == goto(0)

int my_func()
{
    int a = 7;
    asm volatile(".byte 0x05, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00" :::);
    return a;
}