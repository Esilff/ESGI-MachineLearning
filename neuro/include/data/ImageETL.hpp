#ifndef N_IMAGEETL_HPP
#define H_IMAGEETL_HPP
#include <string>
#include<Dense>
#include <filesystem>
#include <vector>
#include <map>

extern "C" {

struct ImageDataset {
    Eigen::MatrixXf X;
    Eigen::VectorXf Y;
    std::map<std::string, int> categories;

    ImageDataset(std::vector<std::vector<float>>, std::vector<int>,
                 std::map<std::string, int>, bool hasIntercept);

    std::string getCategory(int);
};

class ImageETL {
public:
    ImageETL(int, int);

    void extract(const std::string &directoryPath, const std::string &category);

    ImageDataset toEigen(bool withIntercept = false);

    ImageDataset *toEigenPtr(bool withIntercept);

    Eigen::MatrixXf getProcessedImage(const std::string &path);

private:
    std::vector<std::vector<float>> images;
    std::vector<int> labels;

    int categoryIndex = 0;
    std::map<std::string, int> categories;

    int requiredWidth;
    int requiredHeight;

    std::vector<float> processImage(const std::string &imagePath);
};

};

#endif