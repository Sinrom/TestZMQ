project(routerdealer)

add_definitions("-std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall")
#include_directories()

#file(GLOB ROUTERDEALER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*)

add_executable(rdproxy rdproxy.cpp)
target_link_libraries(rdproxy zmq)
install (TARGETS rdproxy DESTINATION bin PERMISSIONS
    OWNER_EXECUTE OWNER_WRITE OWNER_READ GROUP_EXECUTE GROUP_WRITE GROUP_READ)

add_executable(rdrep rep.cpp)
target_link_libraries(rdrep zmq)
install (TARGETS rdrep DESTINATION bin PERMISSIONS
    OWNER_EXECUTE OWNER_WRITE OWNER_READ GROUP_EXECUTE GROUP_WRITE GROUP_READ)

add_executable(rdreq req.cpp)
target_link_libraries(rdreq zmq)
install (TARGETS rdreq DESTINATION bin PERMISSIONS
    OWNER_EXECUTE OWNER_WRITE OWNER_READ GROUP_EXECUTE GROUP_WRITE GROUP_READ)
