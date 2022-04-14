cmake_minimum_required(VERSION 3.21)
project(lab7IoanaUrsu)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab7IoanaUrsu main.cpp Entity/Entity.cpp Entity/Entity.h Repo/Repo.cpp Repo/Repo.h Tests/tests.cpp Tests/tests.h Console/console.cpp Console/console.h Service/Service.cpp Service/Service.h)
