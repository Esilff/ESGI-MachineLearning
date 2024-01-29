#ifndef N_LINEARREGRESSION_HPP
#define N_LINEARREGRESSION_HPP
#include <Eigen/Dense>

class LinearRegression {
public:
    LinearRegression();


    float cost();
private:
    Eigen::MatrixXf X;
    Eigen::VectorXi Y;


};

#endif