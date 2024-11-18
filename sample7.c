#include <linux/types.h>
#include <bpf/bpf_helpers.h>

SEC("what")
void my_func()
{
    asm volatile(".byte 0xb7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00" :::); // dst(r0) = 0
}

char _license[] SEC("license") = "GPL";