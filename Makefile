all: meeting-scheduler.exe

meeting-scheduler.exe: main.cpp CSVParser.o
	g++ -Wall -Werror $^ -o $@

CSVParser.o: CSVParser.cpp
	g++ -Wall -Werror -c $^

clean:
	rm *.o *.exe