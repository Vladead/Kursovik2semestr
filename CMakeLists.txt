cmake_minimum_required(VERSION 3.10)
project(Kursovik)

set(CMAKE_CXX_STANDARD 11)

add_executable(Kursovik main.cpp List1.h BlocksList.h LineWithMarker.h Form.h FormBlock.h Processing.cpp Processing.h Employer.cpp Employer.h JobSeeker.cpp JobSeeker.h Vacancy.cpp Vacancy.h JobInfo.cpp JobInfo.h)