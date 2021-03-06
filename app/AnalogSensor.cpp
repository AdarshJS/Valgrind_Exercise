/*
 * @file       AnalogSensor.cpp
 * @author     Adarsh Jagan S
 * @copyright  2018 Adarsh Jagan S
 * @brief      Example code for Valgrind exercise.
 *             
 */
#include <AnalogSensor.hpp>
#include<memory>
#include <numeric>
#include <vector>


AnalogSensor::AnalogSensor(unsigned int samples)
    : mSamples(samples) {
}

AnalogSensor::~AnalogSensor() {
}

int AnalogSensor::Read() {
  // Data leak was found in following line. Fixed using smart pointer.
  std::unique_ptr<std::vector<int>> readings =
      std::make_unique<std::vector<int>>(mSamples, 10);

    double result = std::accumulate(readings->begin(), readings->end(), 0.0) / readings->size();
    return result;
}


