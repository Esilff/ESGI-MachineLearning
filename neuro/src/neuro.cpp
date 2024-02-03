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