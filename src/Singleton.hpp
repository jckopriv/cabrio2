//
// Simple singleton class.
// Inherit from this class to make any class a singleton.
//
#ifndef CABRIO_SINGLETON_H
#define CABRIO_SINGLETON_H

template <class T>
class Singleton
{
public:
  virtual ~Singleton();
  
  //template <typename... Args>
  static
  T* get_instance(/*Args... args*/)
  {
    if (instance_ == nullptr)
      {
        instance_ = new T(/*std::forward<Args>(args)...*/);
      }

    return instance_;
  }

  static
  void destroy_instance()
  {
    delete instance_;
    instance_ = nullptr;
  }
 
protected: 
  Singleton();

  
private:
  Singleton(Singleton const&);
  Singleton& operator=(Singleton const&);  
  static T* instance_;
};

template<class T> T* Singleton<T>::instance_ = nullptr;
template<class T> inline Singleton<T>::Singleton(){}
template<class T> inline Singleton<T>::~Singleton(){}


#endif // SINGLETON_H
