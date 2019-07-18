#include "stub_parameter.h"



extern "C" {
	int work_queue(int qid, struct work_s *work, worker_t worker, void *arg, uint32_t delay)
	{
		return stub_work_queue_callback(qid, work, worker, arg, delay);
	}

	int work_cancel(int qid, struct work_s *work)
	{
		return stub_work_cancel_callback(qid, work);
	}

	int px4_shutdown_lock() {return stub_px4_shutdown_lock_callback();}

	int px4_shutdown_unlock() {return stub_px4_shutdown_unlock_callback();}

	/* This function blocks forever in tests, so override it with a version that can be customized */
	int pthread_cond_wait(pthread_cond_t *cond, pthread_mutex_t *mutex)
	{
		return stub_pthread_cond_wait_callback(cond, mutex);
	}
}
