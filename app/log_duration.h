#pragma once

#include <chrono>
#include <iostream>

#define PROFILE_CONCAT_INTERNAL(X, Y) X##Y
#define PROFILE_CONCAT(X, Y) PROFILE_CONCAT_INTERNAL(X, Y)
#define UNIQUE_VAR_NAME_PROFILE PROFILE_CONCAT(profileGuard, __LINE__)
#define LOG_DURATION(x) LogDuration UNIQUE_VAR_NAME_PROFILE(x)

class LogDuration {
public:
  // заменим имя типа std::chrono::steady_clock
  // с помощью using для удобства
  using Clock = std::chrono::steady_clock;

  LogDuration(std::string caption = "") : caption_(caption) {}

  ~LogDuration() {
    using namespace std::chrono;
    using namespace std::literals;

    const auto end_time = Clock::now();
    const auto dur = end_time - start_time_;
    std::cerr << caption_ << ": "s << duration_cast<microseconds>(dur).count()
              << " us"s << std::endl;
  }

private:
  const Clock::time_point start_time_ = Clock::now();
  const std::string caption_;
};
