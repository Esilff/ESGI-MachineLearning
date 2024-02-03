#include <iostream>
#include "algorithms/linearRegression.hpp"
#include "data/ImageETL.hpp"

int main(void) {
    ImageETL etl = ImageETL(150,150);
    std::cout << "Extracting images..." << std::endl;
    etl.extract("C:\\Users\\Esilff\\Git\\ImageScrapper\\data\\moba","moba");
    etl.extract("C:\\Users\\Esilff\\Git\\ImageScrapper\\data\\fps","fps");
    etl.extract("C:\\Users\\Esilff\\Git\\ImageScrapper\\data\\rts","rts");
    std::cout << "Extraction done" << std::endl;
    ImageDataset id = etl.toEigen(true);
    LinearRegression lr = LinearRegression(id.X, id.Y, 0.0001, 50);
    lr.train();
    Eigen::MatrixXf input = etl.getProcessedImage("C:\\Users\\Esilff\\Downloads\\meilleurs-jeux-MOBA-pour-PC-1024x576.jpg");
    int prediction = (int) lr.predict(input)[0];
    std::cout << "Moba image was predicted as a : " << id.getCategory(prediction) << " the categoryId is " << prediction << std::endl;
    return 0;
}