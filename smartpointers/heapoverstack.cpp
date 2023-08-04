#include <iostream>

int *getData()
{
    int *a = new int(5);
    return a;
} // we use new, which adds to the heap instead of the stack
  // as we used new, we need to delete the memory manually,
  // smart pointers allow us to avoid manual mem management

int main()
{
    int *b = getData();
    std::cout << *b << std::endl;
    delete b;
    return 0;
}