
file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

set(SOURCES
  ../lib/vfs.c
  ../lib/vfs_local_fs.c
  ../lib/vfs_file.c
  client.c)

add_executable(vfs-client ${SOURCES})

target_link_libraries(vfs-client)
install(TARGETS RUNTIME DESTINATION bin)
