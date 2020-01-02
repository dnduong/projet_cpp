CPP=g++ --std=c++11 -Wall
all : creator main
creator : creator.o element.o diams.o teupor.o reumu.o geurchar.o mobile.o streumon.o
	$(CPP) -o creator creator.o element.o diams.o teupor.o reumu.o geurchar.o mobile.o streumon.o
creator.o : creator.cpp
	$(CPP) -c creator.cpp
main : main.o element.o diams.o teupor.o reumu.o geurchar.o mobile.o oueurj.o streumon.o
	$(CPP) -o main main.o element.o diams.o teupor.o reumu.o geurchar.o mobile.o oueurj.o streumon.o -lncurses
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
mobile.o : mobile.cpp
	$(CPP) -c mobile.cpp
oueurj.o : oueurj.cpp
	$(CPP) -c oueurj.cpp
streumon.o : streumon.cpp
	$(CPP) -c streumon.cpp

clean :
	rm *.o
