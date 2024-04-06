#include <iostream>
#include <string>
#include "qp_testfunctions.h"

int main() {
    test_it(test_constructor_empty(), "Empty constructor");
    test_it(test_constructor_double(), "Double constructor");
    test_it(test_constructor_full(), "Full constructor");
    test_it(test_normalized(), "Normalized function");
    test_it(test_conjugate(), "Conjugate function");
    test_it(test_equals(), "Equal operator");
    test_it(test_isequalto(), "'Is equal' operator");
    test_it(test_neg(),"Negative operator");
    test_it(test_add_q(), "Quaternion addition");
    test_it(test_add_d(), "Double addition");
    test_it(test_add_f(), "Float addition");
    test_it(test_add_int(), "Integer addition");
    test_it(test_minus_q(), "Quaternion subtraction");
    test_it(test_minus_d(), "Double subtraction");
    test_it(test_minus_f(), "Float subtraction");
    test_it(test_minus_int(), "Integer subtraction");
    test_it(test_times_q(), "Quaternion multiplication");
    test_it(test_times_d(), "Double multiplication");
    test_it(test_times_f(), "Float multiplication");
    test_it(test_times_int(), "Integer multiplication");

    return 0;
}
