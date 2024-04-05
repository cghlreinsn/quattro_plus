#ifndef QP_QUATERNION_H
#define QP_QUATERNION_H

namespace qp {
    class quaternion {
    private:
        double m_real;
        double m_imag_i;
        double m_imag_j;
        double m_imag_k;
    public:
        quaternion();
        quaternion(double realin);
        quaternion(double realin,double ipartin,double jpartin,double kpartin);
        ~quaternion();
        double getReal();
        double getImag_i;
        double getImag_j;
        double getImag_k;
        quaternion(const quaternion&);
        operator=();
        operator==();
        operator+();
        operator*();
    };
}

#endif