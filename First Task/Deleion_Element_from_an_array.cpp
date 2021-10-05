/*Removes from the container all the elements that compare equal to val. This calls the destructor of these objects and reduces the container size by the number of elements removed.
Unlike member function list::erase, which erases elements by their position (using an iterator), this function (list::remove) removes elements by their value.
First I have stored the elements in a list instead of array. Next I have used builtin function */
#include <iostream>
#include <list>

int main ()
{
  int myints[]= {3,2,2,3};
  std::list<int> mylist (myints,myints+4);

  mylist.remove(2);

  std::cout << "After deletion:";
  for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
