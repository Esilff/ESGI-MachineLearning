#ifndef N_LINEARREGRESSION_HPP
#define N_LINEARREGRESSION_HPP
#include <Dense>

extern "C" {

class LinearRegression {
public:
    LinearRegression(const Eigen::MatrixXf &X, Eigen::VectorXf Y, float alpha, int iterations);

    void train();

    Eigen::VectorXf predict(Eigen::MatrixXf input);


private:
    Eigen::MatrixXf X;
    Eigen::VectorXf Y;

    Eigen::MatrixXf theta;
    float alpha;
    int iterations;

    float cost();

    Eigen::MatrixXf gradientDescent();


    };
};

#endif