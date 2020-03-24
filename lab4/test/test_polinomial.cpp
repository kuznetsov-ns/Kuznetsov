#include "polinomial.h"
#include <gtest.h>

TEST(Monom, can_create_monomial)
{
	ASSERT_NO_THROW(Monom mon);
}

TEST(Monom, can_create_monomial_with_positive_lenght)
{
	int arr[] = { 1,2,3 };
	ASSERT_NO_THROW(Monom mon(3, arr, 4));
}

TEST(Monom, throws_when_create_monomial_with_negative_size)
{
	int arr[] = { 1,2,3 };
	ASSERT_ANY_THROW(Monom mon(-2, arr, 2));
}

