#ifndef N_LINEARREGRESSION_HPP
#define N_LINEARREGRESSION_HPP
#include <Eigen/Dense>

class LinearRegression {
public:
    LinearRegression(Eigen::MatrixXf X, Eigen::VectorXi Y, float alpha, int iterations);

    void train();



private:
    Eigen::MatrixXf X;
    Eigen::VectorXi Y;

    Eigen::MatrixXf theta;
    float alpha;
    int iterations;

    float cost();
    Eigen::MatrixXf gradientDescent();



};

#endif