

file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

set(SOURCES
  ../lib/vfs.c
  ../lib/vfs_file.c
  ../lib/vfs_ftp.c
  ../lib/vfs_local_fs.c
  vfs_tests.c
  vfs_local_fs.c
  vfs_ftp.c)

add_executable(vfs-tests ${SOURCES})

find_library(CMOCKA_LIBRARY libcmocka.so.0)

target_link_libraries(vfs-tests ${CMOCKA_LIBRARY})
install(TARGETS RUNTIME DESTINATION bin)



