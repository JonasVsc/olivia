cmake_minimum_required(VERSION 4.0)
project("olivia")

add_subdirectory(thirdparty)

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME} PRIVATE
	src/main.cpp
)

# PLATFORM

target_sources(${PROJECT_NAME} PRIVATE
	src/platform.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE
	SDL3::SDL3
)

# VOLK

target_link_libraries(${PROJECT_NAME} PRIVATE
	volk::volk_headers
)