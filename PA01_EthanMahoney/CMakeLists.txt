cmake_minimum_required(VERSION 2.8.9)
set(CMAKE_CXX_STANDARD 11)

# Necessary to give our project a name of our choice
project(postfix)
project(delimiters)

# Add subfolder named [include] to the list directories to be 
# considered for #include statements throughout the entire project
include_directories(include)

# Create a variable with the list of source files for Vehicle
set(MY_LINKED_STACK src/StackLinked/StackLinked.cpp)
# Create a library by compiling these (uses the above created list of sources)
add_library(StackLinked ${MY_LINKED_STACK}) 
# Rule for creating an executable (by compiling the project source main)
add_executable(postfix src/postfix.cpp)
add_executable(delimiters src/delimiters.cpp)
# Specify any necessary linking for the above rule, against other libraries 
# either created by this project or externally provided
target_link_libraries(postfix StackLinked)
target_link_libraries(delimiters StackLinked)

# Specify where to place build products if we also want to do a [make install]
install(TARGETS postfix delimiters StackLinked
	RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/devel/bin
	LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/devel/lib
	ARCHIVE DESTINATION ${PROJECT_SOURCE_DIR}/devel/lib/static)
# Copy the headers (for people who want to use our libraries) to install path
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/
	DESTINATION ${PROJECT_SOURCE_DIR}/devel/include
	FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp")
