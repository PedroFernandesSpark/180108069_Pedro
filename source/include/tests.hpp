// copyright [2020] <Pedro Fernandes 180108169>
#ifndef SOURCE_INCLUDE_TESTS_HPP_
#define SOURCE_INCLUDE_TESTS_HPP_
#include "catch.hpp"
#include "stack.hpp"
#endif  // SOURCE_INCLUDE_TESTS_HPP_


// Inicia os testes do Catch2
TEST_CASE("Testing stack functions") {
    stackArray pilha;
    pilha.CreateStack(5);

    REQUIRE(pilha.Size() == 5);
    REQUIRE(pilha.IsEmpty() == true);
    REQUIRE(pilha.IsFull() == false);
// Testa os metodos Size, IsEmpty, IsFull e Pop
    SECTION("Testing Pop function") {
        for (int i = 0; i < 4; i++) {
            pilha.Push(i);
        }
        REQUIRE(pilha.Size() == 5);
        REQUIRE(pilha.Pop().StackItem == 3);
        REQUIRE(pilha.Pop().StackItem == 2);
        REQUIRE(pilha.Pop().StackItem == 1);
        REQUIRE(pilha.IsFull() == false);
        REQUIRE(pilha.IsEmpty() == false); }
// Testa o metodo Push
    SECTION("Testing Top function") {
        pilha.Push(66);
        REQUIRE(pilha.Top().StackItem == 66); }
// Testa o metodo SetSize
    SECTION("Testing Set Size function") {
        pilha.SetSize(10);

        REQUIRE(pilha.Size() == 10);
    }
// Testa o metodo DestroyStack
    SECTION("Testing delete function") {
        REQUIRE(pilha.DestroyStack(pilha) == true);
    }
}
