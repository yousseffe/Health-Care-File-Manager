cmake_minimum_required(VERSION 3.28)
project(Project)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Project
        Appointment.cpp
        Appointment.h
        Doctor.cpp
        Doctor.h
        FileHandler.cpp
        main.cpp
        PrimaryIndex_Doctor.h
        PrimaryIndex_Doctor.cpp
        PrimaryIndex_Appoinment.h
        PrimaryIndex_Appoinment.cpp
        SecondaryIndex_Doctor.h
        SecondaryIndex_Doctor.cpp
        Record.h
        Index.h
)
