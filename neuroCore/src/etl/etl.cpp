#include "etl/etl.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

void ImageETL::extract(const std::string & directoryPath, int label) {
    for (const auto& file : std::filesystem::directory_iterator(directoryPath)) {
        if (!file.is_regular_file()) continue;
        images.push_back(processImage(file.path().string()));
        labels.push_back(label);
    }
}

Eigen::MatrixXd ImageETL::processImage(const std::string &filePath) {
    int width, height, channels;

    unsigned char* data = stbi_load(filePath.c_str(), &width, &height, &channels, 0);

    if (data == nullptr) {
        std::cerr << "Error loading image: " << filePath << std::endl;
        return Eigen::MatrixXd();
    }

    Eigen::MatrixXd resizedImage(globalHeight, globalWidth);
    for (int i = 0; i < globalHeight; ++i) {
        for (int j = 0; j < globalWidth; ++j) {
            // Nearest neighbor interpolation
            int nearestI = static_cast<int>(height * i / static_cast<double>(globalHeight));
            int nearestJ = static_cast<int>(width * j / static_cast<double>(globalWidth));
            int index = (nearestI * width + nearestJ) * channels;

            if (channels == 1) {
                resizedImage(i, j) = static_cast<double>(data[index]) / 255.0;
            } else {
                double gray = (data[index] + data[index + 1] + data[index + 2]) / 3.0 / 255.0;
                resizedImage(i, j) = gray;
            }
        }
    }
    stbi_image_free(data);
    return resizedImage;
}