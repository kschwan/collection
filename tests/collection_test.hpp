
#ifndef COLLECTION_TEST_HPP
#define COLLECTION_TEST_HPP

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "test_case.hpp"

namespace tests
{
  class CollectionTest : public TestCase
  {
      CPPUNIT_TEST_SUITE(CollectionTest);
      CPPUNIT_TEST(testCollectionIsEmptyAfterConstruction);
      CPPUNIT_TEST(testAnItemCanBeAddedToTheCollection);
      CPPUNIT_TEST(testMultipleItemsCanBeAddedToTheCollection);
      CPPUNIT_TEST(testAnItemCanAccessedFromTheCollection);
      CPPUNIT_TEST(testAnItemCanBePluckedFromTheCollection);
      CPPUNIT_TEST(testAnItemCanBeErasedFromTheCollection);
      CPPUNIT_TEST(testThatMultipleItemsCanBeErasedFromTheCollection);
      CPPUNIT_TEST(testThatItIsPossibleToManipulateEachItemInTheCollection);
      CPPUNIT_TEST(testThatItIsPossibleToSortTheCollection);
      CPPUNIT_TEST(testThatItIsPossibleToSortTheCollectionWithALambda);
      CPPUNIT_TEST(testThatTheCollectinCanBeCleared);
      CPPUNIT_TEST_SUITE_END();

    protected:
      void testCollectionIsEmptyAfterConstruction();
      void testAnItemCanBeAddedToTheCollection();
      void testMultipleItemsCanBeAddedToTheCollection();
      void testAnItemCanAccessedFromTheCollection();
      void testAnItemCanBePluckedFromTheCollection();
      void testAnItemCanBeErasedFromTheCollection();
      void testThatMultipleItemsCanBeErasedFromTheCollection();
      void testThatItIsPossibleToManipulateEachItemInTheCollection();
      void testThatItIsPossibleToSortTheCollection();
      void testThatItIsPossibleToSortTheCollectionWithALambda();
      void testThatTheCollectinCanBeCleared();
  };
} // namespace tests

#endif /* COLLECTION_TEST_HPP */
