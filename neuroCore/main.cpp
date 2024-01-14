#include <iostream>
#include "etl/etl.hpp"
#include "networks/linearRegression.hpp"



int main(void) {
    ImageETL etl = ImageETL(600,600);
    etl.extract(R"(C:\Users\Esilff\Git\ESGI-MachineLearning\moba)", 0);
    etl.extract(R"(C:\Users\Esilff\Git\ESGI-MachineLearning\downloaded_images)", 1);
    LinearRegressionNetwork lrn = LinearRegressionNetwork(etl.inputSize(), 2);
    lrn.train(etl.inputs(), etl.getLabels(), 10, 0.3);
    lrn.predict(etl.inputs()[0]);
    std::cout << "Test" << std::endl;
    return 0;
}