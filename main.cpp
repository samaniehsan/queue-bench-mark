#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream> 

#include "producer.h"
#include "consumer.h"
#include "queue-wrapper.h"
#include "timing.h"

using namespace std;

void showUsage(int argc, char *argv[]) {
  cerr<<"usage: ./queue-benchmark --type={D|A|S} {nItems} {--log=true} {nProducers} {nConsumers} {ConsumerDelay} {Producer-duration} {Consumer-duration}"<<endl;
  cerr<<"example:./queue-benchmark --type=A 1000000 --log=true -1 -1 10000 1 5"<<endl;
  cout<<"args:"<<argc<<endl;
  int i = 0;
  for(i=0; i<argc; i++) {
    cout<<"arg["<<i<<"]="<<argv[i]<<endl;
  }
}

struct TunningOptions {
  bool isVerbose;
  QueueType queueType;
  int nItems; 
  int nProducers;
  int nConsumers;
  int nDelay;
  int nProducerDuration;
  int nConsumerDuration;
  TunningOptions() {
    nProducerDuration = 0;
    nConsumerDuration = 0;
    nDelay = 0;
    nProducers = -1;
    nConsumers = -1;
    nItems = 0;
    queueType = (QueueType) 0;
    isVerbose = true;
  }
};

void getParams(
  TunningOptions& options,
  int argc,
  char *argv[]
) {
  int i;
  for(int i=1; i< argc;i++) {
    if(1 == i) {
      if( 0 == strcmp("--type=d", argv[i])) {
        options.queueType = QueueType_DoubleEnded;
      } else if( 0 == strcmp("--type=a", argv[i])) {
        options.queueType = QueueType_CircularArray;
      } if( 0 == strcmp("--type=s", argv[i])) {
        options.queueType = QueueType_DoubleStacks;
      }
    } else if(2 == i) {
      int nItems = atoi(argv[i]);
      options.nItems = nItems;
    } else if(3 == i) {
      int compare2 = strcmp("--log=false", argv[i]);
      if( 0 == compare2) {
        options.isVerbose = false;
      }
    } else if(4 == i) {
      int nProducers = atoi(argv[i]);
      options.nProducers = nProducers;
    } else if(5 == i) {
      int nConsumers = atoi(argv[i]);
      options.nConsumers = nConsumers;
    } else if(6 == i) {
      int nDelay = atoi(argv[i]);
      options.nDelay = nDelay;
    } else if(7 == i) {
      int producerDuration = atoi(argv[i]);
      options.nProducerDuration = producerDuration;
    } else if(8 == i) {
      int consumerDuration = atoi(argv[i]);
      options.nConsumerDuration = consumerDuration;
    }
  }
}

bool validateOptions(const TunningOptions  &options) {
  int nErrors = 0;
  if (0 > options.nConsumerDuration ) {
    cerr<<"ConsumerDuration:"<<options.nConsumerDuration<<" should not be less than 0"<<endl;
    nErrors++;
  }
  if (0 > options.nProducerDuration ) {
    cerr<<"ProducerDuration:"<<options.nProducerDuration<<" should not be less than 0"<<endl;
    nErrors++;
  }
  if (options.nConsumers != -1 && 1 > options.nConsumers ) {
    cerr<<"nConsumers:"<<options.nConsumers<<" should be more than zero"<<endl;
    nErrors++;
  }
  if (options.nProducers != -1 && 1 > options.nProducers ) {
    cerr<<"nProducers:"<<options.nProducers<<" should be more than zero"<<endl;
    nErrors++;
  }
  if (0 > options.nDelay ) {
    cerr<<"nConsumerDelay:"<<options.nDelay<<" should be 0 or greater"<<endl;
    nErrors++;
  }
  if (0 == options.queueType ) {
    cerr<<"queueType:"<<options.queueType<<" Queue should be 'A','D','S'"<<endl;
    nErrors++;
  }
  if (0 >= options.nItems ) {
    cerr<<"nItems:"<<options.nItems<<" has to be more than zero"<<endl;
    nErrors++;
  }
  
  return nErrors == 0;
}

void runSequential(
  const int nItems,
  Producer & producer,
  Consumer & consumer
) {
  
  producer.run(nItems);
  consumer.run(nItems);
}

void runStraddle(
  const int nItems,
  Producer & producer,
  Consumer & consumer
) {
  const int stepSize = 10000;
  const int consumerSize = stepSize - 100;
  int nSteps = nItems/ stepSize;
  
  int nLeftOvers = 0;
  int i;
  for(i=0; i<nSteps; i++) {
    producer.run(stepSize);
    consumer.run(consumerSize);
    nLeftOvers +=  stepSize - consumerSize; 
  }
  
  if(nLeftOvers > 0) {
    consumer.run(nLeftOvers);
  }
  
}


int main(int argc, char *argv[]) {
  if(argc < 4) {
    showUsage(argc, argv);
    return 1;
  }
  TunningOptions options;
  getParams(options, argc, argv);
  
  if(!validateOptions(options))
    return 2;

  QueueWrapper queueWrapper(
    options.queueType);

  Producer producer(&queueWrapper);
  Consumer consumer(&queueWrapper, options.isVerbose);

  // runSequential(
  //   options.nItems, 
  //   producer, 
  //   consumer);

  runStraddle(
    options.nItems, 
    producer, 
    consumer);

  if(!queueWrapper.empty()) {
    cerr<<"queue is not empty"<<endl;
    return 3;
  }
  return 0;
}
