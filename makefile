main:
	g++ -g -std=c++11 -pthread threaded.cpp -o threaded.out
	
nonthreaded:
	g++ -g nonthreaded.cpp -o nonthreaded.out
	
simplified:
	g++ -g -std=c++11 -pthread simplified.cpp -o simplified.out
