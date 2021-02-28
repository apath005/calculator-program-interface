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
