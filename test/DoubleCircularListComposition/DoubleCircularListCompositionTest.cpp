#include <gtest/gtest.h>
#include <sstream>
#include "DoubleCircularListComposition.h"

// InsertFront
TEST(DoubleCircularListCompositionTest, InsertFrontYSize) {
    DoubleCircularListComposition<int> list;
    list.insertFront(1);
    list.insertFront(2);
    list.insertFront(3); // 3 <-> 2 <-> 1 -> (3)
    EXPECT_EQ(list.size(), 3);
}

TEST(DoubleCircularListCompositionTest, InsertFrontOrden) {
    DoubleCircularListComposition<int> list;
    list.insertFront(1);
    list.insertFront(2);
    list.insertFront(3); // 3 <-> 2 <-> 1 -> (3)
    std::ostringstream os;
    os << list;
    EXPECT_EQ(os.str(), "3<->2<->1->(3)\n");
}

// InsertBack
TEST(DoubleCircularListCompositionTest, InsertBackOrden) {
    DoubleCircularListComposition<int> list;
    list.insertBack(1);
    list.insertBack(2);
    list.insertBack(3); // 1 <-> 2 <-> 3 -> (1)
    std::ostringstream os;
    os << list;
    EXPECT_EQ(os.str(), "1<->2<->3->(1)\n");
}

// RemoveFront
TEST(DoubleCircularListCompositionTest, RemoveFrontReduceSize) {
    DoubleCircularListComposition<int> list;
    list.insertBack(1);
    list.insertBack(2);
    list.insertBack(3);
    list.removeFront(); // 2 <-> 3 -> (2)
    EXPECT_EQ(list.size(), 2);
    std::ostringstream os;
    os << list;
    EXPECT_EQ(os.str(), "2<->3->(2)\n");
}

TEST(DoubleCircularListCompositionTest, RemoveFrontVacia) {
    DoubleCircularListComposition<int> list;
    EXPECT_THROW(list.removeFront(), std::out_of_range);
}

// RemoveBack
TEST(DoubleCircularListCompositionTest, RemoveBackReduceSize) {
    DoubleCircularListComposition<int> list;
    list.insertBack(1);
    list.insertBack(2);
    list.insertBack(3);
    list.removeBack(); // 1 <-> 2 -> (1)
    EXPECT_EQ(list.size(), 2);
    std::ostringstream os;
    os << list;
    EXPECT_EQ(os.str(), "1<->2->(1)\n");
}

TEST(DoubleCircularListCompositionTest, RemoveBackVacia) {
    DoubleCircularListComposition<int> list;
    EXPECT_THROW(list.removeBack(), std::out_of_range);
}

// Rotate
TEST(DoubleCircularListCompositionTest, RotateUnaVez) {
    DoubleCircularListComposition<int> list;
    list.insertBack(1);
    list.insertBack(2);
    list.insertBack(3); // 1 <-> 2 <-> 3 -> (1)
    list.rotate();      // 2 <-> 3 <-> 1 -> (2)
    std::ostringstream os;
    os << list;
    EXPECT_EQ(os.str(), "2<->3<->1->(2)\n");
}

TEST(DoubleCircularListCompositionTest, RotateVueltaCompleta) {
    DoubleCircularListComposition<int> list;
    list.insertBack(1);
    list.insertBack(2);
    list.insertBack(3); // 1 <-> 2 <-> 3 -> (1)
    list.rotate();      // 2 <-> 3 <-> 1 -> (2)
    list.rotate();      // 3 <-> 1 <-> 2 -> (3)
    list.rotate();      // 1 <-> 2 <-> 3 -> (1) vuelta completa
    std::ostringstream os;
    os << list;
    EXPECT_EQ(os.str(), "1<->2<->3->(1)\n");
}

TEST(DoubleCircularListCompositionTest, RotateVacia) {
    DoubleCircularListComposition<int> list;
    EXPECT_THROW(list.rotate(), std::out_of_range);
}

// Front / Back
TEST(DoubleCircularListCompositionTest, FrontRetornaValor) {
    DoubleCircularListComposition<int> list;
    list.insertBack(1);
    list.insertBack(2);
    EXPECT_EQ(list.front(), 1);
}

TEST(DoubleCircularListCompositionTest, BackRetornaValor) {
    DoubleCircularListComposition<int> list;
    list.insertBack(1);
    list.insertBack(2);
    EXPECT_EQ(list.back(), 2);
}

TEST(DoubleCircularListCompositionTest, FrontVacia) {
    DoubleCircularListComposition<int> list;
    EXPECT_THROW((void)list.front(), std::out_of_range);
}

TEST(DoubleCircularListCompositionTest, BackVacia) {
    DoubleCircularListComposition<int> list;
    EXPECT_THROW((void)list.back(), std::out_of_range);
}

// isEmpty / size
TEST(DoubleCircularListCompositionTest, IsEmptyVerdadero) {
    DoubleCircularListComposition<int> list;
    EXPECT_TRUE(list.isEmpty());
}

TEST(DoubleCircularListCompositionTest, IsEmptyFalso) {
    DoubleCircularListComposition<int> list;
    list.insertBack(1);
    EXPECT_FALSE(list.isEmpty());
}

// Print vacia
TEST(DoubleCircularListCompositionTest, PrintVacia) {
    DoubleCircularListComposition<int> list;
    std::ostringstream os;
    os << list;
    EXPECT_EQ(os.str(), "");
}

// Template con otros tipos
TEST(DoubleCircularListCompositionTest, TemplateConString) {
    DoubleCircularListComposition<std::string> list;
    list.insertBack("hola");
    list.insertBack("mundo");
    std::ostringstream os;
    os << list;
    EXPECT_EQ(os.str(), "hola<->mundo->(hola)\n");
}