CFLAGS = -g -c -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline \
		 -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default \
 		 -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy \
		 -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers \
		 -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing \
		 -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE

EXE_FLAG_VALGRIND = valgrind -s --leak-check=yes --show-leak-kinds=all --track-origins=yes --log-file="valgrind_log.txt" 

all: run_queue

main.o: main.cpp
	g++ $(CFLAGS) main.cpp -o main.o

queue.o: queue.cpp
	g++ $(CFLAGS) queue.cpp -o queue.o

run_queue: main.o queue.o
	g++ main.o queue.o -o run_queue.exe

# run_queue: make_queue
# 	$(EXE_FLAG_VALGRIND) ./make_queue.exe
	
clean:
	rm *.o *.exe