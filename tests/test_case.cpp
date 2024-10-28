
#include "test_case.hpp"

#include <sstream>
#include <iostream>

tests::TestCase::TestCase(bool captureStdOut)
    : captureStdCout_{captureStdOut}
{
}

void tests::TestCase::setUp()
{
  if (captureStdCout_)
  {
    this->buffer_             = new std::stringstream();
    this->previousCoutBuffer_ = std::cout.rdbuf(this->buffer_->rdbuf());
  }
}

void tests::TestCase::tearDown()
{
  if (captureStdCout_)
  {
    std::cout.rdbuf(this->previousCoutBuffer_);
    delete this->buffer_;
  }
}

void tests::TestCase::assertTrue(bool value)
{
  CPPUNIT_ASSERT_EQUAL(true, value);
}

void tests::TestCase::assertFalse(bool value)
{
  CPPUNIT_ASSERT_EQUAL(false, value);
}
