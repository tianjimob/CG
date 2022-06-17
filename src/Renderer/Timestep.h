#pragma once

#include <chrono>

class Timestep {
public:
  void onUpdate() {
    timepoint now = clock::now();
    m_delta = now - m_lastFrame;
    m_lastFrame = now;
  }

  explicit(false) inline operator float() const { return m_delta.count(); }

private:
  using clock = std::chrono::high_resolution_clock;
  using timepoint = std::chrono::time_point<clock>;
  using duration = std::chrono::duration<float>;
  timepoint m_lastFrame{clock::now()};
  duration m_delta;
};