cmake_minimum_required(VERSION 3.5)
project(gazebo_plugin_modelpush)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(gazebo REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

include(GNUInstallDirs)

add_library(model_push SHARED src/model_push.cpp)
target_include_directories(model_push
  PUBLIC
  ${GAZEBO_INCLUDE_DIRS}
)
target_link_libraries(model_push
  PUBLIC
  ${GAZEBO_LIBRARIES}
)

install(
  TARGETS model_push
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

# essential to use ros2 launch pkg-name launchfile.launch.xml
# to make the command be able to find the launch file
install(
  DIRECTORY launch/
  DESTINATION share/${PROJECT_NAME}
)

install(
  DIRECTORY world/
  DESTINATION share/${PROJECT_NAME}/world
)



if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
