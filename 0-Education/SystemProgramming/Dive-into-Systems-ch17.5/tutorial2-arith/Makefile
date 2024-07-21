CC = gcc
AR = ar
CFLAGS = -Wall -O2 -fPIC -Iinclude
TARGET = myprog
STATIC_LIB = lib/libarith_static.a
SHARED_LIB = lib/libarith_shared.so
STATIC_OBJS = add.o sub.o
SHARED_OBJS = mul.o div.o
MAIN_OBJS = main.o

# 기본 빌드
all: $(TARGET)

$(TARGET): $(MAIN_OBJS) $(STATIC_LIB) $(SHARED_LIB)
	$(CC) $(CFLAGS) -o $@ src/$(MAIN_OBJS) $(STATIC_LIB) -Llib -larith_shared -Wl,-rpath,lib

$(STATIC_LIB): $(STATIC_OBJS)
	$(AR) rcs $@ $(addprefix src/,$(STATIC_OBJS))

$(SHARED_LIB): $(SHARED_OBJS)
	$(CC) -shared -o $@ $(addprefix src/,$(SHARED_OBJS))

%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o src/$@

clean:
	rm -f $(TARGET) $(STATIC_LIB) $(SHARED_LIB) $(addprefix src/,$(STATIC_OBJS)) $(addprefix src/,$(SHARED_OBJS)) src/$(MAIN_OBJS)

test: $(TARGET)
	./$(TARGET)
