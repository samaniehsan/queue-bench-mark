#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

#include "producer.h"
#include "consumer.h"
#include "timing.h"


using namespace std;

void showUsage(int argc, char *argv[]) {
  cerr<<"usage: ./queue-benchmark --type={A|C|D} {--verbose=true} {nItems} {nProducers} {nConsumers} {ConsumerDelay} {Producer-Time-Taken} {Consumer-Time-Taken}"<<endl;
  cerr<<"example:./queue-benchmark --verbose=true 1000000 -1 -1 10000 1 5"<<endl;
  cout<<"args:"<<argc<<endl;
  int i = 0;
  for(i=0; i<argc; i++) {
    cout<<"arg["<<i<<"]="<<argv[i]<<endl;
  }
}
int main(int argc, char *argv[]) {
  if(argc < 4) {
    showUsage(argc, argv);
    return 1;
  }
  return 0;
}
