#include <stdio.h>
#include <stdarg.h>
#include <setjmp.h>
#include <cmocka.h>
#include "asfd.c"

static void sum_test(void **state){
    int result = add(7, 3);
    assert_int_equal(result, 10);
}

static void subtract_test(void **state){
    int result = subtract(7, 3);
    assert_int_equal(result, 4);
}

static void multiply_test(void **state){
    int result = multiply(7, 3);
    assert_int_equal(result, 21);
}

static void divide_test(void **state){
    int result = divide(9, 3);
    assert_int_equal(result, 3);
}

static void sum_negative_test(void **state){
    int result =add(-5, -3);
    assert_int_equal(result, -8);
}

static void subtract_negative_test(void **state){
    int result =subtract(3, 7);
    assert_int_equal(result, -4);
}

static void multiply_zero_test(void **state){
    int result =multiply(5, 0);
    assert_int_equal(result, 0);
}

static void divide_by_zero_test(void **state){
    int result = divide(10, 0);
    assert_int_equal(result, 0);
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(sum_test),
        cmocka_unit_test(subtract_test),
        cmocka_unit_test(multiply_test),
        cmocka_unit_test(divide_test),
        cmocka_unit_test(sum_negative_test),
        cmocka_unit_test(subtract_negative_test),
        cmocka_unit_test(multiply_zero_test),
        cmocka_unit_test(divide_by_zero_test)
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}