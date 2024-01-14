#ifndef NEUROCORE_H
#define NEUROCORE_H

#include <neurocore_export.hpp>
#include <networks/linearRegression.hpp>
#include <etl/etl.hpp>



extern "C" {
    NEURO_CORE_API int hello_neuro();

    NEURO_CORE_API LinearRegressionNetwork getLRNetwork(const char* path);


};

#endif