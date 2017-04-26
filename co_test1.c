#include <stdlib.h>
#include <stdio.h>
#include "settings.h"
#include "libco.h"

//arm64: https://github.com/fluent/fluent-bit/issues/228
static int add(int a, int b, int c) {
    printf("test a=%d b=%d c=%d\n", a,b,c);
    return (a+b+c);
}

static void testco2() {
    printf("in testco2\n");
    printf("result=%d\n", add(1,2,3));
    exit(1);
}

static void testco() {
    printf("in testco\n");
    printf("result=%d\n", add(1,2,3));
    size_t out_size = 0;
    cothread_t lth = co_create(4096, testco2, &out_size);
    co_switch(lth);
}

int main() {
    size_t out_size = 0;
    cothread_t lth = co_create(4096, testco, &out_size);
    co_switch(lth);
    return 0;
}

