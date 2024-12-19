#include "libbpf/src/libbpf.h"

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("please put arg for file to open\n");
        return 1;
    }
    
    struct bpf_object *obj = NULL;
    obj = bpf_object__open(argv[1]);
    if (!obj) {
        printf("Unable to open\n");
        return 1;
    }
    struct bpf_program *prog = NULL;
    bpf_object__for_each_program(prog, obj) {
        printf("%s and %s\n", bpf_program__name(prog), bpf_program__section_name(prog));
    }

    int error = bpf_object__load(obj);

    if (error < 0) {
       printf("Unable to load\n");
       return 1;
    }

    return 0;
}