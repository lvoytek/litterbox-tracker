cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr)
project(litterbox_tracker)

set(SHIELD adafruit_apds9960)

FILE(GLOB app_sources src/*.c)
target_sources(app PRIVATE ${app_sources})
