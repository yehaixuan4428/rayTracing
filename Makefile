SHELL=/bin/zsh

TARGET = createImage
SOURCES = $(shell echo *.C)

$(TARGET): $(SOURCES)
	g++ -o $(TARGET) $(SOURCES)

clean:
	rm $(TARGET)
