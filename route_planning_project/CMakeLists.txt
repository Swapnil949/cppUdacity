cmake_minimum_required(VERSION 3.11.3)

# Set the C++ standard we will use
set(CMAKE_CXX_STANDARD 17)



# Add the pugixml and GoogleTest library subdirectories
add_subdirectory(thirdparty/pugixml)
add_subdirectory(thirdparty/googletest)