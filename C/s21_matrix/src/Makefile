CC = gcc-11
CFLAGS = -Werror -Wall -Wextra -std=c11
TARGET = s21_matrix
TARGET_DIR = functions
SRCS = $(TARGET_DIR)/*.c shared/*.c
OBJS = $(SRCS:.c=.o)
TEST_DIR = tests
TEST_SRCS = $(TEST_DIR)/*.c
TEST_OBJS = $(TEST_SRCS:.c=.o)
TEST_FLAGS = $(shell pkg-config --libs --cflags check) -lm
GCOV_FLAGS = -ftest-coverage -fprofile-arcs -fPIC	

.PHONY: all clean test_compile test build rebuild gcov_report clang cpp_check valgrind

all: rebuild
rebuild: clean build
build: $(TARGET).a

$(TARGET).a : $(wildcard $(SRCS))
	@$(CC) $(CFLAGS) -c $+
	ar rc $(TARGET).a *.o
	ranlib $(TARGET).a
	rm -rf *.o

test_compile: rebuild
	$(CC) $(CFLAGS) $(GCOV_FLAGS) $(TEST_DIR)/*.c $(TARGET).a -o test $(TEST_FLAGS)

test: test_compile
	./test
	rm -rf *.o test *.a $(TEST_DIR)/*.o *.gcda *.gcno *.info report *.out coverage

gcov_report: clean
	$(CC) $(GCOV_FLAGS) $(SRCS) $(TEST_SRCS) $(TEST_FLAGS) -o coverage
	./coverage
	lcov -t "coverage" -o coverage.info --no-external -c -d .
	genhtml -o report coverage.info
	open ./report/index.html

clean:
	rm -rf *.o test *.a *.gcda *.gcno *.info report *.out coverage

clang:
	clang-format -i --style=Google $(SRCS) shared/*.h *.h $(TEST_DIR)/*.[ch] 

cpp_check:
	cppcheck --enable=all --suppress=missingIncludeSystem $(SRCS) $(TARGET).h $(TEST_DIR)/*.h $(TEST_SRCS)

valgrind: test_compile
	valgrind --tool=memcheck --leak-check=yes -s ./test

single_testing_valgrind:
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./a.out