CC = gcc
CFLAGS = -Wall -Werror -std=c99 -ggdb
HEADERS = -I../include/
SRCS = pw_gen.c \
	   help.c \
	   print_error.c \
	   args.c \
	   pw_source.c \
	   pw_filter.c \
	   info.c \
	   custom_character_model_parser.c \
	   custom_character_group_model_parser.c \
	   custom_common.c

OBJS = $(patsubst %.c, %.o, $(SRCS))

all: pw-generator
	mv pw-generator ../

pw-generator: $(OBJS)
	$(CC) -o $@ $(OBJS) $(CFLAGS) && make clean

%.o: %.c
	$(CC) -c $(SRCS) $(HEADERS)


.PHONY: clean all

clean:
	rm *.o
