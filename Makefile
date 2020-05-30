SHELL=/bin/zsh

# CFLAGS = -O0 -ggdb3

TARGET = createImage
SOURCES = $(shell echo *.C)

$(TARGET): $(SOURCES)
	g++ $(CFLAGS) -o $(TARGET) $(SOURCES)

clean:
	rm $(TARGET)
