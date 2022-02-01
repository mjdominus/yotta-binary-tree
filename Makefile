
all: try

try: try.o tree-trace.o

try.o: try.c tree.h
tree-trace.o: tree-trace.c tree.h
