cmake_minimum_required( VERSION 2.6 )
project( ime_test )
find_package(SDL2 REQUIRED)

if ( WIN32 )
	find_file(SDL2DLL "SDL2.dll" PATHS "${CMAKE_CURRENT_BINARY_DIR}" REQUIRED)
endif ( WIN32 )

include_directories( ${SDL2_INCLUDE_DIRS} )

add_executable(
	ime_test
	main.c
	)
target_link_libraries( ime_test ${SDL2_LIBRARIES} )

# 'install' and 'package' targets.
set(CMAKE_INSTALL_SYSTEM_RUNTIME_DESTINATION .)
set(CMAKE_INSTALL_PREFIX install)
install(TARGETS ime_test
	RUNTIME DESTINATION .
	LIBRARY DESTINATION .
	ARCHIVE DESTINATION .
	)
install(FILES ${SDL2DLL} DESTINATION .)
SET(CPACK_GENERATOR "ZIP")
SET(CPACK_INCLUDE_TOPLEVEL_DIRECTORY 1)
SET(CPACK_MONOLITHIC_INSTALL 1)
SET(CPACK_COMPONENTS_ALL_IN_ONE_PACKAGE 1)
SET(CPACK_PACKAGE_FILE_NAME "ime_test")
include(CPack)
