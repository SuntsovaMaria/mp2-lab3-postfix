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

TEST(TStack, test_isEmpty_1) {
	TStack<int> stack;
	ASSERT_EQ(true, stack.isEmpty());
}
TEST(TStack, top_on_empty_stack) {
	TStack<int> stack;
	ASSERT_ANY_THROW(stack.top());
}
TEST(TStack, test_push) {
	TStack<int> stack;
	int a = 1;
	stack.push(a);
	int e = stack.top();
	ASSERT_EQ(a, e);
}
TEST(TStack, test_push1) {
	TStack<int> stack;
	int a = 1;
	int b = 2;
	stack.push(a);
	stack.push(b);
	int e = stack.top();
	ASSERT_EQ(b, e);
}
TEST(TStack, test_push_with_litle_stack) {
	TStack <int> stack(2);
	stack.push(0);
	stack.push(1);
	int a = 2;
	stack.push(a);
	int b = stack.top();
	ASSERT_EQ(a, b);

}
TEST(TStack, test_copy_constr) {
	TStack<int> stack1;
	int arr[4] = { 1,2,3,4 };
	for (int i = 0; i < 4; i++) {
		stack1.push(arr[i]);
	}
	TStack<int> stack2(stack1);
	bool c = true;
	if (stack1.getSize() != stack2.getSize()) {
		c = false;
	}
	else
		for (int i = 0; i < stack1.getSize(); i++) {
			int  a = stack1.top();
			int b = stack2.top();
			stack1.pop();
			stack2.pop();
			if (a != b) {
				c = false;
			}
		}
	ASSERT_TRUE(c);
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
TEST(TStack, test_equal_cmp_on_equal_stacks) {
	TStack<int> stack1;
	int arr[4] = { 1,2,3,4 };
	for (int i = 0; i < 4; i++) {
		stack1.push(arr[i]);
	}
	TStack<int> stack2(stack1);
	bool c = true;
	if (stack1.getSize() != stack2.getSize()) {
		c = false;
	}
	else
		for (int i = 0; i < stack1.getSize(); i++) {
			int  a = stack1.top();
			int b = stack2.top();
			stack1.pop();
			stack2.pop();
			if (a != b) {
				c = false;
			}
		}
	ASSERT_EQ(c, stack1 == stack2);
}
TEST(TStack, test_equal_cmp_on_not_equal_stacks) {
	TStack<int> stack1;
	int arr[4] = { 1,2,3,4 };
	for (int i = 0; i < 4; i++) {
		stack1.push(arr[i]);
	}
	TStack<int> stack2(stack1);
	stack2.push(9);
	bool c = true;
	if (stack1.getSize() != stack2.getSize()) {
		c = false;
	}
	else
		for (int i = 0; i < stack1.getSize(); i++) {
			int  a = stack1.top();
			int b = stack2.top();
			stack1.pop();
			stack2.pop();
			if (a != b) {
				c = false;
			}
		}
	ASSERT_EQ(c, stack1 == stack2);
}
