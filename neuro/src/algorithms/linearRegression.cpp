#include <iostream>
#include "algorithms/linearRegression.hpp"

LinearRegression::LinearRegression(Eigen::MatrixXf X, Eigen::VectorXi Y, float alpha, int iterations) :
X(X), Y(Y), alpha(alpha), iterations(iterations) {
    theta = Eigen::MatrixXf::Zero(X.cols(), 1);
}

void LinearRegression::train() {
    gradientDescent();

    std::cout << "The final cost is : " << cost() << std::endl;
}

float LinearRegression::cost() {
    //Do the mean squared error regression
    int n = (int) X.rows();

    Eigen::VectorXf predictions = X * theta;
    Eigen::VectorXf errors = predictions - Y.cast<float>();
    Eigen::VectorXf squaredErrors = errors.array().square();

    return squaredErrors.sum() / (float) n;
}

Eigen::MatrixXf LinearRegression::gradientDescent() {
    int n = (int) X.rows();

    for (int i = 0; i < iterations; i++) {
        Eigen::VectorXf predictions = X * theta;
        Eigen::VectorXf gradient = (X.transpose() * (predictions - Y.cast<float>())) / (float) n;
        theta = theta - alpha * gradient;
    }
    return theta;
}


