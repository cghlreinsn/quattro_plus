#include "qp_testfunctions.h"

void test_it(const bool& testresult, std::string fname) {
    if (testresult) {
        std::cout << "pass: ";
    }
    else {
        std::cout << "FAIL: ";
    }
    std::cout << fname << " test.\n";
}

bool test_constructor_empty() {
    qp::quaternion testcase = qp::quaternion();
    return ((testcase.getReal() == 0.0) &&
            (testcase.getImag_i() == 0.0) &&
            (testcase.getImag_j() == 0.0) &&
            (testcase.getImag_k() == 0.0) &&
            (testcase.getNorm() == 0.0));
}

bool test_constructor_double() {
    double testvalue = 3.1;
    qp::quaternion testcase = qp::quaternion(testvalue);
    return ((testcase.getReal() == testvalue) &&
            (testcase.getImag_i() == 0.0) &&
            (testcase.getImag_j() == 0.0) &&
            (testcase.getImag_k() == 0.0) &&
            (testcase.getNorm() == testvalue));
}

bool test_constructor_full() {
    double testval1 = 3.3;
    double testval2 = 10.9;
    double testval3 = 6.2;
    double testval4 = 12;
    qp::quaternion testcase = qp::quaternion(testval1,testval2,testval3,testval4);
    return ((testcase.getReal() == testval1) &&
            (testcase.getImag_i() == testval2) &&
            (testcase.getImag_j() == testval3) &&
            (testcase.getImag_k() == testval4) &&
            (testcase.getNorm()
             == std::sqrt((testval1*testval1)
              +           (testval2*testval2)
              +           (testval3*testval3)
              +           (testval4*testval4))));
}

bool test_normalized() {
    qp::quaternion testcase = qObj.normalized();
    return ((testcase.getReal() == 0.5) &&
            (testcase.getImag_i() == 0.5) &&
            (testcase.getImag_j() == 0.5) &&
            (testcase.getImag_k() == 0.5) &&
            (testcase.getNorm() == 1));
}

bool test_conjugate() {
    qp::quaternion testcase = qObj.conjugate();
    return ((testcase.getReal() == qObj.getReal()) &&
            (testcase.getImag_i() == -(qObj.getImag_i())) &&
            (testcase.getImag_j() == -(qObj.getImag_j())) &&
            (testcase.getImag_k() == -(qObj.getImag_k())));
}

bool test_equals() {
    qp::quaternion testcase = qObj;
    return ((testcase.getReal() == qObj.getReal()) &&
            (testcase.getImag_i() == qObj.getImag_i()) &&
            (testcase.getImag_j() == qObj.getImag_j()) &&
            (testcase.getImag_k() == qObj.getImag_j()) &&
            (testcase.getNorm() == qObj.getNorm()));
}

bool test_isequalto() {
    qp::quaternion test1 = qObj;
    qp::quaternion test2 = qObj.conjugate();
    return ((test1 == qObj) && !(test2 == qObj));
}

bool test_neg() {
    qp::quaternion negObj = -qObj;
    return (negObj == qp::quaternion(-qObj.getReal(),   -qObj.getImag_i(),
                                     -qObj.getImag_j(), -qObj.getImag_k()));
}

bool test_add_q() {
    qp::quaternion testcase = qp::quaternion(2,3,4,6);
    qp::quaternion testsum = testcase + qObj;
    return ((testsum.getReal() == testcase.getReal()+qObj.getReal()) &&
            (testsum.getImag_i() == testcase.getImag_i()+qObj.getImag_i()) &&
            (testsum.getImag_j() == testcase.getImag_j()+qObj.getImag_j()) &&
            (testsum.getImag_k() == testcase.getImag_k()+qObj.getImag_k()));
}

bool test_add_d() {
    double num = 3.1;
    qp::quaternion testcase = qObj + num;
    return ((testcase.getReal() == qObj.getReal()+num) &&
            (testcase.getImag_i() == qObj.getImag_i()) &&
            (testcase.getImag_j() == qObj.getImag_j()) &&
            (testcase.getImag_k() == qObj.getImag_k()));
}

bool test_add_f() {
    float num = 6.2f;
    qp::quaternion testcase = qObj + num;
    return ((testcase.getReal() == qObj.getReal()+num) &&
            (testcase.getImag_i() == qObj.getImag_i()) &&
            (testcase.getImag_j() == qObj.getImag_j()) &&
            (testcase.getImag_k() == qObj.getImag_k()));
}

bool test_add_int() {
    int num = 4;
    qp::quaternion testcase = qObj + num;
    return ((testcase.getReal() == qObj.getReal()+num) &&
            (testcase.getImag_i() == qObj.getImag_i()) &&
            (testcase.getImag_j() == qObj.getImag_j()) &&
            (testcase.getImag_k() == qObj.getImag_k()));
}

bool test_minus_q() {
    qp::quaternion testcase = qp::quaternion(2,4,6,9);
    qp::quaternion testdiff = testcase - qObj;
    return ((testdiff.getReal() == testcase.getReal() - qObj.getReal()) &&
            (testdiff.getImag_i() == testcase.getImag_i() - qObj.getImag_i()) &&
            (testdiff.getImag_j() == testcase.getImag_j() - qObj.getImag_j()) &&
            (testdiff.getImag_k() == testcase.getImag_k() - qObj.getImag_k()));
}

bool test_minus_d() {
    double num = 9.8;
    qp::quaternion testcase = qObj - num;
    return ((testcase.getReal() == qObj.getReal() - num) &&
            (testcase.getImag_i() == qObj.getImag_i()) &&
            (testcase.getImag_j() == qObj.getImag_j()) &&
            (testcase.getImag_k() == qObj.getImag_k()));
}

bool test_minus_f() {
    float num = 2.78f;
    qp::quaternion testcase = qObj - num;
    return ((testcase.getReal() == qObj.getReal() - num) &&
            (testcase.getImag_i() == qObj.getImag_i()) &&
            (testcase.getImag_j() == qObj.getImag_j()) &&
            (testcase.getImag_k() == qObj.getImag_k()));
}

bool test_minus_int() {
    int num = 6;
    qp::quaternion testcase = qObj - num;
    return ((testcase.getReal() == qObj.getReal() - num) &&
            (testcase.getImag_i() == qObj.getImag_i()) &&
            (testcase.getImag_j() == qObj.getImag_j()) &&
            (testcase.getImag_k() == qObj.getImag_k()));
}

bool test_times_q() {
    qp::quaternion testcase = qp::quaternion(3,9,6,5);
    qp::quaternion testprod = testcase * qObj;
    return ((testprod.getReal()
            == (testcase.getReal()*qObj.getReal())
             - (testcase.getImag_i()*qObj.getImag_i())
             - (testcase.getImag_j()*qObj.getImag_j())
             - (testcase.getImag_k()*qObj.getImag_k())) &&
            (testprod.getImag_i()
            == (testcase.getReal()*qObj.getImag_i())
             + (testcase.getImag_i()*qObj.getReal())
             + (testcase.getImag_j()*qObj.getImag_k())
             - (testcase.getImag_k()*qObj.getImag_j())) &&
            (testprod.getImag_j()
            == (testcase.getReal()*qObj.getImag_j())
             + (testcase.getImag_j()*qObj.getReal())
             + (testcase.getImag_k()*qObj.getImag_i())
             - (testcase.getImag_i()*qObj.getImag_k())) &&
            (testprod.getImag_k()
            == (testcase.getReal()*qObj.getImag_k())
             + (testcase.getImag_k()*qObj.getReal())
             + (testcase.getImag_i()*qObj.getImag_j())
             - (testcase.getImag_j()*qObj.getImag_k())));
}

bool test_times_d() {
    double num = 1.68;
    qp::quaternion testcase = qObj * num;
    return ((testcase.getReal() == qObj.getReal()*num) &&
            (testcase.getImag_i() == qObj.getImag_i()*num) &&
            (testcase.getImag_j() == qObj.getImag_j()*num) &&
            (testcase.getImag_k() == qObj.getImag_k()*num));

}

bool test_times_f() {
    float num = 3.7f;
    qp::quaternion testcase = qObj * num;
    return ((testcase.getReal() == qObj.getReal()*num) &&
            (testcase.getImag_i() == qObj.getImag_i()*num) &&
            (testcase.getImag_j() == qObj.getImag_j()*num) &&
            (testcase.getImag_k() == qObj.getImag_k()*num));
}

bool test_times_int() {
    int num = 8;
    qp::quaternion testcase = qObj *num;
    return ((testcase.getReal() == qObj.getReal()*num) &&
        (testcase.getImag_i() == qObj.getImag_i()*num) &&
        (testcase.getImag_j() == qObj.getImag_j()*num) &&
        (testcase.getImag_k() == qObj.getImag_k()*num));
}
