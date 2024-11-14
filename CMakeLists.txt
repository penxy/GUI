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

list(APPEND CMAKE_AUTOUIC_SEARCH_PATHS "ui")
set(INCLUDE_Qt5 ${Qt5Core_INCLUDE_DIRS} ${Qt5Widgets_INCLUDE_DIRS})
set(LIBS_Qt5 ${Qt5Core_LIBRARIESY} ${Qt5Widgets_LIBRARIES})
message(STATUS "INCLUDE_Qt5: ${INCLUDE_Qt5}")
message(STATUS "LIBS_Qt5 : ${LIBS_Qt5}")

include_directories(${CMAKE_SOURCE_DIR}/release/Linux/include)
include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${INCLUDE_Qt5})

set(LIBS ${LIBS} "${CMAKE_SOURCE_DIR}/release/Linux/lib/libcjson${CMAKE_SHARED_LIBRARY_SUFFIX}")

FILE(GLOB SOURCE 
    # src/*.cpp 
    # src/*/*.cpp 
    # src/*/*/*.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Base/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ListBar/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ListInfoItem/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/MainPage/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Message/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/normal/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/RightPage/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/RightPage/WidgetType/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Search/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/TalkBar/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/TalkBar/*/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/TitleBar/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ToolBar/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
    icons.qrc
)
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

