// set status of r0 and then exit.

int my_func()
{
    asm volatile(".byte 0xb7, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00" :::); // dst(r0) = 1
    asm volatile(".byte 0x95, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00" :::); // EXIT
    return 7; // should this be unreachable?
    // answer: no; even commented out, compiler still sets r0 to SOME VALUE and exits.
}


// solution(?) MAKE IT VOID
//1) stops forcing r0 to be a value, only calls EXIT, so that's the only thing we have to omit.