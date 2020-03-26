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

TEST(Monom, can_copy_monomial)
{
	int arr[] = { 1,2 };
	Monom mon_original(2, arr, 2);
	ASSERT_NO_THROW(Monom mon_copy(mon_original));
}

TEST(Monom, can_set_power)
{
	int arr[] = { 1,2 };
	Monom mon;
	ASSERT_NO_THROW(mon.setPower(arr));
}

TEST(Monom, can_get_power)
{
	int arr[] = { 1,2,3 };
	Monom mon(3, arr, 1);
	ASSERT_NO_THROW(mon.setPower(arr));
	ASSERT_EQ(arr[0], mon.getPower()[0]);
	ASSERT_EQ(arr[1], mon.getPower()[1]);
	ASSERT_EQ(arr[2], mon.getPower()[2]);
}

TEST(Monom, can_set_and_get_size)
{
	int arr[] = { 1,2,3 };
	Monom mon(3, arr, 1);
	mon.setN(2);
	EXPECT_EQ(2, mon.getN());
}

TEST(Monom, can_set_and_get_coeff)
{
	Monom mon;
	mon.setCoeff(3);
	EXPECT_EQ(3, mon.getCoeff());
}

TEST(Monom, can_set_and_get_next)
{
	int arr[] = { 1,2,3 };
	int narr[] = { 4,5,7 };
	Monom mon1(3, arr, 3);
	Monom mon2(3, narr, 3);
	ASSERT_NO_THROW(mon1.setNext(&mon2));
	EXPECT_EQ(mon1.getNext(), &mon2);
}

TEST(Monom, can_assign_monomials_w_equal_size)
{
	int arr[] = { 1,2,3 };
	int narr[] = { 4,5,6 };
	Monom mon1(3, arr, 3);
	Monom mon2(3, narr, 3);
	ASSERT_NO_THROW(mon1 = mon2);
}

TEST(Monom, throws_when_assign_monomials_w_diff_size)
{
	int arr[] = { 1,2,3 };
	int narr[] = { 4,5 };
	Monom mon1(3, arr, 3);
	Monom mon2(2, narr, 3);
	ASSERT_ANY_THROW(mon1 = mon2);
}

TEST(Monom, can_add_monomials_w_eq_size)
{
	int arr[] = { 1,2 };
	Monom mon1(2, arr, 2);
	Monom mon2(2, arr, 4);
	ASSERT_NO_THROW(mon1 + mon2);
}

TEST(Monom, can_subtract_monomials_w_eq_size)
{
	int arr[] = { 1,2 };
	Monom mon1(2, arr, 2);
	Monom mon2(2, arr, 4);
	ASSERT_NO_THROW(mon1 - mon2);
}

TEST(Monom, throws_when_add_or_subtract_monomials_w_diff_size)
{
	int arr[] = { 1,2 };
	int narr[] = { 1,2,3 };
	Monom mon1(2, arr, 2);
	Monom mon2(3, narr, 4);
	ASSERT_ANY_THROW(mon1 + mon2);
	ASSERT_ANY_THROW(mon1 - mon2);
}

TEST(Monom, can_multiply_monomials)
{
	int arr[] = { 1,2 };
	int narr[] = { 3,4 };
	Monom mon1(2, arr, 2);
	Monom mon2(2, narr, 4);
	ASSERT_NO_THROW(mon1 * mon2);
}

TEST(Monom, throws_when_multiply_diff_monomials)
{
	int arr[] = { 1,2 };
	int narr[] = { 3,4,5 };
	Monom mon1(2, arr, 2);
	Monom mon2(3, narr, 4);
	ASSERT_ANY_THROW(mon1 * mon2);
}

TEST(Monom, can_compare_monomials_w_eq_size)
{
	int arr[] = { 1,2,3 };
	int narr[] = { 4,5,6 };
	Monom mon1(3, arr, 3);
	Monom mon2(3, narr, 4);
	ASSERT_NO_THROW(mon1 > mon2);
	ASSERT_NO_THROW(mon1 < mon2);
	ASSERT_TRUE(mon1 < mon2);
	ASSERT_FALSE(mon1 > mon2);
}

TEST(Monom, throws_when_compare_monomials_w_diff_size)
{
	int arr[] = { 1,2,3 };
	int narr[] = { 4,5,6,7 };
	Monom mon1(3, arr, 3);
	Monom mon2(4, narr, 4);
	ASSERT_ANY_THROW(mon1 > mon2);
	ASSERT_ANY_THROW(mon1 < mon2);
}

TEST(Monom, can_equivalence_monomials)
{
	int arr[] = { 1,2,3 };
	int narr[] = { 1,5,3 };
	Monom mon(3, arr, 4);
	Monom mon1(3, arr, 4);
	Monom mon2(3, narr, 4);
	ASSERT_TRUE(mon == mon1);
	ASSERT_FALSE(mon == mon2);
}

TEST(TMonom, throws_when_equivalence_monomials_w_diff_size)
{
	int arr[] = { 1,2,3 };
	int narr[] = { 1,5,3,4 };
	Monom mon(3, arr, 2);
	Monom mon1(4, narr, 2);
	ASSERT_ANY_THROW(mon == mon1);
}