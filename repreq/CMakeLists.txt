project(repreq)

add_definitions("-std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall")
#include_directories()

#file(GLOB REPREQ_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*)

add_executable(rep rep.cpp)
target_link_libraries(rep zmq)
install (TARGETS rep DESTINATION bin PERMISSIONS
    OWNER_EXECUTE OWNER_WRITE OWNER_READ GROUP_EXECUTE GROUP_WRITE GROUP_READ)

add_executable(req req.cpp)
target_link_libraries(req zmq)
install (TARGETS req DESTINATION bin PERMISSIONS
    OWNER_EXECUTE OWNER_WRITE OWNER_READ GROUP_EXECUTE GROUP_WRITE GROUP_READ)
