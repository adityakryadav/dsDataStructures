class WholeNum:
    UINT_MAX = (1 << 32) - 1  # Simulating unsigned int max value

    def __init__(self, value=0):
        self.value = min(max(value, 0), WholeNum.UINT_MAX)

    def get_value(self):
        return self.value

    def get_successor(self):
        return WholeNum(self.value + 1 if self.value < WholeNum.UINT_MAX else WholeNum.UINT_MAX)

    def __add__(self, other):
        return WholeNum(min(self.value + other.value, WholeNum.UINT_MAX))

    def __sub__(self, other):
        return WholeNum(max(self.value - other.value, 0))

    def __eq__(self, other):
        return self.value == other.value

    def __str__(self):
        return str(self.value)


if __name__ == "__main__":
    zero = WholeNum()
    one = zero.get_successor()
    sum_val = one + one

    print(zero)  # 0
    print(one)  # 1
    print(sum_val)  # 2

    if zero == WholeNum(0):
        print("0 is zero")

    if one == sum_val:
        print("Something is wrong: 1 is equal to sum")
    else:
        print("Correct: 1 is not equal to sum (1 != 2)")
