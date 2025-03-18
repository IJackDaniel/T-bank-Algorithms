#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    // Чтение матрицы
    vector<vector<long>> matrix(N, vector<long>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> matrix[i][j];
        }
    }

    // Создание массива префиксных сумм
    vector<vector<long>> prefixSum(N + 1, vector<long>(M + 1, 0));
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            prefixSum[i][j] = prefixSum[i-1][j] + prefixSum[i][j-1] - prefixSum[i-1][j-1] + matrix[i-1][j-1];
        }
    }

    // Обработка запросов
    for (int k = 0; k < K; ++k) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;

        // Вычисление суммы в прямоугольнике
        long sum = prefixSum[y2][x2] - prefixSum[y1-1][x2] - prefixSum[y2][x1-1] + prefixSum[y1-1][x1-1];
        cout << sum << endl;
    }

    return 0;
}