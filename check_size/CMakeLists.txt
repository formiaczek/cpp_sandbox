cmake_minimum_required(VERSION 3.10)

project (check_container_size
	VERSION 0.1
	DESCRIPTION "Example program to demonstrate container size checking")

set(CMAKE_BUILD_TYPE Release)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(
  ${PROJECT_NAME}
  same_size.cpp
)



