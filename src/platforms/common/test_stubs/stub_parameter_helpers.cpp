#include <sys/types.h>
#include <stdint.h>

#include "px4_workqueue.h"

extern "C" {
	int work_queue(int qid, struct work_s *work, worker_t worker, void *arg, uint32_t delay) {return -1;}
	int work_cancel(int qid, struct work_s *work) {return -1;}
	int px4_shutdown_lock() {return -1;}
	int px4_shutdown_unlock() {return -1;}
}
