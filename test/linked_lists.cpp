#include "gtest/gtest.h"
#include "linked_lists.h"
#include <vector>

TEST(linked_lists_tests, permutation_test) {
    Node head = Node(0);
    Node* head_ptr = &head;
    for (int i = 1; i < 5; i++)
    {
        head.appendToTail(i);
    }
    std::string expected_output = "01234";
    std::string output = "";
    while (head_ptr->next != nullptr)
    {
        output += std::to_string(head_ptr->data);
        head_ptr = head_ptr->next.get();
    }
    output += std::to_string(head_ptr->data);
    ASSERT_EQ(expected_output, output);
}