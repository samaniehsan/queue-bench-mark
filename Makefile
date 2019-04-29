all: clean benchmark-O3
benchmark:
	g++ main.cpp consumer.cpp producer.cpp timing.cpp queue-wrapper.cpp queue-item.cpp double-stacked-queue.cpp circular-queue.cpp simple-stack.cpp -o queue-benchmark
benchmark-O3:
	g++ -O3 main.cpp consumer.cpp producer.cpp timing.cpp queue-wrapper.cpp queue-item.cpp double-stacked-queue.cpp circular-queue.cpp simple-stack.cpp -o queue-benchmark
benchmark-llvm:
	clang++ main.cpp consumer.cpp producer.cpp timing.cpp queue-wrapper.cpp queue-item.cpp double-stacked-queue.cpp circular-queue.cpp simple-stack.cpp -o queue-benchmark
benchmark-llvm-O3:
	clang++ -O3 main.cpp consumer.cpp producer.cpp timing.cpp queue-wrapper.cpp queue-item.cpp double-stacked-queue.cpp circular-queue.cpp simple-stack.cpp -o queue-benchmark
clean:
	rm -f queue-benchmark *.o
