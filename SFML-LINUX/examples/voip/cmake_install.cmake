# Install script for directory: /home/unit-hacker/pac-man/SFML-LINUX/examples/voip

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "examples")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/SFML/examples/voip/voip" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/SFML/examples/voip/voip")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/SFML/examples/voip/voip"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/SFML/examples/voip" TYPE EXECUTABLE FILES "/home/unit-hacker/pac-man/SFML-LINUX/examples/voip/voip")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/SFML/examples/voip/voip" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/SFML/examples/voip/voip")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/SFML/examples/voip/voip"
         OLD_RPATH "/home/unit-hacker/pac-man/SFML-LINUX/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/SFML/examples/voip/voip")
    endif()
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "examples")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/SFML/examples/voip" TYPE FILE FILES
    "/home/unit-hacker/pac-man/SFML-LINUX/examples/voip/VoIP.cpp"
    "/home/unit-hacker/pac-man/SFML-LINUX/examples/voip/Client.cpp"
    "/home/unit-hacker/pac-man/SFML-LINUX/examples/voip/Server.cpp"
    )
endif()

