#include "main.h"
#include <assert.h>

void test_kv_num() {
    assert(kv_num(10) == 14916253649);
}

void test_num_pos() {
    assert(num_pos(9,10,49,10) == 4);
}
#undef main
int main() {
    test_kv_num();
    test_num_pos();
}