cmake_minimum_required(VERSION 3.17.5)
project(ft_containers)

set(CMAKE_CXX_STANDARD 14)

include_directories(List)
include_directories(Vector)

add_executable(ft_containers
        iterators/iterator_list.hpp
        List.hpp
        iterators/reverse_iterator_list.hpp
        iterators/random_iterator.hpp
        iterators/reverse_random_iterator.hpp
        iterators/Utils.hpp
        Vector.hpp
        tests.cpp
        main.cpp iterators/enableif.hpp)
