function Y = matrix_mult(X, W)
    % Fixed size 4x4 matrix multiplication for high performance
    M = size(X, 1);
    N = size(X, 2);
    P = size(W, 2);

    % Use 'like' to preserve data types (e.g., fixed-point)
    Y = zeros(M, P, 'like', X);

    % Tell Vitis HLS to completely partition all dimensions (dim=0 means all dimensions)
    coder.hdl.literaltext("#pragma HLS ARRAY_PARTITION variable=X complete dim=0");
    coder.hdl.literaltext("#pragma HLS ARRAY_PARTITION variable=W complete dim=0");
    coder.hdl.literaltext("#pragma HLS ARRAY_PARTITION variable=Y complete dim=0");

    % Force complete unrolling on every loop level to build a pure hardware grid
    for i = 1:M
        coder.hdl.loopspec('unroll');
        for j = 1:P
            coder.hdl.loopspec('unroll');
            for k = 1:N
                coder.hdl.loopspec('unroll');
                
                % Optional optimization: flatten addition trees or handle base initialization
                if k == 1
                    Y(i, j) = X(i, k) * W(k, j);
                else
                    Y(i, j) = Y(i, j) + X(i, k) * W(k, j);
                end
            end
        end
    end
end