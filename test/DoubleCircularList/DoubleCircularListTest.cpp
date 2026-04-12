#include <gtest/gtest.h>
#include <sstream>
#include "../include/DoubleCircularList.h"

// Insert
TEST(DoubleCircularListTest, InsertVacia) {
    DoubleCircularList<int> list;
    list.insert(1, 0);
    EXPECT_EQ(list.size(), 1);
}

TEST(DoubleCircularListTest, InsertVaciaApuntaASiMismo) {
    DoubleCircularList<int> list;
    list.insert(1, 0);
    // head->next y head->prev deben apuntar al mismo nodo
    EXPECT_EQ(list.searchPos(0), 1);
    EXPECT_EQ(list.size(), 1);
}

TEST(DoubleCircularListTest, InsertAlInicio) {
    DoubleCircularList<int> list;
    list.insert(1, 0);
    list.insert(2, 0);
    list.insert(3, 0); // 3 <-> 2 <-> 1 -> (3)
    std::ostringstream os;
    os << list;
    EXPECT_EQ(os.str(), "3<->2<->1->(3)\n");
}

TEST(DoubleCircularListTest, InsertAlFinal) {
    DoubleCircularList<int> list;
    list.insert(1, 0);
    list.insert(2, 1);
    list.insert(3, 2); // 1 <-> 2 <-> 3 -> (1)
    std::ostringstream os;
    os << list;
    EXPECT_EQ(os.str(), "1<->2<->3->(1)\n");
}

TEST(DoubleCircularListTest, InsertEnMedio) {
    DoubleCircularList<int> list;
    list.insert(1, 0);
    list.insert(3, 1);
    list.insert(2, 1); // 1 <-> 2 <-> 3 -> (1)
    std::ostringstream os;
    os << list;
    EXPECT_EQ(os.str(), "1<->2<->3->(1)\n");
}

TEST(DoubleCircularListTest, InsertPosicionInvalida) {
    DoubleCircularList<int> list;
    EXPECT_THROW(list.insert(1, 5), std::out_of_range);
}

// Remove
TEST(DoubleCircularListTest, RemoveUnicoElemento) {
    DoubleCircularList<int> list;
    list.insert(1, 0);
    list.remove(0);
    EXPECT_TRUE(list.isEmpty());
}

TEST(DoubleCircularListTest, RemoveAlInicio) {
    DoubleCircularList<int> list;
    list.insert(1, 0);
    list.insert(2, 1);
    list.insert(3, 2); // 1 <-> 2 <-> 3 -> (1)
    list.remove(0);    // 2 <-> 3 -> (2)
    std::ostringstream os;
    os << list;
    EXPECT_EQ(os.str(), "2<->3->(2)\n");
}

TEST(DoubleCircularListTest, RemoveAlFinal) {
    DoubleCircularList<int> list;
    list.insert(1, 0);
    list.insert(2, 1);
    list.insert(3, 2); // 1 <-> 2 <-> 3 -> (1)
    list.remove(2);    // 1 <-> 2 -> (1)
    std::ostringstream os;
    os << list;
    EXPECT_EQ(os.str(), "1<->2->(1)\n");
}

TEST(DoubleCircularListTest, RemoveEnMedio) {
    DoubleCircularList<int> list;
    list.insert(1, 0);
    list.insert(2, 1);
    list.insert(3, 2); // 1 <-> 2 <-> 3 -> (1)
    list.remove(1);    // 1 <-> 3 -> (1)
    std::ostringstream os;
    os << list;
    EXPECT_EQ(os.str(), "1<->3->(1)\n");
}

TEST(DoubleCircularListTest, RemoveVariosAlFinal) {
    DoubleCircularList<int> list;
    list.insert(1, 0);
    list.insert(2, 1);
    list.insert(3, 2);
    list.insert(4, 3); // 1 <-> 2 <-> 3 <-> 4 -> (1)
    list.remove(3);    // 1 <-> 2 <-> 3 -> (1)
    list.remove(2);    // 1 <-> 2 -> (1)
    std::ostringstream os;
    os << list;
    EXPECT_EQ(os.str(), "1<->2->(1)\n");
}

TEST(DoubleCircularListTest, RemovePosicionInvalida) {
    DoubleCircularList<int> list;
    EXPECT_THROW(list.remove(0), std::out_of_range);
}

// Search
TEST(DoubleCircularListTest, SearchEncontrado) {
    DoubleCircularList<int> list;
    list.insert(42, 0);
    EXPECT_TRUE(list.search(42));
}

TEST(DoubleCircularListTest, SearchNoEncontrado) {
    DoubleCircularList<int> list;
    list.insert(1, 0);
    EXPECT_FALSE(list.search(99));
}

// SearchPos
TEST(DoubleCircularListTest, SearchPosInicio) {
    DoubleCircularList<int> list;
    list.insert(10, 0);
    list.insert(20, 1);
    list.insert(30, 2);
    EXPECT_EQ(list.searchPos(0), 10);
}

TEST(DoubleCircularListTest, SearchPosFinal) {
    DoubleCircularList<int> list;
    list.insert(10, 0);
    list.insert(20, 1);
    list.insert(30, 2);
    EXPECT_EQ(list.searchPos(2), 30);
}

TEST(DoubleCircularListTest, SearchPosMedio) {
    DoubleCircularList<int> list;
    list.insert(10, 0);
    list.insert(20, 1);
    list.insert(30, 2);
    EXPECT_EQ(list.searchPos(1), 20);
}

TEST(DoubleCircularListTest, SearchPosInvalida) {
    DoubleCircularList<int> list;
    EXPECT_THROW((void)list.searchPos(0), std::out_of_range);
}

// isEmpty / size
TEST(DoubleCircularListTest, IsEmptyVerdadero) {
    DoubleCircularList<int> list;
    EXPECT_TRUE(list.isEmpty());
}

TEST(DoubleCircularListTest, IsEmptyFalso) {
    DoubleCircularList<int> list;
    list.insert(1, 0);
    EXPECT_FALSE(list.isEmpty());
}

// Clear
TEST(DoubleCircularListTest, Clear) {
    DoubleCircularList<int> list;
    list.insert(1, 0);
    list.insert(2, 1);
    list.clear();
    EXPECT_TRUE(list.isEmpty());
}

// Print
TEST(DoubleCircularListTest, PrintVacia) {
    DoubleCircularList<int> list;
    std::ostringstream os;
    os << list;
    EXPECT_EQ(os.str(), "");
}

// Template con otros tipos
TEST(DoubleCircularListTest, TemplateConString) {
    DoubleCircularList<std::string> list;
    list.insert("hola", 0);
    list.insert("mundo", 1);
    std::ostringstream os;
    os << list;
    EXPECT_EQ(os.str(), "hola<->mundo->(hola)\n");
}

// Constructor copia mismo tipo
TEST(DoubleCircularListTest, ConstructorCopiaMismoTipo) {
    DoubleCircularList<int> list;
    list.insert(1, 0);
    list.insert(2, 1);
    list.insert(3, 2);
    DoubleCircularList<int> copy(list);
    std::ostringstream os;
    os << copy;
    EXPECT_EQ(os.str(), "1<->2<->3->(1)\n");
}

// Constructor copia conversion
TEST(DoubleCircularListTest, ConstructorCopiaConversion) {
    DoubleCircularList<int> list;
    list.insert(1, 0);
    list.insert(2, 1);
    DoubleCircularList<double> copy(list);
    EXPECT_EQ(copy.searchPos(0), 1.0);
    EXPECT_EQ(copy.searchPos(1), 2.0);
}

// Operador = mismo tipo
TEST(DoubleCircularListTest, OperadorAsignacionMismoTipo) {
    DoubleCircularList<int> list;
    list.insert(1, 0);
    list.insert(2, 1);
    DoubleCircularList<int> other;
    other = list;
    std::ostringstream os;
    os << other;
    EXPECT_EQ(os.str(), "1<->2->(1)\n");
}

// Operador = auto asignacion
TEST(DoubleCircularListTest, OperadorAsignacionAutoAsignacion) {
    DoubleCircularList<int> list;
    list.insert(1, 0);
    list = list;
    EXPECT_EQ(list.size(), 1);
}

// Operador = conversion
TEST(DoubleCircularListTest, OperadorAsignacionConversion) {
    DoubleCircularList<int> list;
    list.insert(1, 0);
    list.insert(2, 1);
    DoubleCircularList<double> other;
    other = list;
    EXPECT_EQ(other.searchPos(0), 1.0);
    EXPECT_EQ(other.size(), 2);
}

// Polimorfismo
TEST(DoubleCircularListTest, Polimorfismo) {
    List<int>* lista = new DoubleCircularList<int>();
    lista->insert(1, 0);
    lista->insert(2, 1);
    lista->insert(3, 2);
    std::ostringstream os;
    os << *lista;
    EXPECT_EQ(os.str(), "1<->2<->3->(1)\n");
    delete lista;
}