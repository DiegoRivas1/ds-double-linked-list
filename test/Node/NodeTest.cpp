#include <gtest/gtest.h>
#include "Node.h"

TEST(NodeTest, ConstructorSetsData) {
    const Node<int> node(42);
    EXPECT_EQ(node.getData(), 42);
}

TEST(NodeTest, ConstructorAllArgs) {
    const Node<int> node(4, nullptr, nullptr);
    EXPECT_EQ(node.getData(), 4);
}

TEST(NodeTest, LinksWorkCorrectly) {
    Node<int> n1(1);
    Node<int> n2(2);

    n1.setNext(&n2);
    n2.setPrev(&n1);

    EXPECT_EQ(n1.getNext(), &n2);
    EXPECT_EQ(n2.getPrev(), &n1);
}

TEST(NodeTest, SetDataUpdatesValue) {
    Node<int> n1(1);
    n1.setData(1);
    EXPECT_EQ(n1.getData(), 1);
}

TEST(NodeTest, PrintOperator) {
    Node<int> n1(1);
    std::ostringstream os;
    os << n1;
    EXPECT_EQ(os.str(), "1");
}