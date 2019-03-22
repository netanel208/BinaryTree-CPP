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
  .CHECK_OK    (threetree.remove(threetree.root()))
  .CHECK_OK    (threetree.remove(threetree.root()))
  .CHECK_OK    (threetree.remove(threetree.root()))
  .CHECK_OK    (threetree.insert(20))
  .CHECK_OK    (threetree.insert(10))
  .CHECK_OK    (threetree.insert(30))
  .CHECK_OK    (threetree.insert(15))
  .CHECK_OK    (threetree.insert(5))
  .CHECK_OK    (threetree.insert(25))
  .CHECK_OK    (threetree.insert(35))     
  .CHECK_OK    (threetree.insert(1))
  .CHECK_OK    (threetree.insert(6))
  .CHECK_OK    (threetree.insert(11))
  .CHECK_OK    (threetree.insert(16))
  .CHECK_OK    (threetree.insert(21))
  .CHECK_OK    (threetree.insert(26))
  .CHECK_OK    (threetree.insert(31))
  .CHECK_OK    (threetree.insert(36))    
  .CHECK_EQUAL (threetree.contains(30), true)
  .CHECK_EQUAL (threetree.contains(33), false)
  .CHECK_EQUAL (threetree.contains(5), true)
  .CHECK_EQUAL (threetree.contains(26), true)
  .CHECK_EQUAL (threetree.contains(14), false)
  .CHECK_EQUAL (threetree.contains(10), true)
  .CHECK_THROWS(threetree.insert(35))
  .CHECK_THROWS(threetree.insert(25))  
  .CHECK_THROWS(threetree.insert(10))
  .CHECK_EQUAL (threetree.parent(1), 5)
  .CHECK_EQUAL (threetree.parent(6), 5)
  .CHECK_EQUAL (threetree.parent(11), 15)
  .CHECK_EQUAL (threetree.parent(16), 15)
  .CHECK_EQUAL (threetree.parent(5), 10)
  .CHECK_EQUAL (threetree.parent(15), 10)
  .CHECK_EQUAL (threetree.parent(10), 20)
  .CHECK_THROWS(threetree.parent(20))
  .CHECK_OK    (threetree.remove(20))
  .CHECK_EQUAL (threetree.left(16), 10)
  .CHECK_EQUAL (threetree.right(16), 30)
  .CHECK_OK    (threetree.remove(30))
  .CHECK_EQUAL (threetree.left(26), 25)
  .CHECK_EQUAL (threetree.right(26), 35)
  .CHECK_OK    (threetree.remove(16))
  .CHECK_EQUAL (threetree.left(15), 10)
  .CHECK_EQUAL (threetree.right(15), 26)
  .CHECK_THROWS(threetree.left(11))
  .CHECK_THROWS(threetree.right(11))
  .CHECK_OK    (threetree.remove(threetree.root()))
  .CHECK_OK    (threetree.remove(threetree.root()))
  .CHECK_OK    (threetree.remove(threetree.root()))
  .CHECK_OK    (threetree.remove(threetree.root()))
  .CHECK_OK    (threetree.remove(threetree.root()))
  .CHECK_THROWS(threetree.left(threetree.root()))
  .CHECK_EQUAL (threetree.right(threetree.root()), threetree.right(threetree.root()))
  .CHECK_EQUAL (threetree.size(), 7)
  // .CHECK_OK    (threetree.print())
  .CHECK_OK    (threetree.remove(threetree.root()))
  .CHECK_EQUAL (threetree.contains(1), false)
  .CHECK_OK    (threetree.remove(threetree.root()))
  .CHECK_THROWS(threetree.remove(threetree.left(threetree.left(threetree.root()))))
  .CHECK_OK    (threetree.remove(threetree.right(threetree.root())))
  .CHECK_EQUAL (threetree.size(), 4)
  .CHECK_OK    (threetree.remove(threetree.right(threetree.right(threetree.root()))))
  .CHECK_THROWS(threetree.left(threetree.left(threetree.root())))
  //.CHECK_OK    (threetree.print())
  .CHECK_OK    (threetree.remove(threetree.root()))
  .CHECK_OK    (threetree.remove(threetree.root()))
  .CHECK_OK    (threetree.remove(threetree.root()))
  .CHECK_EQUAL (threetree.size(), 0);


  cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;

}