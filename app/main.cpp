/*
 * @file       main.cpp
 * @author     Adarsh Jagan S
 * @copyright  2018 Adarsh Jagan S
 * @brief      Example program for valgrind assignment
 */
#include <iostream>
#include <AnalogSensor.hpp>

int main() {
    AnalogSensor lightSensor(5);
    std::cout << "Averaged sensor reading: " << lightSensor.Read() << std::endl;
  // Initialized terminator to solve valgrind error.
  bool terminator = true;
    if (terminator) {
        std::cout << "DONE" << std::endl;
    }
    return 0;
}
