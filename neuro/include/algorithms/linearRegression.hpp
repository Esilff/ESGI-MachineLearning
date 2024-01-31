#ifndef N_LINEARREGRESSION_HPP
#define N_LINEARREGRESSION_HPP
#include <Eigen/Dense>

class LinearRegression {
public:
    LinearRegression();


    auto mean();

private:
    Eigen::MatrixXf X;
    Eigen::VectorXi Y;

    Eigen::MatrixXf theta;
    float alpha;
    int iterations;


};

#endif