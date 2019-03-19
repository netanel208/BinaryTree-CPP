/**
 * Examples of automatic tests for the exercise on binary trees.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>

using std::cout, std::endl;

#include "badkan.hpp"
#include "Tree.hpp"

int main() {

  ariel::Tree emptytree;

  ariel::Tree threetree;  
  threetree.insert(5);
  threetree.insert(7);
  threetree.insert(3);

  badkan::TestCase tc("Binary tree");


  tc
  .CHECK_EQUAL (emptytree.size(), 0)
  .CHECK_OK    (emptytree.insert(5))
  .CHECK_OK    (emptytree.insert(3))
  .CHECK_OK    (emptytree.insert(7))
  .CHECK_OK    (emptytree.insert(6))
  .CHECK_OK    (emptytree.insert(9))
  .CHECK_OK    (emptytree.insert(10))
  .CHECK_OK    (emptytree.insert(8))
  .CHECK_OK    (emptytree.insert(4))
  .CHECK_OK    (emptytree.insert(1))
  .CHECK_OK    (emptytree.insert(2))
  .CHECK_EQUAL (emptytree.size(), 10)
  .CHECK_EQUAL (emptytree.contains(5), true)
  .CHECK_EQUAL (emptytree.contains(3), true)
  .CHECK_EQUAL (emptytree.contains(2), true)
  //.CHECK_OK    (emptytree.print())
  .CHECK_OK    (emptytree.remove(2))
  .CHECK_OK    (emptytree.remove(7))
  .CHECK_OK    (emptytree.remove(6))
  .CHECK_OK    (emptytree.remove(5))
  .CHECK_THROWS(emptytree.remove(5))
  .CHECK_THROWS(emptytree.remove(6))
  .CHECK_THROWS(emptytree.remove(7))
  .CHECK_THROWS(emptytree.remove(2))
  .CHECK_EQUAL(emptytree.contains(5), false)
  .CHECK_EQUAL(emptytree.contains(6), false)
  .CHECK_EQUAL(emptytree.contains(7), false)
  //.CHECK_OK    (emptytree.print())
  .CHECK_EQUAL (emptytree.left(4), 3)
  .CHECK_EQUAL (emptytree.left(9), 8)
  .CHECK_EQUAL (emptytree.right(4), 9)
  .CHECK_EQUAL (emptytree.right(9), 10)
  .CHECK_THROWS(emptytree.left(2))
  .CHECK_THROWS(emptytree.right(3))
  .CHECK_EQUAL (emptytree.size(), 6)
  .CHECK_OK    (emptytree.remove(3))
  .CHECK_OK    (emptytree.remove(9))
  .CHECK_OK    (emptytree.remove(10))
  .CHECK_EQUAL (emptytree.contains(4), true)
  .CHECK_EQUAL (emptytree.contains(1), true)
  .CHECK_EQUAL (emptytree.contains(8), true)
  //.CHECK_OK    (emptytree.print())
  .CHECK_EQUAL (emptytree.root(), 4)
  .CHECK_EQUAL (emptytree.size() ,3)


  .CHECK_EQUAL (threetree.size(), 3)
  .CHECK_EQUAL (threetree.root(), 5)
  .CHECK_EQUAL (threetree.parent(3), 5)
  .CHECK_EQUAL (threetree.parent(7), 5)
  .CHECK_EQUAL (threetree.contains(5), true)
  .CHECK_EQUAL (threetree.contains(7), true)
  .CHECK_EQUAL (threetree.contains(3), true)
  .CHECK_EQUAL (threetree.contains(9), false)
  .CHECK_EQUAL (threetree.left(5), 3)
  .CHECK_EQUAL (threetree.right(5), 7)
  .CHECK_THROWS(threetree.insert(3))
  .CHECK_OK    (threetree.print())

  .print();

  cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;

}