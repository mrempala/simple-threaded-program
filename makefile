threaded:
	g++ -g -std=c++11 -pthread threaded.cpp -o threaded.out
	
nonthreaded:
	g++ -g nonthreaded.cpp -o nonthreaded.out
	
simplified:
	g++ -g -std=c++11 -pthread simplified.cpp -o simplified.out
	
threaded_primes:
	g++ -g -std=c++11 -pthread threaded_primes.cpp -o threaded_primes.out
	
nonthreaded_primes:
	g++ -g -std=c++11 -pthread nonthreaded_primes.cpp -o nonthreaded_primes.out
