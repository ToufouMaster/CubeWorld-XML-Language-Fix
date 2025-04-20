# CMakeList.txt : CMake project for CubeWorldXMLLanguageFix, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("CubeWorldXMLLanguageFix")

add_subdirectory(cwsdk)
# Add source to this project's executable.
add_library (CubeWorldXMLLanguageFix SHARED "CubeWorldXMLLanguageFix.cpp" "sqlite/sqlite3.c" "sqlite/sqlite3.h")
target_link_libraries (CubeWorldXMLLanguageFix LINK_PUBLIC cwsdk)
#target_link_directories (CubeWorldXMLLanguageFix PUBLIC cwsdk)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CubeWorldXMLLanguageFix PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
