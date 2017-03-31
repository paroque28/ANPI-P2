# ANPI - Polynomial solver
Version original en https://github.com/paroque28/ANPI-P2
## Usage
```
 anpi-pol - Laguerre - Muller solutions for polynomial equations
Usage:
  anpi-pol [OPTION...]

  -l, --laguerre  Use Laguerre method
  -m, --muller    Use Muller method
  -t, --time      Use time tests
  -f, --float     Use floats for precission
  -p, --polish    Use polish
  -d, --division  Division of polynomials
  -a, --xl arg    Muller lower x
  -b, --xm arg    Muller medium x
  -c, --xu arg    Muller upper x
  -u, --equ arg   Equation 1 to solve, example "3.0+2.0+1.0" is equivalent to
                  3x^2+2x+1
  -v, --eqv arg   Equation 2 used to divide
  -h, --help      Print help
```
## Intructions to build
``` bash
cd <path to anpi-pol>
mkdir build
cd build
cmake ..
make
./anpi-pol
```
## Example
Solve with Laguerre x+2 and make time tests
```bash
./anpi-pol -u 1.0+2.0 -l -t
```