cmake_minimum_required(VERSION 3.11.4)

# function(google_better_of target_executable output_var)
#     set(oneValueArgs REGEX)
#     set(multipleValueArgs BENCHS)
#     cmake_parse_arguments(
#         "GBO"
#         "" "${oneValueArgs}" "${multipleValueArgs}"
#         ${ARGN}
#     )

#     execute_process(target_executable)

# endfunction()


message("INVOKATION")

if(NOT EXISTS ${OUTFILE})

    execute_process(COMMAND "${EXECUTABLE}"
        OUTPUT_VARIABLE THENUMBER)

    message("The result : ${THENUMBER}")

    configure_file(${INFILE} ${OUTFILE})

endif()