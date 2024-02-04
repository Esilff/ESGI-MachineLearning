#ifndef N_LINEARREGRESSION_HPP
#define N_LINEARREGRESSION_HPP
#include <Dense>
#include <fstream>

class LinearRegression {
public:
    LinearRegression(const std::string& modelPath);
    LinearRegression(const Eigen::MatrixXf &X, Eigen::VectorXf Y, float alpha, int iterations);

    void train();

    Eigen::VectorXf predict(Eigen::MatrixXf input);

    void saveModel(const std::string& path);
    void loadModel(const std::string& path);


private:
    Eigen::MatrixXf X;
    Eigen::VectorXf Y;

    Eigen::MatrixXf theta;
    float alpha;
    int iterations;

    float cost();

    Eigen::MatrixXf gradientDescent();


};

#endif