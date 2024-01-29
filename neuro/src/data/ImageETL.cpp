#include "data/ImageETL.hpp"
#define STBI_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "stb_image_resize2.h"

ImageDataset::ImageDataset(std::vector<std::vector<float>> images, std::vector<int> labels, std::map<std::string, int> categories,
                           bool hasIntercept) : categories(categories) {
    int cols = hasIntercept ? images[0].size() + 1 : images[0].size();

    X.resize(images.size(), cols);
    for (int i = 0; i < images.size(); ++i) {
        if (hasIntercept) {
            X(i, 0) = 1.0f;
        }
        for (int j = 0; j < images[i].size(); ++j) {
            X(i, hasIntercept ? j + 1 : j) = images[i][j];
        }
    }
    Y.resize(labels.size());
    for (int i = 0; i < labels.size();i++) {
        Y(i) = labels[i];
    }
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

