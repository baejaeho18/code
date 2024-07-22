CC = gcc
AR = ar
CFLAGS = -Wall -O2 -fPIC -Iinclude
TARGET = myprog
STATIC_LIB = lib/libarith_static.a
SHARED_LIB = lib/libarith_shared.so
STATIC_OBJS = add.o sub.o
SHARED_OBJS = mul.o div.o
MAIN_OBJS = main.o

all: build $(TARGET)

build:
	mkdir -p build

$(TARGET): $(addprefix build/,$(MAIN_OBJS)) $(STATIC_LIB) $(SHARED_LIB)
	$(CC) $(CFLAGS) -o $@ $(addprefix build/,$(MAIN_OBJS)) $(STATIC_LIB) -Llib -larith_shared -Wl,-rpath,lib

$(STATIC_LIB): $(addprefix build/,$(STATIC_OBJS))
	$(AR) rcs $@ $(addprefix build/,$(STATIC_OBJS))

$(SHARED_LIB): $(addprefix build/,$(SHARED_OBJS))
	$(CC) -shared -o $@ $(addprefix build/,$(SHARED_OBJS))

build/%.o: src/%.c | build
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(STATIC_LIB) $(SHARED_LIB) $(addprefix build/,$(STATIC_OBJS)) $(addprefix build/,$(SHARED_OBJS))
	rm -rf build

test: $(TARGET)
	./$(TARGET)

static_lib: $(STATIC_LIB)
shared_lib: $(SHARED_LIB)