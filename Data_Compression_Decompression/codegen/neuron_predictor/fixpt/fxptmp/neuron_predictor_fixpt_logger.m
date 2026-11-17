% loggingMode - mode of operation : either read or log
%#codegen
%#internal
function loggedData = neuron_predictor_fixpt_logger(varargin)
    coder.inline( 'never' );
    coder.extrinsic( 'MException', 'throw' );
    persistent iterCount
    if isempty( iterCount )
        iterCount = 0;
    end
    if nargin>0
        % Log the data.
        x_in_TB_logger( varargin{ 1 } );
        reset_TB_logger( varargin{ 2 } );
        residual_TB_logger( varargin{ 3 } );
        predicted_TB_logger( varargin{ 4 } );
        iterCount = iterCount + 1;
        loggedData = [  ];
        if iterCount>=Inf
            throw( MException( 'Coder:FXPCONV:MATLABSimBailOut', 'Return early for input computation' ) );
        end
        return
    else
        % Fetch the data.
        % make sure the 'log setup' has been performed
        assert( ~isempty( iterCount ) );
        loggedData.inputs.x_in = x_in_TB_logger();
        loggedData.inputs.reset = reset_TB_logger();
        loggedData.outputs.residual = residual_TB_logger();
        loggedData.outputs.predicted = predicted_TB_logger();
        loggedData.iterCount = iterCount;
    end
end
function out = x_in_TB_logger(v)
    coder.inline( 'never' );
    persistent p
    if nargin==1
        if isempty( p )
            if isobject( v ) && ~isa( v, 'embedded.fi' )
                p = cell( 1, 1 );
                p{ 1 } = loggableValue( v );
            elseif isvector( v ) || isscalar( v )
                coder.varsize( 'p' );
                p = loggableValue( v );
            else
                assert( ndims( v )<=3 );
                % 3D: row, col, no. samples + 4D: row, col, depth , no. of samples
                if ndims( v )==2
                    coder.varsize( 'p', [ Inf, Inf, Inf ], [ true, true, true ] );
                else
                    coder.varsize( 'p', [ Inf, Inf, Inf, Inf ], [ true, true, true, true ] );
                end
                p = loggableValue( v );
            end
        elseif isobject( v ) && ~isa( v, 'embedded.fi' )
            p{ end + 1 } = loggableValue( v );  %ok<AGROW>
        elseif isvector( v ) || isscalar( v )
            if isrow( v )
                p = [ p, loggableValue( v ) ];
            else
                %col, scalar..
                p = [ p; loggableValue( v ) ];
            end
        else
            if ndims( v )==2  % row, col, no. of samples 
                p = cat( 3, p, loggableValue( v ) );
            else  % row, col, depth , no. of samples
                p = cat( 4, p, loggableValue( v ) );
            end
        end
    else
        assert( ~isempty( p ) );
        out = p;
        if iscell( p )
            p = {  };
        else
            p( : ) = [  ];
        end
    end
end
function out = reset_TB_logger(v)
    coder.inline( 'never' );
    persistent p
    if nargin==1
        if isempty( p )
            if isobject( v ) && ~isa( v, 'embedded.fi' )
                p = cell( 1, 1 );
                p{ 1 } = loggableValue( v );
            elseif isvector( v ) || isscalar( v )
                coder.varsize( 'p' );
                p = loggableValue( v );
            else
                assert( ndims( v )<=3 );
                % 3D: row, col, no. samples + 4D: row, col, depth , no. of samples
                if ndims( v )==2
                    coder.varsize( 'p', [ Inf, Inf, Inf ], [ true, true, true ] );
                else
                    coder.varsize( 'p', [ Inf, Inf, Inf, Inf ], [ true, true, true, true ] );
                end
                p = loggableValue( v );
            end
        elseif isobject( v ) && ~isa( v, 'embedded.fi' )
            p{ end + 1 } = loggableValue( v );  %ok<AGROW>
        elseif isvector( v ) || isscalar( v )
            if isrow( v )
                p = [ p, loggableValue( v ) ];
            else
                %col, scalar..
                p = [ p; loggableValue( v ) ];
            end
        else
            if ndims( v )==2  % row, col, no. of samples 
                p = cat( 3, p, loggableValue( v ) );
            else  % row, col, depth , no. of samples
                p = cat( 4, p, loggableValue( v ) );
            end
        end
    else
        assert( ~isempty( p ) );
        out = p;
        if iscell( p )
            p = {  };
        else
            p( : ) = [  ];
        end
    end
end
function out = residual_TB_logger(v)
    coder.inline( 'never' );
    persistent p
    if nargin==1
        if isempty( p )
            if isobject( v ) && ~isa( v, 'embedded.fi' )
                p = cell( 1, 1 );
                p{ 1 } = loggableValue( v );
            elseif isvector( v ) || isscalar( v )
                coder.varsize( 'p' );
                p = loggableValue( v );
            else
                assert( ndims( v )<=3 );
                % 3D: row, col, no. samples + 4D: row, col, depth , no. of samples
                if ndims( v )==2
                    coder.varsize( 'p', [ Inf, Inf, Inf ], [ true, true, true ] );
                else
                    coder.varsize( 'p', [ Inf, Inf, Inf, Inf ], [ true, true, true, true ] );
                end
                p = loggableValue( v );
            end
        elseif isobject( v ) && ~isa( v, 'embedded.fi' )
            p{ end + 1 } = loggableValue( v );  %ok<AGROW>
        elseif isvector( v ) || isscalar( v )
            if isrow( v )
                p = [ p, loggableValue( v ) ];
            else
                %col, scalar..
                p = [ p; loggableValue( v ) ];
            end
        else
            if ndims( v )==2  % row, col, no. of samples 
                p = cat( 3, p, loggableValue( v ) );
            else  % row, col, depth , no. of samples
                p = cat( 4, p, loggableValue( v ) );
            end
        end
    else
        assert( ~isempty( p ) );
        out = p;
        if iscell( p )
            p = {  };
        else
            p( : ) = [  ];
        end
    end
end
function out = predicted_TB_logger(v)
    coder.inline( 'never' );
    persistent p
    if nargin==1
        if isempty( p )
            if isobject( v ) && ~isa( v, 'embedded.fi' )
                p = cell( 1, 1 );
                p{ 1 } = loggableValue( v );
            elseif isvector( v ) || isscalar( v )
                coder.varsize( 'p' );
                p = loggableValue( v );
            else
                assert( ndims( v )<=3 );
                % 3D: row, col, no. samples + 4D: row, col, depth , no. of samples
                if ndims( v )==2
                    coder.varsize( 'p', [ Inf, Inf, Inf ], [ true, true, true ] );
                else
                    coder.varsize( 'p', [ Inf, Inf, Inf, Inf ], [ true, true, true, true ] );
                end
                p = loggableValue( v );
            end
        elseif isobject( v ) && ~isa( v, 'embedded.fi' )
            p{ end + 1 } = loggableValue( v );  %ok<AGROW>
        elseif isvector( v ) || isscalar( v )
            if isrow( v )
                p = [ p, loggableValue( v ) ];
            else
                %col, scalar..
                p = [ p; loggableValue( v ) ];
            end
        else
            if ndims( v )==2  % row, col, no. of samples 
                p = cat( 3, p, loggableValue( v ) );
            else  % row, col, depth , no. of samples
                p = cat( 4, p, loggableValue( v ) );
            end
        end
    else
        assert( ~isempty( p ) );
        out = p;
        if iscell( p )
            p = {  };
        else
            p( : ) = [  ];
        end
    end
end
function out = loggableValue(in)
    coder.inline( 'always' );
    if isenum( in )
        out = double( in );
    else
        out = in;
    end
end
