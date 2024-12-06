cmake_minimum_required(VERSION 3.28)
project(File)

set(CMAKE_CXX_STANDARD 17)

add_executable(File main.cpp
        Entity.h
        Doctor.h
        Appointment.h
        FileManager.h
        FileManager.cpp
        PrimaryIndex.h
        DoctorPrimaryIndex.h
        AppointmentPrimaryIndex.h
        PrimaryIndex.h
        SecondaryIndex.h
        DoctorSecondaryIndexForName.h
        AppointmentSecondaryForDoctorID.h)
