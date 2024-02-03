#include <utility>

#include "data/ImageETL.hpp"
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_RESIZE_IMPLEMENTATION
#include "stb_image.h"
#include "stb_image_resize2.h"


ImageDataset::ImageDataset(std::vector<std::vector<float>> images, std::vector<int> labels, std::map<std::string, int> categories,
                           bool hasIntercept) : categories(std::move(categories)) {
    int cols = hasIntercept ? images[0].size() + 1 : images[0].size();

    X.resize((long long) images.size(), cols);
    for (int i = 0; i < images.size(); ++i) {
        if (hasIntercept) {
            X(i, 0) = 1.0f;
        }
        for (int j = 0; j < images[i].size(); ++j) {
            X(i, hasIntercept ? j + 1 : j) = images[i][j];
        }
    }
    Y.resize((long long) labels.size());
    for (int i = 0; i < labels.size();i++) {
        Y(i) = (float)labels[i];
    }
}

std::string ImageDataset::getCategory(int value) {
    for (const auto& pair : categories) {
        if (pair.second == value) {
            return pair.first;
        }
    }
    return "";
}

ImageETL::ImageETL(int width, int height) {
    requiredWidth = width;
    requiredHeight = height;
}

void ImageETL::extract(const std::string &directoryPath, const std::string& category) {
    int categoryNumber;
    if (categories.find(category) == categories.end()) {
        categories.insert({category, categoryIndex});
        categoryNumber = categoryIndex;
        categoryIndex++;
    } else categoryNumber = categories.at(category);

    for (const auto& file : std::filesystem::directory_iterator(directoryPath)) {
        if (!file.is_regular_file()) continue;
        images.push_back(processImage(file.path().string()));
        labels.push_back(categoryNumber);
    }
}

std::vector<float> ImageETL::processImage(const std::string &imagePath) {
    int width, height, channels;

    unsigned char *data = stbi_load(imagePath.c_str(), &width, &height, &channels, 1);
    unsigned char *resizedData = new unsigned char[requiredWidth * requiredHeight];
    stbir_resize_uint8_linear(data, width, height, 0, resizedData, requiredWidth, requiredHeight, 0, STBIR_1CHANNEL);
    std::vector<float> floatBasedImage;
    floatBasedImage.reserve(requiredWidth * requiredHeight);
    for (int i = 0; i < requiredWidth * requiredHeight; i++) {
        float pixelValue = static_cast<float>(data[i]) / 255.0f;
        floatBasedImage.push_back(pixelValue);
    }
    delete[] resizedData;
    stbi_image_free(data);
    return floatBasedImage;
}

ImageDataset ImageETL::toEigen(bool withIntercept) {
    return {images,labels,categories, withIntercept};
}

ImageDataset* ImageETL::toEigenPtr(bool withIntercept) {
    return new ImageDataset {images,labels,categories, withIntercept};
}

Eigen::MatrixXf ImageETL::getProcessedImage(const std::string &path) {
    std::vector<float> image = processImage(path);
    Eigen::Map<Eigen::MatrixXf> imageMatrix(image.data(), 1, image.size());
    return imageMatrix;
}



