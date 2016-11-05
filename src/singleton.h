#pragma once

template <typename T>
class Singleton {
 public:
  static T & Instance();

 protected:
  Singleton() = default;
  virtual ~Singleton() = default;

  Singleton(Singleton const &) = delete;
  Singleton & operator = (Singleton const &) = delete;
  Singleton(Singleton &&) = delete;
  Singleton & operator = (Singleton &&) = delete;
};

template <typename T>
T & Singleton<T>::Instance() {
  static T instance;
  return instance;
}
