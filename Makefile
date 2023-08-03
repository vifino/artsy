# Maybe change this.
CC ?= cc
CFLAGS ?= -Os
CPPLAGS += -pedantic -Wall -Wextra

PREFIX ?= /usr/local
DESTDIR ?= /

# Don't touch below unless you added something.
BINS=scrwipe

all: $(BINS)
scrwipe: scrwipe.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o scrwipe $^

install: $(BINS)
	install -d $(DESTDIR)/$(PREFIX)/bin
	install $(BINS) $(DESTDIR)/$(PREFIX)/bin

# just cleanup. no ketchup.
clean:
	rm -f $(BINS)
