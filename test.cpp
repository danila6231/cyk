#include <gtest/gtest.h>
#include "cyk.h"

TEST(GrammarTest, Test1) {
    Config conf;
    conf.add("S->BC");
    conf.add("B->a");
    conf.add("C->b");
    conf.add("S->1");
    ASSERT_TRUE(conf.check("ab"));
}

TEST(GrammarTest, Test2) {
    Config conf;
    conf.add("S->a");
    ASSERT_TRUE(conf.check("a"));
}

TEST(GrammarTest, Test3) {
    Config conf;
    conf.add("S->BC");
    conf.add("B->BC");
    conf.add("C->BC");
    conf.add("B->b");
    conf.add("C->c");
    ASSERT_TRUE(conf.check("bc"));
    ASSERT_TRUE(conf.check("bccc"));
    ASSERT_TRUE(conf.check("bbbc"));
    ASSERT_FALSE(conf.check("cb"));
    ASSERT_TRUE(conf.check("bbbccc"));
}

TEST(GrammarTest, Test4) {
    Config conf;
    conf.add("S->BC");
    conf.add("C->DE");
    conf.add("C->a");
    conf.add("B->b");
    conf.add("D->d");
    conf.add("E->e");
    ASSERT_TRUE(conf.check("ba"));
    ASSERT_TRUE(conf.check("bde"));
    ASSERT_FALSE(conf.check("a"));
}

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}