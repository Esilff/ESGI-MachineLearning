#include "networks/linearRegression.hpp"
#include <random>

LinearRegressionNetwork::LinearRegressionNetwork(int inputSize, int outputSize) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(0,1);

    weights = Eigen::MatrixXd (outputSize, inputSize).unaryExpr([&](auto dummy) {return d(gen);});
    biases = Eigen::VectorXd::Zero(outputSize);
}

void
LinearRegressionNetwork::train(const std::vector<Eigen::MatrixXd> &inputs, const std::vector<int> &labels, int epochs,
                               double learningRate) {
    for (int epoch = 0; epoch < epochs; epoch++) {
        double totalLoss = 0;
        for (size_t i = 0; i <inputs.size(); i++) {
            Eigen::VectorXd output = forward(inputs[i]);
            totalLoss += computeLoss(output, labels[i]);
            backward(inputs[i], output, labels[i], learningRate);
        }
        std::cout << "Epoch " << epoch << ", Loss: " << totalLoss / inputs.size() << std::endl;
    }
}

Eigen::VectorXd LinearRegressionNetwork::predict(const Eigen::MatrixXd& input) {
    return forward(input);
}

Eigen::VectorXd LinearRegressionNetwork::forward(const Eigen::MatrixXd& input) {
    return (weights * input).colwise() + biases;
}

double LinearRegressionNetwork::computeLoss(const Eigen::VectorXd& output, const int label) {
    Eigen::VectorXd labelVec = Eigen::VectorXd::Constant(output.size(), label);
    Eigen::VectorXd diff = output - labelVec;
    return diff.squaredNorm() / output.size();
}

void LinearRegressionNetwork::backward(const Eigen::MatrixXd& input, const Eigen::VectorXd& output, const int label, double learningRate) {
    Eigen::VectorXd labelVec = Eigen::VectorXd::Constant(output.size(), label);
    Eigen::VectorXd error = output - labelVec;

    Eigen::MatrixXd gradientW = error * input.transpose() / input.cols();
    Eigen::VectorXd gradientB = error / input.cols();

    weights -= learningRate * gradientW;
    biases -= learningRate * gradientB;
}

