#pragma once

#include "px4_workqueue.h"

#include <functional>
#include <sys/types.h>
#include <stdint.h>



std::function<int(int, work_s *, worker_t, void *, uint32_t)> stub_work_queue_callback;
std::function<int(int, work_s *)> stub_work_cancel_callback;
std::function<int(void)> stub_px4_shutdown_lock_callback;
std::function<int(void)> stub_px4_shutdown_unlock_callback;
