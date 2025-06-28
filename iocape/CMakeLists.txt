find_package(peff REQUIRED)

file(GLOB HEADERS *.h *.hh)
file(GLOB SRC *.c *.cc)

set(IOCAPE_BUILD_SHARED TRUE CACHE BOOL "Build shared library")

add_library(iocape STATIC)
target_compile_definitions(iocape PRIVATE IOCAPE_IS_BUILDING=1)
set_property(TARGET iocape PROPERTY CXX_STANDARD 17)
target_include_directories(iocape PUBLIC $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/> $<INSTALL_INTERFACE:include/>)
target_link_libraries(iocape PUBLIC peff_base_static peff_containers_static)
set_target_properties(iocape PROPERTIES
    VERSION ${PROJECT_VERSION}
)

add_library(iocaped SHARED)
target_compile_definitions(iocaped PRIVATE IOCAPE_IS_BUILDING=1)
target_compile_definitions(iocaped PUBLIC IOCAPE_BUILD_SHARED=1)
set_property(TARGET iocaped PROPERTY CXX_STANDARD 17)
set_property(TARGET iocaped PROPERTY PUBLIC_HEADER "")
target_include_directories(iocaped PUBLIC $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/> $<INSTALL_INTERFACE:include/>)
target_link_libraries(iocaped PUBLIC peff_base peff_containers)
set_target_properties(iocaped PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    ARCHIVE FALSE
)

target_sources(iocape PRIVATE ${HEADERS} ${SRC})

if(IOCAPE_BUILD_SHARED)
    target_sources(iocaped PRIVATE ${HEADERS} ${SRC})
endif()

configure_file(
    config.h.in
    ${CMAKE_CURRENT_SOURCE_DIR}/generated/config.h
)

install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/generated/config.h DESTINATION ${CMAKE_INSTALL_PREFIX}/include/iocape/generated)

if(${IOCAPE_ENABLE_DEBUGGER})
endif()

install(TARGETS iocape iocaped
    EXPORT iocapeTargets
    LIBRARY DESTINATION lib/
    ARCHIVE DESTINATION lib/
    RUNTIME DESTINATION bin
)
install(FILES ${HEADERS} DESTINATION ${CMAKE_INSTALL_PREFIX}/include/iocape)

if(WIN32)
    add_subdirectory("win32")
endif()
