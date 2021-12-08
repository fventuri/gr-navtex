find_package(PkgConfig)

PKG_CHECK_MODULES(PC_NAVTEX navtex)

FIND_PATH(
    NAVTEX_INCLUDE_DIRS
    NAMES navtex/api.h
    HINTS $ENV{NAVTEX_DIR}/include
        ${PC_NAVTEX_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    NAVTEX_LIBRARIES
    NAMES gnuradio-navtex
    HINTS $ENV{NAVTEX_DIR}/lib
        ${PC_NAVTEX_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
          )

include("${CMAKE_CURRENT_LIST_DIR}/navtexTarget.cmake")

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(NAVTEX DEFAULT_MSG NAVTEX_LIBRARIES NAVTEX_INCLUDE_DIRS)
MARK_AS_ADVANCED(NAVTEX_LIBRARIES NAVTEX_INCLUDE_DIRS)
