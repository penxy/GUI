cmake_minimum_required(VERSION 3.30)
project("GUI")
set(App "test")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
add_compile_options(-g3)  # 添加-g3选项以生成更详细的调试信息


set(EXECUTABLE_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/release/Linux/bin")
  
# Qt
find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5 COMPONENTS Svg REQUIRED)

list(APPEND CMAKE_AUTOMOC_SEARCH_PATHS "./src/widget/form/rmchatdialog.ui")

set(INCLUDE_Qt5 ${Qt5Core_INCLUDE_DIRS} ${Qt5Widgets_INCLUDE_DIRS} ${Qt5Svg_INCLUDE_DIRS})
set(LIBS_Qt5 ${Qt5Core_LIBRARIESY} ${Qt5Widgets_LIBRARIES} ${Qt5Svg_LIBRARIES})
message(STATUS "INCLUDE_Qt5: ${INCLUDE_Qt5}")
message(STATUS "LIBS_Qt5 : ${LIBS_Qt5}")

include_directories(${CMAKE_SOURCE_DIR}/release/Linux/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/Model)
include_directories(${INCLUDE_Qt5})


FILE(GLOB SOURCE 
    # src/*.cpp 
    # src/*/*.cpp 
    # src/*/*/*.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Model/Base/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Model/ListBar/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Model/ToolBar/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Model/ChatBar/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Model/ChatBar/bubble/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Model/TitleBar/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Model/Search/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Model/Card/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Model/test/*.cpp
    
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Main/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Net/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Core/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Chat/*.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/src/widget/form/*.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/src/utils/*.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/args.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/icons.qrc
)
FILE(GLOB HEADER src/*/*.h)
FILE(GLOB LIBS
    ${CMAKE_CURRENT_SOURCE_DIR}/release/Linux/lib/gflags/libgflags${CMAKE_STATIC_LIBRARY_SUFFIX}
    ${CMAKE_CURRENT_SOURCE_DIR}/release/Linux/lib/libhv/libhv_static${CMAKE_STATIC_LIBRARY_SUFFIX}
)
message(STATUS LIBS = "${LIBS}")
SET(LIBS_SYS "-lpthread")

add_executable(
    ${App}
    ${SOURCE}
    ${HEADER}
)

target_link_libraries(
    ${App}
    ${LIBS_Qt5}
    ${LIBS}
    ${LIBS_SYS}
)

