cmake_minimum_required(VERSION 3.16.3)
project(ft_cont)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(iterators)

add_executable(ft_cont
        iterators/enableif.hpp
        iterators/iterator_list.hpp
        iterators/iterator_map.hpp
        iterators/random_iterator.hpp
        iterators/reverse_iterator_list.hpp
        iterators/reverse_random_iterator.hpp
        iterators/Utils.hpp
        List.hpp
        main.cpp
        Map.hpp
        tests.cpp
        Vector.hpp iterators/reverse_iterator_map.hpp Stack.hpp Queue.hpp MapAvl.hpp iterators/iterator_mapavl.hpp iterators/reverse_iterator_mapavl.hpp)
