if(WRAP_EXAMPLE_BUILD_PYTHON)
  set(PYBIND_WRAP_MODULE_NAME ${PROJECT_NAME})
  
  # Generate setup.py.
  file(READ "${PROJECT_SOURCE_DIR}/README.md" README_CONTENTS)
  configure_file(${PROJECT_SOURCE_DIR}/python/setup.py.in
                 ${PROJECT_BINARY_DIR}/setup.py)

  include(PybindWrap)

  add_custom_target(${PYBIND_WRAP_MODULE_NAME}_header DEPENDS "${PROJECT_SOURCE_DIR}/${PYBIND_WRAP_MODULE_NAME}.h")

  # ignoring the non-concrete types (type aliases)
  set(ignore
      )

  pybind_wrap(${PYBIND_WRAP_MODULE_NAME}_py # target
            ${PROJECT_SOURCE_DIR}/${PYBIND_WRAP_MODULE_NAME}.h # interface_header
            "${PYBIND_WRAP_MODULE_NAME}.cpp" # generated_cpp
            "${PYBIND_WRAP_MODULE_NAME}" # module_name
            "${PYBIND_WRAP_MODULE_NAME}" # top_namespace
            "${ignore}" # ignore_classes
            ${CMAKE_CURRENT_LIST_DIR}/pybind_wrapper.tpl
            ${PYBIND_WRAP_MODULE_NAME} # libs
            "${PYBIND_WRAP_MODULE_NAME};${PYBIND_WRAP_MODULE_NAME}_header" # dependencies
            OFF # use_boost
            )

  set(WRAP_EXAMPLE_MODULE_PATH ${PROJECT_BINARY_DIR}/${PYBIND_WRAP_MODULE_NAME})

  set_target_properties(${PYBIND_WRAP_MODULE_NAME}_py PROPERTIES
        INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib"
        INSTALL_RPATH_USE_LINK_PATH TRUE
        OUTPUT_NAME "${PYBIND_WRAP_MODULE_NAME}"
        LIBRARY_OUTPUT_DIRECTORY "${WRAP_EXAMPLE_MODULE_PATH}"
        DEBUG_POSTFIX "" # Otherwise you will have a wrong name
        RELWITHDEBINFO_POSTFIX "" # Otherwise you will have a wrong name
        )

  # Symlink all tests .py files to build folder.
  create_symlinks("${CMAKE_CURRENT_SOURCE_DIR}/${PYBIND_WRAP_MODULE_NAME}_py/"
                  "${WRAP_EXAMPLE_MODULE_PATH}")

  # Copy the __init__.py file so Cython recognizes this as a package.
  # This function also updates the contents to use the correct package name.
  configure_file(${CMAKE_CURRENT_LIST_DIR}/${PYBIND_WRAP_MODULE_NAME}_py/__init__.py.in ${WRAP_EXAMPLE_MODULE_PATH}/__init__.py)

  set(WRAP_EXAMPLE_PYTHON_INSTALL_TARGET python-install)
  add_custom_target(${WRAP_EXAMPLE_PYTHON_INSTALL_TARGET}
    COMMAND ${PYTHON_EXECUTABLE} ${PROJECT_BINARY_DIR}/setup.py install
    WORKING_DIRECTORY ${PROJECT_BINARY_DIR})

endif()
