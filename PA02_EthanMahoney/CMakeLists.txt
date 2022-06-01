cmake_minimum_required(VERSION 2.8.9)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

# Necessary to give our project a name of our choice
project(sortTest)
project(rand)

# Add subfolder named [include] to the list directories to be 
# considered for #include statements throughout the entire project
include_directories(include)

# Create a variable with the list of source files for QuickSort
set(MY_QUICK_SORT src/QuickSort/QuickSort.cpp)
# Create a library by compiling these (uses the above created list of sources)
add_library(QuickSort ${MY_QUICK_SORT}) 

# Create a variable with the list of source files for SelectionSort
set(MY_SELECTION_SORT src/SelectionSort/SelectionSort.cpp)
# Create a library by compiling these (uses the above created list of sources)
add_library(SelectionSort ${MY_SELECTION_SORT}) 

# Rule for creating an executable (by compiling the project source main)
add_executable(sortTest src/sortTest.cpp)
add_executable(rand src/rand.cpp)

# Specify any necessary linking for the above rule, against other libraries 
# either created by this project or externally provided
target_link_libraries(sortTest QuickSort SelectionSort)

# Specify where to place build products if we also want to do a [make install]
install(TARGETS sortTest rand QuickSort SelectionSort
	RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/devel/bin
	LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/devel/lib
	ARCHIVE DESTINATION ${PROJECT_SOURCE_DIR}/devel/lib/static)
# Copy the headers (for people who want to use our libraries) to install path
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/
	DESTINATION ${PROJECT_SOURCE_DIR}/devel/include
	FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp")
