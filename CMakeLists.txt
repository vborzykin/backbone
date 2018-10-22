cmake_minimum_required(VERSION 3.1)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5
    COMPONENTS
        Core Quick QuickControls2 QuickTemplates2
    REQUIRED)

add_subdirectory(backbone)
add_subdirectory(app)
