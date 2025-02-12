#include "..\\include\\qp_quaternion.h"

namespace qp {
    quaternion::quaternion(): m_real(0.0), m_imag_i(0.0), m_imag_j(0.0), m_imag_k(0.0) {
        sqr_magnitude = (m_real*m_real) + (m_imag_i*m_imag_i) + (m_imag_j*m_imag_j) + (m_imag_k*m_imag_k);
        magnitude = std::sqrt(sqr_magnitude);
    }

    quaternion::quaternion(double realin): m_real(realin), m_imag_i(0.0), m_imag_j(0.0), m_imag_k(0.0) {
        sqr_magnitude = (m_real*m_real) + (m_imag_i*m_imag_i) + (m_imag_j*m_imag_j) + (m_imag_k*m_imag_k);
        magnitude = std::sqrt(sqr_magnitude);
    }

    quaternion::quaternion(double realin, double ipartin, double jpartin, double kpartin): m_real(realin), m_imag_i(ipartin), m_imag_j(jpartin), m_imag_k(kpartin) {
        sqr_magnitude = (m_real*m_real) + (m_imag_i*m_imag_i) + (m_imag_j*m_imag_j) + (m_imag_k*m_imag_k);
        magnitude = std::sqrt(sqr_magnitude);
    }
    
    quaternion::~quaternion() {}
    
    quaternion quaternion::normalized() const {
        return (*this)/magnitude;
    }
    
    quaternion quaternion::conjugate() const {
        return quaternion(m_real, -m_imag_i, -m_imag_j, -m_imag_k);
    }

    quaternion quaternion::inverse() const {
        return ((*this).conjugate()) / sqr_magnitude;
    }
    
    void quaternion::operator=(const quaternion& rs) {
        m_real = rs.getReal();
        m_imag_i = rs.getImag_i();
        m_imag_j = rs.getImag_j();
        m_imag_k = rs.getImag_k();
        sqr_magnitude = rs.getsqrNorm();
        magnitude = rs.getNorm();
    }
    
    bool quaternion::operator==(const quaternion& rs) const {
        bool samereal = (abs(m_real - rs.getReal()) < std::numeric_limits<double>::epsilon());
        bool same_i = (abs(m_imag_i - rs.getImag_i()) < std::numeric_limits<double>::epsilon());
        bool same_j = (abs(m_imag_j - rs.getImag_j()) < std::numeric_limits<double>::epsilon());
        bool same_k = (abs(m_imag_k - rs.getImag_k()) < std::numeric_limits<double>::epsilon());
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
            return (*this)*(rs.inverse());
        }
        else {
            double Nan = std::nan("inf");
            std::cout << "Division by 0 attempted.\n";
            return qp::quaternion(Nan,Nan,Nan,Nan);
        }
    }
    
    quaternion quaternion::operator/(const double& rs) const {
        if (rs != 0.0) {
            return quaternion(m_real/rs, m_imag_i/rs, m_imag_j/rs, m_imag_k/rs);
        }
        else {
            double Nan = std::nan("inf");
            std::cout << "Division by 0 attempted.\n";
            return qp::quaternion(Nan,Nan,Nan,Nan);
        }
    }
    
    quaternion quaternion::operator/(const float& rs) const {
        if (rs != 0.0f) {
            return (*this)/((double) rs);
        }
        else {
            double Nan = std::nan("inf");
            std::cout << "Division by 0 attempted.\n";
            return qp::quaternion(Nan,Nan,Nan,Nan);
        }
    }
    
    quaternion quaternion::operator/(const int& rs) const {
        if (rs != 0) {
            return (*this)/((double) rs);
        }
        else {
            double Nan = std::nan("inf");
            std::cout << "Division by 0 attempted.\n";
            return qp::quaternion(Nan,Nan,Nan,Nan);
        }
    }
    
    double abs(const quaternion& rs) {
        return rs.getNorm();
    }

    quaternion exp(const quaternion& pr) {
        double real = pr.getReal();
        double imag_i = pr.getImag_i();
        double imag_j = pr.getImag_j();
        double imag_k = pr.getImag_k();
        double theta = std::sqrt((imag_i*imag_i) + (imag_j*imag_j) + (imag_k*imag_k));
        double newreal = std::exp(real) * std::cos(theta);
        double imagcoef = (std::exp(real) / theta) * std::sin(theta);
        return quaternion(newreal, imagcoef*imag_i, imagcoef*imag_j, imagcoef*imag_k);
    }

    namespace rotation3d {
        void rotate_point_around(const double& angle, double& orig_x, double& orig_y, double& orig_z,
                                 const double& axis_x, const double& axis_y, const double& axis_z)
        {
            double axis_norm_sqr = (axis_x*axis_x) + (axis_y*axis_y) + (axis_z*axis_z);
            double axis_norm = std::sqrt(axis_norm_sqr);
            double x_ax = axis_x / axis_norm;
            double y_ax = axis_y / axis_norm;
            double z_ax = axis_z / axis_norm;
            double cosresult = std::cos(angle/2);
            double sinresult = std::sin(angle/2);
            quaternion rotator = quaternion(cosresult, x_ax * sinresult, y_ax * sinresult, z_ax *sinresult);
            quaternion oldpoint = quaternion(0, orig_x, orig_y, orig_z);
            quaternion newpoint = rotator * oldpoint * (rotator.inverse());
            orig_x = newpoint.getImag_i();
            orig_y = newpoint.getImag_j();
            orig_z = newpoint.getImag_k();
        }

        void rotate_point_around(quaternion& point, const quaternion& rotator) {
            point = rotator * point * (rotator.inverse());
        }

        quaternion point_rotated_around(const quaternion& point, const quaternion& rotator) {
            return rotator * point * (rotator.inverse());
        }
    }
}
