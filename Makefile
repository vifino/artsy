# Maybe change this.
CC ?= cc
CFLAGS ?= -Os
CPPLAGS += -pedantic -Wall -Wextra

# Don't touch below unless you added something.
BINS=scrwipe

all: $(BINS)
scrwipe: scrwipe.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o scrwipe $^

# just cleanup. no ketchup.
clean:
	rm -f $(BINS)
