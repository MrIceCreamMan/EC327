# in EC327, we use the ${GCC} compiler
# therefore, we define the GCC variable
GCC = g++ 

TryingMakefiles: pointerDemo.o print.o reverse.o bubbleSort.o
	${GCC} pointerDemo.o print.o reverse.o bubbleSort.o  -o TryingMakefiles

pointerDemo.o: pointerDemo.cpp
	${GCC} -c pointerDemo.cpp

print.o: print.cpp
	${GCC} -c print.cpp

reverse.o: reverse.cpp
	${GCC} -c reverse.cpp
#this is where you will add the code to compile reverse.cpp

bubbleSort.o: bubbleSort.cpp
	${GCC} -c bubbleSort.cpp
#this is where you will add the code to compile your bubble sort function

clean:
	rm *.o TryingMakefiles  
