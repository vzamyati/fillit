cmake_minimum_required(VERSION 3.9)
project(fillit C)

set(CMAKE_C_STANDARD 99)

add_executable(fillit fillit.h valid.c ft_error.c ft_read_file.c main.c ft_strnew.c ft_bzero.c)
