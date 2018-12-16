$TITLE TEST LOIC FUNCTION
$INLINECOM { }

$ONTEXT
KAUST, August 2016
Loic Giraldi
Omar Knio
Ricardo Lima
Tong Wang

GAMS file to test the extrinsic function developed by Loic Giraldi.
We compare precomputed values -- f, g, h -- for (x(i),y(i)) to the values
computed by the Loic's function.

$OFFTEXT

* Set the gradient and hessian comparison
* Analytical
$SET GRAD grad
$SET HESS hess
* Finite differences
*$SET GRAD gradn
*$SET HESS hessn

sets
    i          'test values' /1*5/
    l          'labels' 
    /f
     fx, fy
     fxx, fxy, fyx, fyy
     f_a, f_r
     fx_a, fx_r
     fy_a, fy_r
     fxx_a, fxx_r
     fxy_a, fxy_r
     fyx_a, fyx_r
     fyy_a, fyy_r/
    lf(l)
    /f
     f_a, f_r/
    lg(l)
    /fx, fy
     fx_a, fx_r
     fy_a, fy_r/
    lh(l)
    /fxx, fxy, fyx, fyy
     fxx_a, fxx_r
     fxy_a, fxy_r
     fyx_a, fyx_r
     fyy_a, fyy_r/
    large(i)   'function - track large errors, absolute or relative'
    ii(i)
parameters
    x(i)       'function argument'
    y(i)       'function argument'
    f(i)       'intrinsic function value for (x(i),y(i))'
    g(i,l)     'intrinsic gradient value for (x(i),y(i))'
    h(i,l)     'intrinsic hessian value for (x(i),y(i))'
* Evaluation values using the extrinsic function from Loic
    ef(i)      'extrinsic function value for (x(i),y(i))'
    eg(i,l)    'extrinsic gradient value for (x(i),y(i))'
    eh(i,l)    'extrinsic hessian value for (x(i),y(i))'
* Evaluation of the deviations
    delta(i,l) 'errors  of l for the point i'
    errorinf(i,l) 'log of errors in f'
    erroring(i,l) 'log of errors in g'
    errorinh(i,l) 'log of errors in h'
    tmp(i);
scalars
    ntests     'number of data points'              /0/ 
    nerrors    'track number of errors'             /0/
    aeps0      'absolute error tolerance: function' / 1e-15 /
    reps0      'relative error tolerance: function' / 1e-15 /
    aeps1      'absolute error tolerance: grad'     / 1e-5 /
    reps1      'relative error tolerance: grad'     / 1e-5 /
    aeps2      'absolute error tolerance: hess'     / 1e-5 /
    reps2      'relative error tolerance: hess'     / 1e-5 /
 ;


display "%system.buildcode%";

* Define the library name
$funclibin ll ./libwrappedU64.so

* Define the function name
function loicf   'Test function from Loic'  / ll.wrappedU /;
*  vel + f + loicf(x(t), y(t))

* Define macros to simpliy calculations
$macro lfv        loicf(x(i),y(i));
$macro lfg(j)     loicf.%GRAD%(j:x(i),y(i));
$macro lfh(j1,j2) loicf.%HESS%(j1:j2:x(i),y(i));

* Data points to test 
x('1') = -10.5;
x('2') = -0.90;
x('3') = 0.00;
x('4') = 1e-6;
x('5') = 1.00;
y('1') = PI;
y('2') = 0.0;
y('3') = 3;
y('4') = PI;
y('5') = 2;

* Number of data points
ntests = card(i);

* Pre-computed values to compare
f(i)       = x(i) * x(i) * sin(y(i));
g(i,'fx')  = 2 * x(i) * sin(y(i));
g(i,'fy')  = x(i) * x(i) * cos(y(i));
h(i,'fxx') = 2 * sin(y(i));
h(i,'fxy') = 2 * x(i) * cos(y(i));
h(i,'fyx') = 2 * x(i) * cos(y(i));
h(i,'fyy') = - x(i) * x(i) * sin(y(i));

* Check pre-computed values
display "function values from the defined function:",f;
display "gradient values from the defined function:",g;
display "hessian values from the defined function:",h;


* Evaluate the function, gradient, and hessian
loop(i,
    ef(i)        = lfv;
    eg(i,'fx')   = lfg(1);
    eg(i,'fy')   = lfg(2);
    eh(i,'fxx')  = lfh(1,1);
    eh(i,'fxy')  = lfh(1,2);
    eh(i,'fyx')  = lfh(2,1);
    eh(i,'fyy')  = lfh(2,2);
);

* Check Loic's values
display "function values from the Loic's function:",ef;
display "gradient values from the Loic's function:",eg;
display "hessian values from the Loic's function:",eh;

       
* Calculate the absolute deviation
delta(i,'f_a') = abs(f(i) - ef(i));
delta(i,'fx_a') = abs(g(i,'fx') - eg(i,'fx'));
delta(i,'fy_a') = abs(g(i,'fy') - eg(i,'fy'));
delta(i,'fxx_a') = abs(h(i,'fxx') - eh(i,'fxx'));
delta(i,'fxy_a') = abs(h(i,'fxy') - eh(i,'fxy'));
delta(i,'fyx_a') = abs(h(i,'fyx') - eh(i,'fyx'));
delta(i,'fyy_a') = abs(h(i,'fyy') - eh(i,'fyy'));

* Calculate the relative deviation
tmp(i) = abs(f(i));
ii(i)  = tmp(i) > 0;
delta(i,'f_r') = INF;
delta(i,'f_r')$(delta(i,'f_a') EQ 0) =0;
delta(ii,'f_r') = delta(ii,'f_a') / tmp(ii);

tmp(i) = abs(g(i,'fx'));
ii(i)  = tmp(i) > 0;
delta(i,'fx_r') = INF;
delta(i,'fx_r')$(delta(i,'fx_a') EQ 0) =0;
delta(ii,'fx_r') = delta(ii,'fx_a') / tmp(ii);

tmp(i) = abs(g(i,'fy'));
ii(i)  = tmp(i) > 0;
delta(i,'fy_r') = INF;
delta(i,'fy_r')$(delta(i,'fy_a') EQ 0) =0;
delta(ii,'fy_r') = delta(ii,'fy_a') / tmp(ii);

tmp(i) = abs(h(i,'fxx'));
ii(i)  = tmp(i) > 0;
delta(i,'fxx_r') = INF;
delta(i,'fxx_r')$(delta(i,'fxx_a') EQ 0) =0;
delta(ii,'fxx_r') = delta(ii,'fxx_a') / tmp(ii);

tmp(i) = abs(h(i,'fxy'));
ii(i)  = tmp(i) > 0;
delta(i,'fxy_r') = INF;
delta(i,'fxy_r')$(delta(i,'fxy_a') EQ 0) =0;
delta(ii,'fxy_r') = delta(ii,'fxy_a') / tmp(ii);

tmp(i) = abs(h(i,'fyx'));
ii(i)  = tmp(i) > 0;
delta(i,'fyx_r') = INF;
delta(i,'fyx_r')$(delta(i,'fyx_a') EQ 0) =0;
delta(ii,'fyx_r') = delta(ii,'fyx_a') / tmp(ii);

tmp(i) = abs(h(i,'fyy'));
ii(i)  = tmp(i) > 0;
delta(i,'fyy_r') = INF;
delta(i,'fyy_r')$(delta(i,'fyy_a') EQ 0) =0;
delta(ii,'fyy_r') = delta(ii,'fyy_a') / tmp(ii);


* Check for errors
large(i)  = ((delta(i,'f_a') > aeps0) and (delta(i,'f_r') > reps0));
errorinf(large,lf) = delta(large,lf);  
nerrors = nerrors + card(large);

large(i)  = ((delta(i,'fx_a') > aeps1) and (delta(i,'fx_r') > reps1)
    OR       (delta(i,'fy_a') > aeps1) and (delta(i,'fy_r') > reps1));
erroring(large,lg) = delta(large,lg);
nerrors = nerrors + card(large);

large(i)  = ((delta(i,'fxx_a') > aeps2) and (delta(i,'fxx_r') > reps2)
    OR      (delta(i,'fxy_a') > aeps2) and (delta(i,'fxy_r') > reps2)
    OR      (delta(i,'fyx_a') > aeps2) and (delta(i,'fyx_r') > reps2)
    OR      (delta(i,'fyy_a') > aeps2) and (delta(i,'fyy_r') > reps2));
errorinh(large,lh) = delta(large,lh);
nerrors = nerrors + card(large);

display 'absolute tolerance, func: ', aeps0;
display 'relative tolerance, func: ', reps0;
display 'failed function tests', errorinf;

display 'absolute tolerance, grad: ', aeps1;
display 'relative tolerance, grad: ', reps1;
display 'failed gradient tests', erroring;

display 'absolute tolerance, hess: ', aeps2;
display 'relative tolerance, hess: ', reps2;
display 'failed Hessian tests', errorinh;

* display data;
display 'data points tested: ', ntests;
display '            errors: ', nerrors;

abort$(nerrors) 'There were errors';


















    