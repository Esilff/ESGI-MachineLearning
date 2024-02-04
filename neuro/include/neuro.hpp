#ifndef NEURO_HPP
#define NEURO_HPP
#include <neuro_export.hpp>
#include <vector>
#include <iostream>
#include "data/ImageETL.hpp"
#include "algorithms/linearRegression.hpp"

extern "C" {


    NEURO_API const char* helloNeuro();

    NEURO_API void* getImageDataset(const char**, const char**);

    NEURO_API void* trainLinearRegression(void*, float, int);

    NEURO_API const char* predictLinearRegression(void*,void*, const char*);
};

#endif