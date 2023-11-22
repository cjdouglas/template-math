# CMakeList.txt : CMake project for TemplateArithmetic, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.23)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# In source build guard
include(Prelude)

# Enable Hot Reload for MSVC compilers if supported.
include(MSVCHotReload)

project (
  "TemplateMath"
  VERSION 0.1.0
  DESCRIPTION "Template based math operations"
  LANGUAGES CXX
)

# Add source to this project's executable.
add_library (
  template_math 
  INTERFACE
)
target_include_directories(template_math INTERFACE include)

set_property(TARGET template_math PROPERTY LINKER_LANGUAGE CXX)
set_property(TARGET template_math PROPERTY CXX_STANDARD 17)

if (TM_BUILD_TESTS)
  add_subdirectory(test)
endif()
