# This file should be used as a template for creating new projects with Python wrapping using the CMake tools

###################################################################################
# To create your own project, replace "wrap_example" with the actual name of your project
cmake_minimum_required(VERSION 3.0)
# If you change the project name, you also need to change the folder name of
# `python/wrap_example_py`
project(wrap_example CXX C)
set(CXX_STANDARD 11)

###################################################################################
# Set the python version
set(WRAP_PYTHON_VERSION "Default" CACHE STRING "The Python version to use for wrapping")
if(WRAP_PYTHON_VERSION STREQUAL "Default")
  find_package(Python3 COMPONENTS Interpreter Development)
  find_package(PythonInterp REQUIRED)
  find_package(PythonLibs REQUIRED)

  set(GTSAM_PYTHON_VERSION "${Python3_VERSION_MAJOR}.${Python3_VERSION_MINOR}"
      CACHE
      STRING
      "The version of Python to build the wrappers against."
      FORCE)

else()
  find_package(PythonInterp ${WRAP_PYTHON_VERSION} EXACT REQUIRED)
  find_package(PythonLibs ${WRAP_PYTHON_VERSION} EXACT REQUIRED)
endif()

###################################################################################
# Add the local source directory for CMake
# Ensure that local folder is searched before library folders
include_directories(BEFORE "${PROJECT_SOURCE_DIR}")

###################################################################################
# Build static library from common sources
add_library(${PROJECT_NAME} SHARED src/greeting.h src/greeting.cpp)
target_link_libraries(${PROJECT_NAME})

###################################################################################
# Install library
install(TARGETS ${PROJECT_NAME} LIBRARY DESTINATION lib ARCHIVE DESTINATION lib RUNTIME DESTINATION bin)

###################################################################################
# Build Pybind wrapper
find_package(gtwrap)

set(WRAP_EXAMPLE_VERSION_STRING 0.0.1) # Needed for generating setup.py

option(WRAP_EXAMPLE_BUILD_PYTHON "Build the Python wrapper" ON)

if(WRAP_EXAMPLE_BUILD_PYTHON)
	# if (NOT GTSAM_TYPEDEF_POINTS_TO_VECTORS)
	# 	message(FATAL_ERROR "WRAP_EXAMPLE_BUILD_PYTHON requires GTSAM_TYPEDEF_POINTS_TO_VECTORS to be enabled but it is not.")
	# endif()
	set(WRAP_EXAMPLE_PY_INSTALL_PATH "${CMAKE_INSTALL_PREFIX}/python")
endif()
add_subdirectory(python)