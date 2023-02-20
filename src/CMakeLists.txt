enable_testing()

set(C_FILE_UTILS "utils.c")

add_executable (ia1 ia1.c ${C_FILE_UTILS})
add_test(test_ia1 ia1)

add_executable (ia2 ia2.c ${C_FILE_UTILS})
add_test(test_ia2 ia2)

add_executable (ia3 ia3.c ${C_FILE_UTILS})
add_test(test_ia3 ia3)

add_executable (ia4 ia4.c ${C_FILE_UTILS})
add_test(test_ia4 ia4)

add_executable (ia5 ia5.c ${C_FILE_UTILS})
add_test(test_ia5 ia5)

add_executable (ia_extra01 ia_extra01.c ${C_FILE_UTILS})
add_test(test_ia_extra01 ia_extra01)

add_executable (sort sort.c ${C_FILE_UTILS})
add_test(test_sort sort)

add_executable (ia_extra03 ia_extra03.c ${C_FILE_UTILS})
add_test(test_ia_extra03 ia_extra03)

add_executable (ia_extra04 ia_extra04.c ${C_FILE_UTILS})
add_test(test_ia_extra04 ia_extra04)

add_executable (ia_extra05 ia_extra05.c ${C_FILE_UTILS})
add_test(test_ia_extra05 ia_extra05)

add_executable (ce_es24 ce_es24.c ${C_FILE_UTILS})
add_test(test_ce_es24 ce_es24)

add_executable (binary_tree binary_tree.c ${C_FILE_UTILS})
add_test(test_binary_tree binary_tree)