#include "qp_quaternion.h"

namespace qp {
    quaternion::quaternion(): m_real(0.0), m_imag_i(0.0), m_imag_j(0.0), m_imag_k(0.0) {}
    quaternion::quaternion(double realin): m_real(realin), m_imag_i(0.0), m_imag_j(0.0), m_imag_k(0.0) {}
    quaternion::quaternion(double realin, double ipartin, double jpartin, double kpartin): m_real(realin), m_imag_i(ipartin), m_imag_j(jpartin), m_imag_k(kpartin) {}
    quaternion::~quaternion() {}
    quaternion quaternion::operator+(const quaternion& rs) {
        return quaternion(m_real+rs.getReal(), m_imag_i+rs.getImag_i(), m_imag_j+rs.getImag_j(), m_imag_k+rs.getImag_k());
    }
    quaternion quaternion::operator+(const double& rs) {
        return quaternion(m_real+rs, m_imag_i, m_imag_j, m_imag_k);
    }
    quaternion quaternion::operator+(const float& rs) {
        return (*this + (double) rs);
    }
    quaternion quaternion::operator+(const int& rs) {
        return (*this + (double) rs);
    }
    quaternion quaternion::operator-(const quaternion& rs) {
        return quaternion(m_real+rs.getReal(), m_imag_i+rs.getImag_i(), m_imag_j+rs.getImag_j(), m_imag_k+rs.getImag_k())
    }
    quaternion quaternion::operator-(const double& rs) {
        return (*this)+(-rs);
    }
    quaternion quaternion::operator-(const float& rs) {
        return (*this)-((double) rs));
    }
    quaternion quaternion::operator-(const int& rs) {
        return (*this)-((double) rs));
    }
}