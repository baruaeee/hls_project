% neuron_tb.m
x = randn(1, 4);
w = [0.5, 0.3, 0.1, 0.1];
b = 0.0;
y = neuron(x, w, b);
disp(y);