add_library(neural 
neural/neuron.cpp)

target_include_directories(neural PRIVATE ${PROJECT_SOURCE_DIR}/include/neural)