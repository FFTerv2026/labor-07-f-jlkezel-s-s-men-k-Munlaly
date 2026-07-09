cmake_minimum_required(VERSION 3.19)
project(Quotes LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

qt_add_executable(Quotes
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
)

qt_add_resources(Quotes "app_resources"
    PREFIX "/"
    FILES
        quotes.txt
        style.qss
)

target_link_libraries(Quotes
    PRIVATE
        Qt::Core
        Qt::Widgets
)

install(TARGETS Quotes
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET Quotes
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
