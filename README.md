# Benchmark Functions for Network-based Distributed Optimization

## Introduction

## Setting of Benchmark Functions

The above table shows the problem scale, homogeneity and heterogeneity, elementary function type, and network topology of benchmark functions. 

Functions F1-F6 contain 20 subcomponents, including five 100-dimensional problems, five 50-dimensional problems, and ten 25-dimensional problems. These subcomponents overlap with each other in a chain structure, the same topology as “f13” and “f14” in benchmark CEC2013. Each subcomponent has two neighbors except for the first and last one, and the size of each overlap domain is 5 dimensions. Thus, the size of the global problem is $1005+505+2510-195=905$ dimensions.

Functions F7-F12 contain 40 100-dimensional subcomponents. Each subcomponent has 3 neighbors. A randomly generated network is used as the topology of functions, where the size of each overlap domain is 10 dimensions. Thus, the size of the global problem is $10040-6010 =3400$ dimensions.

Functions F13-F18 contain 60 200-dimensional subcomponents. Each subcomponent has 4 neighbors. A randomly generated network is used as the topology of functions, where the size of each overlap domain is 15 dimensions. Thus, the size of the global problem is $20060-12015 =10200$ dimensions.

The type of elementary functions includes Elliptic, Schwefel and Rosenbrock. Functions F1-F3, F7-F9, F13-F15 are homogeneous functions, and Functions F4-F6, F10-F12, F16-F18 are heterogeneous functions. 

The definition of local objective functions is described in Table S1 in the supplementary material. To be specific, $|S_i|$ is the problem scale of $i$-th subcomponent, $\boldsymbol{x}i^{opt}$ is the optimum solution of subproblem $f_i$, $T{osz}$ is a transformation function to create smooth local irregularities, $T_{asy}^{0.2}$ is a transformation function to break the symmetry of functions. Thus, all the local objective functions are non-separable functions. 

In the benchmark of network-based distributed optimization, the global objective function $F$ is a sum of local objective functions.

$$F = \sum_{i=1}^{n} f_i$$

The local objective functions are realized based on three elementary functions: Elliptic, Schwefel, and Rosenbrock.

$$f{elliptic}(x)=\sum{i=1}^D 10^{6\frac{i-1}{D-1}}x_i^2$$

$$f{schwefel}(x)=\sum{i=1}^D (\sum_{j=1}^i x_i)^2$$

$$f{rosenbrock}(x) = \sum{i=1}^{D-1} 100(x_i^2-x_{i+1})^2+(x_i-1)^2$$



It is worth noting that the local objective functions are processed in four steps:

1. The optimal solution of functions is shift from $\vec{0}$ to $\boldsymbol{x}_i^{opt}$, which is randomly generated. This operation ensures that the optimal solution of each local objective function is different. 

2. The vector is rotated by an orthogonal matrix $R$, which is also randomly generated. The operation makes all the variables in the objective function interdependent on each other, ensuring the local objective function is non-separable.

3.  The vector is put into a transformation function $T_{osz}$ to create smooth local irregularities. 

4.  The vector is put into a transformation function $T_{asy}$ to break the symmetry of the symmetric functions.



Finally, the local objective function is expressed as follows:

$$f_i=f_{elementary}(z_i)$$

$$z_i=T{asy}^{0.2}(T{osz}(R_iy_i))$$

$$y_i=\boldsymbol{x}i-\boldsymbol{x}i^{opt}$$



The definition of $T{osz}$ and $T{asy}$ can be found in benchmark CEC2013 [1].

[1] X.  Li,  K.  Tang,  M.  N.  Omidvar,  Z.  Yang,  and  K.  Qin,  “Benchmark  Functions  for  the  CEC’2013  Special  Session  and  Competition  onLarge-Scale Global Optimization,”gene, p. 23, 2013.

## Parameter Setting of MACPO

