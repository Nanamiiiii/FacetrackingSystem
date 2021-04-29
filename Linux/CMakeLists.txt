cmake_minimum_required(VERSION 2.8.12)
project(face_tracker)

add_subdirectory(./lib/dlib-19.21)

find_package(OpenCV)

if (OpenCV_FOUND)
    include_directories(${OpenCV_INCLUDE_DIRS})
    add_executable(facetracker main.cpp FaceTracker.cpp FaceTracker.hpp)
    target_link_libraries(facetracker dlib ${OpenCV_LIBS})
endif()

