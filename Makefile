CC = gcc
CFLAGS = -c -Wall
LDFLAGS = -lm
SOURCES = imaginary.c helper.c  
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE= calc

all: $(SOURCES)$(EXECUTABLE)
-include $(OBJECTS:.o=.d)

$(EXECUTABLE):$(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@
.c.o:
	$(CC) $(CFLAGS) $< -o $@
	$(CC) -MM $< -o $*.d

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE) *.d