public class WholeNum {
    private static final long UINT_MAX = (1L << 32) - 1;
    private final long value;

    public WholeNum(long value) {
        this.value = Math.min(Math.max(value, 0), UINT_MAX);
    }

    public long getValue() {
        return value;
    }

    public WholeNum getSuccessor() {
        return new WholeNum(value == UINT_MAX ? UINT_MAX : value + 1);
    }

    public WholeNum add(WholeNum other) {
        return new WholeNum(Math.min(value + other.value, UINT_MAX));
    }

    public WholeNum subtract(WholeNum other) {
        return new WholeNum(Math.max(value - other.value, 0));
    }

    public boolean equals(WholeNum other) {
        return this.value == other.value;
    }

    @Override
    public String toString() {
        return String.valueOf(value);
    }

    public static void main(String[] args) {
        WholeNum zero = new WholeNum(0);
        WholeNum one = zero.getSuccessor();
        WholeNum sum = one.add(one);

        System.out.println(zero); // 0
        System.out.println(one); // 1
        System.out.println(sum); // 2

        if (zero.equals(new WholeNum(0))) {
            System.out.println("0 is zero");
        }

        if (one.equals(sum)) {
            System.out.println("Something is wrong: 1 is equal to sum");
        } else {
            System.out.println("Correct: 1 is not equal to sum (1 != 2)");
        }
    }
}
