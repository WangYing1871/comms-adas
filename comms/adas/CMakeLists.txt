get_filename_component(name ${CMAKE_CURRENT_SOURCE_DIR} NAME)
set (schema_files
    ${CMAKE_CURRENT_SOURCE_DIR}/dsl/main.xml
    ${CMAKE_CURRENT_SOURCE_DIR}/dsl/msg1.xml
    )

message(STATUS "${schema_files}")

dsl_adas_parse(${name} SCHEMAS ${schema_files})
