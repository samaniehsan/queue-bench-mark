all: clean benchmark
benchmark:
	g++ main.cpp consumer.cpp producer.cpp timing.cpp queue-wrapper.cpp queue-item.cpp double-stacked-queue.cpp circular-queue.cpp simple-stack.cpp -o queue-benchmark
clean:
	rm -f queue-benchmark *.o
