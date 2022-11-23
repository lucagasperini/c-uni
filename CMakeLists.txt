project(c-uni)

cmake_minimum_required(VERSION 3.22)

include_directories("include/")

add_subdirectory(src)

# Search on the system Doxygen
find_package(Doxygen)

if (DOXYGEN_FOUND)

    set(DOXYGEN_EXCLUDE_PATTERNS "*/Bin/*")

    doxygen_add_docs(
        doc_master_tracker
        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}

        COMMENT "Generating API documentation with Doxygen"
    )
else (DOXYGEN_FOUND)
  message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)

enable_testing()