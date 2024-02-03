#include <iostream>
#include <utility>
#include "algorithms/linearRegression.hpp"

LinearRegression::LinearRegression(const Eigen::MatrixXf& X, Eigen::VectorXf Y, float alpha, int iterations) :
X(X), Y(std::move(Y)), alpha(alpha), iterations(iterations) {
    theta = Eigen::MatrixXf::Zero(X.cols(), 1);
}

void LinearRegression::train() {
    gradientDescent();
    std::cout << "The final cost is : " << cost() << std::endl;
}

Eigen::VectorXf LinearRegression::predict(Eigen::MatrixXf input) {
    Eigen::MatrixXf inputWithBias(input.rows(), input.cols() + 1);
    inputWithBias.col(0) = Eigen::VectorXf::Ones(input.rows());
    inputWithBias.block(0,1,input.rows(), input.cols()) = input;
    return inputWithBias * theta;
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

        if (!theta.allFinite()) {
            std::cerr << "Gradient descent resulted in nan/inf at iteration " << i << std::endl;
            break;
        }
    }
    return theta;
}


