project(TestApp)


add_executable(${PROJECT_NAME}
    src/entities/entity.cpp
    src/entities/entity.h
    src/entities/branch.cpp
    src/entities/branch.h
    src/entities/corecontext.cpp
    src/entities/corecontext.h
    src/main.cpp
    src/presenters/consts.cpp
    src/presenters/consts.h
    src/presenters/detailpagepresenter.cpp
    src/presenters/detailpagepresenter.h
    src/presenters/indexpagepresenter.cpp
    src/presenters/indexpagepresenter.h
    src/presenters/searchpagepresenter.cpp
    src/presenters/searchpagepresenter.cpp
    src/presenters/searchpagepresenter.h
    src/presenters/searchpagepresenter.h
    src/types.cpp
    src/types.h
    src/usecases/downloaddatausecase.cpp
    src/usecases/downloaddatausecase.h
    src/usecases/usersearchusecase.cpp
    src/usecases/usersearchusecase.h
    qml.qrc
)


target_link_libraries(${PROJECT_NAME}
    PUBLIC
        Qt5::Core
        Qt5::Quick
        backbone::backbone
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}/deps
    )


target_compile_definitions(${PROJECT_NAME}
    PRIVATE
        $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
