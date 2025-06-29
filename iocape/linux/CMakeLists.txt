file(GLOB HEADERS *.h *.hh)
file(GLOB SRC *.c *.cc)
target_sources(iocape PRIVATE ${HEADERS} ${SRC})
target_link_libraries(iocape PRIVATE ws2_32)
if(IOCAPE_BUILD_SHARED)
    target_sources(iocaped PRIVATE ${HEADERS} ${SRC})
target_link_libraries(iocaped PRIVATE ws2_32)
endif()

install(FILES ${HEADERS} DESTINATION ${CMAKE_INSTALL_PREFIX}/include/iocape/win32)

