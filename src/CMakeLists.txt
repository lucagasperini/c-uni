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

add_executable (sort sort.c ${C_FILE_UTILS})
add_test(test_sort sort)