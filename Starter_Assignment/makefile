A1.exe: DriverA1.o GPA.o
	g++ DriverA1.o GPA.o  -o A1.exe

DriverA1.o: DriverA1.cpp
	g++ -c DriverA1.cpp -o DriverA1.o

GPA.o: Student.cpp
	g++ -c Student.cpp -o GPA.o

clean:
	rm -rf *.o A1.exe

run:
	A1.exe