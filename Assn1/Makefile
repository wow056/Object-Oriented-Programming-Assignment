CC=g++
OBJS=main.o Chart.o MovieList.o Pivot.o
TARGET=app.out
 
all: $(TARGET)
 
clean:
	rm -f *.o
	rm -f $(TARGET)
 
$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)

main.o: main.h main.cpp
MovieList.o: MovieList.h MovieList.cpp
Pivot.o: Pivot.h input.h Pivot.cpp
Chart.o: Chart.h input.h Chart.cpp