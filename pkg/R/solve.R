## dyn.load("umfpack_ports.so")

solve_umfpack <- function(A,b) {
	# check arguments
	if (!is.numeric(b))
		stop("argument b must be numeric")
	if( !is(A,"sparseMatrix") )
		stop("argument A must be sparseMatrix")
	if ( ncol(A)!=length(b) )
		stop("ncols of A must be equals to b length")

	# build Ap, Ai, Ax and x arrays
	x = array(0,dim=length(b))
	Ap = A@p
	Ai = A@i
	Ax = A@x

	out <- .C("port_umfpack_di_solve",
		ncol=as.integer(ncol(A)),
		Ap=as.integer(Ap),
		Ai=as.integer(Ai),
		Ax=as.double(Ax),
		b=as.double(b),
		x=as.double(x))

	return(out$x)
}