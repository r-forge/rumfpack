/*
 * File:   umfpack_ports.c
 * Author: Victor Potenciano
 *
 * Created on 23 de marzo de 2011, 13:49
 */

#include "suitesparse/umfpack.h"
#include <stdlib.h>


/**
 * solves Ax = b
 *
 * @param ncol
 * @param Ap
 * @param Ai
 * @param Ax
 * @param b
 * @param x : I/O
 */
void port_umfpack_di_solve( int *ncol, int *Ap, int*Ai, double *Ax, double *b, double *x)
{
    int n = ncol[0];
    double *null = (double *) NULL ;
    void *Symbolic, *Numeric ;
    (void) umfpack_di_symbolic (n, n, Ap, Ai, Ax, &Symbolic, null, null) ;
    (void) umfpack_di_numeric (Ap, Ai, Ax, Symbolic, &Numeric, null, null) ;
    umfpack_di_free_symbolic (&Symbolic) ;
    (void) umfpack_di_solve (UMFPACK_A, Ap, Ai, Ax, x, b, Numeric, null, null) ;
    umfpack_di_free_numeric (&Numeric) ;
}