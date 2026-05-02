cmake_minimum_required(VERSION 3.14)
project(M2G1StudentManagement)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
include_directories(include)
# Fetch xlnt
FetchContent_Declare(
  xlnt
  GIT_REPOSITORY https://github.com/tfussell/xlnt.git
  GIT_TAG master
)
FetchContent_MakeAvailable(xlnt)

# Fetch tabulate
FetchContent_Declare(
  tabulate
  GIT_REPOSITORY https://github.com/p-ranav/tabulate.git
  GIT_TAG master
)
FetchContent_MakeAvailable(tabulate)
set(SOURCES
    src/main.cpp
    src/Student.cpp
    src/ExcelUtils.cpp
    src/MenuUtils.cpp
)


# Add your main.cpp or other source files
add_executable(M2G1StudentManagement ${SOURCES})
# Tell the compiler where to find all the headers 
target_include_directories(M2G1StudentManagement PRIVATE include )
# Link libraries
target_link_libraries(M2G1StudentManagement PRIVATE xlnt tabulate)


# COnfiguration for running on window machine
add_custom_command(TARGET M2G1StudentManagement POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_SOURCE_DIR}/build/_deps/xlnt-build/source/Release/xlnt.dll"
        $<TARGET_FILE_DIR:M2G1StudentManagement>)

