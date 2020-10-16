#include "catch.hpp"
#include "stack.hpp"


TEST_CASE( "Testing stack functions") {

    stackArray pilha(5);

    REQUIRE( pilha.Size() == 5 );
    REQUIRE( pilha.IsEmpty() == true);
    REQUIRE( pilha.IsFull() == false);

    SECTION( "Testing Pop function" ) {
        for (int i = 0; i < 4; i++)
        {
            pilha.Push(i);
        }
        
        REQUIRE( pilha.Size() == 5 );
        REQUIRE( pilha.Pop().StackItem == 3 );
        REQUIRE( pilha.Pop().StackItem == 2 );
        REQUIRE( pilha.Pop().StackItem == 1 );
        REQUIRE( pilha.IsFull() == false);
        REQUIRE( pilha.IsEmpty() == false);
        
    }
    SECTION( "Testing Top function" ) {

        pilha.Push( 66 );

        REQUIRE( pilha.Top().StackItem == 66 );
    }
    SECTION( "Testing Set Size function" ) {
        pilha.SetSize(10);

        REQUIRE( pilha.Size() == 10 );
    }
    SECTION( "Testing delete function" ) {

        REQUIRE( pilha.DestroyStack(pilha) == true) ;
    }
}
