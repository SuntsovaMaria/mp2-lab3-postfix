#include "stack.h"
#include <gtest.h>

TEST(TStack, can_create_TStack) {
	ASSERT_NO_THROW(TStack<int> stack);
}

TEST(TStack, can_create_TStack_with_positiv_len) {
	ASSERT_NO_THROW(TStack<int> stack(12));
}

TEST(TStack, can_create_TStack_with_negativ_len) {
	ASSERT_ANY_THROW(TStack<int> stack(-12));
}

TEST(TStack, test_isEmpty1) {
	TStack<int> stack;
	ASSERT_EQ(true, stack.isEmpty());
}
TEST(TStack, test_isEmpty2) {
	TStack<int> stack;
	stack.push(1);
	ASSERT_EQ(false, stack.isEmpty());
}

TEST(TStack, top_on_empty_stack) {
	TStack<int> stack;
	ASSERT_ANY_THROW(stack.top());
}
TEST(TStack, test_push) {
	TStack<int> stack;
	stack.push(1);
	ASSERT_EQ(stack.top(), 1);
}

TEST(TStack, test_push_with_litle_stack) {
	TStack <int> stack(2);
	stack.push(0);
	stack.push(1);
	stack.push(2);
	ASSERT_EQ(2, stack.top());

}
TEST(TStack, test_copy_constr) {
	TStack<int> stack1;
	int arr[4] = { 1,2,3,4 };
	for (int i = 0; i < 4; i++) {
		stack1.push(arr[i]);
	}
	TStack<int> stack2(stack1);
	
	ASSERT_TRUE(stack1==stack2);
}

TEST(TStack, test_top) {
	TStack<int> stack1;
	int arr[4] = { 1,2,3,4 };
	for (int i = 0; i < 4; i++) {
		stack1.push(arr[i]);
	}
	int a = stack1.top();
	ASSERT_EQ(a, arr[3]);
}
TEST(TStack, test_pop) {
	TStack<int> stack1;
	int arr[4] = { 1,2,3,4 };
	for (int i = 0; i < 4; i++) {
		stack1.push(arr[i]);
	}
	bool c = true;
	int a = stack1.getSize();
	int a1 = stack1.top();
	stack1.pop();
	int b = stack1.getSize();
	int b1 = stack1.top();
	if (b != a - 1)
		c = false;
	ASSERT_TRUE(c);
}
TEST(TStack, Test_pop_on_empty_stack) {
	TStack<int> stack1;
	ASSERT_ANY_THROW(stack1.pop(););
}
TEST(TStack, Test_top_on_empty_stack) {
	TStack<int> stack1;
	ASSERT_ANY_THROW(stack1.top(););
}

TEST(TStack, test_equal_cmp_on_not_equal_stacks) {
	TStack<int> stack1;
	int arr[4] = { 1,2,3,4 };
	for (int i = 0; i < 4; i++) {
		stack1.push(arr[i]);
	}
	TStack<int> stack2(stack1);
	stack2.push(9);
	
	ASSERT_FALSE( stack1 == stack2);
}
