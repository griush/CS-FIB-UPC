int number_of_digits(int n) {
    if (n / 10 == 0) return 1;
    return number_of_digits(n / 10) + 1;
}
