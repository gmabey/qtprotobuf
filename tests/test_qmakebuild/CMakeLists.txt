#set(TARGET wellknowntypes_test)
project(qmakebuild_test)

get_target_property (QT_QMAKE_EXECUTABLE Qt5::qmake IMPORTED_LOCATION)

add_custom_target(qmakebuild_test ALL
        COMMAND ${QT_QMAKE_EXECUTABLE} -o QMakefile ${CMAKE_CURRENT_SOURCE_DIR}/qmakebuild.pro
        COMMAND make -f QMakefile 
)

#install(CODE execute_process(COMMAND "make -f QMakefile install"))
