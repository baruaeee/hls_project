% neuron_tb.m
%x = randn(1, 16);
%w = [0.5, 0.3, 0.1, 0.1, 0.2, 0.8, 0.4, 0.7, 0.3, 0.6, 0.9, 0.5, 0.4, 0.6, 0.2, 0.3];
%b = 0.0;
% y = neuron(x, w, b);
%y = neuron(x, w, b);
% disp(x);
%disp(y);

M = 4;
N = 4;
P = 4;

x = 2 * rand(M, N) - 1;
w = 0.1 * rand(N, P);

y_hls = matrx_mul(x, w);

y_ref = x * w;

error = max(max(abs(y_hls - y_ref)));
fprintf('Maximum absolute error: %.e\n', error);

if error < 1e-6
    fprintf('Test PASSED\n');
else
    fprintf('Test FAILED\n');
end

disp(y_hls);
disp(y_ref);