#include <iostream>

int *getData()
{
    int *a = new int(5);
    return a;
} // we use new, which adds to the heap instead of the stack
  // as we used new, we need to delete the memory manually.

int main()
{
    int *b = getData();
    std::cout << *b << std::endl;
    delete b;
    return 0;
}