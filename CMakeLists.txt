cmake_minimum_required(VERSION 4.0)
project("olivia")

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME} PRIVATE
	src/main.cpp
)