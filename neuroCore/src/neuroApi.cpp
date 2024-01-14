#include <neuroApi.hpp>

int hello_neuro() {
    return 377053450;
}

LinearRegressionNetwork getLRNetwork(const char* path) {
    ImageETL etl = ImageETL(600,600);
    etl.extract(path, 0);
    return LinearRegressionNetwork(etl.inputSize(), 1);
}