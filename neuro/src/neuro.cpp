#include "neuro.hpp"

const char* helloNeuro() {
    return "Hello from Neuro!";
}

void* getImageDataset(const char** paths, const char** categories) {
    ImageETL etl = ImageETL(150,150);
    std::vector<const char*> pathList;
    std::vector<const char*> catList;
    for (const char** p = paths; *p != nullptr; ++p) {
        pathList.push_back(*p);
    }
    for (const char** c = categories; *c != nullptr; ++c) {
        catList.push_back(*c);
    }
    for (int i = 0; i < pathList.size(); i++) {
        etl.extract(pathList[i], catList[i]);
        std::cout << "Extracting images from : " << pathList[i] << " (category : " << catList[i] << ")" << std::endl;
    }
    return etl.toEigenPtr(true);
}

void* trainLinearRegression(void* dataset, float alpha, int iterations) {
    ImageDataset* set = static_cast<ImageDataset*>(dataset);
    LinearRegression * lr = new LinearRegression(set->X, set->Y, alpha, iterations);
    lr->train();
    return lr;
}

void predictLinearRegression(void* model, void* dataset, const char* imagePath) {
    ImageETL etl = ImageETL(150,150);
    ImageDataset* data = static_cast<ImageDataset*>(dataset);
    LinearRegression* lr = static_cast<LinearRegression*>(model);
    int prediction = lr->predict(etl.getProcessedImage(imagePath))[0];
    std::cout << "Moba image was predicted as a : " << data->getCategory(prediction) << " the categoryId is " << prediction << std::endl;
}
