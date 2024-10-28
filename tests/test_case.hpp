
#ifndef HHTYMP_TEST_TEST_CASE_HPP
#define HHTYMP_TEST_TEST_CASE_HPP

#include <sstream>
#include <iostream>
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

namespace tests
{
  class TestCase : public CPPUNIT_NS::TestFixture
  {
    public:
      TestCase(bool = false);

      /**
       * @brief Setup requirements, mocks etc. that are common for all test cases, in the giving class.
       */
      virtual void setUp() override;

      /**
       * @brief Tear down requirements, mock etc. that are common for all tests cases, in the giving class.
       */
      virtual void tearDown() override;

      void assertTrue(bool);
      void assertFalse(bool);

    protected:
      bool captureStdCout_;
      std::stringstream* buffer_;
      std::streambuf* previousCoutBuffer_;
  };

} // namespace tests

#endif /* HHTYMP_TEST_TEST_CASE_HPP */
