#include "qp_quaternion.h"

namespace qp {
    quaternion::quaternion(): m_real(0.0), m_imag_i(0.0), m_imag_j(0.0), m_imag_k(0.0) {
        magnitude = std::sqrt((m_real*m_real) + (m_imag_i*m_imag_i) + (m_imag_j*m_imag_j) + (m_imag_k*m_imag_k));
    }

    quaternion::quaternion(double realin): m_real(realin), m_imag_i(0.0), m_imag_j(0.0), m_imag_k(0.0) {
        magnitude = std::sqrt((m_real*m_real) + (m_imag_i*m_imag_i) + (m_imag_j*m_imag_j) + (m_imag_k*m_imag_k));
    }

    quaternion::quaternion(double realin, double ipartin, double jpartin, double kpartin): m_real(realin), m_imag_i(ipartin), m_imag_j(jpartin), m_imag_k(kpartin) {
        magnitude = std::sqrt((m_real*m_real) + (m_imag_i*m_imag_i) + (m_imag_j*m_imag_j) + (m_imag_k*m_imag_k));
    }
    
    quaternion::~quaternion() {}
    
    quaternion quaternion::normalized() const {
        return (*this)/magnitude;
    }
    
    quaternion quaternion::conjugate() const{
        return quaternion(m_real, -m_imag_i, -m_imag_j, -m_imag_k);
    }
    
    void quaternion::operator=(const quaternion& rs) {
        m_real = rs.getReal();
        m_imag_i = rs.getImag_i();
        m_imag_j = rs.getImag_j();
        m_imag_k = rs.getImag_k();
        magnitude = rs.getNorm();
    }
    
    bool quaternion::operator==(const quaternion& rs) const {
        bool samereal = (m_real == rs.getReal());
        bool same_i = (m_imag_i == rs.getImag_i());
        bool same_j = (m_imag_j == rs.getImag_j());
        bool same_k = (m_imag_k == rs.getImag_k());
        return (samereal && same_i && same_j && same_k);
    }


    quaternion quaternion::operator-() const {
        return quaternion(-m_real, -m_imag_i, -m_imag_j, -m_imag_k);
    }
    
    quaternion quaternion::operator+(const quaternion& rs) const {
        return quaternion(m_real+rs.getReal(), m_imag_i+rs.getImag_i(), m_imag_j+rs.getImag_j(), m_imag_k+rs.getImag_k());
    }
    
    quaternion quaternion::operator+(const double& rs) const {
        return quaternion(m_real+rs, m_imag_i, m_imag_j, m_imag_k);
    }
    
    quaternion quaternion::operator+(const float& rs) const {
        return (*this + (double) rs);
    }
    
    quaternion quaternion::operator+(const int& rs) const {
        return (*this + (double) rs);
    }
    
    quaternion quaternion::operator-(const quaternion& rs) const {
        return quaternion(m_real-rs.getReal(), m_imag_i-rs.getImag_i(), m_imag_j-rs.getImag_j(), m_imag_k-rs.getImag_k());
    }
    
    quaternion quaternion::operator-(const double& rs) const {
        return (*this)+(-rs);
    }
    
    quaternion quaternion::operator-(const float& rs) const {
        return (*this)-((double) rs);
    }
    
    quaternion quaternion::operator-(const int& rs) const {
        return (*this)-((double) rs);
    }
    
    quaternion quaternion::operator*(const quaternion& rs) const {
        double new_real = (m_real*rs.getReal()) - (m_imag_i*rs.getImag_i()) - (m_imag_j*rs.getImag_j()) - (m_imag_k*rs.getImag_k());
        double new_i = (m_real*rs.getImag_i()) + (m_imag_i*rs.getReal()) + (m_imag_j*rs.getImag_k()) - (m_imag_k*rs.getImag_j());
        double new_j = (m_real*rs.getImag_j()) + (m_imag_j*rs.getReal()) + (m_imag_k*rs.getImag_i()) - (m_imag_i*rs.getImag_k());
        double new_k = (m_real*rs.getImag_k()) + (m_imag_k*rs.getReal()) + (m_imag_i*rs.getImag_j()) - (m_imag_j*rs.getImag_i());

        return quaternion(new_real, new_i, new_j, new_k);
    }
    
    quaternion quaternion::operator*(const double& rs) const {
        return quaternion(rs*m_real, rs*m_imag_i, rs*m_imag_j, rs*m_imag_k);
    }
    
    quaternion quaternion::operator*(const float& rs) const {
        return (*this)*((double) rs);
    }
    
    quaternion quaternion::operator*(const int& rs) const {
        return (*this)*((double) rs);
    }
    
    quaternion quaternion::operator/(const quaternion& rs) const {
        if (rs.getNorm() != 0.0) {
            return (*this)*(rs.conjugate()/rs.getNorm());
        }
        else {
            std::cout << "Division by 0 attempted.\n";
            return std::nan("inf");
        }
    }
    
    quaternion quaternion::operator/(const double& rs) const {
        if (rs != 0.0) {
            return quaternion(m_real/rs, m_imag_i/rs, m_imag_j/rs, m_imag_k/rs);
        }
        else {
            std::cout << "Division by 0 attempted.\n";
            return std::nan("inf");
        }
    }
    
    quaternion quaternion::operator/(const float& rs) const {
        if (rs != 0.0f) {
            return (*this)/((double) rs);
        }
        else {
            std::cout << "Division by 0 attempted.\n";
            return std::nan("inf");
        }
    }
    
    quaternion quaternion::operator/(const int& rs) const {
        if (rs != 0) {
            return (*this)/((double) rs);
        }
        else {
            std::cout << "Division by 0 attempted.\n";
            return std::nan("inf");
        }
    }
    
    double abs(const quaternion& rs) {
        return rs.getNorm();
    }    
}
