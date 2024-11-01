cmake_minimum_required(VERSION 3.30)
project("GUI")
set(App "test")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(EXECUTABLE_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/release/Linux/bin")
  
# Qt
find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)

set(INCLUDE_Qt5 ${Qt5Core_INCLUDE_DIRS} ${Qt5Widgets_INCLUDE_DIRS})
set(LIBS_Qt5 ${Qt5Core_LIBRARIESY} ${Qt5Widgets_LIBRARIES})
message(STATUS "INCLUDE_Qt5: ${INCLUDE_Qt5}")
message(STATUS "LIBS_Qt5 : ${LIBS_Qt5}")

include_directories(${CMAKE_SOURCE_DIR}/release/Linux/include)
include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${INCLUDE_Qt5})

set(LIBS ${LIBS} "${CMAKE_SOURCE_DIR}/release/Linux/lib/libcjson${CMAKE_SHARED_LIBRARY_SUFFIX}")

FILE(GLOB SOURCE src/*.cpp src/*/*.cpp icons.qrc)
FILE(GLOB HEADER src/*/*.h)

add_executable(
    ${App}
    ${SOURCE}
    ${HEADER}
)

target_link_libraries(
    ${App}
    ${LIBS_Qt5}
    ${LIBS}
)

