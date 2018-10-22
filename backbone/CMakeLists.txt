project(backbone)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5
    COMPONENTS
        Core Quick QuickControls2 QuickTemplates2
    REQUIRED)

add_library(${PROJECT_NAME}
    include/backbone/appcontroller.h
    include/backbone/applicationframe.h
    include/backbone/args.h
    include/backbone/block.h
    include/backbone/blockpresenter.h
    include/backbone/container.h
    include/backbone/context.h
    include/backbone/global.h
    include/backbone/incubator.h
    include/backbone/module.h
    include/backbone/page.h
    include/backbone/pagepresenter.h
    include/backbone/presenter.h
    include/backbone/qmlcomponentscache.h
    include/backbone/qmlglobalscope.h
    include/backbone/qmlinjectorbuilder.h
    include/backbone/qmlinjector.h
    include/backbone/router.h

    src/appcontroller.cpp
    src/applicationframe.cpp
    src/args.cpp
    src/block.cpp
    src/blockpresenter.cpp
    src/componentscache.cpp
    src/componentscache.h
    src/container.cpp
    src/context.cpp
    src/global.cpp
    src/incubator.cpp
    src/module.cpp
    src/page.cpp
    src/pagepresenter.cpp
    src/presenter.cpp
    src/qmlcomponentscache.cpp
    src/qmlglobalscope.cpp
    src/qmlinjectorbuilder.cpp
    src/qmlinjector.cpp
    src/router.cpp
)
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        Qt5::Core
        Qt5::Gui
        Qt5::Qml
        Qt5::Quick
        Qt5::QuickControls2
        Qt5::QuickTemplates2
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include

    PRIVATE
        ${Qt5Core_PRIVATE_INCLUDE_DIRS}
        ${Qt5Gui_PRIVATE_INCLUDE_DIRS}
        ${Qt5Qml_PRIVATE_INCLUDE_DIRS}
        ${Qt5Quick_PRIVATE_INCLUDE_DIRS}
        ${Qt5QuickControls2_PRIVATE_INCLUDE_DIRS}
        ${Qt5QuickTemplates2_PRIVATE_INCLUDE_DIRS}
)

target_compile_definitions(${PROJECT_NAME}
    PRIVATE
        $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
