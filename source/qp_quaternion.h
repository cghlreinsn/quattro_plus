#ifndef QP_QUATERNION_H
#define QP_QUATERNION_H

#include <iostream>
#include <cmath>

namespace qp {
    class quaternion {
    private:
        double m_real;
        double m_imag_i;
        double m_imag_j;
        double m_imag_k;
        double magnitude;
    public:
        quaternion();
        quaternion(double realin);
        quaternion(double realin, double ipartin, double jpartin, double kpartin);
        ~quaternion();
        inline double getReal() const {return m_real;}
        inline double getImag_i() const {return m_imag_i;}
        inline double getImag_j() const {return m_imag_j;}
        inline double getImag_k() const {return m_imag_k;}
        inline double getNorm() const {return magnitude;}
        quaternion normalized() const;
        quaternion conjugate() const;
        void operator=(const quaternion& rs);
        bool operator==(const quaternion& rs) const;
        quaternion operator-() const;
        quaternion operator+(const quaternion& rs) const;
        quaternion operator+(const double& rs) const;
        quaternion operator+(const float& rs) const;
        quaternion operator+(const int& rs) const;
        quaternion operator-(const quaternion& rs) const;
        quaternion operator-(const double& rs) const;
        quaternion operator-(const float& rs) const;
        quaternion operator-(const int& rs) const;
        quaternion operator*(const quaternion& rs) const;
        quaternion operator*(const double& rs) const;
        quaternion operator*(const float& rs) const;
        quaternion operator*(const int& rs) const;
        quaternion operator/(const quaternion& rs) const;
        quaternion operator/(const double& rs) const;
        quaternion operator/(const float& rs) const;
        quaternion operator/(const int& rs) const;
        
    };
    double abs(const quaternion& rs);
}

#endif
