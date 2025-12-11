# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\SimpleCalculator_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\SimpleCalculator_autogen.dir\\ParseCache.txt"
  "SimpleCalculator_autogen"
  )
endif()
