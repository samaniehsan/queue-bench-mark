all: clean benchmark
benchmark:
	g++ main.cpp consumer.cpp producer.cpp timing.cpp queue-wrapper.cpp -o queue-benchmark
clean:
	rm -f queue-benchmark *.o
