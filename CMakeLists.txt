cmake_minimum_required(VERSION 3.15)

project(Password-safety-guard)

add_executable(checker
	src/main.cc src/checker.cc src/utils.cc
)

