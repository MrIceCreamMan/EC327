# in EC327, we use the ${GCC} compiler
# therefore, we define the GCC variable
GCC = g++ 

TryingMakefiles: pointerDemo.o print.o reverse.o 
	${GCC} pointerDemo.o print.o reverse.o  -o TryingMakefiles

pointerDemo.o: pointerDemo.cpp
	${GCC} -c pointerDemo.cpp

print.o: print.cpp
	${GCC} -c print.cpp
	
#this is where you will add the code to compile reverse.cpp

#this is where you will add the code to compile your bubble sort function

clean:
	rm *.o TryingMakefiles  
