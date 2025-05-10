#include <iostream>
#include <Eigen/Dense>
#include <cmath>
#include <ctime>

using namespace Eigen;
using namespace std;

float sigmoid(float x) {
    return 1.0f / (1.0f + exp(-x));
}

float sigmoid_derivative(float x) {
    return x * (1.0f - x);
}

int main() {
    srand(time(0));

    // Dados XOR: 4 amostras, 2 entradas
    MatrixXf input(4, 2);
    input << 0, 0,
             0, 1,
             1, 0,
             1, 1;

    VectorXf target(4);
    target << 0, 1, 1, 0;

    int input_neurons = 2;
    int hidden_neurons = 2;
    int output_neurons = 1;
    float lr = 0.5;

    // Inicializando pesos com valores aleatórios entre -1 e 1
    MatrixXf weights1 = MatrixXf::Random(input_neurons, hidden_neurons);
    VectorXf weights2 = VectorXf::Random(hidden_neurons);

    for (int epoch = 0; epoch < 10000; ++epoch) {
        for (int i = 0; i < 4; ++i) {
            Vector2f sample = input.row(i);
            float desired = target(i);

            // Feedforward
            Vector2f hidden = (weights1.transpose() * sample).unaryExpr(ptr_fun(sigmoid));
            float output = sigmoid(weights2.dot(hidden));

            // Erro e backpropagation
            float error = desired - output;
            float delta_output = error * sigmoid_derivative(output);

            Vector2f delta_hidden;
            for (int j = 0; j < hidden_neurons; ++j)
                delta_hidden(j) = delta_output * weights2(j) * sigmoid_derivative(hidden(j));

            // Atualiza pesos
            weights2 += lr * delta_output * hidden;
            weights1 += lr * sample * delta_hidden.transpose();
        }
    }

    // Testando
    cout << "Resultados após treino:\n";
    for (int i = 0; i < 4; ++i) {
        Vector2f sample = input.row(i);
        Vector2f hidden = (weights1.transpose() * sample).unaryExpr(ptr_fun(sigmoid));
        float output = sigmoid(weights2.dot(hidden));

        cout << sample(0) << " XOR " << sample(1) << " = " << output << endl;
    }

    return 0;
}
