#include "factory.hpp"

#include "base.hpp"

#include "gtest/gtest.h"


TEST(CalculatorTest, AddingNonZeros) {
	char* input[4]; input[0] = "./calculator"; input[1] = "3"; input[2] = "+"; input[3] = "5";
	Factory* calculator = new Factory();
	Base* test = calculator->parse(input, 4);
	std::string stringifyResult = test->stringify();
	double evaluateResult = test->evaluate();
	EXPECT_EQ("3.000000 + 5.000000", stringifyResult);
	EXPECT_EQ(8, evaluateResult);
}

TEST(CalculatorTest, AddingSequenceofNonZeros) {
        char* input[8]; input[0] = "./calculator"; input[1] = "3"; input[2] = "+"; input[3] = "5"; input[4] = "+"; input[5] = "8"; input[6] = "+"; input[7] = "10";
        Factory* calculator = new Factory();
        Base* test = calculator->parse(input, 8);
        std::string stringifyResult = test->stringify();
        double evaluateResult = test->evaluate();
        EXPECT_EQ("3.000000 + 5.000000 + 8.000000 + 10.000000", stringifyResult);
	EXPECT_EQ(26, evaluateResult);
}

TEST(CalculatorTest, AddSubtractDivideMultiplySequenceofNonZeros) {
        char* input[10]; input[0] = "./calculator"; input[1] = "3"; input[2] = "+"; input[3] = "5"; input[4] = "-"; input[5] = "2"; input[6] = "/"; input[7] = "10"; input[8] = "*"; input[9] = "5";
        Factory* calculator = new Factory();
        Base* test = calculator->parse(input, 10);
        std::string stringifyResult = test->stringify();
        double evaluateResult = test->evaluate();
        EXPECT_EQ("3.000000 + 5.000000 - 2.000000 / 10.000000 * 5.000000", stringifyResult);
	EXPECT_EQ(3, evaluateResult);
}

TEST(CalculatorTest, AddSubtractDivideMultiplySequenceofDecimals) {
        char* input[10]; input[0] = "./calculator"; input[1] = "3.14"; input[2] = "+"; input[3] = "5.5"; input[4] = "-"; input[5] = "8.2"; input[6] = "/"; input[7] = "6.0"; input[8] = "*"; input[9] = "5.5";
        Factory* calculator = new Factory();
        Base* test = calculator->parse(input, 10);
        std::string stringifyResult = test->stringify();
        double evaluateResult = test->evaluate();
        EXPECT_EQ("3.140000 + 5.500000 - 8.200000 / 6.000000 * 5.500000", stringifyResult);

}

TEST(CalculatorTest, AddPowSubtractSequenceofNonZeros) {
        char* input[8]; input[0] = "./calculator"; input[1] = "6"; input[2] = "+"; input[3] = "11"; input[4] = "-"; input[5] = "8"; input[6] = "**"; input[7] = "10";
        Factory* calculator = new Factory();
        Base* test = calculator->parse(input, 8);
        std::string stringifyResult = test->stringify();
        double evaluateResult = test->evaluate();
        EXPECT_EQ("6.000000 + 11.000000 - 8.000000 ** 10.000000", stringifyResult);
	EXPECT_EQ(3486784401, evaluateResult);
}

TEST(CalculatorTest, ProduceNegativeResult) {
        char* input[4]; input[0] = "./calculator"; input[1] = "3"; input[2] = "-"; input[3] = "5";
        Factory* calculator = new Factory();
        Base* test = calculator->parse(input, 4);
        std::string stringifyResult = test->stringify();
        double evaluateResult = test->evaluate();
        EXPECT_EQ("3.000000 - 5.000000", stringifyResult);
	EXPECT_EQ(-2, evaluateResult);
}

TEST(CalculatorTest, ProduceInvalidResultbyLetterInput) {
        char* input[4]; input[0] = "./calculator"; input[1] = "3"; input[2] = "-"; input[3] = "a";
        Factory* calculator = new Factory();
        Base* test = calculator->parse(input, 4);
        ASSERT_TRUE(test == nullptr);
}

TEST(CalculatorTest, AddingAndMultiplyingbyLargerValues) {
        char* input[6]; input[0] = "./calculator"; input[1] = "100"; input[2] = "+"; input[3] = "500"; input[4] = "*"; input[5] = "3000";
        Factory* calculator = new Factory();
        Base* test = calculator->parse(input, 6);
        std::string stringifyResult = test->stringify();
        double evaluateResult = test->evaluate();
        EXPECT_EQ("100.000000 + 500.000000 * 3000.000000", stringifyResult);
	EXPECT_EQ(1800000, evaluateResult);
}

TEST(CalculatorTest, PowtoZeroPower) {
        char* input[4]; input[0] = "./calculator"; input[1] = "3"; input[2] = "**"; input[3] = "0";
        Factory* calculator = new Factory();
        Base* test = calculator->parse(input, 4);
        std::string stringifyResult = test->stringify();
        double evaluateResult = test->evaluate();
        EXPECT_EQ("3.000000 ** 0.000000", stringifyResult);
        EXPECT_EQ(1, evaluateResult);
}

TEST(CalculatorTest, PowofLargeValues) {
        char* input[4]; input[0] = "./calculator"; input[1] = "1000"; input[2] = "**"; input[3] = "1000";
        Factory* calculator = new Factory();
        Base* test = calculator->parse(input, 4);
        std::string stringifyResult = test->stringify();
        double evaluateResult = test->evaluate();
        EXPECT_EQ("1000.000000 ** 1000.000000", stringifyResult);
}

TEST(CalculatorTest, ManyMults) {
        char* input[10]; input[0] = "./calculator"; input[1] = "3"; input[2] = "*"; input[3] = "2"; input[4] = "*"; input[5] = "1"; input[6] = "*"; input[7] = "2"; input[8] = "*"; input[9] = "3";
        Factory* calculator = new Factory();
        Base* test = calculator->parse(input, 10);
        std::string stringifyResult = test->stringify();
        double evaluateResult = test->evaluate();
        EXPECT_EQ("3.000000 * 2.000000 * 1.000000 * 2.000000 * 3.000000", stringifyResult);
        EXPECT_EQ(36, evaluateResult);
}

TEST(CalculatorTest, ManyDivs) {
        char* input[10]; input[0] = "./calculator"; input[1] = "3"; input[2] = "/"; input[3] = "2"; input[4] = "/"; input[5] = "1"; input[6] = "/"; input[7] = "2"; input[8] = "/"; input[9] = "3";
        Factory* calculator = new Factory();
        Base* test = calculator->parse(input, 10);
        std::string stringifyResult = test->stringify();
        double evaluateResult = test->evaluate();
        EXPECT_EQ("3.000000 / 2.000000 / 1.000000 / 2.000000 / 3.000000", stringifyResult);
        EXPECT_EQ(0.25, evaluateResult);
}

TEST(CalculatorTest, SubWayBelowZero) {
        char* input[4]; input[0] = "./calculator"; input[1] = "3"; input[2] = "-"; input[3] = "100";
        Factory* calculator = new Factory();
        Base* test = calculator->parse(input, 4);
        std::string stringifyResult = test->stringify();
        double evaluateResult = test->evaluate();
        EXPECT_EQ("3.000000 - 100.000000", stringifyResult);
        EXPECT_EQ(-97, evaluateResult);
}

TEST(CalculatorTest, SubBelowZeroThenAddAboveZero) {
        char* input[6]; input[0] = "./calculator"; input[1] = "3"; input[2] = "-"; input[3] = "5"; input[4] = "+"; input[5] = "6";
        Factory* calculator = new Factory();
        Base* test = calculator->parse(input, 6);
        std::string stringifyResult = test->stringify();
        double evaluateResult = test->evaluate();
        EXPECT_EQ("3.000000 - 5.000000 + 6.000000", stringifyResult);
        EXPECT_EQ(4, evaluateResult);
}

TEST(CalculatorTest, DivideByZero) {
        char* input[4]; input[0] = "./calculator"; input[1] = "1"; input[2] = "/"; input[3] = "0";
        Factory* calculator = new Factory();
        Base* test = calculator->parse(input, 4);
        std::string stringifyResult = test->stringify();
        double evaluateResult = test->evaluate();
        EXPECT_EQ("1.000000 / 0.000000", stringifyResult);
}

TEST(CalculatorTest, DivByLargeNum) {
        char* input[4]; input[0] = "./calculator"; input[1] = "1"; input[2] = "/"; input[3] = "1000";
        Factory* calculator = new Factory();
        Base* test = calculator->parse(input, 4);
        std::string stringifyResult = test->stringify();
        double evaluateResult = test->evaluate();
        EXPECT_EQ("1.000000 / 1000.000000", stringifyResult);
        EXPECT_EQ(0.001, evaluateResult);
}

TEST(CalculatorTest, ManyPow) {
        char* input[10]; input[0] = "./calculator"; input[1] = "3"; input[2] = "**"; input[3] = "2"; input[4] = "**"; input[5] = "1"; input[6] = "**"; input[7] = "2"; input[8] = "**"; input[9] = "1";
        Factory* calculator = new Factory();
        Base* test = calculator->parse(input, 10);
        std::string stringifyResult = test->stringify();
        double evaluateResult = test->evaluate();
        EXPECT_EQ("3.000000 ** 2.000000 ** 1.000000 ** 2.000000 ** 1.000000", stringifyResult);
        EXPECT_EQ(81, evaluateResult);
}

TEST(CalculatorTest, ManySub) {
        char* input[10]; input[0] = "./calculator"; input[1] = "100"; input[2] = "-"; input[3] = "50"; input[4] = "-"; input[5] = "25"; input[6] = "-"; input[7] = "12"; input[8] = "-"; input[9] = "12";
        Factory* calculator = new Factory();
        Base* test = calculator->parse(input, 10);
        std::string stringifyResult = test->stringify();
        double evaluateResult = test->evaluate();
        EXPECT_EQ("100.000000 - 50.000000 - 25.000000 - 12.000000 - 12.000000", stringifyResult);
        EXPECT_EQ(1, evaluateResult);
}

TEST(CalculatorTest, AddingDoubles) {
        char* input[4]; input[0] = "./calculator"; input[1] = "3.8"; input[2] = "+"; input[3] = "3.2";
        Factory* calculator = new Factory();
        Base* test = calculator->parse(input, 4);
        std::string stringifyResult = test->stringify();
        double evaluateResult = test->evaluate();
        EXPECT_EQ("3.800000 + 3.200000", stringifyResult);
        EXPECT_EQ(7, evaluateResult);
}

TEST(CalculatorTest, DivIntByDoubles) {
        char* input[4]; input[0] = "./calculator"; input[1] = "5"; input[2] = "/"; input[3] = "2.5";
        Factory* calculator = new Factory();
        Base* test = calculator->parse(input, 4);
        std::string stringifyResult = test->stringify();
        double evaluateResult = test->evaluate();
        EXPECT_EQ("5.000000 / 2.500000", stringifyResult);
        EXPECT_EQ(2, evaluateResult);
}

TEST(CalculatorTest, PowByDouble) {
        char* input[4]; input[0] = "./calculator"; input[1] = "2"; input[2] = "**"; input[3] = "2.0";
        Factory* calculator = new Factory();
        Base* test = calculator->parse(input, 4);
        std::string stringifyResult = test->stringify();
        double evaluateResult = test->evaluate();
        EXPECT_EQ("2.000000 ** 2.000000", stringifyResult);
        EXPECT_EQ(4, evaluateResult);
}

