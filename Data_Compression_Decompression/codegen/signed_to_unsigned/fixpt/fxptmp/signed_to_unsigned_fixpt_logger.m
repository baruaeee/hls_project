% loggingMode - mode of operation : either read or log
%#codegen
%#internal
function loggedData = signed_to_unsigned_fixpt_logger(varargin)
    coder.inline( 'never' );
    coder.extrinsic( 'MException', 'throw' );
    persistent iterCount
    if isempty( iterCount )
        iterCount = 0;
    end
    if nargin>0
        % Log the data.
        e_in_TB_logger( varargin{ 1 } );
        u_out_TB_logger( varargin{ 2 } );
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
        loggedData.inputs.e_in = e_in_TB_logger();
        loggedData.outputs.u_out = u_out_TB_logger();
        loggedData.iterCount = iterCount;
    end
end
function out = e_in_TB_logger(v)
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
function out = u_out_TB_logger(v)
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
