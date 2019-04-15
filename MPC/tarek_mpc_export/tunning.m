w=[];
wn=[];
w  =  diag([0.5 0.5 0.5 0.5 0.5 0.5 0.5 0.5]);
wn =  diag([0.5 0.5 0.5 0.5 0.5 0.5 ]);

 w= reshape (w,1,8*8);
 wn= reshape (wn,1,6*6);
 
load('test.mat')
input=[];
ddd=[commandActual TRAJECTORY];
Ts=0.01;
N=40;

X0 = [80/3.6 0 0 0 -1.056 0];
Xref = [0 0 0 0 0 0];
input=[];
input.x = repmat(X0,N+1,1).';
Uref = zeros(N,2);
input.u = Uref.';
input.y = [repmat(Xref,N,1) Uref].';

input.yN = Xref.';
input.W  = diag([0.5 0.5 0.5 0.5 0.5 0.5 0.5 0.5]);
input.WN = diag([0.5 0.5 0.5 0.5 0.5 0.5 ]);

init=[];
input.x0 = X0.';
init.x = input.x(:).';
init.u = input.u(:).';
init.y = input.y(:).';
init.yN = input.yN(:).';
init.W = input.W(:).';
init.WN = input.WN(:).';
init.x0 = input.x0(:).';

