#include "algorithms/linearRegression.hpp"

LinearRegression::LinearRegression(Eigen::MatrixXf X, Eigen::VectorXi Y) :
    X(X), Y(Y) {}
auto LinearRegression::mean() {
    return X.colwise().mean();
}