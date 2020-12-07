# This file should be used as a template for creating new projects with Python wrapping using the CMake tools

###################################################################################
# To create your own project, replace "wrap_example" with the actual name of your project
cmake_minimum_required(VERSION 3.12)
# If you change the project name, you also need to change the folder name of
# `python/wrap_example_py`
project(wrap_example CXX C)
set(CXX_STANDARD 11)

###################################################################################
# Set the python version
set(WRAP_PYTHON_VERSION "Default"
    CACHE STRING
    "The Python version to use for wrapping")

# Unset default values so that `find_package` can set the correct ones.
unset(Python_EXECUTABLE CACHE)
unset(Python_INCLUDE_DIR CACHE)
unset(Python_MAJOR_VERSION CACHE)

if(WRAP_PYTHON_VERSION STREQUAL "Default")
  # Check for Python3 or Python2 in order
  find_package(Python COMPONENTS Interpreter Development)

  set(WRAP_PYTHON_VERSION "${Python_VERSION_MAJOR}.${Python_VERSION_MINOR}"
      CACHE
      STRING
      "The version of Python to build the wrappers against."
      FORCE)

else()
  find_package(Python ${WRAP_PYTHON_VERSION}
               COMPONENTS Interpreter Development
               EXACT
               REQUIRED)
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
# This is our in-house wrapper project which parses an interface file to generate the wrapper.
# Installing it follows the standard CMake process.
find_package(gtwrap)

set(WRAP_EXAMPLE_VERSION_STRING 1.0.0) # Needed for generating setup.py

option(WRAP_EXAMPLE_BUILD_PYTHON "Build the Python wrapper" ON)

if(WRAP_EXAMPLE_BUILD_PYTHON)
	# if (NOT GTSAM_TYPEDEF_POINTS_TO_VECTORS)
	# 	message(FATAL_ERROR "WRAP_EXAMPLE_BUILD_PYTHON requires GTSAM_TYPEDEF_POINTS_TO_VECTORS to be enabled but it is not.")
	# endif()
	set(WRAP_EXAMPLE_PY_INSTALL_PATH "${CMAKE_INSTALL_PREFIX}/python")
endif()
add_subdirectory(python)