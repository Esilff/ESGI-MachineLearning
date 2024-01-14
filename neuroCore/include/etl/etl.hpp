#ifndef N_ETL_H
#define N_ETL_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <Eigen/Dense>
#include <filesystem>


class ImageETL {
public:
    ImageETL(int width, int height) : globalWidth(width), globalHeight(height) {}
    void extract(const std::string&, int label);

    int inputSize();
    std::vector<Eigen::MatrixXd> inputs();

    std::vector<int> getLabels();

private:
    std::vector<Eigen::MatrixXd> images;
    std::vector<int> labels;

    int globalWidth;
    int globalHeight;

    Eigen::MatrixXd processImage(const std::string& filePath);
};

#endif