CC = g++ # compiler

CFLAGS = -O3 -Wall -std=c++11
HEADERS = -Iinclude

SRCDIR = scr
BUILDDIR = bin
DEPDIR = libs

TARGET = library

default: directory book human librarian magazine publication reader test_for_library main

directory:
	mkdir -p $(BUILDDIR) $(DEPDIR)

book:
	$(CC) -c $(HEADERS) $(SRCDIR)/book.cpp -o $(DEPDIR)/book.o

human:
	$(CC) -c $(HEADERS) $(SRCDIR)/human.cpp -o $(DEPDIR)/human.o

librarian:
	$(CC) -c $(HEADERS) $(SRCDIR)/librarian.cpp -o $(DEPDIR)/librarian.o

magazine:
	$(CC) -c $(HEADERS) $(SRCDIR)/magazine.cpp -o $(DEPDIR)/magazine.o

publication:
	$(CC) -c $(HEADERS) $(SRCDIR)/publication.cpp -o $(DEPDIR)/publication.o

reader:
	$(CC) -c $(HEADERS) $(SRCDIR)/reader.cpp -o $(DEPDIR)/reader.o

test_for_library:
	$(CC) -c $(HEADERS) $(SRCDIR)/test_for_library.cpp -o $(DEPDIR)/test_for_library.o

main:
	$(CC) $(CFLAGS) $(HEADERS) $(DEPDIR)/* $(SRCDIR)/main.cpp -o $(BUILDDIR)/$(TARGET)

clean:
	rm -rf $(BUILDDIR)
	rm -rf $(DEPDIR)

open:
	./$(BUILDDIR)/$(TARGET)
