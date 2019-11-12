CPP=g++ --std=c++11 -Wall
all : main
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
mobile.o : mobile.cpp
	$(CPP) -c mobile.cpp	


clean :
	rm *.o