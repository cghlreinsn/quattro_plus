#ifndef QP_QUATERNION_H
#define QP_QUATERNION_H

#include <cmath>

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
        inline double getReal() {return m_real}
        inline double getImag_i() {return m_imag_i}
        inline double getImag_j() {return m_imag_j}
        inline double getImag_k() {return m_imag_k}
        quaternion conjugate();
        double magnitude();
        quaternion operator=(const quaternion& rs);
        bool operator==(const quaternion& rs);
        quaternion operator+(const quaternion& rs);
        quaternion operator+(const double& rs);
        quaternion operator+(const float& rs);
        quaternion operator+(const int& rs);
        quaternion operator-(const quaternion& rs);
        quaternion operator-(const double& rs);
        quaternion operator-(const float& rs);
        quaternion operator-(const int& rs);
        quaternion operator*(const quaternion& rs);
        quaternion operator*(const double& rs);
        quaternion operator*(const float& rs);
        quaternion operator*(const int& rs);
        quaternion operator-(*this);
        
    };
    double abs(const quaternion&);
}

#endif