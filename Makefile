TARGET=test-cityhash
test_cityhash_OBJECTS=test-cityhash.o
test-cityhash_SOURCES=$(test_cityhash_OBJECTS:.o=.c)
OBJECTS=adhf.o

CFLAGS+=-I/usr/local/include -fopenmp
LDADD+=-L/usr/local/lib -lccityhash

.PHONY: all clean

all: $(TARGET)

$(TARGET):$(test_cityhash_OBJECTS) $(OBJECTS)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS) $(LDADD)

clean:
	-rm $(TARGET) $(test_cityhash_OBJECTS) 
