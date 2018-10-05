app.out: main.o Chart.o MovieList.o Pivot.o
	g++ -o app.out main.o MovieList.o Pivot.o Chart.cpp

main.o: MovieList.h Pivot.h main.cpp
MovieList.o: movie.h MovieList.cpp
Pivot.o: Chart.h MovieList.h input.h Pivot.cpp
Chart.o: MovieList.h Chart.cpp input.h
clean:
	rm *.o
	rm app.out
