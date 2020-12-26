.PHONY: clean ALL

CC = g++
CFLAGS = -g -Wall -std=c++11

SOURCE = $(wildcard ./*.c*)
BIN = $(basename $(SOURCE))

ALL: $(BIN)
%: %.c*
	$(CC) $(CFLAGS) $< -o $@

# echo debug info
echo:
	@echo $(CC)
	@echo $(SOURCE)
	@echo $(BIN)

clean:
	-rm -rf $(BIN)