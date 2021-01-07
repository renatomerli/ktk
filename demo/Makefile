CC= g++
INCLUDES = -Iinclude
GTKMM_FLAGS = $(shell pkg-config --libs --cflags gtkmm-2.4)
KTK_FLAGS = -I/usr/include/ktk -L/usr/lib -lktk

OUTPUT = demo

all: demo

demo: tree.o textview.o pdvtoolbox.o gui.o app.o main.o
	$(CC) main.o gui.o tree.o textview.o app.o pdvtoolbox.o -o $(OUTPUT) $(INCLUDES) $(GTKMM_FLAGS) $(KTK_FLAGS)

tree.o:
	$(CC) -c tree.cpp $(INCLUDES) $(GTKMM_FLAGS) 

textview.o:
	$(CC) -c textview.cpp $(INCLUDES) $(GTKMM_FLAGS)

pdvtoolbox.o:
	$(CC) -c pdvtoolbox.cpp $(INCLUDES) $(GTKMM_FLAGS) 

gui.o:
	$(CC) -c gui.cpp $(INCLUDES) $(GTKMM_FLAGS)

app.o:
	$(CC) -c app.cpp $(INCLUDES) $(GTKMM_FLAGS) 


main.o:
	$(CC) -c main.cpp $(INCLUDES) $(GTKMM_FLAGS) 

.PHONY: clean
clean:
	rm -rf *.o demo

