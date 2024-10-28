
import os

env = Environment()
env.Append(CXXFLAGS='-std=c++23')

env.MergeFlags({
    'CPPPATH': [
        os.path.abspath('source/'),
    ],
})

env.Program(
    target='collection-test',
    source=[
        'tests/test_case.cpp',
        'tests/test_suite.cpp',
        'tests/collection_test.cpp',
    ],
    LIBS=[
        'dl',
        'gtest',
        'gmock',
        'cppunit',
    ],
)

env.Program(
    target='collection',
    source=[
        'source/main.cpp',
    ],
    LIBS=[
    ],
)
