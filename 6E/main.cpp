#include <iostream>
#include <vector>
long long point(long long x, long long y, const std::vector<long long> & x_coordinate, const std::vector<long long> & y_coordinate) {
    long long difference_x;
    long long difference_y;
    long long max = -2000000001;
    for (int i = 0; i < x_coordinate.size(); i++) {
         difference_x = x - x_coordinate[i];
        if (difference_x <= 0)
            difference_x = -difference_x;
         difference_y = y - y_coordinate[i];
        if (difference_y <= 0)
            difference_y = -difference_y;
        if (difference_x + difference_y > max)
            max = difference_x + difference_y;
    }
    return max;
}
int main() {
    int N;
    std::cin >> N;
    std::vector<long long> x_coordinate(N);
    std::vector<long long> y_coordinate(N);
    long long min_difference = 2000000001;
    long long min_sum = 2000000001;
    long long max_sum = -2000000001;
    long long max_difference = -2000000001;
    for (int i = 0; i < N; i++) {
        std::cin >> x_coordinate[i];
        std::cin >> y_coordinate[i];
        if (min_difference > x_coordinate[i] - y_coordinate[i])
            min_difference = x_coordinate[i] - y_coordinate[i];
        if (min_sum > x_coordinate[i] + y_coordinate[i])
            min_sum = x_coordinate[i] + y_coordinate[i];
        if (max_difference < x_coordinate[i] - y_coordinate[i])
            max_difference = x_coordinate[i] - y_coordinate[i];
        if (max_sum < x_coordinate[i] + y_coordinate[i])
            max_sum = x_coordinate[i] + y_coordinate[i];
    }
    long long z_0 = (max_sum + min_sum) / 2;
    long long  t_0 = (min_difference + max_difference) / 2;
    long long  x_result = ((z_0 + t_0)) / 2;
    long long  y_result = (z_0 - t_0) / 2;
    long long x_result_result;
    long long y_result_result;
    long long max_1 = point(x_result, y_result, x_coordinate, y_coordinate);

    x_result_result=x_result;
    y_result_result=y_result;
    if(max_1>point(x_result-1, y_result-1, x_coordinate, y_coordinate)) {
        max_1 = point(x_result - 1, y_result - 1, x_coordinate, y_coordinate);
        x_result_result = x_result-1;
        y_result_result = y_result-1;

    }
    if(max_1>point(x_result, y_result-1, x_coordinate, y_coordinate)) {
        max_1 = point(x_result, y_result - 1, x_coordinate, y_coordinate);
        x_result_result = x_result;
        y_result_result = y_result-1;

    }
    if(max_1>point(x_result-1, y_result, x_coordinate, y_coordinate)) {
        max_1 = point(x_result - 1, y_result, x_coordinate, y_coordinate);
        x_result_result = x_result-1;
        y_result_result = y_result;

    }
    if(max_1>point(x_result+1, y_result-1, x_coordinate, y_coordinate)) {
        max_1 = point(x_result + 1, y_result - 1, x_coordinate, y_coordinate);
        x_result_result = x_result+1;
        y_result_result = y_result-1;
    }
    if(max_1>point(x_result-1, y_result+1, x_coordinate, y_coordinate)) {
        max_1 = point(x_result - 1, y_result + 1, x_coordinate, y_coordinate);
        x_result_result = x_result-1;
        y_result_result = y_result+1;

    }
    if(max_1>point(x_result+1, y_result, x_coordinate, y_coordinate)) {
        max_1 = point(x_result + 1, y_result, x_coordinate, y_coordinate);
        x_result_result = x_result+1;
        y_result_result = y_result;

    }
    if(max_1>point(x_result+1, y_result+1, x_coordinate, y_coordinate)) {
        max_1 = point(x_result + 1, y_result + 1, x_coordinate, y_coordinate);
        x_result_result = x_result+1;
        y_result_result = y_result+1;

    }
    if(max_1>point(x_result, y_result+1, x_coordinate, y_coordinate)) {
        max_1 = point(x_result, y_result + 1, x_coordinate, y_coordinate);
        x_result_result = x_result;
        y_result_result = y_result+1;

    }
    std::cout<<x_result_result<<" "<<y_result_result;
    return 0;

}
