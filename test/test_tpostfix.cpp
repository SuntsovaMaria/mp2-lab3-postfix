#include "postfix.h"
#include <gtest.h>
#include <string.h>

TEST(Expression, can_create_expression_without_parameter)
{
	ASSERT_NO_THROW(Expression p);
}

TEST(Expression, can_create_expression_with_parameter)
{
	 string str = "1+1";
	ASSERT_NO_THROW(Expression test(str));
}
TEST(Expression, get_infix) {
	string str = "1+1";
	Expression test(str);
	ASSERT_NO_THROW(test.GetInfix());
	EXPECT_EQ(str, test.GetInfix());

}
TEST(Expression, get_postfix) {
	string str = "1+1";
	Expression test(str);
	ASSERT_NO_THROW(test.GetPostfix());
	EXPECT_EQ("11+", test.GetPostfix());

}
TEST(Expression, can_calculate)
{
	string str = "1+1";
	Expression test(str);
	ASSERT_NO_THROW(test.calc());
	EXPECT_EQ(2, test.calc());
}
TEST(Expression, can_calculate2)
{
	string str = "7+(-9*2)/3-7*((6+3)-(7/2*5))";
	Expression test(str);
	ASSERT_NO_THROW(test.calc());
	EXPECT_EQ(60.5, test.calc());
}
TEST(Expression, can_calculate3)
{
	string str = "-(7*8*10/2)";
	Expression test(str);
	ASSERT_NO_THROW(test.calc());
	EXPECT_EQ(-280, test.calc());
}
TEST(Expression, cant_calculate_div_0)
{
	string str = "7/(9-5-4)";
	Expression test(str);
	ASSERT_ANY_THROW(test.calc());
	
}
TEST(Expression, cant_calculate_incorrect_expr1)
{
	string str = "9+9+";
	Expression test(str);
	ASSERT_ANY_THROW(test.calc());
}
TEST(Expression, cant_calculate_incorrect_expr2)
{
	string str = "(8+5*(9)))";
	Expression test(str);
	ASSERT_ANY_THROW(test.calc());
}
TEST(Expression, cant_calculate_incorrect_expr3)
{
	string str = "à+0-";
	Expression test(str);
	ASSERT_ANY_THROW(test.calc());
}

