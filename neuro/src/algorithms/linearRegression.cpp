#include "algorithms/linearRegression.hpp"

auto LinearRegression::mean() {
    return X.colwise().mean();
}