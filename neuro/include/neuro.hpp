#ifndef NEURO_HPP
#define NEURO_HPP
#include <neuro_export.hpp>
#include <vector>
#include <iostream>
#include "data/ImageETL.hpp"

extern "C" {


    NEURO_API const char* helloNeuro();

    NEURO_API void* getImageDataset(const char**, const char**);
};

#endif