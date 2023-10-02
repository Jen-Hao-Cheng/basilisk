#include <architecture/utilities/avsEigenSupport.h>
#include <architecture/utilities/rigidBodyKinematics.h>

#include <iostream>

int main(int argc, char *argv[])
{
    Eigen::Matrix3d dcm_eigen;
    Eigen::MRPd sigma_eigen;

    double sigma[3] = {1. / 3, 1. / 3, 1. / 3};
    double dcm[3][3];

    sigma_eigen = cArray2EigenMRPd(sigma);
    dcm_eigen = sigma_eigen.toRotationMatrix().transpose();

    MRP2C(sigma, dcm);

    std::cout << dcm_eigen << std::endl;
    std::cout << "----------------" << std::endl;
    std::cout << dcm[0][0] << ", " << dcm[0][1] << ", "<< dcm[0][2] << std::endl;
    std::cout << dcm[1][0] << ", " << dcm[1][1] << ", "<< dcm[1][2] << std::endl;
    std::cout << dcm[2][0] << ", " << dcm[2][1] << ", "<< dcm[2][2] << std::endl;
    std::cout << "----------------" << std::endl;

    return 0;
}