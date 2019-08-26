add_subdirectory(ABY_application)

add_executable(InsuranceCalculator insuranceCalculator.cpp)
target_link_libraries(InsuranceCalculator ABY_PFE ABY::aby ENCRYPTO_utils::encrypto_utils)

