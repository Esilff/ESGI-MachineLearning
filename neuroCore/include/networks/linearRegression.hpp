#ifndef N_LINEARREGRESSION_H
#define N_LINEARREGRESSION_H


#include <Eigen/Dense>
#include <vector>
#include <cmath>
#include <iostream>


class LinearRegressionNetwork {
public:
    LinearRegressionNetwork(int inputSize, int outputSize);

    void train(const std::vector<Eigen::MatrixXd>& inputs, const std::vector<int>& labels, int epochs, double learningRate);
    Eigen::VectorXd predict(const Eigen::MatrixXd& input);

private:
    Eigen::MatrixXd weights;
    Eigen::VectorXd biases;

    Eigen::VectorXd forward(const Eigen::MatrixXd& intput);
    double computeLoss(const Eigen::VectorXd& output, const int label);
    void backward(const Eigen::MatrixXd& input, const Eigen::VectorXd& output, const int label, double learningRate);

};

#endif