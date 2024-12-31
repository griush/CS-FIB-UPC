void digit_maxim_i_minim(int n, int& maxim, int& minim) {
    if (n < 10) {
        maxim = n;
        minim = n;
        return;
    }

    int t_max;
    int t_min;
    digit_maxim_i_minim(n / 10, t_max, t_min);

    maxim = t_max;
    minim = t_min;
    int last = n % 10;
    if (t_max < last)
        maxim = last;
    else if (t_min > last)
        minim = last;
}

#include <iostream>

int main(int argc, char const* argv[]) {
    int n;
    while (std::cin >> n) {
        int m, mn;
        digit_maxim_i_minim(n, m, mn);
        std::cout << m << ' ' << mn << std::endl;
    }

    return 0;
}
