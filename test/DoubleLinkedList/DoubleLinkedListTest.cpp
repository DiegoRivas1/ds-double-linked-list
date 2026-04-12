#include <gtest/gtest.h>
#include <sstream>
#include "DoubleLinkedList.h"

// Insert
TEST(DoubleLinkedListTest, InsertVacia) {
    DoubleLinkedList<int> list;
    list.insert(1, 0);
    EXPECT_EQ(list.size(), 1);
}

TEST(DoubleLinkedListTest, InsertAlInicio) {
    DoubleLinkedList<int> list;
    list.insert(1, 0);
    list.insert(2, 0);
    list.insert(3, 0); // 3 <-> 2 <-> 1
    std::ostringstream os;
    os << list;
    EXPECT_EQ(os.str(), "3<->2<->1\n");
}

TEST(DoubleLinkedListTest, InsertAlFinal) {
    DoubleLinkedList<int> list;
    list.insert(1, 0);
    list.insert(2, 1);
    list.insert(3, 2); // 1 <-> 2 <-> 3
    std::ostringstream os;
    os << list;
    EXPECT_EQ(os.str(), "1<->2<->3\n");
}

TEST(DoubleLinkedListTest, InsertEnMedio) {
    DoubleLinkedList<int> list;
    list.insert(1, 0);
    list.insert(3, 1);
    list.insert(2, 1); // 1 <-> 2 <-> 3
    std::ostringstream os;
    os << list;
    EXPECT_EQ(os.str(), "1<->2<->3\n");
}

TEST(DoubleLinkedListTest, InsertPosicionInvalida) {
    DoubleLinkedList<int> list;
    EXPECT_THROW(list.insert(1, 5), std::out_of_range);
}

// Remove
TEST(DoubleLinkedListTest, RemoveUnicoElemento) {
    DoubleLinkedList<int> list;
    list.insert(1, 0);
    list.remove(0);
    EXPECT_TRUE(list.isEmpty());
}

TEST(DoubleLinkedListTest, RemoveAlInicio) {
    DoubleLinkedList<int> list;
    list.insert(1, 0);
    list.insert(2, 1);
    list.insert(3, 2); // 1 <-> 2 <-> 3
    list.remove(0);    // 2 <-> 3
    std::ostringstream os;
    os << list;
    EXPECT_EQ(os.str(), "2<->3\n");
}

TEST(DoubleLinkedListTest, RemoveAlFinal) {
    DoubleLinkedList<int> list;
    list.insert(1, 0);
    list.insert(2, 1);
    list.insert(3, 2); // 1 <-> 2 <-> 3
    list.remove(2);    // 1 <-> 2
    std::ostringstream os;
    os << list;
    EXPECT_EQ(os.str(), "1<->2\n");
}

TEST(DoubleLinkedListTest, RemoveEnMedio) {
    DoubleLinkedList<int> list;
    list.insert(1, 0);
    list.insert(2, 1);
    list.insert(3, 2); // 1 <-> 2 <-> 3
    list.remove(1);    // 1 <-> 3
    std::ostringstream os;
    os << list;
    EXPECT_EQ(os.str(), "1<->3\n");
}

TEST(DoubleLinkedListTest, RemoveVariosAlFinal) {
    DoubleLinkedList<int> list;
    list.insert(1, 0);
    list.insert(2, 1);
    list.insert(3, 2);
    list.insert(4, 3); // 1 <-> 2 <-> 3 <-> 4
    list.remove(3);    // 1 <-> 2 <-> 3
    list.remove(2);    // 1 <-> 2
    std::ostringstream os;
    os << list;
    EXPECT_EQ(os.str(), "1<->2\n");
}

TEST(DoubleLinkedListTest, RemovePosicionInvalida) {
    DoubleLinkedList<int> list;
    EXPECT_THROW(list.remove(0), std::out_of_range);
}

// Search
TEST(DoubleLinkedListTest, SearchEncontrado) {
    DoubleLinkedList<int> list;
    list.insert(42, 0);
    EXPECT_TRUE(list.search(42));
}

TEST(DoubleLinkedListTest, SearchNoEncontrado) {
    DoubleLinkedList<int> list;
    list.insert(1, 0);
    EXPECT_FALSE(list.search(99));
}

// SearchPos
TEST(DoubleLinkedListTest, SearchPosInicio) {
    DoubleLinkedList<int> list;
    list.insert(10, 0);
    list.insert(20, 1);
    list.insert(30, 2);
    EXPECT_EQ(list.searchPos(0), 10);
}

TEST(DoubleLinkedListTest, SearchPosFinal) {
    DoubleLinkedList<int> list;
    list.insert(10, 0);
    list.insert(20, 1);
    list.insert(30, 2);
    EXPECT_EQ(list.searchPos(2), 30);
}

TEST(DoubleLinkedListTest, SearchPosMedio) {
    DoubleLinkedList<int> list;
    list.insert(10, 0);
    list.insert(20, 1);
    list.insert(30, 2);
    EXPECT_EQ(list.searchPos(1), 20);
}

TEST(DoubleLinkedListTest, SearchPosInvalida) {
    DoubleLinkedList<int> list;
    EXPECT_THROW((void)list.searchPos(0), std::out_of_range);
}

// isEmpty / size
TEST(DoubleLinkedListTest, IsEmptyVerdadero) {
    DoubleLinkedList<int> list;
    EXPECT_TRUE(list.isEmpty());
}

TEST(DoubleLinkedListTest, IsEmptyFalso) {
    DoubleLinkedList<int> list;
    list.insert(1, 0);
    EXPECT_FALSE(list.isEmpty());
}

// Print
TEST(DoubleLinkedListTest, PrintVacia) {
    DoubleLinkedList<int> list;
    std::ostringstream os;
    os << list;
    EXPECT_EQ(os.str(), "");
}

// Template con otros tipos
TEST(DoubleLinkedListTest, TemplateConString) {
    DoubleLinkedList<std::string> list;
    list.insert("hola", 0);
    list.insert("mundo", 1);
    std::ostringstream os;
    os << list;
    EXPECT_EQ(os.str(), "hola<->mundo\n");
}

// Constructor de copia
TEST(DoubleLinkedListTest, ConstructorCopia) {
    DoubleLinkedList<int> list;
    list.insert(1, 0);
    list.insert(2, 1);
    list.insert(3, 2);
    DoubleLinkedList<int> copy(list);
    std::ostringstream os;
    os << copy;
    EXPECT_EQ(os.str(), "1<->2<->3\n");
}

TEST(DoubleLinkedListTest, ConstructorCopiaUnElemento) {
    DoubleLinkedList<int> list;
    list.insert(1, 0);
    DoubleLinkedList<int> copy(list);
    EXPECT_EQ(copy.size(), 1);
    EXPECT_EQ(copy.searchPos(0), 1);
}

// Constructor copia mismo tipo
TEST(DoubleLinkedListTest, ConstructorCopiaMismoTipo) {
    DoubleLinkedList<int> list;
    list.insert(1, 0);
    list.insert(2, 1);
    list.insert(3, 2);
    DoubleLinkedList<int> copy(list);
    std::ostringstream os;
    os << copy;
    EXPECT_EQ(os.str(), "1<->2<->3\n");
}

// Constructor copia conversion de tipo
TEST(DoubleLinkedListTest, ConstructorCopiaConversion) {
    DoubleLinkedList<int> list;
    list.insert(1, 0);
    list.insert(2, 1);
    DoubleLinkedList<double> copy(list);
    EXPECT_EQ(copy.searchPos(0), 1.0);
    EXPECT_EQ(copy.searchPos(1), 2.0);
}

// Operador = mismo tipo
TEST(DoubleLinkedListTest, OperadorAsignacionMismoTipo) {
    DoubleLinkedList<int> list;
    list.insert(1, 0);
    list.insert(2, 1);
    DoubleLinkedList<int> other;
    other = list;
    std::ostringstream os;
    os << other;
    EXPECT_EQ(os.str(), "1<->2\n");
}

// Operador = auto asignacion
TEST(DoubleLinkedListTest, OperadorAsignacionAutoAsignacion) {
    DoubleLinkedList<int> list;
    list.insert(1, 0);
    list = list;
    EXPECT_EQ(list.size(), 1);
}

// Operador = conversion de tipo
TEST(DoubleLinkedListTest, OperadorAsignacionConversion) {
    DoubleLinkedList<int> list;
    list.insert(1, 0);
    list.insert(2, 1);
    DoubleLinkedList<double> other;
    other = list;
    EXPECT_EQ(other.searchPos(0), 1.0);
    EXPECT_EQ(other.size(), 2);
}

// Clear
TEST(DoubleLinkedListTest, Clear) {
    DoubleLinkedList<int> list;
    list.insert(1, 0);
    list.insert(2, 1);
    list.clear();
    EXPECT_TRUE(list.isEmpty());
}

//Polimorfismo
TEST(DoubleLinkedListTest, Polimorfismo) {
    List<int>* lista = new DoubleLinkedList<int>();
    lista->insert(1, 0);
    lista->insert(2, 1);
    lista->insert(3, 2);
    std::ostringstream os;
    os << *lista;
    EXPECT_EQ(os.str(), "1<->2<->3\n");
    delete lista;
}