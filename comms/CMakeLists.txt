function(dsl_adas_parse name)
  dsl_parse("adas" ${name} ${ARGN})
endfunction()

add_subdirectory(adas)
