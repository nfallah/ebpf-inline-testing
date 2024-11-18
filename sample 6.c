#include <linux/bpf.h>
#include <linux/in.h>
#include <linux/if.h>
#include <linux/if_ether.h>
#include <linux/ip.h>
#include <linux/ipv6.h>
#include <linux/if_tunnel.h>
#include <linux/mpls.h>
#include <bpf/bpf_helpers.h>

SEC("socket")
void my_func()
{
    asm volatile(".byte 0xb7, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00" :::); // dst(r0) = 1
}

char _license[] SEC("license") = "GPL";