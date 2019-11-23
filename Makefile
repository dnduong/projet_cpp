CPP=g++ --std=c++11 -Wall
all : main creator
creator : creator.o element.o diams.o teupor.o reumu.o geurchar.o mobile.o
	$(CPP) -o creator creator.o element.o diams.o teupor.o reumu.o geurchar.o mobile.o
creator.o : creator.cpp
	$(CPP) -c creator.cpp
main : main.o element.o diams.o teupor.o reumu.o geurchar.o mobile.o
	$(CPP) -o main main.o element.o diams.o teupor.o reumu.o geurchar.o mobile.o
main.o : main.cpp
	$(CPP) -c main.cpp
element.o : element.cpp
	$(CPP) -c element.cpp
diams.o : diams.cpp
	$(CPP) -c diams.cpp
teupor.o : teupor.cpp
	$(CPP) -c teupor.cpp
reumu.o : reumu.cpp
	$(CPP) -c reumu.cpp
geurchar.o : geurchar.cpp
	$(CPP) -c geurchar.cpp
mobile.o : mobile.cpp mobile.hpp
	$(CPP) -c mobile.cpp


clean :
	rm *.o
