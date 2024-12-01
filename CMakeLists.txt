cmake_minimum_required(VERSION 3.16)
project(FlightBookingSystem)
set(CMAKE_CXX_STANDARD 17)

# Set up Qt (adjust Qt version and components based on your project)
find_package(Qt6 REQUIRED COMPONENTS Core Widgets)
include_directories(${CMAKE_SOURCE_DIR}/src)

set(SRC_FILES
        src/main.cpp
        src/MainWindow.cpp
)
# Enable automatic MOC, UIC, and RCC
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Add the main source file
add_executable(FlightBookingSystem main.cpp src/MainWindow.cpp src/MainWindow.h
        src/FirstClass.h
        src/FirstClass.cpp
        src/BookingClass.cpp
        src/BookingClass.h
        src/BusinessClass.cpp
        src/BusinessClass.h
        src/EconomyClass.cpp
        src/EconomyClass.h
)

# Link the Qt libraries to your executable
target_link_libraries(FlightBookingSystem Qt6::Core Qt6::Widgets)