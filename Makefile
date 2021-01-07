CC= g++ -std=c++11 -fPIC
INCLUDES = -Iinclude
GTKMM_FLAGS = $(shell pkg-config --libs --cflags gtkmm-2.4)
REQ := $(shell pkg-config gtkmm-2.4)

OUTPUT = libktk.so

all: ktk
ifndef REQ
    $(error "gtkmm 2.4 library not found. You need to install it to compile this project.")
endif

ktk: toolbox.o tparent.o kcomp.o tchild.o widedit.o
	$(CC) -shared toolbox.o tparent.o kcomp.o tchild.o widedit.o -Wl,-soname,libktk.so $(GTKMM_FLAGS) -o $(OUTPUT)

kcomp.o:
	$(CC) -c kcomp.cpp $(INCLUDES) $(GTKMM_FLAGS)

tchild.o:
	$(CC) -c tchild.cpp $(INCLUDES) $(GTKMM_FLAGS) 

toolbox.o:
	$(CC) -c toolbox.cpp $(INCLUDES) $(GTKMM_FLAGS) 

tparent.o:
	$(CC) -c tparent.cpp $(INCLUDES) $(GTKMM_FLAGS)

widedit.o:
	$(CC) -c widedit.cpp $(INCLUDES) $(GTKMM_FLAGS)

.PHONY: demo install uninstall

demo:
	cd demo && make 

clean:
	rm -rf *.o libktk.so
	cd demo && make clean

install: ktk
	$(shell cp libktk.so /usr/lib)
	$(shell if [ ! -d /usr/include/ktk ] ; then mkdir /usr/include/ktk ; fi)
	$(shell cp include/* /usr/include/ktk )

uninstall: ktk
	$(shell if [ -d /usr/local/include/ktk ] ; then rm -rf /usr/local/include/ktk ; fi)
	$(shell rm -rf /usr/lib/libktk.so)
	$(shell rm -rf /usr/include/ktk)
