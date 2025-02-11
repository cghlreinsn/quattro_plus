#ifndef QP_TESTER_H
#define QP_TESTER_H

#include <string>
#include "..\\include\\quattro_plus.h"

static const qp::quaternion qObj = qp::quaternion(1,1,1,1);

void test_it(const bool& testresult, std::string fname);
bool test_constructor_empty();
bool test_constructor_double();
bool test_constructor_full();
bool test_normalized();
bool test_conjugate();
bool test_inverse();
bool test_inverse_by_1();
bool test_equals();
bool test_isequalto();
bool test_neg();
bool test_add_q();
bool test_add_d();
bool test_add_f();
bool test_add_int();
bool test_minus_q();
bool test_minus_d();
bool test_minus_f();
bool test_minus_int();
bool test_times_q();
bool test_times_d();
bool test_times_f();
bool test_times_int();
bool test_div_q();
bool test_div_q0();
bool test_div_d();
bool test_div_d0();
bool test_div_f();
bool test_div_f0();
bool test_div_int();
bool test_div_int0();

bool test_abs();
bool test_exp();

#endif
