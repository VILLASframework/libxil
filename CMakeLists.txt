cmake_minimum_required (VERSION 3.10)

project(libxil C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3 -fPIC -Wno-int-conversion -Wno-pointer-to-int-cast -Wno-int-to-pointer-cast -Wl,--no-undefined")

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    message("Enabling debug mode")
	add_compile_definitions("DEBUG")
endif()

include(GNUInstallDirs)

file(GLOB SOURCES src/*.c orig/*/src/*.c)

add_library(xil SHARED ${SOURCES})

target_include_directories(xil PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/include/xilinx
	${CMAKE_CURRENT_SOURCE_DIR}/orig/common
)

target_include_directories(xil PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/include
)


include(FindPkgConfig QUIET)
if(PKG_CONFIG_FOUND)
	# convert lists of link libraries into -lstdc++ -lm etc..
	foreach(LIB ${CMAKE_CXX_IMPLICIT_LINK_LIBRARIES} ${PLATFORM_LIBS})
		set(PRIVATE_LIBS "${PRIVATE_LIBS} -l${LIB}")
	endforeach()

	# Produce a pkg-config file for linking against the shared lib
	configure_file("libxil.pc.in" "libxil.pc" @ONLY)
	install(FILES "${CMAKE_CURRENT_BINARY_DIR}/libxil.pc" DESTINATION ${CMAKE_INSTALL_LIBDIR})
endif()

install(TARGETS xil DESTINATION LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

file(GLOB HEADERS include/xilinx/*.h)

# Make sure we dont install symlinks
set (HEADERS_RESOLVED "")
foreach (HEADER ${HEADERS})
    get_filename_component(HEADER_RESOLVED "${HEADER}" REALPATH)
    list (APPEND HEADERS_RESOLVED "${HEADER_RESOLVED}")
endforeach()

install(FILES ${HEADERS_RESOLVED} DESTINATION include/xilinx)

set(CPACK_PACKAGE_VERSION_MAJOR "0")
set(CPACK_PACKAGE_VERSION_MINOR "1")
set(CPACK_PACKAGE_VERSION_PATCH "1")
set(CPACK_SOURCE_GENERATOR "TGZ")
set(CPACK_SOURCE_PACKAGE_FILE_NAME "${CMAKE_PROJECT_NAME}-${CPACK_PACKAGE_VERSION_MAJOR}.${CPACK_PACKAGE_VERSION_MINOR}")
set(CPACK_SOURCE_IGNORE_FILES "/build/;/.git/;~$;${CPACK_SOURCE_IGNORE_FILES}")
include(CPack)
