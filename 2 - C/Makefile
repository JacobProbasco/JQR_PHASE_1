CFLAGS+=-std=c99 -Wall -Wextra -Werror

CFLAGS+=-D_XOPEN_SOURCE
CFLAGS+=-D_DARWIN_SOURCE

all: 2-0 2-0-1 2-1 2-2-6 2-3-0 2-3-2 2-3-3 2-3-4 2-5

2-0: 2-0-0_Data_types.c
	gcc -o 2-0 2-0-0_Data_types.c $(CFLAGS)

2-0-1: 2-0-1_Arithmetic_Oper.c
	gcc -o 2-0-1 2-0-1_Arithmetic_Oper.c $(CFLAGS)

2-1: 2-1_structure.c
	gcc -o 2-1 2-1_structure.c $(CFLAGS)

2-2-6: 2-2-6_Dynamic_Array.c
	gcc -o 2-2-6 2-2-6_Dynamic_Array.c $(CFLAGS)

2-3-0: 2-3-0_File_IO_Open_File.c
	gcc -o 2-3-0 2-3-0_File_IO_Open_File.c $(CFLAGS)

2-3-2: 2-3-2_File_IO_write_file.c
	gcc -o 2-3-2 2-3-2_File_IO_write_file.c $(CFLAGS)
	
2-3-3: 2-3-3_File_IO_new_file.c
	gcc -o 2-3-3 2-3-3_File_IO_new_file.c $(CFLAGS)
	
2-3-4: 2-3-4_loops.c
	gcc -o 2-3-4 2-3-4_loops.c $(CFLAGS)

2-5: 2-5_Functions.c
	gcc -o 2-5 2-5_Functions.c $(CFLAGS)