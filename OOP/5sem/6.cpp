int** transpose(int** matrix, unsigned int N, unsigned int M) {
    int** result = new int*[M];
    for (int i = 0; i < M; i++) {
        result[i] = new int[N];
        for (int j = 0; j < N; j++) {
            result[i][j] = matrix[j][i];
        }
    }
    return result;
}