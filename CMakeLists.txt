cmake_minimum_required(VERSION 3.22)
project(ft_containers)

set(CMAKE_CXX_STANDARD 98)
#set(CMAKE_CXX_COMPILER /usr/bin/c++)


set(CMAKE_CXX_FLAGS "-Wall -Werror -Wextra -std=c++98")
#set(CMAKE_CXX_FLAGS "-Wall -Werror -Wextra -std=c++98 -D STD")
#set(CMAKE_CXX_FLAGS "-Wall -Werror -Wextra -std=c++98 -fsanitize=address")
#set(CMAKE_CXX_FLAGS_DEBUG "-Wall -Werror -Wextra -std=c++98")

add_executable(
			ft_container
			#mains/vector_main.cpp
			#mains/map_main.cpp
			mains/stack_main.cpp

			containers/vector.hpp
			containers/map.hpp
			containers/stack.hpp

			iterators/iterator.hpp
			iterators/iterator_traits.hpp
			iterators/map_iterator.hpp
			iterators/random_iterator.hpp
			iterators/reverse_iterator.hpp

			utils/binary_tree.hpp
			utils/binary_tree_node.hpp
			utils/distance.hpp
			utils/equal.hpp
			utils/lexicographical_compare.hpp
			utils/pair.hpp
			utils/type_traits.hpp
)

