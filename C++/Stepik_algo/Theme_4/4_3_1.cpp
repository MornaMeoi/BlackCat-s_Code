#include <iostream>
#include <utility>

namespace my
{
  class max_heap;
};

class my::max_heap
{
  private:
    int *data_;
    size_t size_, capacity_;
    void sift_up(int *element);
    void sift_down(int *element);
    //void print_heap();
  public:
    max_heap();
    ~max_heap();
    void insert(int value);
    int extract_max();
};

my::max_heap::max_heap() : size_{0}, capacity_{8}
{
  data_ = new int[8];
}

my::max_heap::~max_heap()
{
  delete[] data_;
}

void my::max_heap::sift_up(int* element)
{
  if(element != data_)
  {
    int* parent = data_ + (element - data_ + 1) / 2 - 1;
    if(*parent < *element)
    {
      std::swap(*parent, *element);
      sift_up(parent);
    }
  }
}

void my::max_heap::sift_down(int* element)
{
  int *left_child = data_ + (element - data_ + 1) * 2 - 1,
      *right_child = data_ + (element - data_ + 1) * 2;
  if(left_child - data_ < static_cast<long int>(size_))
  {
    if(right_child - data_ >= static_cast<long int>(size_))
      --right_child;
    int *child = *left_child > *right_child ? left_child : right_child;
    if(*child > *element)
    {
      std::swap(*child, *element);
      sift_down(child);
    }
  }
}

void my::max_heap::insert(int value)
{
  //std::cout << "heap before insertion: ";
  //print_heap();
  if(size_ == capacity_)
  {
    capacity_ *= 2;
    int *new_data = new int[capacity_];
    for(size_t i = 0; i < size_; ++i)
      new_data[i] = data_[i];
    delete[] data_;
    data_ = new_data;
  }
  data_[size_++] = value;
  sift_up(data_ + size_ - 1);
  //std::cout << "heap ater insertion: ";
  //print_heap();
}

int my::max_heap::extract_max()
{
  //std::cout << "heap before extraction: ";
  //print_heap();
  std::swap(*data_, data_[--size_]);
  sift_down(data_);
  //std::cout << "heap after extraction: ";
  //print_heap();
  return data_[size_];
}

/*void my::max_heap::print_heap()
{
  for(size_t i = 0; i < size_; ++i)
    std::cout << data_[i] << ' ';
  std::cout << std::endl;
}*/

int main()
{
  int N, num;
  std::cin >> N;
  std::string query;
  my::max_heap my_heap;
  for(int i = 0; i < N; ++i)
  {
    std::cin >> query;
    if(query == "Insert")
    {
      std::cin >> num;
      my_heap.insert(num);
    }
    else
      std::cout << my_heap.extract_max() << std::endl;
  }
  return 0;
}