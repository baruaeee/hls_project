function y = neuron(x, w, b)
    % x: input vector, w: weights, b: bias
    y = sum(x .* w) + b;
end