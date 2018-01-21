cmake_minimum_required(VERSION 3.9)
project(fillit C)

set(CMAKE_C_STANDARD 99)

add_executable(fillit valid.c libft/libft.a ft_error.c ft_read_file.c main.c)

target_link_libraries(fillit ${CMAKE_SOURCE_DIR}/libft/libft.a)