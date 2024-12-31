int sum_of_digits(int n) { return n < 10 ? n : n % 10 + sum_of_digits(n / 10); }

int reduction_of_digits(int n) {
    int sum = sum_of_digits(n);
    return n < 10 ? sum : reduction_of_digits(sum);
}
