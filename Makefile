all: meeting-scheduler.exe

meeting-scheduler.exe: main.o CSVParser.o util.o
	g++ -std=c++11 -g -Wall -Werror $^ -o $@

main.o: main.cpp
	g++ -std=c++11 -g -Wall -Werror -c $^

CSVParser.o: CSVParser.cpp
	g++ -std=c++11 -g -Wall -Werror -c $^

util.o: util.cpp
	g++ -std=c++11 -g -Wall -Werror -c $^

clean:
	rm *.o *.exe