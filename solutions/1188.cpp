#include <condition_variable>
#include <mutex>
#include <queue>

class BoundedBlockingQueue {
  std::mutex m_;
  std::condition_variable enq_, deq_;
  std::queue<int> q_;
  size_t capacity_;

 public:
  BoundedBlockingQueue(int capacity)
      : capacity_(static_cast<size_t>(capacity)) {}

  void enqueue(int element) {
    std::unique_lock<std::mutex> lock(m_);
    enq_.wait(lock, [this] { return q_.size() < capacity_; });
    q_.push(element);
    lock.unlock();
    deq_.notify_one();
  }

  int dequeue() {
    std::unique_lock<std::mutex> lock(m_);
    deq_.wait(lock, [this] { return not q_.empty(); });
    auto result = q_.front();
    q_.pop();
    lock.unlock();
    enq_.notify_all();
    return result;
  }

  int size() {
    std::unique_lock<std::mutex> lock(m_);
    return static_cast<int>(q_.size());
  }
};
