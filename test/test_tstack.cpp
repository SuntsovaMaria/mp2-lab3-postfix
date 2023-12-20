#include "stack.h"
#include <gtest.h>

TEST(TStack, can_create_TStack) {
	ASSERT_NO_THROW(TStack<int> stack);
}

TEST(TStack, can_create_TStack_with_positiv_len) {
	ASSERT_NO_THROW(TStack<int> stack(1));
}

TEST(TStack, cant_create_TStack_with_negativ_len) {
	ASSERT_ANY_THROW(TStack<int> stack(-1));
}

TEST(TStack, test_isEmpty1) {
	TStack<int> stack;
	EXPECT_TRUE(stack.isEmpty());
}
TEST(TStack, test_isEmpty2) {
	TStack<int> stack;
	stack.push(1);
	EXPECT_FALSE(stack.isEmpty());
}

TEST(TStack, top_on_empty_stack) {
	TStack<int> stack;
	ASSERT_ANY_THROW(stack.top());
}
TEST(TStack, test_push) {
	TStack<int> stack;
	ASSERT_NO_THROW(stack.push(1));
	EXPECT_EQ(stack.top(), 1);
}

TEST(TStack, test_push1) {
	TStack <int> stack(2);
	stack.push(0);
	stack.push(1);
	ASSERT_NO_THROW(stack.push(2));
	EXPECT_EQ(2, stack.top());


}
TEST(TStack, test_copy_constr) {
	TStack<int> stack1;
	int arr[4] = { 1,2,3,4 };
	for (int i = 0; i < 4; i++) {
		stack1.push(arr[i]);
	}
	TStack<int> stack2(stack1);
	
	EXPECT_TRUE(stack1==stack2);
}

TEST(TStack, test_top) {
	TStack<int> stack1;
	int arr[4] = { 1,2,3,4 };
	for (int i = 0; i < 4; i++) {
		stack1.push(arr[i]);
	}
	int a = stack1.top();
	EXPECT_EQ(a, 4);
}
TEST(TStack, test_pop) {
	TStack<int> stack1;
	int arr[4] = { 1,2,3,4 };
	for (int i = 0; i < 4; i++) {
		stack1.push(arr[i]);
	}
	ASSERT_NO_THROW(stack1.pop());
	EXPECT_EQ(stack1.top(), 3);
}
TEST(TStack, test_pop_on_empty_stack) {
	TStack<int> stack1;
	ASSERT_ANY_THROW(stack1.pop(););
}
TEST(TStack, test_top_on_empty_stack) {
	TStack<int> stack1;
	ASSERT_ANY_THROW(stack1.top(););
}
TEST(TStack, test_equal_cmp_on_equal_stacks) {
	TStack<int> stack1;
	TStack<int>stack2;
	int arr[4] = { 1,2,3,4 };
	for (int i = 0; i < 4; i++) {
		stack1.push(arr[i]);
		stack2.push(arr[i]);
	}
	EXPECT_TRUE(stack1 == stack2);
}
TEST(TStack, test_equal_cmp_on_not_equal_stacks) {
	TStack<int> stack1;
	int arr[4] = { 1,2,3,4 };
	for (int i = 0; i < 4; i++) {
		stack1.push(arr[i]);
	}
	TStack<int> stack2(stack1);
	stack2.push(9);
	
	EXPECT_FALSE(stack1 == stack2);
}
