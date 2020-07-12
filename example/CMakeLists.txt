# This file should be used as a template for creating new projects with Python wrapping using the CMake tools

###################################################################################
# To create your own project, replace "wrap_example" with the actual name of your project
cmake_minimum_required(VERSION 3.0)
project(wrap_example CXX C)
set(CXX_STANDARD 11)

###################################################################################
# Set the python version
set(WRAP_PYTHON_VERSION "Default" CACHE STRING "The Python version to use for wrapping")
if(WRAP_PYTHON_VERSION STREQUAL "Default")
  find_package(PythonInterp REQUIRED)
  find_package(PythonLibs REQUIRED)
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
# Copy the __init__.py file so Cython recognizes this as a package.
# This function also updates the contents to use the correct package name.
configure_file(${PROJECT_SOURCE_DIR}/__init__.py.in ${PROJECT_BINARY_DIR}/python/${PROJECT_NAME}/__init__.py)

###################################################################################
# (Strict) Copy over the setup.py file so we can build and install the package.
configure_file(${PROJECT_SOURCE_DIR}/setup.py ${PROJECT_BINARY_DIR}/python/setup.py COPYONLY)

###################################################################################
# Build Pybind wrapper
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/wrap/cmake")

set(WRAP_EXAMPLE_VERSION_STRING 0.0.1) # Needed for generating setup.py

if(WRAP_EXAMPLE_BUILD_PYTHON)
	# if (NOT GTSAM_TYPEDEF_POINTS_TO_VECTORS)
	# 	message(FATAL_ERROR "WRAP_EXAMPLE_BUILD_PYTHON requires GTSAM_TYPEDEF_POINTS_TO_VECTORS to be enabled but it is not.")
	# endif()
	set(WRAP_EXAMPLE_PY_INSTALL_PATH "${CMAKE_INSTALL_PREFIX}/python")
endif()
add_subdirectory(python)