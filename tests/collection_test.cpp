
#include "collection_test.hpp"

#include <array>

#include "../source/collection.hpp"

namespace tests
{
  void CollectionTest::testCollectionIsEmptyAfterConstruction()
  {
    collection::Collection<int> collection{};

    CPPUNIT_ASSERT_EQUAL(size_t{0}, collection.size());
  }

  void CollectionTest::testAnItemCanBeAddedToTheCollection()
  {
    collection::Collection<int> collection{};

    collection.append(1);

    CPPUNIT_ASSERT_EQUAL(1, collection.get(0));
    CPPUNIT_ASSERT_EQUAL(size_t{1}, collection.size());
  }

  void CollectionTest::testMultipleItemsCanBeAddedToTheCollection()
  {
    collection::Collection<int> collection{};

    std::array<int, 3> items{1, 2, 3};

    collection.append(items);

    CPPUNIT_ASSERT_EQUAL(1, collection.get(0));
    CPPUNIT_ASSERT_EQUAL(2, collection.get(1));
    CPPUNIT_ASSERT_EQUAL(3, collection.get(2));
    CPPUNIT_ASSERT_EQUAL(size_t{3}, collection.size());
  }

  void CollectionTest::testAnItemCanAccessedFromTheCollection()
  {
    collection::Collection<int> collection{};

    collection.append(2);

    CPPUNIT_ASSERT_EQUAL(size_t{1}, collection.size());
    CPPUNIT_ASSERT_EQUAL(2, collection.get(0));
    CPPUNIT_ASSERT_EQUAL(size_t{1}, collection.size());
  }

  void CollectionTest::testAnItemCanBePluckedFromTheCollection()
  {
    collection::Collection<int> collection{};

    collection.append(2);

    CPPUNIT_ASSERT_EQUAL(size_t{1}, collection.size());
    CPPUNIT_ASSERT_EQUAL(2, collection.pluck(0));
    CPPUNIT_ASSERT_EQUAL(size_t{0}, collection.size());
  }

  void CollectionTest::testAnItemCanBeErasedFromTheCollection()
  {
    collection::Collection<int> collection{};

    collection.append(2);

    CPPUNIT_ASSERT_EQUAL(size_t{1}, collection.size());
    collection.erase(0);
    CPPUNIT_ASSERT_EQUAL(size_t{0}, collection.size());
  }

  void CollectionTest::testThatMultipleItemsCanBeErasedFromTheCollection()
  {
    collection::Collection<int> collection{};

    collection
        .append(2)
        .append(3)
        .append(4);

    CPPUNIT_ASSERT_EQUAL(size_t{3}, collection.size());
    collection.erase(0, 3);
    CPPUNIT_ASSERT_EQUAL(size_t{0}, collection.size());
  }

  void CollectionTest::testThatItIsPossibleToManipulateEachItemInTheCollection()
  {
    collection::Collection<int> collection{};

    collection
        .append(1)
        .append(2)
        .append(3)
        .append(4);

    CPPUNIT_ASSERT_EQUAL(size_t{4}, collection.size());
    CPPUNIT_ASSERT_EQUAL(1, collection.get(0));
    CPPUNIT_ASSERT_EQUAL(2, collection.get(1));
    CPPUNIT_ASSERT_EQUAL(3, collection.get(2));
    CPPUNIT_ASSERT_EQUAL(4, collection.get(3));

    collection.each([](auto&& item) {
      if (item % 2 == 0)
      {
        item *= 2;
      }
      else
      {
        item = 0;
      }
    });

    CPPUNIT_ASSERT_EQUAL(0, collection.get(0));
    CPPUNIT_ASSERT_EQUAL(4, collection.get(1));
    CPPUNIT_ASSERT_EQUAL(0, collection.get(2));
    CPPUNIT_ASSERT_EQUAL(8, collection.get(3));

    struct Test
    {
        Test(int a, int b)
            : a{a}
            , b{b}
        {
        }

        int a;
        int b;
    };

    collection::Collection<Test> collectionOfStructs{};

    collectionOfStructs
        .append(Test{1, 2})
        .append(Test{3, 4});

    collectionOfStructs
        .each([](auto&& item) {
          item.a *= 2;
          item.b *= 3;
        });

    CPPUNIT_ASSERT_EQUAL(2, collectionOfStructs.get(0).a);
    CPPUNIT_ASSERT_EQUAL(6, collectionOfStructs.get(0).b);
    CPPUNIT_ASSERT_EQUAL(6, collectionOfStructs.get(1).a);
    CPPUNIT_ASSERT_EQUAL(12, collectionOfStructs.get(1).b);
  }

  void CollectionTest::testThatItIsPossibleToSortTheCollection()
  {
    collection::Collection<int> collection{};

    collection
        .append(3)
        .append(2)
        .append(1)
        .append(4);

    CPPUNIT_ASSERT_EQUAL(3, collection.get(0));
    CPPUNIT_ASSERT_EQUAL(2, collection.get(1));
    CPPUNIT_ASSERT_EQUAL(1, collection.get(2));
    CPPUNIT_ASSERT_EQUAL(4, collection.get(3));

    collection.sort();

    CPPUNIT_ASSERT_EQUAL(1, collection.get(0));
    CPPUNIT_ASSERT_EQUAL(2, collection.get(1));
    CPPUNIT_ASSERT_EQUAL(3, collection.get(2));
    CPPUNIT_ASSERT_EQUAL(4, collection.get(3));
  }

  void CollectionTest::testThatItIsPossibleToSortTheCollectionWithALambda()
  {
    collection::Collection<int> collection{};

    collection
        .append(3)
        .append(2)
        .append(1)
        .append(4);

    CPPUNIT_ASSERT_EQUAL(3, collection.get(0));
    CPPUNIT_ASSERT_EQUAL(2, collection.get(1));
    CPPUNIT_ASSERT_EQUAL(1, collection.get(2));
    CPPUNIT_ASSERT_EQUAL(4, collection.get(3));

    collection.sort([](auto&& a, auto&& b) {
      return a > b;
    });

    CPPUNIT_ASSERT_EQUAL(4, collection.get(0));
    CPPUNIT_ASSERT_EQUAL(3, collection.get(1));
    CPPUNIT_ASSERT_EQUAL(2, collection.get(2));
    CPPUNIT_ASSERT_EQUAL(1, collection.get(3));
  }

  void CollectionTest::testThatTheCollectinCanBeCleared()
  {
    collection::Collection<int> collection{};

    collection
        .append(1)
        .append(2)
        .append(3)
        .append(4);

    CPPUNIT_ASSERT_EQUAL(size_t{4}, collection.size());

    collection.clear();

    CPPUNIT_ASSERT_EQUAL(size_t{0}, collection.size());
  }
} // namespace tests
